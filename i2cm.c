#include "libc.h"
#include "registers.h"
#include "functions.h"

void
i2cm_set_baud_rate(struct sdk_i2cm *i2cm, uint32_t baud_hz)
{
	uint32_t clock_hz = sercom_get_clock_rate_hz(i2cm);

	i2cm->BAUD = 0
	  | BITS(I2CM_BAUD_HSBAUDLOW, 0)
	  | BITS(I2CM_BAUD_HSBAUD, baud_hz)
	  | BITS(I2CM_BAUD_BAUDLOW, 0)
	  | BITS(I2CM_BAUD_BAUD, baud_hz);
}

void
i2cm_enable(struct sdk_i2cm *i2cm)
{
	/* enable the I2C *after* it is configured (#27.6.2.1) */
	i2cm->CTRLA |= BIT(I2CM_CTRLA_ENABLE);
	while (i2cm->SYNCBUSY & I2CM_SYNCBUSY_ENABLE);
}
