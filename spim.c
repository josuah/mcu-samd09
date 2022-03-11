#include "libc.h"
#include "registers.h"
#include "functions.h"

void
spim_init(struct sdk_spi *spim, uint32_t baud_hz, uint8_t pin_sck,
	uint8_t pin_miso, uint8_t pin_mosi, uint8_t pin_ss,
	uint8_t dipo, uint8_t dopo)
{
	uint32_t clock_hz;
	uint8_t pincfg;

	pincfg = 0
	/* enable peripheral multiplexing */
	 | BIT(PORT_PINCFG_PMUXEN)
	/* internal pull-up resistor on SCL pin */
	 | BIT(PORT_PINCFG_PULLEN)
	/* permit input to check for SCL pin stretching as common in I²C */
	 | BIT(PORT_PINCFG_INEN)
	/* increase driver strength a bit */
	 | BIT(PORT_PINCFG_DRVSTR);
	/* apply the configuration to the pins */
	PORT->PINCFG[pin_sck] = pincfg;
	PORT->PINCFG[pin_miso] = pincfg;
	PORT->PINCFG[pin_mosi] = pincfg;
	PORT->PINCFG[pin_ss] = pincfg;

	/* pins MOSI, SCK, SS as output */
	PORT->DIRSET = BIT(pin_mosi) | BIT(pin_sck) | BIT(pin_ss);
	/* pins MISO as input */
	PORT->DIRCLR = BIT(pin_miso);

	/* plug the SCK, MISO, MOSI and SS pins to the SERCOM */
	port_set_pmux(pin_sck, PORT_PMUX_SERCOM);
	port_set_pmux(pin_miso, PORT_PMUX_SERCOM);
	port_set_pmux(pin_mosi, PORT_PMUX_SERCOM);
	port_set_pmux(pin_ss, PORT_PMUX_SERCOM);

	spim->CTRLA = 0
	/* select SPI Master mode for the SERCOM peripheral */
	 | BITS(SPI_CTRLA_MODE, SPI_CTRLA_MODE_SPI_MASTER)
	/* not using SPI addresses, just regular frames */
	 | BITS(SPI_CTRLA_FORM, SPI_CTRLA_FORM_SPI)
	/* pinout for input and output */
	 | BITS(SPI_CTRLA_DIPO, dipo)
	 | BITS(SPI_CTRLA_DOPO, dopo)
	/* least-significant bit first */
	 | BIT(SPI_CTRLA_DORD);

	spim->CTRLB = 0
	/* the hardware toggles the SS pin */
	 | BIT(SPI_CTRLB_MSSEN)
	/* character size to 8-bit */
	 | BITS(SPI_CTRLB_CHSIZE, SPI_CTRLB_CHSIZE_8BIT)
	/* enable the receiver */
	 | BIT(SPI_CTRLB_RXEN);

	/* set the baud rate (Asynchronous Arithmetic mode) */
	clock_hz = sercom_get_clock_hz(sercom_get_id(spim));
	spim->BAUD = clock_hz / (2 * baud_hz) - 1;

	/* enable SPI *after* it is configured (#26.6.2.1 ) */
	spim->CTRLA |= BIT(SPI_CTRLA_ENABLE);
	while (spim->SYNCBUSY & BIT(SPI_SYNCBUSY_ENABLE));
}
