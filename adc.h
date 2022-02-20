#include <stddef.h>
#include <stdint.h>
#include <binary.h>

#define ADC ((struct zmcu_adc *)0x42002000)

struct zmcu_adc {

	/* 0x00: Control A */
	uint32_t volatile CTRLA;
#define ADC_CTRLA_RUNSTDBY			(1u << 2)
#define ADC_CTRLA_ENABLE			(1u << 1)
#define ADC_CTRLA_SWRST				(1u << 0)

	/* 0x01: Reference Control */
	uint32_t volatile REFCTRL;
#define ADC_REFCTRL_REFCOMP			(1u << 7)
#define ADC_REFCTRL_REFSEL(x)			((x) << 0)

	/* 0x02: Average Control */
	uint32_t volatile AVGCTRL;
#define ADC_AVGCTRL_ADJRES(x)			((x) << 4)
#define ADC_AVGCTRL_SAMPLENUM(x)		((x) << 0)

	/* 0x03: Sampling Time Control */
	uint32_t volatile SAMPCTRL;
#define ADC_SAMPCTRL_SAMPLEN(x)			((x) << 0)

	/* 0x04: Control B */
	uint32_t volatile CTRLB;
#define ADC_CTRLB_PRESCALER(x)			((x) << 8)
#define ADC_CTRLB_RESSEL(x)			((x) << 4)
#define ADC_CTRLB_CORREN			(1u << 3)
#define ADC_CTRLB_FREERUN			(1u << 2)
#define ADC_CTRLB_LEFTADJ			(1u << 1)
#define ADC_CTRLB_DIFFMODE			(1u << 0)

	/* 0x08: Window Monitor Control */
	uint32_t volatile WINCTRL;
#define ADC_WINCTRL_WINMODE(x)			((x) << 0)

	/* 0x0C: Software Trigger */
	uint32_t volatile SWTRIG;
#define ADC_SWTRIG_START			(1u << 1)
#define ADC_SWTRIG_FLUSH			(1u << 0)

	/* 0x10: Input Control */
	uint32_t volatile INPUTCTRL;
#define ADC_INPUTCTRL_GAIN(x)			((x) << 24)
#define ADC_INPUTCTRL_INPUTOFFSET(x)		((x) << 20)
#define ADC_INPUTCTRL_INPUTSCAN(x)		((x) << 16)
#define ADC_INPUTCTRL_MUXNEG(x)			((x) << 8)
#define ADC_INPUTCTRL_MUXPOS(x)			((x) << 0)

	/* 0x14: Event Control */
	uint32_t volatile EVCTRL;
#define ADC_EVCTRL_WINMONEO			(1u << 5)
#define ADC_EVCTRL_RESRDYEO			(1u << 4)
#define ADC_EVCTRL_SYNCEI			(1u << 1)
#define ADC_EVCTRL_STARTEI			(1u << 0)

	/* 0x16: Interrupt Enable Clear */
	uint32_t volatile INTENCLR;
#define ADC_INTENCLR_SYNCRDY			(1u << 3)
#define ADC_INTENCLR_WINMON			(1u << 2)
#define ADC_INTENCLR_OVERRUN			(1u << 1)
#define ADC_INTENCLR_RESRDY			(1u << 0)

	/* 0x17: Interrupt Enable Set */
	uint32_t volatile INTENSET;
#define ADC_INTENSET_SYNCRDY			(1u << 3)
#define ADC_INTENSET_WINMON			(1u << 2)
#define ADC_INTENSET_OVERRUN			(1u << 1)
#define ADC_INTENSET_RESRDY			(1u << 0)

	/* 0x18: Interrupt Flag Status and Clear */
	uint32_t volatile INTFLAG;
#define ADC_INTFLAG_SYNCRDY			(1u << 3)
#define ADC_INTFLAG_WINMON			(1u << 2)
#define ADC_INTFLAG_OVERRUN			(1u << 1)
#define ADC_INTFLAG_RESRDY			(1u << 0)

	/* 0x19: Status */
	uint32_t volatile STATUS;
#define ADC_STATUS_SYNCBUSY			(1u << 7)

	/* 0x1A: Result */
	uint32_t volatile RESULT;
#define ADC_RESULT_RESULT(x)			((x) << 0)

	/* 0x1C: Window Monitor Lower Threshold */
	uint32_t volatile WINLT;
#define ADC_WINLT_WINLT(x)			((x) << 0)

	/* 0x20: Window Monitor Upper Threshold */
	uint32_t volatile WINUT;
#define ADC_WINUT_WINUT(x)			((x) << 0)

	/* 0x24: Gain Correction */
	uint32_t volatile GAINCORR;
#define ADC_GAINCORR_GAINCORR(x)		((x) << 0)

	/* 0x26: Offset Correction */
	uint32_t volatile OFFSETCORR;
#define ADC_OFFSETCORR_OFFSETCORR(x)		((x) << 0)

	/* 0x28: Calibration */
	uint32_t volatile CALIB;
#define ADC_CALIB_BIAS_CAL(x)			((x) << 8)
#define ADC_CALIB_LINEARITY_CAL(x)		((x) << 0)

	/* 0x2A: Debug Control */
	uint32_t volatile DBGCTRL;
#define ADC_DBGCTRL_DBGRUN			(1u << 0)

};
