#include <stddef.h>
#include <stdint.h>
#include <binary.h>

#define I2C0S ((struct zmcu_i2c_slave *)SERCOM0_BASE)
#define I2C0M ((struct zmcu_i2c_master *)SERCOM0_BASE)
#define I2C1S ((struct zmcu_i2c_slave *)SERCOM1_BASE)
#define I2C1M ((struct zmcu_i2c_master *)SERCOM1_BASE)

struct zmcu_i2c_slave {

	/* 0x00: Control A */
	uint32_t volatile CTRLA;
#define I2CS_CTRLA_LOWTOUT			(1u << 30)
#define I2CS_CTRLA_SPEED(x)			((x) << 24)
#define I2CS_CTRLA_SPEED_MASK			I2CS_CTRLA_SPEED(B00000011)
#define I2CS_CTRLA_SEXTTOEN			(1u << 23)
#define I2CS_CTRLA_SDAHOLD(x)			((x) << 20)
#define I2CS_CTRLA_SDAHOLD_MASK			I2CS_CTRLA_SDAHOLD(B00000011)
#define I2CS_CTRLA_PINOUT			(1u << 16)
#define I2CS_CTRLA_RUNSTDBY			(1u << 7)
#define I2CS_CTRLA_MODE(x)			((x) << 2)
#define I2CS_CTRLA_MODE_MASK			I2CS_CTRLA_MODE(B00000111)
#define I2CS_CTRLA_ENABLE			(1u << 1)
#define I2CS_CTRLA_SWRST				(1u << 0)

	/* 0x04: Control B */
	uint32_t volatile CTRLB;
#define I2CS_CTRLB_ACKACT			(1u << 18)
#define I2CS_CTRLB_CMD(x)			((x) << 16)
#define I2CS_CTRLB_CMD_MASK			I2CS_CTRLB_CMD(B00000011)
#define I2CS_CTRLB_AMODE(x)			((x) << 14)
#define I2CS_CTRLB_AMODE_MASK			I2CS_CTRLB_AMODE(B00000011)
#define I2CS_CTRLB_GCMD				(1u << 9)
#define I2CS_CTRLB_SMEN				(1u << 8)

	/* 0x08 */
	uint8_t volatile RESERVED0[0x14-0x08];

	/* 0x14: */
	uint8_t volatile INTENCLR;
#define I2CS_INTENCLR_DRDY			(1u << 2)
#define I2CS_INTENCLR_AMATCH			(1u << 1)
#define I2CS_INTENCLR_PREC			(1u << 0)

	/* 0x15 */
	uint8_t volatile RESERVED1[0x16-0x15];

	/* 0x16: */
	uint8_t volatile INTENSET;
#define I2CS_INTENSET_ERROR			(1u << 7)
#define I2CS_INTENSET_DRDY			(1u << 2)
#define I2CS_INTENSET_AMATCH			(1u << 1)
#define I2CS_INTENSET_PREC			(1u << 0)

	/* 0x17 */
	uint8_t volatile RESERVED2[0x18-0x17];

	/* 0x18: Interrupt Flag Status and Clear */
	uint8_t volatile INTFLAG;
#define I2CS_INTFLAG_DRDY			(1u << 2)
#define I2CS_INTFLAG_AMATCH			(1u << 1)
#define I2CS_INTFLAG_PREC			(1u << 0)

	/* 0x19 */
	uint8_t volatile RESERVED3[0x1A-0x19];

	/* 0x1A: Status */
	uint8_t volatile STATUS;
#define I2CS_STATUS_HS				(1u << 10)
#define I2CS_STATUS_SEXTTOUT			(1u << 9)
#define I2CS_STATUS_CLKHOLD			(1u << 7)
#define I2CS_STATUS_LOWTOUT			(1u << 6)
#define I2CS_STATUS_SR				(1u << 4)
#define I2CS_STATUS_DIR				(1u << 3)
#define I2CS_STATUS_RXNACK			(1u << 2)
#define I2CS_STATUS_COLL				(1u << 1)
#define I2CS_STATUS_BUSERR			(1u << 0)

	/* 0x1B */
	uint8_t volatile RESERVED4[0x1C-0x1B];

	/* 0x1C: Synchronization Busy */
	uint32_t volatile SYNCBUSY;
#define I2CS_SYNCBUSY_ENABLE			(1u << 1)
#define I2CS_SYNCBUSY_SWRST			(1u << 0)

	/* 0x20 */
	uint8_t volatile RESERVED5[0x24-0x20];

	/* 0x24: Address */
	uint16_t volatile ADDR;
#define I2CS_ADDR_ADDRMASK(x)			((x) << 17)
#define I2CS_ADDR_ADDR(x)			((x) << 1)
#define I2CS_ADDR_GENCEN				(1u << 0)

	/* 0x26 */
	uint8_t volatile RESERVED6[0x28-0x26];

	/* 0x28: Data */
	uint16_t volatile DATA;
#define I2CS_DATA_DATA(x)			((x) << 0)
#define I2CS_DATA_DATA_MASK			I2CS_DATA_DATA(B11111111)

};

struct zmcu_i2c_master {

	/* 0x00: Control A */
	uint32_t volatile CTRLA;
#define I2CM_CTRLA_LOWTOUT			(1u << 30)
#define I2CM_CTRLA_INACTOUT(x)			((x) << 28)
#define I2CM_CTRLA_INACTOUT_MASK			I2CM_CTRLA_INACTOUT(B00000011)
#define I2CM_CTRLA_SPEED(x)			((x) << 24)
#define I2CM_CTRLA_SPEED_MASK			I2CM_CTRLA_SPEED(B00000011)
#define I2CM_CTRLA_SEXTTOEN			(1u << 23)
#define I2CM_CTRLA_MEXTTOEN			(1u << 22)
#define I2CM_CTRLA_SDAHOLD(x)			((x) << 20)
#define I2CM_CTRLA_SDAHOLD_MASK			I2CM_CTRLA_SDAHOLD(B00000011)
#define I2CM_CTRLA_PINOUT			(1u << 16)
#define I2CM_CTRLA_RUNSTDBY			(1u << 7)
#define I2CM_CTRLA_MODE(x)			((x) << 2)
#define I2CM_CTRLA_MODE_MASK			I2CM_CTRLA_MODE(B00000111)
#define I2CM_CTRLA_ENABLE			(1u << 1)
#define I2CM_CTRLA_SWRST				(1u << 0)

	/* 0x04: Control B */
	uint32_t volatile CTRLB;
#define I2CM_CTRLB_ACKACT			(1u << 18)
#define I2CM_CTRLB_CMD(x)			((x) << 16)
#define I2CM_CTRLB_CMD_MASK			I2CM_CTRLB_CMD(B00000011)
#define I2CM_CTRLB_QCEN				(1u << 9)
#define I2CM_CTRLB_SMEN				(1u << 8)

	/* 0x08 */
	uint8_t volatile RESERVED0[0x0C-0x08];

	/* 0x0C: Baud Rate */
	uint32_t volatile BAUD;
#define I2CM_BAUD_HSBAUDLOW(x)			((x) << 24)
#define I2CM_BAUD_HSBAUDLOW_MASK			I2CM_BAUD_HSBAUDLOW(B11111111)
#define I2CM_BAUD_HSBAUD(x)			((x) << 16)
#define I2CM_BAUD_HSBAUD_MASK			I2CM_BAUD_HSBAUD(B11111111)
#define I2CM_BAUD_BAUDLOW(x)			((x) << 8)
#define I2CM_BAUD_BAUDLOW_MASK			I2CM_BAUD_BAUDLOW(B11111111)
#define I2CM_BAUD_BAUD(x)			((x) << 0)
#define I2CM_BAUD_BAUD_MASK			I2CM_BAUD_BAUD(B11111111)

	/* 0x10 */
	uint8_t volatile RESERVED1[0x14-0x10];

	/* 0x14: */
	uint8_t volatile INTENCLR;
#define I2CM_INTENCLR_SB				(1u << 1)
#define I2CM_INTENCLR_MB				(1u << 0)

	/* 0x15 */
	uint8_t volatile RESERVED2[0x16-0x15];

	/* 0x16: */
	uint8_t volatile INTENSET;
#define I2CM_INTENSET_ERROR			(1u << 7)
#define I2CM_INTENSET_SB				(1u << 1)
#define I2CM_INTENSET_MB				(1u << 0)

	/* 0x17 */
	uint8_t volatile RESERVED3[0x18-0x17];

	/* 0x18: Interrupt Flag Status and Clear */
	uint8_t volatile INTFLAG;
#define I2CM_INTFLAG_SB				(1u << 1)
#define I2CM_INTFLAG_MB				(1u << 0)

	/* 0x19 */
	uint8_t volatile RESERVED4[0x1A-0x19];

	/* 0x1A: Status */
	uint8_t volatile STATUS;
#define I2CM_STATUS_LENERR			(1u << 10)
#define I2CM_STATUS_SEXTTOUT			(1u << 9)
#define I2CM_STATUS_MEXTTOUT			(1u << 8)
#define I2CM_STATUS_CLKHOLD			(1u << 7)
#define I2CM_STATUS_LOWTOUT			(1u << 6)
#define I2CM_STATUS_BUSSTATE(x)			((x) << 4)
#define I2CM_STATUS_BUSSTATE_MASK		I2CM_STATUS_BUSSTATE(B00000011)
#define I2CM_STATUS_RXNACK			(1u << 2)
#define I2CM_STATUS_ARBLOST			(1u << 1)
#define I2CM_STATUS_BUSERR			(1u << 0)

	/* 0x1B */
	uint8_t volatile RESERVED5[0x1C-0x1B];

	/* 0x1C: Syncbusy */
	uint32_t volatile SYNCBUSY;
#define I2CM_SYNCBUSY_ENABLE			(1u << 1)
#define I2CM_SYNCBUSY_SWRST			(1u << 0)

	/* 0x20 */
	uint8_t volatile RESERVED6[0x24-0x20];

	/* 0x24: Address */
	uint16_t volatile ADDR;
#define I2CM_ADDR_LEN(x)				((x) << 16)
#define I2CM_ADDR_LEN_MASK			I2CM_ADDR_LEN(B11111111)
#define I2CM_ADDR_TENBITEN			(1u << 15)
#define I2CM_ADDR_HS				(1u << 14)
#define I2CM_ADDR_LENEN				(1u << 13)
#define I2CM_ADDR_ADDR(x)			((x) << 0)
#define I2CM_ADDR_LEN(x)				((x) << 16)
#define I2CM_ADDR_LEN_MASK			I2CM_ADDR_LEN(B11111111)
#define I2CM_ADDR_TENBITEN			(1u << 15)
#define I2CM_ADDR_HS				(1u << 14)
#define I2CM_ADDR_LENEN				(1u << 13)
#define I2CM_ADDR_ADDR(x)			((x) << 0)

	/* 0x18: Data */
	uint16_t volatile DATA;
#define I2CM_DATA_DATA(x)			((x) << 0)
#define I2CM_DATA_DATA_MASK			I2CM_DATA_DATA(B11111111)

	/* 0x1A */
	uint8_t volatile RESERVED7[0x30-0x1A];

	/* 0x30: Debug Control */
	uint8_t volatile DBGCTRL;
#define I2CM_DBGCTRL_DBGSTOP			(1u << 0)

};
