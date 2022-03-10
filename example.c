#include "libc.h"
#include "registers.h"
#include "functions.h"

#define LED		27
#define I2CM0_SDA	22
#define I2CM0_SCL	23

int
main(void)
{
	power_on_sercom0();
	power_on_dfll48m();

	port_set_gpio_output(LED);
	port_set_peripheral(I2CM0_SDA, PORT_PMUX_SERCOM);
	port_set_peripheral(I2CM0_SCL, PORT_PMUX_SERCOM);

	clock_init_generator(GCLK_GENCTRL_ID_GCLKGEN0, GCLK_GENCTRL_SRC_DFLL48M, 1);
	clock_init_generator(GCLK_GENCTRL_ID_GCLKGEN1, GCLK_GENCTRL_SRC_OSCULP32K, 1);
	clock_init(GCLK_CLKCTRL_ID_SERCOM0_CORE, GCLK_GENCTRL_ID_GCLKGEN0);
	clock_init(GCLK_CLKCTRL_ID_SERCOM_SLOW, GCLK_GENCTRL_ID_GCLKGEN1);

	i2cm_init(I2CM0, 100000);
	sercom_enable_interrupts(0);

	i2cm_try(I2CM0);

	return 0;
}
