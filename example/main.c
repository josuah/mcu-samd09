#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>
#include "main.h"
#include "registers.h"

#define LED		27
#define USART_TX	4
#define USART_RX	6
#define XOSC_HZ		0

void
port_mode_output(uint8_t pin)
{
	PORT->DIRSET = BIT(pin);
}

void
port_mode_periph(uint8_t pin, uint8_t fn)
{
	uint32_t reg;

	/* open access to the pad to peripherals */
	PORT->PINCFG[pin] |= BIT(PORT_PINCFG_PMUXEN);

	/* associate the pin to the chosen module */
	reg = PORT->PMUX[pin/2] & PORT_PMUX(pin, BITMASK(PORT_PMUX));
	PORT->PMUX[pin/2] = reg | PORT_PMUX(pin, fn);
}

void
port_mode_periph_in(uint8_t pin, uint8_t fn)
{
	/* set the pin as output */
	PORT->DIRSET = 1 << pin;

	port_mode_periph(pin, fn);
}

void
port_mode_periph_out(uint8_t pin, uint8_t fn)
{
	/* set the pin as output */
	PORT->DIRCLR = 1 << pin;

	port_mode_periph(pin, fn);
}

void
port_pin_set(uint8_t pin)
{
	PORT->OUTSET = BIT(pin);
}

void
port_pin_clear(uint8_t pin)
{
	PORT->OUTCLR = BIT(pin);
}

static inline uint32_t clock_generator_get_rate_hz(uint8_t genid);

static inline uint8_t
clock_generator_get_source(uint8_t genid)
{
	uint8_t *GENCTRL = (void *)&GCLK->GENCTRL;

	GENCTRL[0] = genid;
	return BITREAD(GCLK->GENCTRL, GCLK_GENCTRL_SRC);
}

static inline uint32_t
clock_source_get_rate_hz(uint8_t src)
{
	switch (src) {
	case GCLK_GENCTRL_SRC_XOSC:
		break; // TODO
	case GCLK_GENCTRL_SRC_GCLKIN:
		break; // TODO
	case GCLK_GENCTRL_SRC_GCLKGEN1:
	       return clock_generator_get_rate_hz(1);
	case GCLK_GENCTRL_SRC_OSCULP32K:
	       return 32000;
	case GCLK_GENCTRL_SRC_OSC32K:
	       return 32000;
	case GCLK_GENCTRL_SRC_XOSC32K:
	       return 32000;
	case GCLK_GENCTRL_SRC_OSC8M:
	       return 8000000;
	case GCLK_GENCTRL_SRC_DFLL48M:
	       return 48000000;
	case GCLK_GENCTRL_SRC_DPLL96M:
	       return 96000000;
	}
       __stop_program();
       return 0;
}

static inline uint8_t
clock_generator_get_div(uint8_t genid)
{
	uint8_t *GENDIV = (void *)&GCLK->GENDIV;

	GENDIV[0] = genid;
	return BITREAD(GCLK->GENDIV, GCLK_GENDIV_DIV);
}

static inline uint32_t
clock_generator_get_rate_hz(uint8_t genid)
{
	uint32_t clock_rate_hz;
	uint8_t clock_div_num;

	clock_rate_hz = clock_source_get_rate_hz(clock_generator_get_source(genid));
	clock_div_num = clock_generator_get_div(genid);

	/* lldiv to avoid a bug with libgcc not in thumb mode */
	return lldiv(clock_rate_hz, clock_div_num).quot;
}

static inline uint8_t
clock_get_generator(uint8_t clkid)
{
	uint8_t *CLKCTRL = (void *)&GCLK->CLKCTRL;

	CLKCTRL[0] = clkid;
	return BITREAD(GCLK->CLKCTRL, GCLK_CLKCTRL_GEN);
}

static inline uint32_t
clock_get_rate_hz(uint8_t clkid)
{
	return clock_generator_get_rate_hz(clock_get_generator(clkid));
}

static inline uint32_t
usart_get_clock_rate_hz(struct zmcu_usart *usart)
{
	if (usart == USART0)
		return clock_get_rate_hz(GCLK_CLKCTRL_ID_SERCOM0_CORE);
	if (usart == USART1)
		return clock_get_rate_hz(GCLK_CLKCTRL_ID_SERCOM1_CORE);
	__stop_program();
	return 0;
}

static inline uint8_t
usart_get_sample_num(struct zmcu_usart *usart)
{
	switch (BITREAD(usart->CTRLA, USART_CTRLA_SAMPR)) {
	case USART_CTRLA_SAMPR_16_ARITHMETIC:
	case USART_CTRLA_SAMPR_16_FRACTIONAL:
		return 16;
	case USART_CTRLA_SAMPR_8_ARITHMETIC:
	case USART_CTRLA_SAMPR_8_FRACTIONAL:
		return 8;
	case USART_CTRLA_SAMPR_3_ARITHMETIC:
		return 3;
	}
	__stop_program();
	return 0;
}

void
usart_set_baudrate(struct zmcu_usart *usart, uint32_t baud_hz)
{
	uint8_t samples = usart_get_sample_num(usart);
	uint32_t clock_hz = usart_get_clock_rate_hz(usart);

	/* lldiv to avoid a bug with libgcc not in thumb mode */
	//usart->BAUD = 0x10000 - lldiv(0x10000 * samples, clock_hz).quot * baud_hz;
}

int
main(void)
{
	port_mode_output(LED);


	/* pin configuration */


	port_mode_periph_out(USART_TX, PORT_PMUX_SERCOM);
	port_mode_periph_in(USART_RX, PORT_PMUX_SERCOM);


	/* clock configuration */


	/* use this clock generator for USART0 */
	GCLK->CLKCTRL = BITS(GCLK_CLKCTRL_ID, SERCOM0_CORE)
	  | BITS(GCLK_CLKCTRL_GEN, GCLKGEN0)
	  | BIT(GCLK_CLKCTRL_CLKEN);

	/* wait for completion */
	while (GCLK->STATUS & BIT(GCLK_STATUS_SYNCBUSY));


	/* power management */


	/* power-up the USART *before* it is configured */
	PM->APBCMASK |= BIT(PM_APBCMASK_SERCOM0);


	/* usart peripheral configuration */

	/* setup SERCOM0 for use with USART with internal clock */
	BITWRITE(USART0->CTRLA, USART_CTRLA_MODE, USART_INT_CLK);

	/* setup SERCOM0 for use with USART in asynchronous mode */
	USART0->CTRLA &= ~BIT(USART_CTRLA_CMODE);

	/* assign the RX pin to USART_RX */
	BITWRITE(USART0->CTRLA, USART_CTRLA_RXPO, RX0);

	/* assign the TX pin to USART_TX */
	BITWRITE(USART0->CTRLA, USART_CTRLA_TXPO, TX2_CK3);

	/* set the character size to regular 8 bits mode */
	BITWRITE(USART0->CTRLB, USART_CTRLB_CHSIZE, 8BITS);

	/* set the data order to regular MSB first */
	USART0->CTRLA &= ~BIT(USART_CTRLA_DORD);

	usart_set_baudrate(USART0, 9600);

	/* enable the receiver and transmitter */
	USART0->CTRLB |= BIT(USART_CTRLB_RXEN) | BIT(USART_CTRLB_TXEN);
	while (USART0->SYNCBUSY & BIT(USART_SYNCBUSY_CTRLB));

	/* enable the USART *after* it is configured (#25.6.2) */
	USART0->CTRLA |= BIT(USART_CTRLA_ENABLE);
	while (USART0->SYNCBUSY & USART_SYNCBUSY_ENABLE);


	/* data transmission */


	for (;;) {
		USART0->DATA = '0';
		while (USART0->SYNCBUSY & BIT(USART_SYNCBUSY_CTRLB));
		port_pin_set(LED);
	}

	return 0;
}
