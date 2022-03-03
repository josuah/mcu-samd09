#include "libc.h"
#include "registers.h"
#include "functions.h"

void
irq_sercom0(void)
{
	switch (FIELD(SERCOM0->CTRLA, SERCOM_CTRLA_MODE)) {
	case SERCOM_CTRLA_MODE_USART_EXT_CLK:
	case SERCOM_CTRLA_MODE_USART_INT_CLK:
		irq_usart0();
		break;
	case SERCOM_CTRLA_MODE_SPI_SLAVE:
	case SERCOM_CTRLA_MODE_SPI_MASTER:
		break;
	case SERCOM_CTRLA_MODE_I2C_SLAVE:
	case SERCOM_CTRLA_MODE_I2C_MASTER:
		break;
	}
}
