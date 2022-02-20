#include <stddef.h>
#include <stdint.h>
#include <binary.h>

#define GCLK ((struct zmcu_gclk *)0x40000C00)

struct zmcu_gclk {

	/* 0x00: Control */
	uint32_t volatile CTRL;
#define GCLK_CTRL_SWRST				(1u << 0)

	/* 0x01: Status */
	uint32_t volatile STATUS;
#define GCLK_STATUS_SYNCBUSY			(1u << 7)

	/* 0x02: Generic Clock Control */
	uint32_t volatile CLKCTRL;
#define GCLK_CLKCTRL_WRTLOCK			(1u << 15)
#define GCLK_CLKCTRL_CLKEN			(1u << 14)
#define GCLK_CLKCTRL_GEN(x)			((x) << 8)
#define GCLK_CLKCTRL_ID(x)			((x) << 0)

	/* 0x04: Generic Clock Generator Control */
	uint32_t volatile GENCTRL;
#define GCLK_GENCTRL_RUNSTDBY			(1u << 21)
#define GCLK_GENCTRL_DIVSEL			(1u << 20)
#define GCLK_GENCTRL_OE				(1u << 19)
#define GCLK_GENCTRL_OOV			(1u << 18)
#define GCLK_GENCTRL_IDC			(1u << 17)
#define GCLK_GENCTRL_GENEN			(1u << 16)
#define GCLK_GENCTRL_SRC(x)			((x) << 8)
#define GCLK_GENCTRL_ID(x)			((x) << 0)

	/* 0x08: Generic Clock Generator Division */
	uint32_t volatile GENDIV;
#define GCLK_GENDIV_DIV(x)			((x) << 8)
#define GCLK_GENDIV_ID(x)			((x) << 0)

};
