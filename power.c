#include "libc.h"
#include "main.h"
#include "registers.h"
#include "functions.h"

void
power_on_sercom0(void)
{
	/* power-up the USART *before* it is configured */
	PM->APBCMASK |= BIT(PM_APBCMASK_SERCOM0);
}

void
power_off_sercom0(void)
{
	/* power-up the USART *before* it is configured */
	PM->APBCMASK &= ~BIT(PM_APBCMASK_SERCOM0);
}
