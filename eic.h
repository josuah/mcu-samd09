#include <stddef.h>
#include <stdint.h>
#include <binary.h>

#define EIC ((struct zmcu_eic *)0x40001800)

struct zmcu_eic {

	/* 0x00: Control */
	uint8_t volatile CTRL;
#define EIC_CTRL_ENABLE				(1u << 1)
#define EIC_CTRL_SWRST				(1u << 0)

	/* 0x01: Status */
	uint8_t volatile STATUS;
#define EIC_STATUS_SYNCBUSY			(1u << 7)

	/* 0x02: Non-Maskable Interrupt Control */
	uint8_t volatile NMICTRL;
#define EIC_NMICTRL_NMIFILTEN			(1u << 3)
#define EIC_NMICTRL_NMISENSE(x)			((x) << 0)
#define EIC_NMICTRL_NMISENSE_MASK		EIC_NMICTRL_NMISENSE(B00000111)

	/* 0x03: Non-Maskable Interrupt Flag Status and Clear */
	uint8_t volatile NMIFLAG;
#define EIC_NMIFLAG_NMI				(1u << 0)

	/* 0x04: Event Control */
	uint32_t volatile EVCTRL;
#define EIC_EVCTRL_EXTINTEOx(x)			((x) << 0)
#define EIC_EVCTRL_EXTINTEOx_MASK		EIC_EVCTRL_EXTINTEOx(B11111111)

	/* 0x08: Interrupt Enable Clear */
	uint32_t volatile INTENCLR;
#define EIC_INTENCLR_EXTINTx(x)			((x) << 0)
#define EIC_INTENCLR_EXTINTx_MASK		EIC_INTENCLR_EXTINTx(B11111111)

	/* 0x0C: Interrupt Enable Set */
	uint32_t volatile INTENSET;
#define EIC_INTENSET_EXTINTx(x)			((x) << 0)
#define EIC_INTENSET_EXTINTx_MASK		EIC_INTENSET_EXTINTx(B11111111)

	/* 0x10: Interrupt Flag Status and Clear */
	uint32_t volatile INTFLAG;
#define EIC_INTFLAG_EXTINTx(x)			((x) << 0)
#define EIC_INTFLAG_EXTINTx_MASK		EIC_INTFLAG_EXTINTx(B11111111)

	/* 0x14: Wake-Up Enable */
	uint32_t volatile WAKEUP;
#define EIC_WAKEUP_WAKEUPENx(x)			((x) << 0)
#define EIC_WAKEUP_WAKEUPENx_MASK		EIC_WAKEUP_WAKEUPENx(B11111111)

	/* 0x18: Configuration n */
	uint32_t volatile CONFIG;

};
