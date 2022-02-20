#include <main.h>
#include <port.h>
#include <sercom.h>
#include <usart.h>

#define LED_PIN		27
#define USART_PIN	.

int
main(void)
{
	uint32_t reg;

	/* turn led on */
	PORT->DIRSET = 1 << LED_PIN;
	PORT->OUTSET = 1 << LED_PIN;

	/* turn usart on */
	reg = SERCOM0->CTRLA & SERCOM_CTRLA_MASK;

	return 0;
}
