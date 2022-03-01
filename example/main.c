#include "libc.h"
#include "main.h"
#include "registers.h"
#include "functions.h"

#define LED		27
#define USART_TX	4
#define USART_RX	6
#define XOSC_HZ		0

int
main(void)
{
	port_mode_output(LED);

	clock_set_generator(GCLK_CLKCTRL_ID_SERCOM0_CORE, 0);

	port_mode_periph_out(USART_TX, PORT_PMUX_SERCOM);
	port_mode_periph_in(USART_RX, PORT_PMUX_SERCOM);

	usart_mode_internal_async(USART0);
	usart_set_frame_size(USART0, 8);
	usart_set_baud_rate(USART0, 9600);
	usart_enable(USART0);

	for (;;) {
		usart_send_byte(USART0, '0');
		port_pin_set(LED);
	}

	return 0;
}
