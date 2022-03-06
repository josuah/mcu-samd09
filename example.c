#include "libc.h"
#include "registers.h"
#include "functions.h"

#define USART0_RX	5
#define USART0_TX	6
#define GCLK4_IO	10

#define LED		27

void
init_usart(void)
{
	power_on_sercom0();
	SYSCTRL->OSC8M |= SYSCTRL_OSC8M_ENABLE;

	clock_generator_init(GCLK_GENCTRL_ID_GCLKGEN4, GCLK_GENCTRL_SRC_OSC8M, 1);
	clock_init(GCLK_CLKCTRL_ID_SERCOM0_CORE, GCLK_GENCTRL_ID_GCLKGEN4);

	port_set_periph_output(GCLK4_IO, PORT_PMUX_GCLK);
	clock_generator_enable_output(GCLK_GENCTRL_ID_GCLKGEN4);

	usart_set_internal_async(USART0);

	usart_set_least_significant_bit_first(USART0);
	port_set_periph_input(USART0_RX, PORT_PMUX_SERCOM);
	usart_set_pinout_rx(USART0, USART_CTRLA_RXPO_RX3);

	port_set_periph_output(USART0_TX, PORT_PMUX_SERCOM);
	usart_set_pinout_tx(USART0, USART_CTRLA_TXPO_TX0_CK1);

	usart_set_baud_rate(USART0, 9600);
	usart_enable(USART0);
}

void
init_led(void)
{
	port_set_gpio_output(LED);
}

int
main(void)
{
	char *str = "hello world\r\n";

	init_led();
	init_usart();

	for (;;) {
		usart_tx_queue(USART0, (uint8_t *)str, strlen(str));
		usart_tx_wait(USART0);
		port_pin_set(LED);
		port_pin_clear(LED);
	}
	return 0;
}
