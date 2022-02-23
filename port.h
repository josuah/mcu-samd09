#include <stddef.h>
#include <stdint.h>
#include <binary.h>

#define PORT ((struct zmcu_port *)0x41004400)

struct zmcu_port {

	/* 0x00: Data Direction */
	uint32_t volatile DIR;

	/* 0x04: Data Direction Clear */
	uint32_t volatile DIRCLR;

	/* 0x08: Data Direction Set */
	uint32_t volatile DIRSET;

	/* 0x0C: Data Direction Toggle */
	uint32_t volatile DIRTGL;

	/* 0x10: Data Output Value */
	uint32_t volatile OUT;

	/* 0x14: Data Output Value Clear */
	uint32_t volatile OUTCLR;

	/* 0x18: Data Output Value Set */
	uint32_t volatile OUTSET;

	/* 0x1C: Data Output Value Toggle */
	uint32_t volatile OUTTGL;

	/* 0x20: Data Input Value */
	uint32_t volatile IN;

	/* 0x24: Control */
	uint32_t volatile CTRL;

	/* 0x28: Write Configuration */
	uint32_t volatile WRCONFIG;
#define PORT_WRCONFIG_HWSEL			(1u << 31)
#define PORT_WRCONFIG_WRPINCFG			(1u << 30)
#define PORT_WRCONFIG_WRPMUX			(1u << 28)
#define PORT_WRCONFIG_PMUX(x)			((x) << 24)
#define PORT_WRCONFIG_PMUX_MASK			PORT_WRCONFIG_PMUX(B00001111)
#define PORT_WRCONFIG_DRVSTR			(1u << 22)
#define PORT_WRCONFIG_PULLEN			(1u << 18)
#define PORT_WRCONFIG_INEN			(1u << 17)
#define PORT_WRCONFIG_PMUXEN			(1u << 16)
#define PORT_WRCONFIG_PINMASK(x)		((x) << 0)

	/* 0x2C */
	uint8_t volatile RESERVED0[0x30-0x2C];

	/* 0x30: Peripheral Multiplexing, use PMUX[pin/2] */
	uint8_t volatile PMUX[16];
	/* Table 6-1. PORT Function Multiplexing */
#define PORT_PMUX(pin, x)			((x) << ((pin) % 2) * 4)
#define PORT_PMUX_MASK(pin)			PORT_PMUX((pin), B00001111)
#define PORT_PMUX_EIC				0
#define PORT_PMUX_REF				1
#define PORT_PMUX_ADC				1
#define PORT_PMUX_SERCOM			2
#define PORT_PMUX_SERCOM_ALT			3
#define PORT_PMUX_TC				4
#define PORT_PMUX_COM				5
#define PORT_PMUX_GCLK				6

	/* 0x40: Pin Configuration n */
	uint8_t volatile PINCFG[32];
#define PORT_PINCFG_DRVSTR			(1u << 6)
#define PORT_PINCFG_PULLEN			(1u << 2)
#define PORT_PINCFG_INEN			(1u << 1)
#define PORT_PINCFG_PMUXEN			(1u << 0)

};
