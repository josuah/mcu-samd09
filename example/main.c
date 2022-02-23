#include <main.h>
#include <port.h>
#include <usart.h>
#include <gclk.h>
#include <pm.h>
#include <sysctrl.h>

#define LED		27
#define USART_TX	4
#define USART_RX	6
#define GCLK_IO4	10

void
port_mode_output(uint8_t pin)
{
	PORT->DIRSET = 1 << pin;
}

void
port_mode_periph(uint8_t pin, uint8_t fn)
{
	uint32_t reg;

	/* open access to the pad to peripherals */
	PORT->PINCFG[pin] |= PORT_PINCFG_PMUXEN;

	/* associate the pin to the chosen module */
	reg = PORT->PMUX[pin/2] & ~PORT_PMUX_MASK(pin);
	PORT->PMUX[pin/2] = reg | PORT_PMUX(pin, fn);
}

void
port_pin_set(uint8_t pin)
{
	PORT->OUTSET = 1 << pin;
}

void
port_pin_clear(uint8_t pin)
{
	PORT->OUTCLR = 1 << pin;
}

int
main(void)
{
	uint32_t reg;

	port_mode_output(LED);

	GCLK->GENCTRL = GCLK_GENCTRL_ID(GCLK_GENID_GCLKGEN4)
	  | GCLK_GENCTRL_SRC(GCLK_GENCTRL_SRC_OSCULP32K)
	  | GCLK_GENCTRL_OE;

	port_mode_periph(USART_TX, PORT_PMUX_SERCOM);
	port_mode_periph(USART_RX, PORT_PMUX_SERCOM);

	/* use the default clock already running for USART0 */
	GCLK->CLKCTRL = GCLK_CLKCTRL_CLKEN
	  | GCLK_CLKCTRL_GEN(GCLK_GENID_GCLKGEN0)
	  | GCLK_CLKCTRL_ID(GCLK_CLKID_SERCOM0_CORE);

	while (GCLK->STATUS & GCLK_STATUS_SYNCBUSY);

	/* wake-up the USART */
	PM->APBCMASK |= PM_APBCMASK_SERCOM0;

	/* setup SERCOM0 for use with USART */
	reg = USART0->CTRLA & ~USART_CTRLA_MODE_MASK;
	USART0->CTRLA = reg 
	  | USART_CTRLA_MODE(USART_CTRLA_MODE_INTERNAL_CLK)
	  | USART_CTRLA_ENABLE;
	while (USART0->SYNCBUSY & USART_SYNCBUSY_ENABLE);

	/* assign the TX pin to USART_TX */
	reg = USART0->CTRLA & ~USART_CTRLA_TXPO_MASK;
	USART0->CTRLA = reg | USART_CTRLA_TXPO(USART_CTRLA_TXPO_TX2_CK3);

	/* assign the RX pin to USART_RX */
	reg = USART0->CTRLA & ~USART_CTRLA_RXPO_MASK;
	USART0->CTRLA = reg | USART_CTRLA_RXPO(USART_CTRLA_RXPO_RX0);

	/* enable the receiver and transmitter */
	USART0->CTRLB = USART_CTRLB_RXEN | USART_CTRLB_TXEN;
	while (USART0->SYNCBUSY & USART_SYNCBUSY_CTRLB);

	for (;;) USART0->DATA = '.';

	return 0;
}
