#include "libc.h"
#include "registers.h"
#include "functions.h"

#define USART0_RX	17
#define USART0_TX	22

int
main(void)
{
	char *str = "hello world\r\n";

	port_set_peripheral_input(USART0_RX, PORT_PMUX_SERCOM);
	port_set_peripheral_output(USART0_TX, PORT_PMUX_SERCOM);

	clock_init_generator(GCLK_GENCTRL_ID_GCLKGEN2, GCLK_GENCTRL_SRC_OSC8M, 1);
	clock_init(GCLK_CLKCTRL_ID_SERCOM0_CORE, GCLK_GENCTRL_ID_GCLKGEN2);

	power_on_sercom0();
	usart_init(USART0, 600, USART_CTRLA_TXPO_TX0_CK1, USART_CTRLA_RXPO_RX3);
	sercom_enable_interrupts(0);

	for (;;) {
		usart_tx_queue(USART0, (uint8_t *)str, strlen(str));
		usart_tx_wait(USART0);
	}

	return 0;
}
