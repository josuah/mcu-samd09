#include <stddef.h>
#include <stdint.h>
#include <binary.h>

struct zmcu_dmacsram {

	/* 0x00: Block Transfer Control */
	uint16_t volatile BTCTRL;
#define DMACSRAM_BTCTRL_STEPSIZE(x)			((x) << 13)
#define DMACSRAM_BTCTRL_STEPSEL			(1u << 12)
#define DMACSRAM_BTCTRL_DSTINC			(1u << 11)
#define DMACSRAM_BTCTRL_SRCINC			(1u << 10)
#define DMACSRAM_BTCTRL_BEATSIZE(x)			((x) << 8)
#define DMACSRAM_BTCTRL_BLOCKACT(x)			((x) << 3)
#define DMACSRAM_BTCTRL_EVOSEL(x)			((x) << 1)
#define DMACSRAM_BTCTRL_VALID			(1u << 0)

	/* 0x02: Block Transfer Count */
	uint16_t volatile BTCNT;
#define DMACSRAM_BTCNT_BTCNT(x)			((x) << 0)

	/* 0x04: Transfer Source Address */
	uint32_t volatile SRCADDR;
#define DMACSRAM_SRCADDR_SRCADDR(x)			((x) << 0)

	/* 0x08: Transfer Destination Address */
	uint32_t volatile DSTADDR;
#define DMACSRAM_DSTADDR_DSTADDR(x)			((x) << 0)

	/* 0x0C: Next Descriptor Address */
	uint32_t volatile DESCADDR;
#define DMACSRAM_DESCADDR_DESCADDR(x)		((x) << 0)

};
