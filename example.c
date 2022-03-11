#include "libc.h"
#include "registers.h"
#include "functions.h"

#define SPIM0_MISO
#define SPIM0_MOSI
#define SPIM0_CLK

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

	i2cm_init(SPIM0, 400000, SPIM0_CLK, SPIM0_MISO, SPIM0_MOSI);

	return 0;
}
