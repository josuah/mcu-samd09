#include "libc.h"
#include "main.h"
#include "registers.h"
#include "functions.h"

#define USART_RX3	5
#define USART_TX2	4

void
init_usart(void)
{
	port_mode_periph_output(USART_TX2, PORT_PMUX_SERCOM);
	port_mode_periph_input(USART_RX3, PORT_PMUX_SERCOM);

	power_on_sercom0();

	clock_set_generator(GCLK_CLKCTRL_ID_SERCOM0_CORE, GCLK_GENCTRL_ID_GCLKGEN0);

	//GCLK->GENCTRL |= GCLK_GENCTRL_GENEN | GCLK_GENCTRL_OE;
	//port_mode_periph_output(8, PORT_PMUX_GCLK);

	usart_mode_internal_async(USART0);
	usart_set_pinout(USART0, USART_CTRLA_TXPO_TX2_CK3, USART_CTRLA_RXPO_RX3);
	usart_set_frame_size(USART0, 8);
	usart_set_baud_rate(USART0, 9600);
	usart_enable(USART0);
}

#define LED		27

void
init_led(void)
{
	port_mode_gpio_output(LED);
}

int
main(void)
{
	init_led();
	init_usart();

	for (;;) {
		usart_send_byte(USART0, '0');
		port_pin_set(LED);
	}

	return 0;
}
