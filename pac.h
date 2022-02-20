#include <stddef.h>
#include <stdint.h>
#include <binary.h>

#define PAC0 ((struct zmcu_pac *)0x40000000)
#define PAC1 ((struct zmcu_pac *)0x41000000)
#define PAC2 ((struct zmcu_pac *)0x42000000)

struct zmcu_pac {

	/* 0x00: Write Protect Clear */
	uint32_t volatile WPCLR;
#define PAC0_WPCLR_EIC(x)			((x) << 1)
#define PAC1_WPCLR_MTB(x)			((x) << 1)

	/* 0x04: Write Protect Clear */
	uint32_t volatile WPSET;
#define PAC0_WPSET_EIC(x)			((x) << 1)
#define PAC1_WPSET_MTB(x)			((x) << 1)

};
