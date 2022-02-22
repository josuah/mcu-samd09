#include <stddef.h>
#include <stdint.h>
#include <binary.h>

#define RTC ((struct zmcu_rtc *)0x40001400)

struct zmcu_rtc {

	/* 0x00: Control */
	uint16_t volatile CTRL;
#define RTC_CTRL_PRESCALER(x)			((x) << 8)
#define RTC_CTRL_PRESCALER_MASK			RTC_CTRL_PRESCALER(B00001111)
#define RTC_CTRL_MATCHCLR			(1u << 7)
#define RTC_CTRL_CLKREP				(1u << 6)
#define RTC_CTRL_MODE(x)			((x) << 2)
#define RTC_CTRL_MODE_MASK			RTC_CTRL_MODE(B00000011)
#define RTC_CTRL_ENABLE				(1u << 1)
#define RTC_CTRL_SWRST				(1u << 0)

	/* 0x02: Read Request */
	uint16_t volatile READREQ;
#define RTC_READREQ_RREQ			(1u << 15)
#define RTC_READREQ_RCONT			(1u << 14)
#define RTC_READREQ_ADDR(x)			((x) << 0)
#define RTC_READREQ_ADDR_MASK			RTC_READREQ_ADDR(B00111111)
#define RTC_CTRL_PRESCALER_MASK			RTC_CTRL_PRESCALER(B00001111)

	/* 0x04: Event Control */
	uint16_t volatile EVCTRL;
#define RTC_EVCTRL_OVFEO			(1u << 15)
#define RTC_EVCTRL_OVFEO			(1u << 15)
#define RTC_EVCTRL_OVFEO			(1u << 15)
#define RTC_EVCTRL_CMPEO			(1u << 8)
#define RTC_EVCTRL_ALARMEO			(1u << 8)
#define RTC_EVCTRL_CMPEOx(x)			((x) << 8)
#define RTC_EVCTRL_PEREOx(x)			((x) << 0)
#define RTC_EVCTRL_PEREOx_MASK			RTC_EVCTRL_PEREOx(B11111111)

	/* 0x06: Interrupt Enable Clear */
	uint8_t volatile INTENCLR;
#define RTC_INTENCLR_OVF			(1u << 7)
#define RTC_INTENCLR_SYNCRDY			(1u << 6)
#define RTC_INTENCLR_CMP			(1u << 0)
#define RTC_INTENCLR_CMPx(x)			((x) << 0)
#define RTC_INTENCLR_CMPx_MASK			RTC_INTENCLR_CMPx(B00000011)
#define RTC_INTENCLR_ALARM			(1u << 0)

	/* 0x07: Interrupt Enable Set */
	uint8_t volatile INTENSET;
#define RTC_INTENSET_OVF			(1u << 7)
#define RTC_INTENSET_SYNCRDY			(1u << 6)
#define RTC_INTENSET_CMP			(1u << 0)
#define RTC_INTENSET_CMPx(x)			((x) << 0)
#define RTC_INTENSET_CMPx_MASK			RTC_INTENSET_CMPx(B00000011)
#define RTC_INTENSET_ALARM			(1u << 0)

	/* 0x08: Interrupt Flag Status and Clear */
	uint8_t volatile INTFLAG;
#define RTC_INTFLAG_OVF				(1u << 7)
#define RTC_INTFLAG_SYNCRDY			(1u << 6)
#define RTC_INTFLAG_CMP				(1u << 0)
#define RTC_INTFLAG_CMPx(x)			((x) << 0)
#define RTC_INTFLAG_CMPx_MASK			RTC_INTFLAG_CMPx(B00000011)
#define RTC_INTFLAG_ALARM			(1u << 0)

	/* 0x09 */
	uint8_t volatile RESERVED[0x0A-0x09];

	/* 0x0A: Status */
	uint8_t volatile STATUS;
#define RTC_STATUS_SYNCBUSY			(1u << 7)

	/* 0x0B: Debug Control */
	uint8_t volatile DBGCTRL;
#define RTC_DBGCTRL_DBGRUN			(1u << 0)

	/* 0x0C: Frequency Correction */
	uint8_t volatile FREQCORR;
#define RTC_FREQCORR_SIGN			(1u << 7)
#define RTC_FREQCORR_VALUE(x)			((x) << 0)
#define RTC_FREQCORR_VALUE_MASK			RTC_FREQCORR_VALUE(B01111111)

	/* 0x10 */
	uint8_t volatile RESERVED1[0x10-0x0D];

	union {
		struct {
			/* 0x10: Counter Value */
			uint32_t volatile COUNT;
#define RTC_COUNT_COUNT(x)			((x) << 0)

			/* 0x14 */
			uint8_t volatile RESERVED0[0x18-0x14];

			/* 0x18: Compare n Value */
			uint32_t volatile COMP;
#define RTC_COMP_COMP(x)			((x) << 0)

		} MODE0;

		struct {

			/* 0x10: Counter Value */
			uint32_t volatile COUNT;
#define RTC_COUNT_COUNT(x)			((x) << 0)

			/* 0x14: Counter Period */
			uint32_t volatile PER;
#define RTC_PER_PER(x)				((x) << 0)

			/* 0x18: Compare n Value */
			uint16_t volatile COMP[2];
#define RTC_COMPn_COMP(x)			((x) << 0)

		} MODE1;

		struct {

			/* 0x10: Clock Value */
			uint32_t volatile CLOCK;
#define RTC_CLOCK_YEAR(x)			((x) << 26)
#define RTC_CLOCK_YEAR_MASK			RTC_CLOCK_YEAR(B00111111)
#define RTC_CLOCK_MONTH(x)			((x) << 22)
#define RTC_CLOCK_MONTH_MASK			RTC_CLOCK_MONTH(B00001111)
#define RTC_CLOCK_DAY(x)			((x) << 17)
#define RTC_CLOCK_DAY_MASK			RTC_CLOCK_DAY(B00011111)
#define RTC_CLOCK_HOUR(x)			((x) << 12)
#define RTC_CLOCK_HOUR_MASK			RTC_CLOCK_HOUR(B00011111)
#define RTC_CLOCK_MINUTE(x)			((x) << 6)
#define RTC_CLOCK_MINUTE_MASK			RTC_CLOCK_MINUTE(B00111111)
#define RTC_CLOCK_SECOND(x)			((x) << 0)
#define RTC_CLOCK_SECOND_MASK			RTC_CLOCK_SECOND(B00111111)

			/* 0x14 */
			uint8_t volatile RESERVED0[0x18-0x14];

			/* 0x18: Alarm n Value */
			uint32_t volatile ALARM;
#define RTC_ALARM_YEAR(x)			((x) << 26)
#define RTC_ALARM_YEAR_MASK			RTC_ALARM_YEAR(B00111111)
#define RTC_ALARM_MONTH(x)			((x) << 22)
#define RTC_ALARM_MONTH_MASK			RTC_ALARM_MONTH(B00001111)
#define RTC_ALARM_DAY(x)			((x) << 17)
#define RTC_ALARM_DAY_MASK			RTC_ALARM_DAY(B00011111)
#define RTC_ALARM_HOUR(x)			((x) << 12)
#define RTC_ALARM_HOUR_MASK			RTC_ALARM_HOUR(B00011111)
#define RTC_ALARM_MINUTE(x)			((x) << 6)
#define RTC_ALARM_MINUTE_MASK			RTC_ALARM_MINUTE(B00111111)
#define RTC_ALARM_SECOND(x)			((x) << 0)
#define RTC_ALARM_SECOND_MASK			RTC_ALARM_SECOND(B00111111)

			/* 0x1C: Alarm n Mask */
			uint8_t volatile MASK;
#define RTC_MASK_SEL(x)				((x) << 0)
#define RTC_MASK_SEL_MASK			RTC_MASK_SEL(B00000111)

		} MODE2;
	};
};
