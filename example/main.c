#include <stddef.h>
#include <stdint.h>
#include "main.h"
#include "registers.h"

#define LED		27
#define USART_TX	4
#define USART_RX	6
#define GCLK_IO4	10

void
port_mode_output(uint8_t pin)
{
	PORT->DIRSET = BIT(pin);
}

void
port_mode_periph(uint8_t pin, uint8_t fn)
{
	uint32_t reg;

	/* open access to the pad to peripherals */
	PORT->PINCFG[pin] |= BIT(PORT_PINCFG_PMUXEN);

	/* associate the pin to the chosen module */
	reg = PORT->PMUX[pin/2] & ~PORT_PMUX_MASK(pin);
	PORT->PMUX[pin/2] = reg | PORT_PMUX(pin, fn);
}

void
port_pin_set(uint8_t pin)
{
	PORT->OUTSET = BIT(pin);
}

void
port_pin_clear(uint8_t pin)
{
	PORT->OUTCLR = BIT(pin);
}

int
main(void)
{
	uint32_t reg;

	port_mode_output(LED);

	GCLK->GENCTRL = BITS(GCLK_GENCTRL_ID,GCLKGEN4)
	  | BITS(GCLK_GENCTRL_SRC,OSCULP32K)
	  | BIT(GCLK_GENCTRL_OE);

	port_mode_periph(USART_TX, PORT_PMUX_SERCOM);
	port_mode_periph(USART_RX, PORT_PMUX_SERCOM);

	/* use the default clock already running for USART0 */
	GCLK->CLKCTRL = BIT(GCLK_CLKCTRL_CLKEN)
	  | BITS(GCLK_CLKCTRL_GEN,GCLKGEN0)
	  | BITS(GCLK_CLKCTRL_ID,SERCOM0_CORE);

	while (BITREAD(GCLK, STATUS, SYNCBUSY));

	/* wake-up the USART */
	PM->APBCMASK |= BIT(PM_APBCMASK_SERCOM0);

	/* setup SERCOM0 for use with USART */
	USART0->CTRLA = BITWRITE(USART0->CTRLA, USART_CTRLA_MODE,CLK);
	USART0->CTRLA |= BIT(USART_CTRLA_ENABLE);
	while (USART0->SYNCBUSY & USART_SYNCBUSY_ENABLE);

	/* assign the TX pin to USART_TX */
	BITWRITE(USART0->CTRLA, USART_CTRLA_TXPO,TX2_CK3);

	/* assign the RX pin to USART_RX */
	BITWRITE(USART0->CTRLA, USART_CTRLA_RXPO,RX0);

	/* enable the receiver and transmitter */
	USART0->CTRLB |= BIT(USART_CTRLB_RXEN) | BIT(USART_CTRLB_TXEN);

	while (USART0->SYNCBUSY & BIT(USART_SYNCBUSY_CTRLB));

	for (;;) {
		USART0->DATA = '.';
		port_pin_set(LED);
		for (uint32_t volatile i = 0; i < 0xFFFF; i++);
		port_pin_clear(LED);
		for (uint32_t volatile i = 0; i < 0xFFFF; i++);
	}

	return 0;
}
