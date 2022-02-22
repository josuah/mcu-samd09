#include <stddef.h>
#include <stdint.h>
#include <binary.h>

#define PM ((struct zmcu_pm *)0x40000400)

struct zmcu_pm {

	/* 0x00: Control */
	uint8_t volatile CTRL;
#define PM_CTRL_BKUPCLK				(1u << 4)
#define PM_CTRL_CFDEN				(1u << 2)

	/* 0x01: Sleep Mode */
	uint8_t volatile SLEEP;
#define PM_SLEEP_IDLE(x)			((x) << 0)
#define PM_SLEEP_IDLE_MASK			PM_SLEEP_IDLE(B00000011)

	/* 0x02: External Reset Controller */
	uint8_t volatile EXTCTRL;
#define PM_EXTCTRL_SETDIS			(1u << 0)

	/* 0x03 */
	uint8_t volatile RESERVED0[0x08-0x03];

	/* 0x08: CPU Clock Select */
	uint8_t volatile CPUSEL;
#define PM_CPUSEL_CPUDIV(x)			((x) << 0)
#define PM_CPUSEL_CPUDIV_MASK			PM_CPUSEL_CPUDIV(B00000111)

	/* 0x09: APBA Clock Select */
	uint8_t volatile APBASEL;
#define PM_APBASEL_APBADIV(x)			((x) << 0)
#define PM_APBASEL_APBADIV_MASK			PM_APBASEL_APBADIV(B00000111)

	/* 0x0A: APBB Clock Select */
	uint8_t volatile APBBSEL;
#define PM_APBBSEL_APBBDIV(x)			((x) << 0)
#define PM_APBBSEL_APBBDIV_MASK			PM_APBBSEL_APBBDIV(B00000111)

	/* 0x0B: APBC Clock Select */
	uint8_t volatile APBCSEL;
#define PM_APBCSEL_APBCDIV(x)			((x) << 0)
#define PM_APBCSEL_APBCDIV_MASK			PM_APBCSEL_APBCDIV(B00000111)

	/* 0x0C */
	uint8_t volatile RESERVED1[0x14-0x0C];

	/* 0x14: AHB Mask */
	uint32_t volatile AHBMASK;
#define PM_AHBMASK_DMAC				(1u << 5)
#define PM_AHBMASK_NVMCTRL			(1u << 4)
#define PM_AHBMASK_DSU				(1u << 3)
#define PM_AHBMASK_HPB2				(1u << 2)
#define PM_AHBMASK_HPB1				(1u << 1)
#define PM_AHBMASK_HPB0				(1u << 0)

	/* 0x18: APBA Mask */
	uint32_t volatile APBAMASK;
#define PM_APBAMASK_EIC				(1u << 6)
#define PM_APBAMASK_RTC				(1u << 5)
#define PM_APBAMASK_WDT				(1u << 4)
#define PM_APBAMASK_GCLK			(1u << 3)
#define PM_APBAMASK_SYSCTRL			(1u << 2)
#define PM_APBAMASK_PM				(1u << 1)
#define PM_APBAMASK_PAC0			(1u << 0)

	/* 0x1C: APBB Mask */
	uint32_t volatile APBBMASK;
#define PM_APBBMASK_DMAC			(1u << 4)
#define PM_APBBMASK_PORT			(1u << 3)
#define PM_APBBMASK_NVMCTRL			(1u << 2)
#define PM_APBBMASK_DSU				(1u << 1)
#define PM_APBBMASK_PAC1			(1u << 0)

	/* 0x20: APBC Mask */
	uint8_t volatile APBCMASK;
#define PM_APBCMASK_ADC				(1u << 8)
#define PM_APBCMASK_TC2				(1u << 7)
#define PM_APBCMASK_TC1				(1u << 6)
#define PM_APBCMASK_SERCOM1			(1u << 3)
#define PM_APBCMASK_SERCOM0			(1u << 2)
#define PM_APBCMASK_EVSYS			(1u << 1)
#define PM_APBCMASK_PAC2			(1u << 0)

	/* 0x21 */
	uint8_t volatile RESERVED2[0x34-0x21];

	/* 0x34: Interrupt Enable Clear */
	uint8_t volatile INTENCLR;
#define PM_INTENCLR_CFD				(1u << 1)
#define PM_INTENCLR_CKRDY			(1u << 0)

	/* 0x35: Interrupt Enable Set */
	uint8_t volatile INTENSET;
#define PM_INTENSET_CFD				(1u << 1)
#define PM_INTENSET_CKRDY			(1u << 0)

	/* 0x36: Interrupt Flag Status and Clear */
	uint8_t volatile INTFLAG;
#define PM_INTFLAG_CFD				(1u << 1)
#define PM_INTFLAG_CKRDY			(1u << 0)

	/* 0x37 */
	uint8_t volatile RESERVED3[0x38-0x37];

	/* 0x38: Reset Cause */
	uint8_t volatile RCAUSE;
#define PM_RCAUSE_SYST				(1u << 6)
#define PM_RCAUSE_WDT				(1u << 5)
#define PM_RCAUSE_EXT				(1u << 4)
#define PM_RCAUSE_BOD33				(1u << 2)
#define PM_RCAUSE_BOD12				(1u << 1)
#define PM_RCAUSE_POR				(1u << 0)

};

