#include "libc.h"
#include "registers.h"
#include "functions.h"

static struct sdk_i2cm_ctx {
	uint8_t *buf;
	size_t sz;
	uint8_t volatile status;
} i2cm_ctx[2];

void
i2cm_init(struct sdk_i2cm *i2cm, uint32_t baud_hz, uint8_t pin_scl, uint8_t pin_sda)
{
	uint8_t pincfg;
	uint32_t baud;

	pincfg = 0
	/* enable peripheral multiplexing */
	 | BIT(PORT_PINCFG_PMUXEN)
	/* internal pull-up resistor on SCL pin */
	 | BIT(PORT_PINCFG_PULLEN)
	/* permit input to check for SCL pin stretching as common in I²C */
	 | BIT(PORT_PINCFG_INEN)
	/* increase driver strength a bit */
	 | BIT(PORT_PINCFG_DRVSTR);
	PORT->PINCFG[pin_scl] = pincfg;
	PORT->PINCFG[pin_sda] = pincfg;

	/* plug SCL and SDA pins to SERCOM */
	PORT->PMUX[pin_scl/2] = (PORT->PMUX[pin_scl/2] & ~PORT_PMUX(pin_scl, 0xFu))
	 | PORT_PMUX(pin_scl, PORT_PMUX_SERCOM);
	PORT->PMUX[pin_sda/2] = (PORT->PMUX[pin_sda/2] & ~PORT_PMUX(pin_sda, 0xFu))
	 | PORT_PMUX(pin_sda, PORT_PMUX_SERCOM);

	i2cm->CTRLA = 0
	/* time-out when SCL held low for too long */
	 | BIT(I2CM_CTRLA_LOWTOUTEN)
	/* default for inactivity time-out */
	 | BITS(I2CM_CTRLA_INACTOUT, I2CM_CTRLA_INACTOUT_205_US)
	/* allow SCL pin to be stretched by the slave */
	 | BIT(I2CM_CTRLA_SCLSM)
	/* time-out and reset ourself when a slave stretches SCL for 25ms */
	 | BIT(I2CM_CTRLA_SEXTTOEN)
	/* time-out and reset ourself when a slave stretches SCL for 10ms */
	 | BIT(I2CM_CTRLA_MEXTTOEN)
	/* default speed mode to standard speed */
	 | BITS(I2CM_CTRLA_SPEED, I2CM_CTRLA_SPEED_400_KHZ_MAX)
	/* set SERCOM generic serial to I²C Master mode */
	 | BITS(I2CM_CTRLA_MODE, I2CM_CTRLA_MODE_I2C_MASTER)
	/* default for SDA pin hold time */
	 | BITS(I2CM_CTRLA_SDAHOLD, I2CM_CTRLA_SDAHOLD_450_NS);

	i2cm->CTRLB = 0
	/* this code only supports "smart mode" */
	 | BIT(I2CM_CTRLB_SMEN);

	/* the rising time of the clock has been ignored below, it varies
	 * depending on the capacitance of the bus */
	baud = sercom_get_clock_hz(sercom_get_id(i2cm)) / (baud_hz * 2) - 1;

	i2cm->BAUD = 0
	/* set the baud rate for high-speed mode */
//	 | BITS(I2CM_BAUD_HSBAUDLOW, 0) | BITS(I2CM_BAUD_HSBAUD, baud)
	/* set the baud rate for normal mode */
	 | BITS(I2CM_BAUD_BAUDLOW, 0) | BITS(I2CM_BAUD_BAUD, baud);

	i2cm->INTENSET = 0
	/* master-on-bus interrupt: when writing */
	 | BIT(I2CM_INTENSET_MB) 
	/* slave-on-bus interrupt: when reading */
	 | BIT(I2CM_INTENSET_SB)
	/* interrupts for transaction errors */
	 | BIT(I2CM_INTENSET_ERROR);

	/* enable I²C *after* it is configured (#27.6.2.1) */
	i2cm->CTRLA |= BIT(I2CM_CTRLA_ENABLE);
	while (i2cm->SYNCBUSY & BIT(I2CM_SYNCBUSY_ENABLE));

	/* we just started, we do not know in which state are the
	 * slave, but we guess and move from UNKNOWN to IDLE */
	i2cm->STATUS = (i2cm->STATUS  & ~MASK(I2CM_STATUS_BUSSTATE))
	 | BITS(I2CM_STATUS_BUSSTATE, I2CM_STATUS_BUSSTATE_IDLE);
	while (i2cm->SYNCBUSY & BIT(I2CM_SYNCBUSY_SYSOP));

	/* interrupt will be triggered as soon as I2CM->ADDR is written */
	NVIC->ISER = BIT(9 + sercom_get_id(i2cm));
}

static inline void
i2cm_interrupt_error(struct sdk_i2cm *i2cm, struct sdk_i2cm_ctx *ctx)
{
	if (FIELD(i2cm->STATUS, I2CM_STATUS_BUSSTATE)
	 == I2CM_STATUS_BUSSTATE_BUSY) {
		i2cm->CTRLB &= ~BIT(I2CM_CTRLB_ACKACT);
		i2cm->CTRLB = (i2cm->CTRLB & ~MASK(I2CM_CTRLB_CMD))
		 | BITS(I2CM_CTRLB_CMD, I2CM_CTRLB_CMD_ACK_STOP);
	}
	ctx->status = -1;
}

static inline void
i2cm_interrupt_master_on_bus(struct sdk_i2cm *i2cm, struct sdk_i2cm_ctx *ctx)
{
	if (ctx->sz == 0) {
		i2cm->CTRLB = (i2cm->CTRLB & ~MASK(I2CM_CTRLB_CMD))
		 | BITS(I2CM_CTRLB_CMD, I2CM_CTRLB_CMD_ACK_STOP);
		ctx->status = 0;
	} else {
		i2cm->DATA = *ctx->buf++;
		ctx->sz--;
	}
}

static inline void
i2cm_interrupt_slave_on_bus(struct sdk_i2cm *i2cm, struct sdk_i2cm_ctx *ctx)
{
	if (ctx->sz == 0) {
		i2cm->CTRLB &= ~BIT(I2CM_CTRLB_ACKACT);
		i2cm->CTRLB = (i2cm->CTRLB & ~MASK(I2CM_CTRLB_CMD))
		 | BITS(I2CM_CTRLB_CMD, I2CM_CTRLB_CMD_ACK_STOP);
		ctx->status = 0;
	} else {
		*ctx->buf++ = i2cm->DATA;
		ctx->sz--;
	}
}

void
i2cm_interrupt(struct sdk_i2cm *i2cm)
{
	struct sdk_i2cm_ctx *ctx = &i2cm_ctx[sercom_get_id(i2cm)];
	uint8_t reg = i2cm->INTFLAG;

	if (reg & BIT(I2CM_INTFLAG_ERROR))
		i2cm_interrupt_error(i2cm, ctx);
	else if (reg & BIT(I2CM_INTFLAG_MB))
		i2cm_interrupt_master_on_bus(i2cm, ctx);
	else if (reg & BIT(I2CM_INTFLAG_SB))
		i2cm_interrupt_slave_on_bus(i2cm, ctx);
}

static inline void
i2cm_queue(struct sdk_i2cm *i2cm, uint8_t addr, uint8_t *buf, size_t sz, uint8_t rw)
{
	struct sdk_i2cm_ctx *ctx = &i2cm_ctx[sercom_get_id(i2cm)];

	ctx->status = 1;
	ctx->buf = buf;
	ctx->sz = sz;

        /* this starts to send the address immediately */
	i2cm->ADDR = BITS(I2CM_ADDR_ADDR, (addr << 1) | rw);

	/* that's it, the rest happens in interrupts */
}

void
i2cm_queue_tx(struct sdk_i2cm *i2cm, uint8_t addr, uint8_t const *buf, size_t sz)
{
	i2cm_queue(i2cm, addr, (uint8_t *)buf, sz, 0);
}

void
i2cm_queue_rx(struct sdk_i2cm *i2cm, uint8_t addr, uint8_t *buf, size_t sz)
{
	i2cm_queue(i2cm, addr, buf, sz, 1);
}

int
i2cm_wait(struct sdk_i2cm *i2cm)
{
	struct sdk_i2cm_ctx *ctx = &i2cm_ctx[sercom_get_id(i2cm)];

	while (ctx->status > 0);
	return ctx->status;
}
