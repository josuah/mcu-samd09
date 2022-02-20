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
#define PORT_WRCONFIGn_HWSEL			(1u << 31)
#define PORT_WRCONFIGn_WRPINCFG			(1u << 30)
#define PORT_WRCONFIGn_WRPMUX			(1u << 28)
#define PORT_WRCONFIGn_PMUX(x)			((x) << 24)
#define PORT_WRCONFIGn_DRVSTR			(1u << 22)
#define PORT_WRCONFIGn_PULLEN			(1u << 18)
#define PORT_WRCONFIGn_INEN			(1u << 17)
#define PORT_WRCONFIGn_PMUXEN			(1u << 16)
#define PORT_WRCONFIGn_PINMASK(x)		((x) << 0)

	/* 0x2C */
	uint8_t volatile RESERVED12[0x30-0x2C];

	/* 0x30: Peripheral Multiplexing n */
	uint32_t volatile PMUXnm;
#define PORT_PMUXnm_PMUXO(x)			((x) << 4)
#define PORT_PMUXnm_PMUXE(x)			((x) << 0)

	/* 0x34 */
	uint8_t volatile RESERVED13[0x40-0x34];

	/* 0x40: Pin Configuration n */
	uint32_t volatile PINCFGnm;
#define PORT_PINCFGnm_DRVSTR			(1u << 6)
#define PORT_PINCFGnm_PULLEN			(1u << 2)
#define PORT_PINCFGnm_INEN			(1u << 1)
#define PORT_PINCFGnm_PMUXEN			(1u << 0)

};
