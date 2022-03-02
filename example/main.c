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

	clock_generator_init(GCLK_GENCTRL_ID_GCLKGEN4, GCLK_GENCTRL_SRC_OSC8M, 0x1);
	clock_init(GCLK_CLKCTRL_ID_SERCOM0_CORE, GCLK_GENCTRL_ID_GCLKGEN4);

	port_mode_periph_output(GCLK4_IO, PORT_PMUX_GCLK);
	clock_generator_enable_output(GCLK_GENCTRL_ID_GCLKGEN4);

	usart_mode_internal_async(USART0);

	port_mode_periph_input(USART0_RX, PORT_PMUX_SERCOM);
	usart_set_pinout_rx(USART0, USART_CTRLA_RXPO_RX3);

	port_mode_periph_output(USART0_TX, PORT_PMUX_SERCOM);
	usart_set_pinout_tx(USART0, USART_CTRLA_TXPO_TX0_CK1);

	usart_set_frame_size(USART0, 8);
	usart_set_baud_rate(USART0, 120);
	usart_enable(USART0);
}

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
		usart_send_byte(USART0, 0x3F);
	}

	return 0;
}
