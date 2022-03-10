#include "libc.h"
#include "registers.h"
#include "functions.h"

uint8_t
sercom_get_id(void *ptr)
{
	return (ptr == SERCOM0) ? 0 : (ptr == SERCOM1) ? 1 : 0xFF;
}

uint32_t
sercom_get_clock_hz(void *sercom)
{
	switch (sercom_get_id(sercom)) {
	case 0:
		return clock_get_hz(GCLK_CLKCTRL_ID_SERCOM0_CORE);
	case 1:
		return clock_get_hz(GCLK_CLKCTRL_ID_SERCOM1_CORE);
	default:
		assert(!"not reached");
	}
	return 0;
}

void
sercom_enable_interrupts(uint8_t sercom_id)
{
	NVIC->ISER = BIT(9 + sercom_id);
}
