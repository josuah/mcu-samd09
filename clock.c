#include "libc.h"
#include "registers.h"
#include "functions.h"

static inline uint32_t
clock_get_source_hz(uint32_t srcid)
{
	switch (srcid) {
	case GCLK_GENCTRL_SRC_XOSC:
		break; // TODO
	case GCLK_GENCTRL_SRC_GCLKIN:
		break; // TODO
	case GCLK_GENCTRL_SRC_GCLKGEN1:
		return clock_get_generator_hz(1);
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
	default:
		assert(!"unknown clock value");
	}
	assert(!"unknown clock source");
	return 0;
}

static inline uint32_t
clock_get_generator_source(uint8_t genid)
{
	*(uint8_t *)&GCLK->GENCTRL = genid;
	return GCLK->GENCTRL & GCLK_GENCTRL_SRC_Msk;
}

static inline uint8_t
clock_get_generator_div(uint8_t genid)
{
	uint8_t div;

	*(uint8_t *)&GCLK->GENDIV = genid;
	div = FIELD(GCLK->GENDIV, GCLK_GENDIV_DIV);
	return div ? div : 1;
}

static inline uint8_t
clock_get_generator(uint8_t clkid)
{
	*(uint8_t *)&GCLK->CLKCTRL = clkid;
	return FIELD(GCLK->CLKCTRL, GCLK_CLKCTRL_GEN);
}

uint32_t
clock_get_generator_hz(uint8_t genid)
{
	return clock_get_source_hz(clock_get_generator_source(genid))
	 / clock_get_generator_div(genid);
}

uint32_t
clock_get_channel_hz(uint8_t clkid)
{
	return clock_get_generator_hz(clock_get_generator(clkid));
}

void
clock_init_generator(uint8_t genid, uint32_t srcid, uint32_t div)
{
	GCLK->GENDIV = genid | div;
	GCLK->GENCTRL = genid | srcid | GCLK_GENCTRL_GENEN;
	while (GCLK->STATUS & GCLK_STATUS_SYNCBUSY);
}

void
clock_enable_generator_output(uint8_t genid)
{
	GCLK->GENCTRL = (GCLK->GENCTRL & ~GCLK_GENCTRL_ID_Msk)
	 | genid | GCLK_GENCTRL_OE;
	while (GCLK->STATUS & GCLK_STATUS_SYNCBUSY);
}

void
clock_init(uint8_t clkid, uint8_t genid)
{
	GCLK->CLKCTRL = clkid | genid | GCLK_CLKCTRL_CLKEN;
	while (GCLK->STATUS & GCLK_STATUS_SYNCBUSY);
}
