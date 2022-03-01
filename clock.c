#include "libc.h"
#include "main.h"
#include "registers.h"

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
	return clock_rate_hz / clock_div_num;
}

static inline uint8_t
clock_get_generator(uint8_t clkid)
{
	uint8_t *clkctrl = (void *)&GCLK->CLKCTRL;

	*clkctrl = clkid;
	return BITREAD(GCLK->CLKCTRL, GCLK_CLKCTRL_GEN);
}

uint32_t
clock_get_rate_hz(uint8_t clkid)
{
	return clock_generator_get_rate_hz(clock_get_generator(clkid));
}

void
clock_set_generator(uint8_t clkid, uint8_t genid)
{
	GCLK->CLKCTRL = BIT(GCLK_CLKCTRL_CLKEN)
	  | genid << GCLK_CLKCTRL_GEN_lsb
	  | clkid << GCLK_CLKCTRL_ID_lsb
	  | GCLK_CLKCTRL_CLKEN;

	while (GCLK->STATUS & BIT(GCLK_STATUS_SYNCBUSY));
}
