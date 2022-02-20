#include <stddef.h>
#include <stdint.h>
#include <binary.h>

#define RTC ((struct zmcu_rtc *)0x40001400)

struct zmcu_rtc {

	/* 0x00: Control - MODE0/1/2 */
	uint32_t volatile CTRL;
#define RTC_CTRL_PRESCALER(x)			((x) << 8)
#define RTC_CTRL_MATCHCLR			(1u << 7)
#define RTC_CTRL_CLKREP				(1u << 6)
#define RTC_CTRL_MODE(x)			((x) << 2)
#define RTC_CTRL_ENABLE				(1u << 1)
#define RTC_CTRL_SWRST				(1u << 0)

	/* 0x02: Read Request */
	uint32_t volatile READREQ;
#define RTC_READREQ_RREQ			(1u << 15)
#define RTC_READREQ_RCONT			(1u << 14)
#define RTC_READREQ_ADDR(x)			((x) << 0)

	/* 0x04: Event Control - MODE0 */
	uint32_t volatile EVCTRL;
#define RTC_EVCTRL_OVFEO			(1u << 15)
#define RTC_EVCTRL_CMPEO			(1u << 8)
#define RTC_EVCTRL_PEREOx(x)			((x) << 0)

	/* 0x04: Event Control - MODE1 */
	uint32_t volatile EVCTRL;
#define RTC_EVCTRL_OVFEO			(1u << 15)
#define RTC_EVCTRL_CMPEOx(x)			((x) << 8)
#define RTC_EVCTRL_PEREOx(x)			((x) << 0)

	/* 0x04: Event Control - MODE2 */
	uint32_t volatile EVCTRL;
#define RTC_EVCTRL_OVFEO			(1u << 15)
#define RTC_EVCTRL_ALARMEO			(1u << 8)
#define RTC_EVCTRL_PEREOx(x)			((x) << 0)

	/* 0x06: Interrupt Enable Clear - MODE0 */
	uint32_t volatile INTENCLR;
#define RTC_INTENCLR_OVF			(1u << 7)
#define RTC_INTENCLR_SYNCRDY			(1u << 6)
#define RTC_INTENCLR_CMP			(1u << 0)

	/* 0x06: Interrupt Enable Clear - MODE1 */
	uint32_t volatile INTENCLR;
#define RTC_INTENCLR_OVF			(1u << 7)
#define RTC_INTENCLR_SYNCRDY			(1u << 6)
#define RTC_INTENCLR_CMPx(x)			((x) << 0)

	/* 0x06: Interrupt Enable Clear - MODE2 */
	uint32_t volatile INTENCLR;
#define RTC_INTENCLR_OVF			(1u << 7)
#define RTC_INTENCLR_SYNCRDY			(1u << 6)
#define RTC_INTENCLR_ALARM			(1u << 0)

	/* 0x07: Interrupt Enable Set - MODE0 */
	uint32_t volatile INTENSET;
#define RTC_INTENSET_OVF			(1u << 7)
#define RTC_INTENSET_SYNCRDY			(1u << 6)
#define RTC_INTENSET_CMP			(1u << 0)

	/* 0x07: Interrupt Enable Set - MODE1 */
	uint32_t volatile INTENSET;
#define RTC_INTENSET_OVF			(1u << 7)
#define RTC_INTENSET_SYNCRDY			(1u << 6)
#define RTC_INTENSET_CMPx(x)			((x) << 0)

	/* 0x07: Interrupt Enable Set - MODE2 */
	uint32_t volatile INTENSET;
#define RTC_INTENSET_OVF			(1u << 7)
#define RTC_INTENSET_SYNCRDY			(1u << 6)
#define RTC_INTENSET_ALARM			(1u << 0)

	/* 0x08: Interrupt Flag Status and Clear - MODE0 */
	uint32_t volatile INTFLAG;
#define RTC_INTFLAG_OVF				(1u << 7)
#define RTC_INTFLAG_SYNCRDY			(1u << 6)
#define RTC_INTFLAG_CMP				(1u << 0)

	/* 0x08: Interrupt Flag Status and Clear - MODE1 */
	uint32_t volatile INTFLAG;
#define RTC_INTFLAG_OVF				(1u << 7)
#define RTC_INTFLAG_SYNCRDY			(1u << 6)
#define RTC_INTFLAG_CMPx(x)			((x) << 0)

	/* 0x08: Interrupt Flag Status and Clear - MODE2 */
	uint32_t volatile INTFLAG;
#define RTC_INTFLAG_OVF				(1u << 7)
#define RTC_INTFLAG_SYNCRDY			(1u << 6)
#define RTC_INTFLAG_ALARM			(1u << 0)

	/* 0x0A: Status */
	uint32_t volatile STATUS;
#define RTC_STATUS_SYNCBUSY			(1u << 7)

	/* 0x0B: Debug Control */
	uint32_t volatile DBGCTRL;
#define RTC_DBGCTRL_DBGRUN			(1u << 0)

	/* 0x0C: Frequency Correction */
	uint32_t volatile FREQCORR;
#define RTC_FREQCORR_SIGN			(1u << 7)
#define RTC_FREQCORR_VALUE(x)			((x) << 0)

	/* 0x10: Counter Value - MODE0 */
	uint32_t volatile COUNT;
#define RTC_COUNT_COUNT(x)			((x) << 0)

	/* 0x10: Counter Value - MODE1 */
	uint32_t volatile COUNT;
#define RTC_COUNT_COUNT(x)			((x) << 0)

	/* 0x10: Clock Value - MODE2 */
	uint32_t volatile CLOCK;
#define RTC_CLOCK_YEAR(x)			((x) << 26)
#define RTC_CLOCK_MONTH(x)			((x) << 22)
#define RTC_CLOCK_DAY(x)			((x) << 17)
#define RTC_CLOCK_HOUR(x)			((x) << 12)
#define RTC_CLOCK_MINUTE(x)			((x) << 6)
#define RTC_CLOCK_SECOND(x)			((x) << 0)

	/* 0x14: Counter Period - MODE1 */
	uint32_t volatile PER;
#define RTC_PER_PER(x)				((x) << 0)

	/* 0x18: Compare n Value - MODE0 */
	uint32_t volatile COMP;
#define RTC_COMP_COMP(x)			((x) << 0)

	/* 0x18: Compare n Value - MODE1 */
	uint32_t volatile COMPn;
#define RTC_COMPn_COMP(x)			((x) << 0)

	/* 0x18: Alarm n Value - MODE2 */
	uint32_t volatile ALARM;
#define RTC_ALARM_YEAR(x)			((x) << 26)
#define RTC_ALARM_MONTH(x)			((x) << 22)
#define RTC_ALARM_DAY(x)			((x) << 17)
#define RTC_ALARM_HOUR(x)			((x) << 12)
#define RTC_ALARM_MINUTE(x)			((x) << 6)
#define RTC_ALARM_SECOND(x)			((x) << 0)

	/* 0x1C: Alarm n Mask - MODE2 */
	uint32_t volatile MASK;
#define RTC_MASK_SEL(x)				((x) << 0)

};
