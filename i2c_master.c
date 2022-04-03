#include "libc.h"
#include "registers.h"
#include "functions.h"

static struct mcu_i2c_master_ctx {
	uint8_t *buf;
	size_t sz;
	uint8_t volatile status;
} i2c_master_ctx[2];

void
i2c_master_init(struct mcu_i2c_master *i2c_master, uint32_t baud_hz, uint8_t pin_scl, uint8_t pin_sda)
{
	uint8_t pincfg;
	uint32_t baud;

	pincfg = 0
	/* enable peripheral multiplexing */
	 | PORT_PINCFG_PMUXEN
	/* internal pull-up resistor on SCL pin */
	 | PORT_PINCFG_PULLEN
	/* permit input to check for SCL pin stretching as common in I²C */
	 | PORT_PINCFG_INEN
	/* increase driver strength a bit */
	 | PORT_PINCFG_DRVSTR;
	PORT->PINCFG[pin_scl] = pincfg;
	PORT->PINCFG[pin_sda] = pincfg;

	/* plug SCL and SDA pins to SERCOM */
	port_set_pmux(pin_scl, PORT_PMUX_SERCOM);
	port_set_pmux(pin_sda, PORT_PMUX_SERCOM);

	i2c_master->CTRLA = 0
	/* time-out when SCL held low for too long */
	 | I2C_MASTER_CTRLA_LOWTOUTEN
	/* default for inactivity time-out */
	 | I2C_MASTER_CTRLA_INACTOUT_205_US
	/* allow SCL pin to be stretched by the slave */
	 | I2C_MASTER_CTRLA_SCLSM
	/* time-out and reset ourself when a slave stretches SCL for 25ms */
	 | I2C_MASTER_CTRLA_SEXTTOEN
	/* time-out and reset ourself when a slave stretches SCL for 10ms */
	 | I2C_MASTER_CTRLA_MEXTTOEN
	/* set SERCOM generic serial to I²C Master mode */
	 | I2C_MASTER_CTRLA_MODE_I2C_MASTER
	/* default speed mode to standard speed */
	 | I2C_MASTER_CTRLA_SPEED_400_KHZ_MAX
	/* default for SDA pin hold time */
	 | I2C_MASTER_CTRLA_SDAHOLD_450_NS;

	i2c_master->CTRLB = 0
	/* this code only supports "smart mode" where hardware does more */
	 | I2C_MASTER_CTRLB_SMEN;

	/* the rising time of the clock has been ignored below, it varies
	 * depending on the capacitance of the bus */
	baud = sercom_get_clock_hz(sercom_get_id(i2c_master)) / (baud_hz * 2) - 1;

	/* set the baud rate for normal mode */
	i2c_master->BAUD = baud << I2C_MASTER_BAUD_BAUD_Pos;

	i2c_master->INTENSET = 0
	/* master-on-bus interrupt: when writing */
	 | I2C_MASTER_INTENSET_MB 
	/* slave-on-bus interrupt: when reading */
	 | I2C_MASTER_INTENSET_SB
	/* interrupts for transaction errors */
	 | I2C_MASTER_INTENSET_ERROR;

	/* enable I²C *after* it is configured (#27.6.2.1) */
	i2c_master->CTRLA |= I2C_MASTER_CTRLA_ENABLE;
	while (i2c_master->SYNCBUSY & I2C_MASTER_SYNCBUSY_ENABLE);

	/* we just started, we do not know in which state are the
	 * slave, but we guess and move from UNKNOWN to IDLE */
	i2c_master->STATUS = (i2c_master->STATUS  & ~I2C_MASTER_STATUS_BUSSTATE_Msk)
	 | I2C_MASTER_STATUS_BUSSTATE_IDLE;
	while (i2c_master->SYNCBUSY & I2C_MASTER_SYNCBUSY_SYSOP);

	/* interrupt will be triggered as soon as I2C_MASTER->ADDR is written */
	NVIC->ISER = 1u << (9 + sercom_get_id(i2c_master));
}

static inline void
i2c_master_interrupt_error(struct mcu_i2c_master *i2c_master, struct mcu_i2c_master_ctx *ctx)
{
	if (FIELD(i2c_master->STATUS, I2C_MASTER_STATUS_BUSSTATE)
	 == I2C_MASTER_STATUS_BUSSTATE_BUSY) {
		i2c_master->CTRLB &= ~I2C_MASTER_CTRLB_ACKACT;
		i2c_master->CTRLB = (i2c_master->CTRLB & ~I2C_MASTER_CTRLB_CMD_Msk)
		 | I2C_MASTER_CTRLB_CMD_ACK_STOP;
	}
	ctx->status = -1;
}

static inline void
i2c_master_interrupt_master_on_bus(struct mcu_i2c_master *i2c_master, struct mcu_i2c_master_ctx *ctx)
{
	if (ctx->sz == 0) {
		i2c_master->CTRLB = (i2c_master->CTRLB & ~I2C_MASTER_CTRLB_CMD_Msk)
		 | I2C_MASTER_CTRLB_CMD_ACK_STOP;
		ctx->status = 0;
	} else {
		i2c_master->DATA = *ctx->buf++;
		ctx->sz--;
	}
}

static inline void
i2c_master_interrupt_slave_on_bus(struct mcu_i2c_master *i2c_master, struct mcu_i2c_master_ctx *ctx)
{
	if (ctx->sz == 0) {
		i2c_master->CTRLB &= ~I2C_MASTER_CTRLB_ACKACT;
		i2c_master->CTRLB = (i2c_master->CTRLB & ~I2C_MASTER_CTRLB_CMD_Msk)
		 | I2C_MASTER_CTRLB_CMD_ACK_STOP;
		ctx->status = 0;
	} else {
		*ctx->buf++ = i2c_master->DATA;
		ctx->sz--;
	}
}

void
i2c_master_interrupt(struct mcu_i2c_master *i2c_master)
{
	struct mcu_i2c_master_ctx *ctx = &i2c_master_ctx[sercom_get_id(i2c_master)];
	uint8_t reg = i2c_master->INTFLAG;

	if (reg & I2C_MASTER_INTFLAG_ERROR)
		i2c_master_interrupt_error(i2c_master, ctx);
	else if (reg & I2C_MASTER_INTFLAG_MB)
		i2c_master_interrupt_master_on_bus(i2c_master, ctx);
	else if (reg & I2C_MASTER_INTFLAG_SB)
		i2c_master_interrupt_slave_on_bus(i2c_master, ctx);
}

static inline void
i2c_master_queue(struct mcu_i2c_master *i2c_master, uint8_t addr, uint8_t *buf, size_t sz, uint8_t rw)
{
	struct mcu_i2c_master_ctx *ctx = &i2c_master_ctx[sercom_get_id(i2c_master)];

	ctx->status = 1;
	ctx->buf = buf;
	ctx->sz = sz;

        /* this starts to send the address immediately */
	i2c_master->ADDR = ((addr << 1) | rw) << I2C_MASTER_ADDR_ADDR_Pos;

	/* that's it, the rest happens in interrupts */
}

void
i2c_master_queue_tx(struct mcu_i2c_master *i2c_master, uint8_t addr, uint8_t const *buf, size_t sz)
{
	i2c_master_queue(i2c_master, addr, (uint8_t *)buf, sz, 0);
}

void
i2c_master_queue_rx(struct mcu_i2c_master *i2c_master, uint8_t addr, uint8_t *buf, size_t sz)
{
	i2c_master_queue(i2c_master, addr, buf, sz, 1);
}

int
i2c_master_wait(struct mcu_i2c_master *i2c_master)
{
	struct mcu_i2c_master_ctx *ctx = &i2c_master_ctx[sercom_get_id(i2c_master)];

	while (ctx->status > 0);
	return ctx->status;
}
