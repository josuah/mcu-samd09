#include <stddef.h>
#include <stdint.h>
#include <binary.h>

#define PORT ((struct zmcu_port *)0x41004400)

struct zmcu_port {

	/* 0x00: Data Direction */
	uint32_t volatile DIRn;
#define PORT_DIRn_DIR(x)			((x) << 0)

	/* 0x04: Data Direction Clear */
	uint32_t volatile DIRCLRn;
#define PORT_DIRCLRn_DIRCLR(x)			((x) << 0)

	/* 0x08: Data Direction Set */
	uint32_t volatile DIRSETn;
#define PORT_DIRSETn_DIRSET(x)			((x) << 0)

	/* 0x0C: Data Direction Toggle */
	uint32_t volatile DIRTGLn;
#define PORT_DIRTGLn_DIRTGL(x)			((x) << 0)

	/* 0x10: Data Output Value */
	uint32_t volatile OUTn;
#define PORT_OUTn_OUT(x)			((x) << 0)

	/* 0x14: Data Output Value Clear */
	uint32_t volatile OUTCLRn;
#define PORT_OUTCLRn_OUTCLR(x)			((x) << 0)

	/* 0x18: Data Output Value Set */
	uint32_t volatile OUTSETn;
#define PORT_OUTSETn_OUTSET(x)			((x) << 0)

	/* 0x1C: Data Output Value Toggle */
	uint32_t volatile OUTTGLn;
#define PORT_OUTTGLn_OUTTGL(x)			((x) << 0)

	/* 0x20: Data Input Value */
	uint32_t volatile INn;
#define PORT_INn_IN(x)				((x) << 0)

	/* 0x24: Control */
	uint32_t volatile CTRLn;
#define PORT_CTRLn_SAMPLING(x)			((x) << 0)

	/* 0x28: Write Configuration */
	uint32_t volatile WRCONFIGn;
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
	uint32_t volatile RESERVED12;

	/* 0x30: Peripheral Multiplexing n */
	uint32_t volatile PMUXnm;
#define PORT_PMUXnm_PMUXO(x)			((x) << 4)
#define PORT_PMUXnm_PMUXE(x)			((x) << 0)

	/* 0x34 */
	uint32_t volatile RESERVED13[(0x40-0x34)/4];

	/* 0x40: Pin Configuration n */
	uint32_t volatile PINCFGnm;
#define PORT_PINCFGnm_DRVSTR			(1u << 6)
#define PORT_PINCFGnm_PULLEN			(1u << 2)
#define PORT_PINCFGnm_INEN			(1u << 1)
#define PORT_PINCFGnm_PMUXEN			(1u << 0)

};
