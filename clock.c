#include "libc.h"
#include "main.h"
#include "registers.h"
#include "functions.h"

static inline uint32_t clock_generator_get_rate_hz(uint8_t genid);

static inline uint32_t
clock_source_get_rate_hz(uint8_t srcid)
{
	switch (srcid) {
	case GCLK_GENCTRL_SRC_XOSC:
		port_pin_set(27);
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
	return 0;
}

static inline uint8_t
clock_generator_get_source(uint8_t genid)
{
	uint32_t reg;

	*(uint8_t *)&GCLK->GENCTRL = (uint8_t)4;
	reg = GCLK->GENCTRL;
	if (((reg >> GCLK_GENCTRL_SRC_lsb) & 0xF) == 6)
		port_pin_set(27);
	*(uint8_t *)&GCLK->GENCTRL = genid;
	return FIELD(GCLK->GENCTRL, GCLK_GENCTRL_SRC);
}

static inline uint8_t
clock_generator_get_div(uint8_t genid)
{
	*(uint8_t *)&GCLK->GENDIV = genid;
	return FIELD(GCLK->GENDIV, GCLK_GENDIV_DIV);
}

static inline uint32_t
clock_generator_get_rate_hz(uint8_t genid)
{
	return clock_source_get_rate_hz(clock_generator_get_source(genid))
	  / clock_generator_get_div(genid);
}

static inline uint8_t
clock_get_generator(uint8_t clkid)
{
	*(uint8_t *)&GCLK->CLKCTRL = clkid;
	return FIELD(GCLK->CLKCTRL, GCLK_CLKCTRL_GEN);
}

uint32_t
clock_get_rate_hz(uint8_t clkid)
{
	return clock_generator_get_rate_hz(clock_get_generator(clkid));
}

void
clock_generator_init(uint8_t genid, uint8_t srcid, uint16_t div)
{
	GCLK->GENDIV = 0
	  | BITS(GCLK_GENDIV_ID, genid)
	  | BITS(GCLK_GENDIV_DIV, div);
	GCLK->GENCTRL = 0
	  | BITS(GCLK_GENCTRL_ID, genid)
	  | BITS(GCLK_GENCTRL_SRC, srcid)
	  | BIT(GCLK_GENCTRL_GENEN);
	while (GCLK->STATUS & BIT(GCLK_STATUS_SYNCBUSY));
}

void
clock_generator_enable_output(uint8_t genid)
{
	GCLK->GENCTRL = (GCLK->GENCTRL & ~MASK(GCLK_GENCTRL_ID))
	  | BITS(GCLK_GENCTRL_ID, genid)
	  | BIT(GCLK_GENCTRL_OE);
	while (GCLK->STATUS & BIT(GCLK_STATUS_SYNCBUSY));
}

void
clock_init(uint8_t clkid, uint8_t genid)
{
	GCLK->CLKCTRL = 0
	  | BITS(GCLK_CLKCTRL_ID, clkid)
	  | BITS(GCLK_CLKCTRL_GEN, genid)
	  | BIT(GCLK_CLKCTRL_CLKEN);
	while (GCLK->STATUS & BIT(GCLK_STATUS_SYNCBUSY));
}
