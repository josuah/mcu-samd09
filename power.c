#include "libc.h"
#include "registers.h"
#include "functions.h"

void
power_on_sercom0(void)
{
	/* power-up the USART *before* it is configured */
	PM->APBCMASK |= BIT(PM_APBCMASK_SERCOM0);
}

void
power_on_sercom1(void)
{
	/* power-up the USART *before* it is configured */
	PM->APBCMASK |= BIT(PM_APBCMASK_SERCOM1);
}

void
power_on_osc8m(void)
{
	SYSCTRL->OSC8M |= SYSCTRL_OSC8M_ENABLE;
}
