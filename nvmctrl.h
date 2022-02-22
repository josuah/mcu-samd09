#include <stddef.h>
#include <stdint.h>
#include <binary.h>

#define NVMCTRL ((struct zmcu_nvmctrl *)0x41004000)

struct zmcu_nvmctrl {

	/* 0x00: Control A */
	uint8_t volatile CTRLA;
#define NVMCTRL_CTRLA_CMDEX(x)			((x) << 8)
#define NVMCTRL_CTRLA_CMDEX_MASK		NVMCTRL_CTRLA_CMDEX(B11111111)
#define NVMCTRL_CTRLA_CMD(x)			((x) << 0)
#define NVMCTRL_CTRLA_CMD_MASK			NVMCTRL_CTRLA_CMD(B01111111)

	/* 0x01 */
	uint8_t volatile RESERVED0[0x04-0x01];

	/* 0x04: Control B */
	uint32_t volatile CTRLB;
#define NVMCTRL_CTRLB_CACHEDIS			(1u << 18)
#define NVMCTRL_CTRLB_READMODE(x)		((x) << 16)
#define NVMCTRL_CTRLB_READMODE_MASK		NVMCTRL_CTRLB_READMODE(B00000011)
#define NVMCTRL_CTRLB_SLEEPPRM(x)		((x) << 8)
#define NVMCTRL_CTRLB_SLEEPPRM_MASK		NVMCTRL_CTRLB_SLEEPPRM(B00000011)
#define NVMCTRL_CTRLB_MANW			(1u << 7)
#define NVMCTRL_CTRLB_RWS(x)			((x) << 1)
#define NVMCTRL_CTRLB_RWS_MASK			NVMCTRL_CTRLB_RWS(B00001111)

	/* 0x08: NVM Parameter */
	uint32_t volatile PARAM;
#define NVMCTRL_PARAM_PSZ(x)			((x) << 16)
#define NVMCTRL_PARAM_PSZ_MASK			NVMCTRL_PARAM_PSZ(B00000111)
#define NVMCTRL_PARAM_NVMP(x)			((x) << 0)

	/* 0x0C: Interrupt Enable Clear */
	uint8_t volatile INTENCLR;
#define NVMCTRL_INTENCLR_ERROR			(1u << 1)
#define NVMCTRL_INTENCLR_READY			(1u << 0)

	/* 0x0D */
	uint8_t volatile RESERVED1[0x10-0x0D];

	/* 0x10: Interrupt Enable Set */
	uint8_t volatile INTENSET;
#define NVMCTRL_INTENSET_ERROR			(1u << 1)
#define NVMCTRL_INTENSET_READY			(1u << 0)

	/* 0x11 */
	uint8_t volatile RESERVED2[0x14-0x11];

	/* 0x14: Interrupt Flag Status and Clear */
	uint8_t volatile INTFLAG;
#define NVMCTRL_INTFLAG_ERROR			(1u << 1)
#define NVMCTRL_INTFLAG_READY			(1u << 0)

	/* 0x15 */
	uint8_t volatile RESERVED3[0x18-0x15];

	/* 0x18: Status */
	uint16_t volatile STATUS;
#define NVMCTRL_STATUS_SB			(1u << 8)
#define NVMCTRL_STATUS_NVME			(1u << 4)
#define NVMCTRL_STATUS_LOCKE			(1u << 3)
#define NVMCTRL_STATUS_PROGE			(1u << 2)
#define NVMCTRL_STATUS_LOAD			(1u << 1)
#define NVMCTRL_STATUS_PRM			(1u << 0)

	/* 0x1A */
	uint8_t volatile RESERVED4[0x1C-0x1A];

	/* 0x1C: Address */
	uint32_t volatile ADDR;
#define NVMCTRL_ADDR_ADDR(x)			((x) << 0)

	/* 0x20: Lock Section */
	uint16_t volatile LOCK;
#define NVMCTRL_LOCK_LOCK(x)			((x) << 0)

};
