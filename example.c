#include "libc.h"
#include "registers.h"
#include "functions.h"

#define LED		27

void
init_led(void)
{
	port_set_gpio_output(LED);
}

#define USART1_RX	17
#define USART1_TX	22

void
init_usart(void)
{
	power_on_osc8m();
	clock_generator_init(GCLK_GENCTRL_ID_GCLKGEN2, GCLK_GENCTRL_SRC_OSC8M, 1);
	clock_init(GCLK_CLKCTRL_ID_SERCOM1_CORE, GCLK_GENCTRL_ID_GCLKGEN2);

	port_set_peripheral_input(USART1_RX, PORT_PMUX_SERCOM);
	port_set_peripheral_output(USART1_TX, PORT_PMUX_SERCOM);

	power_on_sercom1();
	sercom_set_mode_usart_internal(SERCOM1);
	usart_set_pinout_rx(USART1, USART_CTRLA_RXPO_RX3);
	usart_set_pinout_tx(USART1, USART_CTRLA_TXPO_TX0_CK1);
	usart_set_asynchronous(USART1);
	usart_set_least_significant_bit_first(USART1);
	usart_set_baud_rate(USART1, 600);
	usart_enable(USART1);
}

void
main_usart(void)
{
	char *str = "hello world\r\n";

	for (;;) {
		usart_tx_queue(USART1, (uint8_t *)str, strlen(str));
		usart_tx_wait(USART1);
		port_set_pin_up(LED);
		port_set_pin_down(LED);
	}
}

#define I2CM0_SDA	6
#define I2CM0_SCL	7

void
init_i2cm(void)
{
	clock_generator_init(GCLK_GENCTRL_ID_GCLKGEN0, GCLK_GENCTRL_SRC_OSCULP32K, 0);
	clock_init(GCLK_CLKCTRL_ID_SERCOM0_CORE, GCLK_GENCTRL_ID_GCLKGEN0);
	clock_init(GCLK_CLKCTRL_ID_SERCOM_SLOW, GCLK_GENCTRL_ID_GCLKGEN0);

	port_set_peripheral_output(I2CM0_SDA, PORT_PMUX_SERCOM);
	port_set_peripheral_output(I2CM0_SCL, PORT_PMUX_SERCOM);
	port_set_pull_up(I2CM0_SDA);
	port_set_pull_up(I2CM0_SCL);

	power_on_sercom0();
	sercom_set_mode_i2c_master(SERCOM0);
	i2cm_set_baud_rate(I2CM0, 400);
	i2cm_enable(I2CM0);
}

void
main_i2cm(void)
{
	I2CM0->ADDR = 0x30;
}

int
main(void)
{
	init_led();
	init_i2cm();
	main_i2cm();
	return 0;
}
