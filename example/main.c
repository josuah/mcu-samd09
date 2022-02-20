#include <main.h>
#include <port.h>
#include <sercom.h>
#include <usart.h>

#define LED		27
#define USART_TX	.
#define USART_RX	.

int
main(void)
{
	uint32_t reg;

	/* turn led on */
	PORT->DIRSET = 1 << LED;
	PORT->OUTSET = 1 << LED;

	/* open access to the pad to peripherals */
	PORT->PINCFG[USART_TX] |= PORT_PINCFG_PMUXEN;

	/* setup multiplexing for the port */
	reg = PORT->PMUX[USART_TX/2] & ~PORT_PMUX_O_MASK
	PORT->PMUX[USART_TX/2] = reg | PORT_PMUX_O(USART_TX, 2);

	/* give the SERCOM a clock */
	[...] (page 428)

	/* wake-up the USART */
	PM->APBCMASK |= PM_APBCMASK_SERCOM0;

	/* setup SERCOM0 for use with USART */
	reg = SERCOM0->CTRLA & ~SERCOM_CTRLA_MASK;
	SERCOM0->CTRLA = reg | SERCOM_CTRLA();

	return 0;
}
