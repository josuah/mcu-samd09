#include <stddef.h>
#include <stdint.h>
#include <binary.h>

#define TC1 ((struct zmcu_tc *)0x42001800)
#define TC2 ((struct zmcu_tc *)0x42001C00)

struct zmcu_tc {

	/* 0x00: Control A */
	uint32_t volatile CTRLA;
#define TC_CTRLA_PRESCSYNC(x)			((x) << 12)
#define TC_CTRLA_RUNSTDBY			(1u << 11)
#define TC_CTRLA_PRESCALER(x)			((x) << 8)
#define TC_CTRLA_WAVEGEN(x)			((x) << 5)
#define TC_CTRLA_MODE(x)			((x) << 2)
#define TC_CTRLA_ENABLE				(1u << 1)
#define TC_CTRLA_SWRST				(1u << 0)

	/* 0x02: */
	uint32_t volatile READREQ;
#define TC_READREQ_RREQ				(1u << 15)
#define TC_READREQ_RCONT			(1u << 14)
#define TC_READREQ_ADDR(x)			((x) << 0)

	/* 0x04: */
	uint32_t volatile CTRLBCLR;
#define TC_CTRLBCLR_CMD(x)			((x) << 6)
#define TC_CTRLBCLR_ONESHOT			(1u << 2)
#define TC_CTRLBCLR_DIR				(1u << 0)

	/* 0x05: */
	uint32_t volatile CTRLBSET;
#define TC_CTRLBSET_CMD(x)			((x) << 6)
#define TC_CTRLBSET_ONESHOT			(1u << 2)
#define TC_CTRLBSET_DIR				(1u << 0)

	/* 0x06: Control C */
	uint32_t volatile CTRLC;
#define TC_CTRLC_CPTENx(x)			((x) << 4)
#define TC_CTRLC_INVENx(x)			((x) << 0)

	/* 0x08: Debug Control */
	uint32_t volatile DBGCTRL;
#define TC_DBGCTRL_DBGRUN			(1u << 0)

	/* 0x0A: Event Control */
	uint32_t volatile EVCTRL;
#define TC_EVCTRL_MCEOx(x)			((x) << 12)
#define TC_EVCTRL_OVFEO				(1u << 8)
#define TC_EVCTRL_TCEI				(1u << 5)
#define TC_EVCTRL_TCINV				(1u << 4)
#define TC_EVCTRL_EVACT(x)			((x) << 0)

	/* 0x0C: */
	uint32_t volatile INTENCLR;
#define TC_INTENCLR_MCx(x)			((x) << 4)
#define TC_INTENCLR_SYNCRDY			(1u << 3)
#define TC_INTENCLR_ERR				(1u << 1)
#define TC_INTENCLR_OVF				(1u << 0)

	/* 0x0D: */
	uint32_t volatile INTENSET;
#define TC_INTENSET_MCx(x)			((x) << 4)
#define TC_INTENSET_SYNCRDY			(1u << 3)
#define TC_INTENSET_ERR				(1u << 1)
#define TC_INTENSET_OVF				(1u << 0)

	/* 0x0E: Interrupt Flag Status and Clear */
	uint32_t volatile INTFLAG;
#define TC_INTFLAG_MCx(x)			((x) << 4)
#define TC_INTFLAG_SYNCRDY			(1u << 3)
#define TC_INTFLAG_ERR				(1u << 1)
#define TC_INTFLAG_OVF				(1u << 0)

	/* 0x0F: Status */
	uint32_t volatile STATUS;
#define TC_STATUS_SYNCBUSY			(1u << 7)
#define TC_STATUS_SLAVE				(1u << 4)
#define TC_STATUS_STOP				(1u << 3)

	/* 0x10: 8-Bit Mode */
	uint32_t volatile COUNT;
#define TC_COUNT_COUNT(x)			((x) << 0)

	/* 0x10: 16-Bit Mode */
	uint32_t volatile COUNT;
#define TC_COUNT_COUNT(x)			((x) << 0)

	/* 0x10: 32-Bit Mode */
	uint32_t volatile COUNT;
#define TC_COUNT_COUNT(x)			((x) << 0)

	/* 0x14: 8-Bit Mode */
	uint32_t volatile PER;
#define TC_PER_PER(x)				((x) << 0)

	/* 0x18: 8-Bit Mode */
	uint32_t volatile CCx;
#define TC_CCx_CC(x)				((x) << 0)

	/* 0x18: 16-Bit Mode */
	uint32_t volatile CCx;
#define TC_CCx_CC(x)				((x) << 0)

	/* 0x18: 32-Bit Mode */
	uint32_t volatile CCx;
#define TC_CCx_CC(x)				((x) << 0)

};
