#include <stddef.h>
#include <stdint.h>
#include <binary.h>

#define ADC ((struct zmcu_adc *)0x42002000)

struct zmcu_adc {

	/* 0x00: Control A */
	uint8_t volatile CTRLA;
#define ADC_CTRLA_RUNSTDBY			(1u << 2)
#define ADC_CTRLA_ENABLE			(1u << 1)
#define ADC_CTRLA_SWRST				(1u << 0)

	/* 0x01: Reference Control */
	uint8_t volatile REFCTRL;
#define ADC_REFCTRL_REFCOMP			(1u << 7)
#define ADC_REFCTRL_REFSEL(x)			((x) << 0)
#define ADC_REFCTRL_REFSEL_MASK			ADC_REFCTRL_REFSEL(B00001111)

	/* 0x02: Average Control */
	uint8_t volatile AVGCTRL;
#define ADC_AVGCTRL_ADJRES(x)			((x) << 4)
#define ADC_AVGCTRL_ADJRES_MASK			ADC_AVGCTRL_ADJRES(B00000111)
#define ADC_AVGCTRL_SAMPLENUM(x)		((x) << 0)
#define ADC_AVGCTRL_SAMPLENUM_MASK		ADC_AVGCTRL_SAMPLENUM(B00001111)

	/* 0x03: Sampling Time Control */
	uint8_t volatile SAMPCTRL;
#define ADC_SAMPCTRL_SAMPLEN(x)			((x) << 0)
#define ADC_SAMPCTRL_SAMPLEN_MASK		ADC_SAMPCTRL_SAMPLEN(B00111111)

	/* 0x04: Control B */
	uint16_t volatile CTRLB;
#define ADC_CTRLB_PRESCALER(x)			((x) << 8)
#define ADC_CTRLB_PRESCALER_MASK		ADC_CTRLB_PRESCALER(B00000111)
#define ADC_CTRLB_RESSEL(x)			((x) << 4)
#define ADC_CTRLB_RESSEL_MASK			ADC_CTRLB_RESSEL(B00000011)
#define ADC_CTRLB_CORREN			(1u << 3)
#define ADC_CTRLB_FREERUN			(1u << 2)
#define ADC_CTRLB_LEFTADJ			(1u << 1)
#define ADC_CTRLB_DIFFMODE			(1u << 0)

	/* 0x06 */
	uint8_t volatile RESERVED0[0x08-0x06];

	/* 0x08: Window Monitor Control */
	uint8_t volatile WINCTRL;
#define ADC_WINCTRL_WINMODE(x)			((x) << 0)
#define ADC_WINCTRL_WINMODE_MASK		ADC_WINCTRL_WINMODE(B00000111)

	/* 0x09 */
	uint8_t volatile RESERVED1[0x0C-0x09];

	/* 0x0C: Software Trigger */
	uint8_t volatile SWTRIG;
#define ADC_SWTRIG_START			(1u << 1)
#define ADC_SWTRIG_FLUSH			(1u << 0)

	/* 0x0D */
	uint8_t volatile RESERVED2[0x10-0x0D];

	/* 0x10: Input Control */
	uint32_t volatile INPUTCTRL;
#define ADC_INPUTCTRL_GAIN(x)			((x) << 24)
#define ADC_INPUTCTRL_GAIN_MASK			ADC_INPUTCTRL_GAIN(B00001111)
#define ADC_INPUTCTRL_INPUTOFFSET(x)		((x) << 20)
#define ADC_INPUTCTRL_INPUTOFFSET_MASK		ADC_INPUTCTRL_INPUTOFFSET(B00001111)
#define ADC_INPUTCTRL_INPUTSCAN(x)		((x) << 16)
#define ADC_INPUTCTRL_INPUTSCAN_MASK		ADC_INPUTCTRL_INPUTSCAN(B00001111)
#define ADC_INPUTCTRL_MUXNEG(x)			((x) << 8)
#define ADC_INPUTCTRL_MUXNEG_MASK		ADC_INPUTCTRL_MUXNEG(B00011111)
#define ADC_INPUTCTRL_MUXPOS(x)			((x) << 0)
#define ADC_INPUTCTRL_MUXPOS_MASK		ADC_INPUTCTRL_MUXPOS(B00011111)

	/* 0x14: Event Control */
	uint8_t volatile EVCTRL;
#define ADC_EVCTRL_WINMONEO			(1u << 5)
#define ADC_EVCTRL_RESRDYEO			(1u << 4)
#define ADC_EVCTRL_SYNCEI			(1u << 1)
#define ADC_EVCTRL_STARTEI			(1u << 0)

	/* 0x15 */
	uint8_t volatile RESERVED3[0x16-0x15];

	/* 0x16: Interrupt Enable Clear */
	uint8_t volatile INTENCLR;
#define ADC_INTENCLR_SYNCRDY			(1u << 3)
#define ADC_INTENCLR_WINMON			(1u << 2)
#define ADC_INTENCLR_OVERRUN			(1u << 1)
#define ADC_INTENCLR_RESRDY			(1u << 0)

	/* 0x17: Interrupt Enable Set */
	uint8_t volatile INTENSET;
#define ADC_INTENSET_SYNCRDY			(1u << 3)
#define ADC_INTENSET_WINMON			(1u << 2)
#define ADC_INTENSET_OVERRUN			(1u << 1)
#define ADC_INTENSET_RESRDY			(1u << 0)

	/* 0x18: Interrupt Flag Status and Clear */
	uint8_t volatile INTFLAG;
#define ADC_INTFLAG_SYNCRDY			(1u << 3)
#define ADC_INTFLAG_WINMON			(1u << 2)
#define ADC_INTFLAG_OVERRUN			(1u << 1)
#define ADC_INTFLAG_RESRDY			(1u << 0)

	/* 0x19: Status */
	uint8_t volatile STATUS;
#define ADC_STATUS_SYNCBUSY			(1u << 7)

	/* 0x1A: Result */
	uint16_t volatile RESULT;
#define ADC_RESULT_RESULT(x)			((x) << 0)

	/* 0x1C: Window Monitor Lower Threshold */
	uint16_t volatile WINLT;
#define ADC_WINLT_WINLT(x)			((x) << 0)

	/* 0x1E */
	uint8_t volatile RESERVED4[0x20-0x1E];

	/* 0x20: Window Monitor Upper Threshold */
	uint16_t volatile WINUT;
#define ADC_WINUT_WINUT(x)			((x) << 0)

	/* 0x22 */
	uint8_t volatile RESERVED5[0x24-0x22];

	/* 0x24: Gain Correction */
	uint16_t volatile GAINCORR;
#define ADC_GAINCORR_GAINCORR(x)		((x) << 0)

	/* 0x26: Offset Correction */
	uint16_t volatile OFFSETCORR;
#define ADC_OFFSETCORR_OFFSETCORR(x)		((x) << 0)

	/* 0x28: Calibration */
	uint16_t volatile CALIB;
#define ADC_CALIB_BIAS_CAL(x)			((x) << 8)
#define ADC_CALIB_BIAS_CAL_MASK			ADC_CALIB_BIAS_CAL(B00000111)
#define ADC_CALIB_LINEARITY_CAL(x)		((x) << 0)
#define ADC_CALIB_LINEARITY_CAL_MASK		ADC_CALIB_LINEARITY_CAL(B11111111)

	/* 0x2A: Debug Control */
	uint8_t volatile DBGCTRL;
#define ADC_DBGCTRL_DBGRUN			(1u << 0)

};
