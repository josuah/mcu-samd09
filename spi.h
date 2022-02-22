#include <stddef.h>
#include <stdint.h>
#include <binary.h>

#define SPI0 ((struct zmcu_spi *)SERCOM0_BASE)
#define SPI1 ((struct zmcu_spi *)SERCOM1_BASE)

struct zmcu_spi {

	/* 0x00: Control A */
	uint32_t volatile CTRLA;
#define SPI_CTRLA_DORD				(1u << 30)
#define SPI_CTRLA_CPOL				(1u << 29)
#define SPI_CTRLA_CPHA				(1u << 28)
#define SPI_CTRLA_FORM(x)			((x) << 24)
#define SPI_CTRLA_FORM_MASK			SPI_CTRLA_FORM(B00001111)
#define SPI_CTRLA_DIPO(x)			((x) << 20)
#define SPI_CTRLA_DIPO_MASK			SPI_CTRLA_DIPO(B00000011)
#define SPI_CTRLA_DOPO(x)			((x) << 16)
#define SPI_CTRLA_DOPO_MASK			SPI_CTRLA_DOPO(B00000011)
#define SPI_CTRLA_IBON				(1u << 8)
#define SPI_CTRLA_RUNSTDBY			(1u << 7)
#define SPI_CTRLA_MODE(x)			((x) << 2)
#define SPI_CTRLA_MODE_MASK			SPI_CTRLA_MODE(B00000111)
#define SPI_CTRLA_ENABLE			(1u << 1)
#define SPI_CTRLA_SWRST				(1u << 0)

	/* 0x04: Control B */
	uint32_t volatile CTRLB;
#define SPI_CTRLB_RXEN				(1u << 17)
#define SPI_CTRLB_AMODE(x)			((x) << 14)
#define SPI_CTRLB_AMODE_MASK			SPI_CTRLB_AMODE(B00000011)
#define SPI_CTRLB_MSSEN				(1u << 13)
#define SPI_CTRLB_SSDE				(1u << 9)
#define SPI_CTRLB_PLOADEN			(1u << 6)
#define SPI_CTRLB_CHSIZE(x)			((x) << 0)
#define SPI_CTRLB_CHSIZE_MASK			SPI_CTRLB_CHSIZE(B00000111)

	/* 0x08 */
	uint8_t volatile RESERVED0[0x0C-0x08];

	/* 0x0C: Baud Rate */
	uint8_t volatile BAUD;
#define SPI_BAUD_BAUD(x)			((x) << 0)
#define SPI_BAUD_BAUD_MASK			SPI_BAUD_BAUD(B11111111)

	/* 0x0D */
	uint8_t volatile RESERVED1[0x14-0x0D];

	/* 0x14: */
	uint8_t volatile INTENCLR;
#define SPI_INTENCLR_RXC			(1u << 2)
#define SPI_INTENCLR_TXC			(1u << 1)
#define SPI_INTENCLR_DRE			(1u << 0)

	/* 0x15 */
	uint8_t volatile RESERVED2[0x16-0x15];

	/* 0x16: */
	uint8_t volatile INTENSET;
#define SPI_INTENSET_ERROR			(1u << 7)
#define SPI_INTENSET_SSL			(1u << 3)
#define SPI_INTENSET_RXC			(1u << 2)
#define SPI_INTENSET_TXC			(1u << 1)
#define SPI_INTENSET_DRE			(1u << 0)

	/* 0x17 */
	uint8_t volatile RESERVED3[0x18-0x17];

	/* 0x18: Interrupt Flag Status and Clear */
	uint8_t volatile INTFLAG;
#define SPI_INTFLAG_ERROR			(1u << 7)
#define SPI_INTFLAG_SSL				(1u << 3)
#define SPI_INTFLAG_RXC				(1u << 2)
#define SPI_INTFLAG_TXC				(1u << 1)
#define SPI_INTFLAG_DRE				(1u << 0)

	/* 0x19 */
	uint8_t volatile RESERVED4[0x1A-0x19];

	/* 0x1A: Status */
	uint16_t volatile STATUS;
#define SPI_STATUS_BUFOVF			(1u << 2)

	/* 0x1C: Synchronization Busy */
	uint32_t volatile SYNCBUSY;
#define SPI_SYNCBUSY_ENABLE			(1u << 1)
#define SPI_SYNCBUSY_SWRST			(1u << 0)

	/* 0x20 */
	uint8_t volatile RESERVED5[0x24-0x20];

	/* 0x24: Address */
	uint32_t volatile ADDR;
#define SPI_ADDR_ADDRMASK(x)			((x) << 16)
#define SPI_ADDR_ADDRMASK_MASK			SPI_ADDR_ADDRMASK(B11111111)
#define SPI_ADDR_ADDR(x)			((x) << 0)
#define SPI_ADDR_ADDR_MASK			SPI_ADDR_ADDR(B11111111)

	/* 0x28: Data */
	uint16_t volatile DATA;
#define SPI_DATA_DATA(x)			((x) << 0)

	/* 0x2A */
	uint8_t volatile RESERVED6[0x30-0x2A];

	/* 0x30: Debug Control */
	uint8_t volatile DBGCTRL;
#define SPI_DBGCTRL_DBGSTOP			(1u << 0)

};
