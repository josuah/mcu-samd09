#include <stddef.h>
#include <stdint.h>
#include <binary.h>

#define SYSCTRL ((struct zmcu_sysctrl *)0x40000800)

struct zmcu_sysctrl {

	/* 0x00: Interrupt Enable Clear */
	uint32_t volatile INTENCLR;
#define SYSCTRL_INTENCLR_DPLLLTO		(1u << 17)
#define SYSCTRL_INTENCLR_DPLLLCKF		(1u << 16)
#define SYSCTRL_INTENCLR_DPLLLCKR		(1u << 15)
#define SYSCTRL_INTENCLR_B33SRDY		(1u << 11)
#define SYSCTRL_INTENCLR_BOD33DET		(1u << 10)
#define SYSCTRL_INTENCLR_BOD33RDY		(1u << 9)
#define SYSCTRL_INTENCLR_DFLLRCS		(1u << 8)
#define SYSCTRL_INTENCLR_DFLLLCKC		(1u << 7)
#define SYSCTRL_INTENCLR_DFLLLCKF		(1u << 6)
#define SYSCTRL_INTENCLR_DFLLOOB		(1u << 5)
#define SYSCTRL_INTENCLR_DFLLRDY		(1u << 4)
#define SYSCTRL_INTENCLR_OSC8MRDY		(1u << 3)
#define SYSCTRL_INTENCLR_OSC32KRDY		(1u << 2)
#define SYSCTRL_INTENCLR_XOSC32KRDY		(1u << 1)
#define SYSCTRL_INTENCLR_XOSCRDY		(1u << 0)

	/* 0x04: Interrupt Enable Set */
	uint32_t volatile INTENSET;
#define SYSCTRL_INTENSET_DPLLLTO		(1u << 17)
#define SYSCTRL_INTENSET_DPLLLCKF		(1u << 16)
#define SYSCTRL_INTENSET_DPLLLCKR		(1u << 15)
#define SYSCTRL_INTENSET_B33SRDY		(1u << 11)
#define SYSCTRL_INTENSET_BOD33DET		(1u << 10)
#define SYSCTRL_INTENSET_BOD33RDY		(1u << 9)
#define SYSCTRL_INTENSET_DFLLRCS		(1u << 8)
#define SYSCTRL_INTENSET_DFLLLCKC		(1u << 7)
#define SYSCTRL_INTENSET_DFLLLCKF		(1u << 6)
#define SYSCTRL_INTENSET_DFLLOOB		(1u << 5)
#define SYSCTRL_INTENSET_DFLLRDY		(1u << 4)
#define SYSCTRL_INTENSET_OSC8MRDY		(1u << 3)
#define SYSCTRL_INTENSET_OSC32KRDY		(1u << 2)
#define SYSCTRL_INTENSET_XOSC32KRDY		(1u << 1)
#define SYSCTRL_INTENSET_XOSCRDY		(1u << 0)

	/* 0x08: Interrupt Flag Status and Clear */
	uint32_t volatile INTFLAG;
#define SYSCTRL_INTFLAG_DPLLLTO			(1u << 17)
#define SYSCTRL_INTFLAG_DPLLLCKF		(1u << 16)
#define SYSCTRL_INTFLAG_DPLLLCKR		(1u << 15)
#define SYSCTRL_INTFLAG_B33SRDY			(1u << 11)
#define SYSCTRL_INTFLAG_BOD33DET		(1u << 10)
#define SYSCTRL_INTFLAG_BOD33RDY		(1u << 9)
#define SYSCTRL_INTFLAG_DFLLRCS			(1u << 8)
#define SYSCTRL_INTFLAG_DFLLLCKC		(1u << 7)
#define SYSCTRL_INTFLAG_DFLLLCKF		(1u << 6)
#define SYSCTRL_INTFLAG_DFLLOOB			(1u << 5)
#define SYSCTRL_INTFLAG_DFLLRDY			(1u << 4)
#define SYSCTRL_INTFLAG_OSC8MRDY		(1u << 3)
#define SYSCTRL_INTFLAG_OSC32KRDY		(1u << 2)
#define SYSCTRL_INTFLAG_XOSC32KRDY		(1u << 1)
#define SYSCTRL_INTFLAG_XOSCRDY			(1u << 0)

	/* 0x0C: Power and Clocks Status */
	uint32_t volatile PCLKSR;
#define SYSCTRL_PCLKSR_DPLLLTO			(1u << 17)
#define SYSCTRL_PCLKSR_DPLLLCKF			(1u << 16)
#define SYSCTRL_PCLKSR_DPLLLCKR			(1u << 15)
#define SYSCTRL_PCLKSR_B33SRDY			(1u << 11)
#define SYSCTRL_PCLKSR_BOD33DET			(1u << 10)
#define SYSCTRL_PCLKSR_BOD33RDY			(1u << 9)
#define SYSCTRL_PCLKSR_DFLLRCS			(1u << 8)
#define SYSCTRL_PCLKSR_DFLLLCKC			(1u << 7)
#define SYSCTRL_PCLKSR_DFLLLCKF			(1u << 6)
#define SYSCTRL_PCLKSR_DFLLOOB			(1u << 5)
#define SYSCTRL_PCLKSR_DFLLRDY			(1u << 4)
#define SYSCTRL_PCLKSR_OSC8MRDY			(1u << 3)
#define SYSCTRL_PCLKSR_OSC32KRDY		(1u << 2)
#define SYSCTRL_PCLKSR_XOSC32KRDY		(1u << 1)
#define SYSCTRL_PCLKSR_XOSCRDY			(1u << 0)

	/* 0x10: External Multipurpose Crystal Oscillator (XOSC) Control */
	uint32_t volatile XOSC;
#define SYSCTRL_XOSC_STARTUP(x)			((x) << 12)
#define SYSCTRL_XOSC_AMPGC			(1u << 11)
#define SYSCTRL_XOSC_GAIN(x)			((x) << 8)
#define SYSCTRL_XOSC_ONDEMAND			(1u << 7)
#define SYSCTRL_XOSC_RUNSTDBY			(1u << 6)
#define SYSCTRL_XOSC_XTALEN			(1u << 2)
#define SYSCTRL_XOSC_ENABLE			(1u << 1)

	/* 0x14: 32kHz External Crystal Oscillator (XOSC32K) Control */
	uint32_t volatile XOSC32K;
#define SYSCTRL_XOSC32K_WRTLOCK			(1u << 12)
#define SYSCTRL_XOSC32K_STARTUP(x)		((x) << 8)
#define SYSCTRL_XOSC32K_ONDEMAND		(1u << 7)
#define SYSCTRL_XOSC32K_RUNSTDBY		(1u << 6)
#define SYSCTRL_XOSC32K_AAMPEN			(1u << 5)
#define SYSCTRL_XOSC32K_EN1K			(1u << 4)
#define SYSCTRL_XOSC32K_EN32K			(1u << 3)
#define SYSCTRL_XOSC32K_XTALEN			(1u << 2)
#define SYSCTRL_XOSC32K_ENABLE			(1u << 1)

	/* 0x18: 32kHz Internal Oscillator (OSC32K) Control */
	uint32_t volatile OSC32K;
#define SYSCTRL_OSC32K_CALIB(x)			((x) << 16)
#define SYSCTRL_OSC32K_WRTLOCK			(1u << 12)
#define SYSCTRL_OSC32K_STARTUP(x)		((x) << 8)
#define SYSCTRL_OSC32K_ONDEMAND			(1u << 7)
#define SYSCTRL_OSC32K_RUNSTDBY			(1u << 6)
#define SYSCTRL_OSC32K_EN1K			(1u << 3)
#define SYSCTRL_OSC32K_EN32K			(1u << 2)
#define SYSCTRL_OSC32K_ENABLE			(1u << 1)

	/* 0x1C: 32kHz Ultra Low Power Internal Oscillator (OSCULP32K) Control */
	uint32_t volatile OSCULP32K;
#define SYSCTRL_OSCULP32K_WRTLOCK		(1u << 7)
#define SYSCTRL_OSCULP32K_CALIB(x)		((x) << 0)

	/* 0x20: 8MHz Internal Oscillator (OSC8M) Control */
	uint32_t volatile OSC8M;
#define SYSCTRL_OSC8M_FRANGE(x)			((x) << 30)
#define SYSCTRL_OSC8M_CALIB(x)			((x) << 16)
#define SYSCTRL_OSC8M_PRESC(x)			((x) << 8)
#define SYSCTRL_OSC8M_ONDEMAND			(1u << 7)
#define SYSCTRL_OSC8M_RUNSTDBY			(1u << 6)
#define SYSCTRL_OSC8M_ENABLE			(1u << 1)

	/* 0x24: DFLL48M Control */
	uint32_t volatile DFLLCTRL;
#define SYSCTRL_DFLLCTRL_WAITLOCK		(1u << 11)
#define SYSCTRL_DFLLCTRL_BPLCKC			(1u << 10)
#define SYSCTRL_DFLLCTRL_QLDIS			(1u << 9)
#define SYSCTRL_DFLLCTRL_CCDIS			(1u << 8)
#define SYSCTRL_DFLLCTRL_ONDEMAND		(1u << 7)
#define SYSCTRL_DFLLCTRL_LLAW			(1u << 4)
#define SYSCTRL_DFLLCTRL_STABLE			(1u << 3)
#define SYSCTRL_DFLLCTRL_MODE			(1u << 2)
#define SYSCTRL_DFLLCTRL_ENABLE			(1u << 1)

	/* 0x28: DFLL48M Value */
	uint32_t volatile DFLLVAL;
#define SYSCTRL_DFLLVAL_DIFF(x)			((x) << 16)
#define SYSCTRL_DFLLVAL_COARSE(x)		((x) << 10)
#define SYSCTRL_DFLLVAL_FINE(x)			((x) << 0)

	/* 0x2C: DFLL48M Multiplier */
	uint32_t volatile DFLLMUL;
#define SYSCTRL_DFLLMUL_CSTEP(x)		((x) << 26)
#define SYSCTRL_DFLLMUL_FSTEP(x)		((x) << 16)
#define SYSCTRL_DFLLMUL_MUL(x)			((x) << 0)

	/* 0x30: DFLL48M Synchronization */
	uint32_t volatile DFLLSYNC;
#define SYSCTRL_DFLLSYNC_READREQ		(1u << 7)

	/* 0x34: 3.3V Brown-Out Detector (BOD33) Control */
	uint32_t volatile BOD33;
#define SYSCTRL_BOD33_LEVEL(x)			((x) << 16)
#define SYSCTRL_BOD33_PSEL(x)			((x) << 12)
#define SYSCTRL_BOD33_CEN			(1u << 9)
#define SYSCTRL_BOD33_MODE			(1u << 8)
#define SYSCTRL_BOD33_RUNSTDBY			(1u << 6)
#define SYSCTRL_BOD33_ACTION(x)			((x) << 3)
#define SYSCTRL_BOD33_HYST			(1u << 2)
#define SYSCTRL_BOD33_ENABLE			(1u << 1)

	/* 0x38 */
	uint8_t volatile RESERVED8[0x40-0x38];

	/* 0x40: Voltage References System (VREF) Control */
	uint32_t volatile VREF;
#define SYSCTRL_VREF_CALIB(x)			((x) << 16)
#define SYSCTRL_VREF_BGOUTEN			(1u << 2)
#define SYSCTRL_VREF_TSEN			(1u << 1)

	/* 0x44: DPLL Control A */
	uint32_t volatile DPLLCTRLA;
#define SYSCTRL_DPLLCTRLA_ONDEMAND		(1u << 7)
#define SYSCTRL_DPLLCTRLA_ENABLE		(1u << 1)

	/* 0x48: DPLL Ratio Control */
	uint32_t volatile DPLLRATIO;
#define SYSCTRL_DPLLRATIO_LDRFRAC(x)		((x) << 16)
#define SYSCTRL_DPLLRATIO_LDR(x)		((x) << 0)

	/* 0x4C: DPLL Control B */
	uint32_t volatile DPLLCTRLB;
#define SYSCTRL_DPLLCTRLB_DIV(x)		((x) << 16)
#define SYSCTRL_DPLLCTRLB_LBYPASS		(1u << 12)
#define SYSCTRL_DPLLCTRLB_LTIME(x)		((x) << 8)
#define SYSCTRL_DPLLCTRLB_REFCLK(x)		((x) << 4)
#define SYSCTRL_DPLLCTRLB_WUF			(1u << 3)
#define SYSCTRL_DPLLCTRLB_LPEN			(1u << 2)
#define SYSCTRL_DPLLCTRLB_FILTER(x)		((x) << 0)

	/* 0x50: DPLL Status */
	uint32_t volatile DPLLSTATUS;
#define SYSCTRL_DPLLSTATUS_DIV			(1u << 3)
#define SYSCTRL_DPLLSTATUS_ENABLE		(1u << 2)
#define SYSCTRL_DPLLSTATUS_CLKRDY		(1u << 1)
#define SYSCTRL_DPLLSTATUS_LOCK			(1u << 0)

};
