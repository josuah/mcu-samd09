#include <stddef.h>
#include <stdint.h>
#include <binary.h>

#define WDT ((struct zmcu_wdt *)0x40001000)

struct zmcu_wdt {

	/* 0x00: Control */
	uint8_t volatile CTRL;
#define WDT_CTRL_ALWAYSON			(1u << 7)
#define WDT_CTRL_WEN				(1u << 2)
#define WDT_CTRL_ENABLE				(1u << 1)

	/* 0x01: Configuration */
	uint8_t volatile CONFIG;
#define WDT_CONFIG_WINDOW(x)			((x) << 4)
#define WDT_CONFIG_WINDOW_MASK			WDT_CONFIG_WINDOW(B00001111)
#define WDT_CONFIG_PER(x)			((x) << 0)
#define WDT_CONFIG_PER_MASK			WDT_CONFIG_PER(B00001111)

	/* 0x02: Early Warning Interrupt Control */
	uint8_t volatile EWCTRL;
#define WDT_EWCTRL_EWOFFSET(x)			((x) << 0)
#define WDT_EWCTRL_EWOFFSET_MASK		WDT_EWCTRL_EWOFFSET(B00001111)

	/* 0x03 */
	uint8_t volatile RESERVED0[0x04-0x03];

	/* 0x04: Interrupt Enable Clear */
	uint8_t volatile INTENCLR;
#define WDT_INTENCLR_EW				(1u << 0)

	/* 0x05: Interrupt Enable Set */
	uint8_t volatile INTENSET;
#define WDT_INTENSET_EW				(1u << 0)

	/* 0x06: Interrupt Flag Status and Clear */
	uint8_t volatile INTFLAG;
#define WDT_INTFLAG_EW				(1u << 0)

	/* 0x07: Status */
	uint8_t volatile STATUS;
#define WDT_STATUS_SYNCBUSY			(1u << 7)

	/* 0x08: Clear */
	uint8_t volatile CLEAR;
#define WDT_CLEAR_CLEAR(x)			((x) << 0)
#define WDT_CLEAR_CLEAR_MASK			WDT_CLEAR_CLEAR(B11111111)

};
