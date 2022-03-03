#include "libc.h"
#include "main.h"
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

	usart_set_baud_rate(USART0, 8000);
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
	init_led();
	init_usart();

// at 1200 baud, limit at 2400/2401
// at 800 baud: limit at 1800/1801
// at 600 baud: limit at 1200/1201

	for (;;) {
		for (uint32_t volatile i = 0; i < 0x10000; i++);

		usart_send_byte(USART0, 'h');
		usart_send_byte(USART0, 'e');
		usart_send_byte(USART0, 'l');
		usart_send_byte(USART0, 'l');
		usart_send_byte(USART0, 'o');
		usart_send_byte(USART0, ' ');
		usart_send_byte(USART0, 'w');
		usart_send_byte(USART0, 'o');
		usart_send_byte(USART0, 'r');
		usart_send_byte(USART0, 'l');
		usart_send_byte(USART0, 'd');
		usart_send_byte(USART0, '!');
		usart_send_byte(USART0, '\r');
		usart_send_byte(USART0, '\n');
		port_pin_set(LED);
	}

	return 0;
}
