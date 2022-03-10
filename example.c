#include "libc.h"
#include "registers.h"
#include "functions.h"

#define LED		27
#define I2CM1_SDA	22
#define I2CM1_SCL	23

int
main(void)
{
	power_on_dfll48m();
	power_on_sercom1();

	port_set_gpio_output(LED);

	clock_init_generator(GCLK_GENCTRL_ID_GCLKGEN0, GCLK_GENCTRL_SRC_DFLL48M, 1);
	clock_init_generator(GCLK_GENCTRL_ID_GCLKGEN1, GCLK_GENCTRL_SRC_OSCULP32K, 1);
	clock_init(GCLK_CLKCTRL_ID_SERCOM1_CORE, GCLK_GENCTRL_ID_GCLKGEN0);
	clock_init(GCLK_CLKCTRL_ID_SERCOM_SLOW, GCLK_GENCTRL_ID_GCLKGEN1);

	i2cm_init(I2CM1, 100000, I2CM1_SCL, I2CM1_SDA);
	sercom_enable_interrupts(1);
	i2cm_try(I2CM1);

	return 0;
}
