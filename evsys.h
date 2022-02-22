#include <stddef.h>
#include <stdint.h>
#include <binary.h>

struct zmcu_evsys {

	/* 0x00: Control */
	uint8_t volatile CTRL;
#define EVSYS_CTRL_GCLKREQ			(1u << 4)
#define EVSYS_CTRL_SWRST			(1u << 0)

	/* 0x01 */
	uint8_t volatile RESERVED0[0x04-0x01];

	/* 0x04: Channel */
	uint32_t volatile CHANNEL;
#define EVSYS_CHANNEL_EDGSEL(x)			((x) << 26)
#define EVSYS_CHANNEL_EDGSEL_MASK		EVSYS_CHANNEL_EDGSEL(B00000011)
#define EVSYS_CHANNEL_PATH(x)			((x) << 24)
#define EVSYS_CHANNEL_PATH_MASK			EVSYS_CHANNEL_PATH(B00000011)
#define EVSYS_CHANNEL_EVGEN(x)			((x) << 16)
#define EVSYS_CHANNEL_EVGEN_MASK		EVSYS_CHANNEL_EVGEN(B00111111)
#define EVSYS_CHANNEL_SWEVT			(1u << 8)
#define EVSYS_CHANNEL_CHANNEL(x)		((x) << 0)
#define EVSYS_CHANNEL_CHANNEL_MASK		EVSYS_CHANNEL_CHANNEL(B00000111)

	/* 0x08: User Multiplexer */
	uint16_t volatile USER;
#define EVSYS_USER_CHANNEL(x)			((x) << 8)
#define EVSYS_USER_CHANNEL_MASK			EVSYS_USER_CHANNEL(B00001111)
#define EVSYS_USER_USER(x)			((x) << 0)
#define EVSYS_USER_USER_MASK			EVSYS_USER_USER(B00011111)

	/* 0x0A */
	uint8_t volatile RESERVED1[0x0C-0x0A];

	/* 0x0C: Channel Status */
	uint32_t volatile CHSTATUS;
#define EVSYS_CHSTATUS_CHBUSYx(x)		((x) << 8)
#define EVSYS_CHSTATUS_CHBUSYx_MASK		EVSYS_CHSTATUS_CHBUSYx(B00111111)
#define EVSYS_CHSTATUS_USRRDYx(x)		((x) << 0)
#define EVSYS_CHSTATUS_USRRDYx_MASK		EVSYS_CHSTATUS_USRRDYx(B00111111)

	/* 0x10: Interrupt Enable Clear */
	uint32_t volatile INTENCLR;
#define EVSYS_INTENCLR_EVDx(x)			((x) << 8)
#define EVSYS_INTENCLR_EVDx_MASK		EVSYS_INTENCLR_EVDx(B00111111)
#define EVSYS_INTENCLR_OVRx(x)			((x) << 0)
#define EVSYS_INTENCLR_OVRx_MASK		EVSYS_INTENCLR_OVRx(B00111111)

	/* 0x14: Interrupt Enable Set */
	uint32_t volatile INTENSET;
#define EVSYS_INTENSET_EVDx(x)			((x) << 8)
#define EVSYS_INTENSET_EVDx_MASK		EVSYS_INTENSET_EVDx(B00111111)
#define EVSYS_INTENSET_OVRx(x)			((x) << 0)
#define EVSYS_INTENSET_OVRx_MASK		EVSYS_INTENSET_OVRx(B00111111)

	/* 0x18: Interrupt Flag Status and Clear */
	uint32_t volatile INTFLAG;
#define EVSYS_INTFLAG_EVDx(x)			((x) << 8)
#define EVSYS_INTFLAG_EVDx_MASK			EVSYS_INTFLAG_EVDx(B00111111)
#define EVSYS_INTFLAG_OVRx(x)			((x) << 0)
#define EVSYS_INTFLAG_OVRx_MASK			EVSYS_INTFLAG_OVRx(B00111111)

};
