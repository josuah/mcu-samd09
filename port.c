#include "libc.h"
#include "main.h"
#include "registers.h"
#include "functions.h"

void
port_mode_gpio_output(uint8_t pin)
{
	PORT->DIRSET = BIT(pin);
}

static inline void
port_mode_periph(uint8_t pin, uint8_t fn)
{
	uint32_t reg;

	/* open access to the pad to peripherals */
	PORT->PINCFG[pin] |= BIT(PORT_PINCFG_PMUXEN);

	/* associate the pin to the chosen module */
	reg = PORT->PMUX[pin/2] & PORT_PMUX(pin, MASK(PORT_PMUX));
	PORT->PMUX[pin/2] = reg | PORT_PMUX(pin, fn);
}

void
port_mode_periph_input(uint8_t pin, uint8_t fn)
{
	PORT->DIRSET = BIT(pin);
	port_mode_periph(pin, fn);
}

void
port_mode_periph_output(uint8_t pin, uint8_t fn)
{
	PORT->DIRCLR = BIT(pin);
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
