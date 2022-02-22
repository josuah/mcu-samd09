#include <main.h>
#include <port.h>
#include <sercom.h>
#include <usart.h>
#include <gclk.h>
#include <pm.h>

#define LED		27
#define USART_TX	2
#define USART_RX	3

int
main(void)
{
	uint32_t reg;

	/* turn led on */
	PORT->DIRSET = 1 << LED;
	PORT->OUTSET = 1 << LED;

	/* open access to the pad to peripherals */
	PORT->PINCFG[USART_TX] |= PORT_PINCFG_PMUXEN;

	/* associate the port to the USART module */
	reg = PORT->PMUX[USART_TX/2] & ~PORT_PMUX_MASK(USART_TX);
	PORT->PMUX[USART_TX/2] = reg | PORT_PMUX(USART_TX, PORT_PMUX_FN_C);

	/* assign the RX pin to it */
	reg = USART0->CTRLA & ~USART_CTRLA_TXPO_MASK;
	USART0->CTRLA = reg | USART_CTRLA_TXPO(USART_CTRLA_TXPO_TX2_CK3);

	/* configure an /1 divider for clock generator 0 */
	GCLK->GENDIV = GCLK_GENDIV_ID(0)
	  | GCLK_GENDIV_DIV(1);

	/* use the default crystal oscillator for it */
	GCLK->GENCTRL = GCLK_GENDIV_ID(0)
	  | GCLK_GENCTRL_SRC(GCLK_GENCTRL_SRC_XOSC);

	/* use it as a source for a the SERCOM0 clock */
	GCLK->CLKCTRL = GCLK_CLKCTRL_ID(GCLK_ID_SERCOM0_CORE)
	  | GCLK_CLKCTRL_GEN(0)
	  | GCLK_CLKCTRL_CLKEN;

	/* wake-up the USART */
	PM->APBCMASK |= PM_APBCMASK_SERCOM0;

	/* setup SERCOM0 for use with USART */
	reg = SERCOM0->CTRLA & ~SERCOM_CTRLA_MODE_MASK;
	SERCOM0->CTRLA = reg 
	  | SERCOM_CTRLA_MODE(SERCOM_CTRLA_MODE_USART_INT)
	  | SERCOM_CTRLA_ENABLE;


	return 0;
}
