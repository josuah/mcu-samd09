#include "libc.h"
#include "registers.h"
#include "functions.h"

void
spi_master_init(struct mcu_spi *spi_master, uint32_t baud_hz, uint8_t pin_sck,
	uint8_t pin_miso, uint8_t pin_mosi, uint8_t pin_ss,
	uint32_t dipo, uint32_t dopo)
{
	uint32_t clock_hz;
	uint8_t pincfg;

	pincfg = 0
	/* enable peripheral multiplexing */
	 | PORT_PINCFG_PMUXEN
	/* internal pull-up resistor on SCL pin */
	 | PORT_PINCFG_PULLEN
	/* permit input to check for SCL pin stretching as common in I²C */
	 | PORT_PINCFG_INEN
	/* increase driver strength a bit */
	 | PORT_PINCFG_DRVSTR;
	/* apply the configuration to the pins */
	PORT->PINCFG[pin_sck] = pincfg;
	PORT->PINCFG[pin_miso] = pincfg;
	PORT->PINCFG[pin_mosi] = pincfg;
	PORT->PINCFG[pin_ss] = pincfg;

	/* pins MOSI, SCK, SS as output */
	PORT->DIRSET = (1u << pin_mosi) | (1u << pin_sck) | (1u << pin_ss);
	/* pins MISO as input */
	PORT->DIRCLR = (1u << pin_miso);

	/* plug the SCK, MISO, MOSI and SS pins to the SERCOM */
	port_set_pmux(pin_sck, PORT_PMUX_SERCOM);
	port_set_pmux(pin_miso, PORT_PMUX_SERCOM);
	port_set_pmux(pin_mosi, PORT_PMUX_SERCOM);
	port_set_pmux(pin_ss, PORT_PMUX_SERCOM);

	spi_master->CTRLA = 0
	/* select SPI Master mode for the SERCOM peripheral */
	 | SPI_CTRLA_MODE_SPI_MASTER
	/* not using SPI addresses, just regular frames */
	 | SPI_CTRLA_FORM_SPI
	/* pinout for input and output */
	 | (dipo << SPI_CTRLA_DIPO_Pos)
	 | (dopo << SPI_CTRLA_DOPO_Pos)
	/* least-significant bit first */
	 | SPI_CTRLA_DORD;

	spi_master->CTRLB = 0
	/* the hardware toggles the SS pin */
	 | SPI_CTRLB_MSSEN
	/* character size to 8-bit */
	 | SPI_CTRLB_CHSIZE_8BIT
	/* enable the receiver */
	 | SPI_CTRLB_RXEN;

	/* set the baud rate (Asynchronous Arithmetic mode) */
	clock_hz = sercom_get_clock_hz(sercom_get_id(spi_master));
	spi_master->BAUD = clock_hz / (2 * baud_hz) - 1;

	/* enable SPI *after* it is configured (#26.6.2.1 ) */
	spi_master->CTRLA |= SPI_CTRLA_ENABLE;
	while (spi_master->SYNCBUSY & SPI_SYNCBUSY_ENABLE);
}
