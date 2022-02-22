#include <stddef.h>
#include <stdint.h>
#include <binary.h>

#define SERCOM0 ((struct zmcu_sercom *)SERCOM0_BASE)
#define SERCOM1 ((struct zmcu_sercom *)SERCOM1_BASE)
#define SERCOM2 ((struct zmcu_sercom *)SERCOM2_BASE)

struct zmcu_sercom {

	/* 0x00: Control A */
	uint32_t volatile CTRLA;
#define SERCOM_CTRLA_MODE(x)			((x) << 2)
#define SERCOM_CTRLA_MODE_MASK			SERCOM_CTRLA_MODE(0x7)
#define SERCOM_CTRLA_MODE_USART_EXT		0x0
#define SERCOM_CTRLA_MODE_USART_INT		0x1
#define SERCOM_CTRLA_MODE_SPI_SLAVE		0x2
#define SERCOM_CTRLA_MODE_SPI_MASTER		0x3
#define SERCOM_CTRLA_MODE_I2C_SLAVE		0x4
#define SERCOM_CTRLA_MODE_I2C_MASTER		0x5
#define SERCOM_CTRLA_ENABLE			(1u << 1)
#define SERCOM_CTRLA_SWRST			(1u << 0)

};
