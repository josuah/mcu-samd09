#include "libc.h"
#include "registers.h"
#include "functions.h"

void
i2cm_set_baud_rate(struct sdk_i2cm *i2cm, uint32_t baud_hz)
{
	/* the rising time of the clock has been ignored below, it varies
	 * depending on the capacitance of the bus */
	uint32_t baud = sercom_get_clock_rate_hz(i2cm) / (baud_hz * 2) - 1;

	i2cm->BAUD = 0
	 | BITS(I2CM_BAUD_HSBAUDLOW, 0) | BITS(I2CM_BAUD_HSBAUD, baud)
	 | BITS(I2CM_BAUD_BAUDLOW, 0) | BITS(I2CM_BAUD_BAUD, baud);
}

void
i2cm_enable(struct sdk_i2cm *i2cm)
{
	/* enable all interrupts types */
	I2CM0->INTENSET = BIT(I2CM_INTENSET_MB) | BIT(I2CM_INTENSET_SB)
	 | BIT(I2CM_INTENSET_ERROR);

	/* this code only supports "smart mode", which lets more work be done
	 * by the hardware */
	i2cm->CTRLB |= BIT(I2CM_CTRLB_SMEN);

	/* enable the I2C *after* it is configured (#27.6.2.1) */
	i2cm->CTRLA |= BIT(I2CM_CTRLA_ENABLE);
	while (i2cm->SYNCBUSY & BIT(I2CM_SYNCBUSY_ENABLE));

	/* we are just connected to the BUS, we do not know the state of
	 * the slave or other masters, but assume we are the first to talk
	 * and immediately change the state from UNKNOWN to IDLE */
	I2CM0->STATUS = (I2CM0->STATUS & ~MASK(I2CM_STATUS_BUSSTATE))
	 | BITS(I2CM_STATUS_BUSSTATE, I2CM_STATUS_BUSSTATE_IDLE);
	while (i2cm->SYNCBUSY & BIT(I2CM_SYNCBUSY_SYSOP));
}

static inline void
i2cm_interrupt_master_on_bus(struct sdk_i2cm *i2cm)
{
}

static inline void
i2cm_interrupt_slave_on_bus(struct sdk_i2cm *i2cm)
{
}

static inline void
i2cm_interrupt_error(struct sdk_i2cm *i2cm)
{
}

void
i2cm_interrupt(struct sdk_i2cm *i2cm)
{
	uint8_t reg = i2cm->INTFLAG;

	port_set_pin_up(27);

	if (reg & BIT(I2CM_INTFLAG_MB))
		i2cm_interrupt_master_on_bus(i2cm);
	if (reg & BIT(I2CM_INTFLAG_SB))
		i2cm_interrupt_slave_on_bus(i2cm);
	if (reg & BIT(I2CM_INTFLAG_ERROR))
		i2cm_interrupt_error(i2cm);
}
