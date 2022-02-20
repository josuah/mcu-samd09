#include <stddef.h>
#include <stdint.h>
#include <binary.h>

#define I2C0 ((struct zmcu_i2c *)SERCOM0_BASE)
#define I2C1 ((struct zmcu_i2c *)SERCOM1_BASE)
#define I2C2 ((struct zmcu_i2c *)SERCOM2_BASE)

struct zmcu_i2c {

	/* 0x00: Control A */
	uint32_t volatile CTRLA;
#define I2C_CTRLA_LOWTOUT			(1u << 30)
#define I2C_CTRLA_SPEED(x)			((x) << 24)
#define I2C_CTRLA_SEXTTOEN			(1u << 23)
#define I2C_CTRLA_SDAHOLD(x)			((x) << 20)
#define I2C__PINOUT				(1u << 16)
#define I2C__RUNSTDBY				(1u << 7)
#define I2C__MODE(x)				((x) << 2)
#define I2C__ENABLE				(1u << 1)
#define I2C__SWRST				(1u << 0)

	/* 0x04: Control B */
	uint32_t volatile CTRLB;
#define I2C_CTRLB_ACKACT			(1u << 18)
#define I2C_CTRLB_CMD(x)			((x) << 16)
#define I2C_CTRLB_AMODE(x)			((x) << 14)
#define I2C_CTRLB_GCMD				(1u << 9)
#define I2C_CTRLB_SMEN				(1u << 8)

	/* 0x08 */
	uint32_t volatile RESERVED22[(0x14-0x08)/4];

	/* 0x14: */
	uint32_t volatile INTENCLR;
#define I2C_INTENCLR_DRDY			(1u << 2)
#define I2C_INTENCLR_AMATCH			(1u << 1)
#define I2C_INTENCLR_PREC			(1u << 0)

	/* 0x16: */
	uint32_t volatile INTENSET;
#define I2C_INTENSET_ERROR			(1u << 7)
#define I2C_INTENSET_DRDY			(1u << 2)
#define I2C_INTENSET_AMATCH			(1u << 1)
#define I2C_INTENSET_PREC			(1u << 0)

	/* 0x18: Interrupt Flag Status and Clear */
	uint32_t volatile INTFLAG;
#define I2C_INTFLAG_DRDY			(1u << 2)
#define I2C_INTFLAG_AMATCH			(1u << 1)
#define I2C_INTFLAG_PREC			(1u << 0)

	/* 0x1A: Status */
	uint32_t volatile STATUS;
#define I2C_STATUS_HS				(1u << 10)
#define I2C_STATUS_SEXTTOUT			(1u << 9)
#define I2C_STATUS_CLKHOLD			(1u << 7)
#define I2C_STATUS_LOWTOUT			(1u << 6)
#define I2C_STATUS_SR				(1u << 4)
#define I2C_STATUS_DIR				(1u << 3)
#define I2C_STATUS_RXNACK			(1u << 2)
#define I2C_STATUS_COLL				(1u << 1)
#define I2C_STATUS_BUSERR			(1u << 0)

	/* 0x1C: Synchronization Busy */
	uint32_t volatile SYNCBUSY;
#define I2C_SYNCBUSY_ENABLE			(1u << 1)
#define I2C_SYNCBUSY_SWRST			(1u << 0)

	/* 0x20 */
	uint32_t volatile RESERVED23;

	/* 0x24: Address */
	uint32_t volatile ADDR;
#define I2C_ADDR_ADDRMASK(x)			((x) << 17)
#define I2C_ADDR_ADDR(x)			((x) << 1)
#define I2C_ADDR_GENCEN				(1u << 0)

	/* 0x28: Data */
	uint32_t volatile DATA;
#define I2C_DATA_DATA(x)			((x) << 0)

};

struct zmcu_i2c {

	/* 0x00: Control A */
	uint32_t volatile CTRLA;
#define I2C_CTRLA_LOWTOUT			(1u << 30)
#define I2C_CTRLA_INACTOUT(x)			((x) << 28)
#define I2C_CTRLA_SPEED(x)			((x) << 24)
#define I2C_CTRLA_SEXTTOEN			(1u << 23)
#define I2C_CTRLA_MEXTTOEN			(1u << 22)
#define I2C__SDAHOLD(x)				((x) << 20)
#define I2C__PINOUT				(1u << 16)
#define I2C__RUNSTDBY				(1u << 7)
#define I2C__MODE(x)				((x) << 2)
#define I2C__ENABLE				(1u << 1)
#define I2C__SWRST				(1u << 0)

	/* 0x04: Control B */
	uint32_t volatile CTRLB;
#define I2C_CTRLB_ACKACT			(1u << 18)
#define I2C_CTRLB_CMD(x)			((x) << 16)
#define I2C_CTRLB_QCEN				(1u << 9)
#define I2C_CTRLB_SMEN				(1u << 8)

	/* 0x08 */
	uint32_t volatile RESERVED24;

	/* 0x0C: Baud Rate */
	uint32_t volatile BAUD;
#define I2C_BAUD_HSBAUDLOW(x)			((x) << 24)
#define I2C_BAUD_HSBAUD(x)			((x) << 16)
#define I2C_BAUD_BAUDLOW(x)			((x) << 8)
#define I2C_BAUD_BAUD(x)			((x) << 0)

	/* 0x10 */
	uint32_t volatile RESERVED25;

	/* 0x14: */
	uint32_t volatile INTENCLR;
#define I2C_INTENCLR_SB				(1u << 1)
#define I2C_INTENCLR_MB				(1u << 0)

	/* 0x16: */
	uint32_t volatile INTENSET;
#define I2C_INTENSET_ERROR			(1u << 7)
#define I2C_INTENSET_SB				(1u << 1)
#define I2C_INTENSET_MB				(1u << 0)

	/* 0x18: Interrupt Flag Status and Clear */
	uint32_t volatile INTFLAG;
#define I2C_INTFLAG_SB				(1u << 1)
#define I2C_INTFLAG_MB				(1u << 0)

	/* 0x1A: Status */
	uint32_t volatile STATUS;
#define I2C_STATUS_LENERR			(1u << 10)
#define I2C_STATUS_SEXTTOUT			(1u << 9)
#define I2C_STATUS_MEXTTOUT			(1u << 8)
#define I2C_STATUS_CLKHOLD			(1u << 7)
#define I2C_STATUS_LOWTOUT			(1u << 6)
#define I2C_STATUS_BUSSTATE(x)			((x) << 4)
#define I2C_STATUS_RXNACK			(1u << 2)
#define I2C_STATUS_ARBLOST			(1u << 1)
#define I2C_STATUS_BUSERR			(1u << 0)

	/* 0x1C: Syncbusy */
	uint32_t volatile SYNCBUSY;
#define I2C_SYNCBUSY_ENABLE			(1u << 1)
#define I2C_SYNCBUSY_SWRST			(1u << 0)

	/* 0x20 */
	uint32_t volatile RESERVED26;

	/* 0x24: Address */
	uint32_t volatile ADDR;
#define I2C_ADDR_LEN(x)				((x) << 16)
#define I2C_ADDR_TENBITEN			(1u << 15)
#define I2C_ADDR_HS				(1u << 14)
#define I2C_ADDR_LENEN				(1u << 13)
#define I2C_ADDR_ADDR(x)			((x) << 0)
#define I2C_ADDR_LEN(x)				((x) << 16)
#define I2C_ADDR_TENBITEN			(1u << 15)
#define I2C_ADDR_HS				(1u << 14)
#define I2C_ADDR_LENEN				(1u << 13)
#define I2C_ADDR_ADDR(x)			((x) << 0)

	/* 0x18: Data */
	uint32_t volatile DATA;
#define I2C_DATA_DATA(x)			((x) << 0)

	/* 0x1C */
	uint32_t volatile RESERVED27[(0x30-0x1C)/4];

	/* 0x30: Debug Control */
	uint32_t volatile DBGCTRL;
#define I2C_DBGCTRL_DBGSTOP			(1u << 0)

};
