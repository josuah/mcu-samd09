#include "libc.h"
#include "registers.h"
#include "functions.h"

uint8_t
sercom_get_id(void *ptr)
{
	return (ptr == SERCOM0) ? 0 : (ptr == SERCOM1) ? 1 : 0xFF;
}

uint32_t
sercom_get_clock_rate_hz(void *sercom)
{
	switch (sercom_get_id(sercom)) {
	case 0:
		return clock_get_rate_hz(GCLK_CLKCTRL_ID_SERCOM0_CORE);
	case 1:
		return clock_get_rate_hz(GCLK_CLKCTRL_ID_SERCOM1_CORE);
	default:
		__stop_program();
	}
	return 0;
}

void
sercom_set_mode_usart_internal(struct sdk_sercom *sercom)
{
	sercom->CTRLA = (sercom->CTRLA & ~MASK(SERCOM_CTRLA_MODE))
	 | BITS(SERCOM_CTRLA_MODE, SERCOM_CTRLA_MODE_USART_INT_CLK);
}

void
sercom_set_mode_i2c_master(struct sdk_sercom *sercom)
{
	sercom->CTRLA = (sercom->CTRLA & ~MASK(SERCOM_CTRLA_MODE))
	 | BITS(SERCOM_CTRLA_MODE, SERCOM_CTRLA_MODE_I2C_MASTER);
}

void
sercom_enable_interrupts(void *sercom)
{
	NVIC->ISER = BIT(9 + sercom_get_id(sercom));
}
