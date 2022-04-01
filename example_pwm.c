#include "libc.h"
#include "registers.h"
#include "functions.h"

#define SPI0_SS		10
#define SPI0_MISO	11
#define SPI0_MOSI	14
#define SPI0_SCK	15

int
main(void)
{
	power_on_sercom(0);

	clock_init_generator(GCLK_GENCTRL_ID_GCLKGEN0, GCLK_GENCTRL_SRC_OSC8M, 1);
	clock_init(GCLK_CLKCTRL_ID_TC1_TC2, GCLK_GENCTRL_ID_GCLKGEN0);

	pwm_init(TC1_COUNT8);
	pwm_init_counter(4);

	for (;;) {
		for (uint16_t i = 0x10; i < 0xFFF; i++)
			pwm_set_duty_cycle(TC1_COUNT8, 0, i * UINT8_MAX / 0xFFF);
		for (uint16_t i = 0xFFF; i > 0x10; i--)
			pwm_set_duty_cycle(TC1_COUNT8, 0, i * UINT8_MAX / 0xFFF);
	}

	return 0;
}
