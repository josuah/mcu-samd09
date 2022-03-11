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
	power_on_osc8m();
	power_on_sercom(0);

	port_set_output(27);

	clock_init_generator(GCLK_GENCTRL_ID_GCLKGEN0, GCLK_GENCTRL_SRC_OSC8M, 1);
	clock_init(GCLK_CLKCTRL_ID_SERCOM0_CORE, GCLK_GENCTRL_ID_GCLKGEN0);

	spim_init(SPI0, 100, SPI0_SCK, SPI0_MISO, SPI0_MOSI, SPI0_SS,
	 SPI_CTRLA_DIPO_MISO2, SPI_CTRLA_DOPO_MOSI0_SCK1_SS2);

	SPI0->DATA = 0x09;

	return 0;
}
