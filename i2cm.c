#include "libc.h"
#include "registers.h"
#include "functions.h"

static void
led(uint8_t duty_cycle_percent)
{
	for (uint32_t i = 0; i < 10; i++) {
		for (uint8_t ii = 0; ii < duty_cycle_percent; ii++)
			port_set_pin_up(27);
		for (uint8_t ii = duty_cycle_percent; ii < 100; ii++)
			port_set_pin_down(27);
	}
}

void
i2cm_blink(struct sdk_i2cm *i2cm)
{
	switch (FIELD(i2cm->STATUS, I2CM_STATUS_BUSSTATE)) {
	case I2CM_STATUS_BUSSTATE_UNKNOWN:
		led(100); led(0); led(0); led(0);
		led(0); led(0); led(0); led(0);
		break;
	case I2CM_STATUS_BUSSTATE_IDLE:
		led(1); led(1); led(1); led(1);
		led(1); led(1); led(1); led(1);
		break;
	case I2CM_STATUS_BUSSTATE_OWNER:
		led(55); led(50); led(50); led(50);
		led(55); led(50); led(50); led(50);
		break;
	case I2CM_STATUS_BUSSTATE_BUSY:
		led(70); led(80); led(90); led(100);
		led(90); led(80); led(70); led(60);
		break;
	}
}

void
i2cm_init(struct sdk_i2cm *i2cm, uint32_t baud_hz)
{
	/* the rising time of the clock has been ignored below, it varies
	 * depending on the capacitance of the bus */
	uint32_t baud = sercom_get_clock_hz(i2cm) / (baud_hz * 2) - 1;

	i2cm->CTRLA = 0
	/* time-out when SCL held low for too long */
	 | BIT(I2CM_CTRLA_LOWTOUTEN)
	/* default for inactivity time-out */
	 | BITS_(I2CM_CTRLA_INACTOUT, 205_US)
	/* allow SCL pin to be stretched by the slave */
	 | BIT(I2CM_CTRLA_SCLSM)
	/* time-out and reset ourself when a slave stretches SCL for 25ms */
	 | BIT(I2CM_CTRLA_SEXTTOEN)
	/* time-out and reset ourself when a slave stretches SCL for 10ms */
	 | BIT(I2CM_CTRLA_MEXTTOEN)
	/* default speed mode to standard speed */
	 | BITS_(I2CM_CTRLA_SPEED, 400_KHZ_MAX)
	/* set SERCOM generic serial to I²C Master mode */
	 | BITS_(I2CM_CTRLA_MODE, I2C_MASTER)
	/* default for SDA pin hold time */
	 | BITS_(I2CM_CTRLA_SDAHOLD, 450_NS)
	 ;

//	i2cm->CTRLB = 0
	/* this code only supports "smart mode" */
//	 | BIT(I2CM_CTRLB_SMEN);

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

	/* enable the I2C *after* it is configured (#27.6.2.1) */
	i2cm->CTRLA |= BIT(I2CM_CTRLA_ENABLE);
	while (i2cm->SYNCBUSY & BIT(I2CM_SYNCBUSY_ENABLE));

        /* we just started, we do not know in which state are the
         * slave, but we guess and move from UNKNOWN to IDLE */
	i2cm->STATUS = (i2cm->STATUS  & ~MASK(I2CM_STATUS_BUSSTATE))
	 | BITS_(I2CM_STATUS_BUSSTATE, IDLE);
	while (i2cm->SYNCBUSY & BIT(I2CM_SYNCBUSY_SYSOP));
}

static inline void
i2cm_interrupt_error(struct sdk_i2cm *i2cm)
{
	volatile uint32_t reg;

//	__asm__("bkpt");
	reg = i2cm->STATUS;

	(void)i2cm;
}

static inline void
i2cm_interrupt_master_on_bus(struct sdk_i2cm *i2cm)
{
	if (i2cm->STATUS & BIT(I2CM_STATUS_RXNACK)) {
	}
	if (i2cm->STATUS & BIT(I2CM_STATUS_ARBLOST)) {
	}
}

static inline void
i2cm_interrupt_slave_on_bus(struct sdk_i2cm *i2cm)
{
	(void)i2cm;
}

void
i2cm_interrupt(struct sdk_i2cm *i2cm)
{
	uint8_t reg = i2cm->INTFLAG;

	if (reg & BIT(I2CM_INTFLAG_ERROR))
		i2cm_interrupt_error(i2cm);
	if (reg & BIT(I2CM_INTFLAG_MB))
		i2cm_interrupt_master_on_bus(i2cm);
	if (reg & BIT(I2CM_INTFLAG_SB))
		i2cm_interrupt_slave_on_bus(i2cm);
}

void
i2cm_try(struct sdk_i2cm *i2cm)
{
	if ((PORT->OUT & BIT(23)) == 0)
		port_set_pin_up(27);

	i2cm->ADDR = BITS(I2CM_ADDR_ADDR, (0x30 << 1) | 0);
}
