#include "libc.h"
#include "registers.h"
#include "functions.h"

void
port_set_gpio_output(uint8_t pin)
{
	PORT->DIRSET = BIT(pin);
}

void
port_set_peripheral(uint8_t pin, uint8_t pmux)
{
	/* open access to the pad to peripherals */
	PORT->PINCFG[pin] |= BIT(PORT_PINCFG_PMUXEN) | BIT(PORT_PINCFG_INEN) | BIT(PORT_PINCFG_DRVSTR);

	/* associate the pin to the chosen module */
	PORT->PMUX[pin/2] = (PORT->PMUX[pin/2] & ~PORT_PMUX(pin, 0xFu))
	 | PORT_PMUX(pin, pmux);
}

void
port_set_peripheral_input(uint8_t pin, uint8_t pmux)
{
	PORT->DIRSET = BIT(pin);
	port_set_peripheral(pin, pmux);
}

void
port_set_peripheral_output(uint8_t pin, uint8_t pmux)
{
	PORT->DIRCLR = BIT(pin);
	port_set_peripheral(pin, pmux);
}

void
port_set_pin_up(uint8_t pin)
{
	PORT->OUTSET = BIT(pin);
}

void
port_set_pin_down(uint8_t pin)
{
	PORT->OUTCLR = BIT(pin);
}

void
port_set_pull_up(uint8_t pin)
{
	PORT->PINCFG[pin] |= BIT(PORT_PINCFG_PULLEN);
	PORT->OUTSET = BIT(pin);
}

void
port_set_pull_down(uint8_t pin)
{
	PORT->PINCFG[pin] |= BIT(PORT_PINCFG_PULLEN);
	PORT->OUTCLR = BIT(pin);
}
