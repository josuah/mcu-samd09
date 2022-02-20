#include <stddef.h>
#include <stdint.h>
#include <binary.h>

#define WDT ((struct zmcu_wdt *)0x40001000)

struct zmcu_wdt {

	/* 0x00: Control */
	uint32_t volatile CTRL;
#define WDT_CTRL_ALWAYSON			(1u << 7)
#define WDT_CTRL_WEN				(1u << 2)
#define WDT_CTRL_ENABLE				(1u << 1)

	/* 0x01: Configuration */
	uint32_t volatile CONFIG;
#define WDT_CONFIG_WINDOW(x)			((x) << 4)
#define WDT_CONFIG_PER(x)			((x) << 0)

	/* 0x02: Early Warning Interrupt Control */
	uint32_t volatile EWCTRL;
#define WDT_EWCTRL_EWOFFSET(x)			((x) << 0)

	/* 0x04: Interrupt Enable Clear */
	uint32_t volatile INTENCLR;
#define WDT_INTENCLR_EW				(1u << 0)

	/* 0x05: Interrupt Enable Set */
	uint32_t volatile INTENSET;
#define WDT_INTENSET_EW				(1u << 0)

	/* 0x06: Interrupt Flag Status and Clear */
	uint32_t volatile INTFLAG;
#define WDT_INTFLAG_EW				(1u << 0)

	/* 0x07: Status */
	uint32_t volatile STATUS;
#define WDT_STATUS_SYNCBUSY			(1u << 7)

	/* 0x08: Clear */
	uint32_t volatile CLEAR;
#define WDT_CLEAR_CLEAR(x)			((x) << 0)

};
