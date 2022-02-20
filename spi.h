#include <stddef.h>
#include <stdint.h>
#include <binary.h>

#define SPI0 ((struct zmcu_spi *)SERCOM0_BASE)
#define SPI1 ((struct zmcu_spi *)SERCOM1_BASE)
#define SPI2 ((struct zmcu_spi *)SERCOM2_BASE)

struct zmcu_spi {

	/* 0x00: Control A */
	uint32_t volatile CTRLA;
#define SPI_CTRLA_DORD				(1u << 30)
#define SPI_CTRLA_CPOL				(1u << 29)
#define SPI_CTRLA_CPHA				(1u << 28)
#define SPI_CTRLA_FORM(x)			((x) << 24)
#define SPI_CTRLA_DIPO(x)			((x) << 20)
#define SPI_CTRLA_DOPO(x)			((x) << 16)
#define SPI_CTRLA_IBON				(1u << 8)
#define SPI_CTRLA_RUNSTDBY			(1u << 7)
#define SPI_CTRLA_MODE(x)			((x) << 2)
#define SPI_CTRLA_ENABLE			(1u << 1)
#define SPI_CTRLA_SWRST				(1u << 0)

	/* 0x04: Control B */
	uint32_t volatile CTRLB;
#define SPI_CTRLB_RXEN				(1u << 17)
#define SPI_CTRLB_AMODE(x)			((x) << 14)
#define SPI_CTRLB_MSSEN				(1u << 13)
#define SPI_CTRLB_SSDE				(1u << 9)
#define SPI_CTRLB_PLOADEN			(1u << 6)
#define SPI_CTRLB_CHSIZE(x)			((x) << 0)

	/* 0x08 */
	uint8_t volatile RESERVED18[0x0C-0x08];

	/* 0x0C: Baud Rate */
	uint32_t volatile BAUD;
#define SPI_BAUD_BAUD(x)			((x) << 0)

	/* 0x10 */
	uint8_t volatile RESERVED19[0x14-0x10];

	/* 0x14: */
	uint16_t volatile INTENCLR;
#define SPI_INTENCLR_RXC			(1u << 2)
#define SPI_INTENCLR_TXC			(1u << 1)
#define SPI_INTENCLR_DRE			(1u << 0)

	/* 0x16: */
	uint16_t volatile INTENSET;
#define SPI_INTENSET_ERROR			(1u << 7)
#define SPI_INTENSET_SSL			(1u << 3)
#define SPI_INTENSET_RXC			(1u << 2)
#define SPI_INTENSET_TXC			(1u << 1)
#define SPI_INTENSET_DRE			(1u << 0)

	/* 0x18: Interrupt Flag Status and Clear */
	uint16_t volatile INTFLAG;
#define SPI_INTFLAG_ERROR			(1u << 7)
#define SPI_INTFLAG_SSL				(1u << 3)
#define SPI_INTFLAG_RXC				(1u << 2)
#define SPI_INTFLAG_TXC				(1u << 1)
#define SPI_INTFLAG_DRE				(1u << 0)

	/* 0x1A: Status */
	uint16_t volatile STATUS;
#define SPI_STATUS_BUFOVF			(1u << 2)

	/* 0x1C: Synchronization Busy */
	uint32_t volatile SYNCBUSY;
#define SPI_SYNCBUSY_ENABLE			(1u << 1)
#define SPI_SYNCBUSY_SWRST			(1u << 0)

	/* 0x20 */
	uint8_t volatile RESERVED20[0x24-0x20];

	/* 0x24: Address */
	uint32_t volatile ADDR;
#define SPI_ADDR_ADDRMASK(x)			((x) << 16)
#define SPI_ADDR_ADDR(x)			((x) << 0)

	/* 0x16: Data */
	uint32_t volatile DATA;
#define SPI_DATA_DATA(x)			((x) << 0)

	/* 0x2A */
	uint8_t volatile RESERVED21[0x30-0x2A];

	/* 0x30: Debug Control */
	uint32_t volatile DBGCTRL;
#define SPI_DBGCTRL_DBGSTOP			(1u << 0)

};
