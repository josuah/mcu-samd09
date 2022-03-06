#include "libc.h"
#include "registers.h"
#include "functions.h"

static inline void
interrupt_sercom(struct sdk_sercom *sercom)
{
	switch (FIELD(sercom->CTRLA, SERCOM_CTRLA_MODE)) {
	case SERCOM_CTRLA_MODE_USART_EXT_CLK:
	case SERCOM_CTRLA_MODE_USART_INT_CLK:
		usart_interrupt((struct sdk_usart *)sercom);
		break;
	case SERCOM_CTRLA_MODE_SPI_SLAVE:
	case SERCOM_CTRLA_MODE_SPI_MASTER:
		break;
	case SERCOM_CTRLA_MODE_I2C_SLAVE:
	case SERCOM_CTRLA_MODE_I2C_MASTER:
		break;
	}
}

void
interrupt_sercom0(void)
{
	interrupt_sercom(SERCOM0);
}

void
interrupt_sercom1(void)
{
	interrupt_sercom(SERCOM1);
}
