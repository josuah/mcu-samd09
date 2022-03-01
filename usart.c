#include "libc.h"
#include "main.h"
#include "registers.h"
#include "functions.h"

static inline uint32_t
usart_get_clock_rate_hz(struct zmcu_usart *usart)
{
	if (usart == USART0)
		return clock_get_rate_hz(GCLK_CLKCTRL_ID_SERCOM0_CORE);
	if (usart == USART1)
		return clock_get_rate_hz(GCLK_CLKCTRL_ID_SERCOM1_CORE);
	__stop_program();
	return 0;
}

static inline uint8_t
usart_get_sample_num(struct zmcu_usart *usart)
{
	switch (BITREAD(usart->CTRLA, USART_CTRLA_SAMPR)) {
	case USART_CTRLA_SAMPR_16_ARITHMETIC:
	case USART_CTRLA_SAMPR_16_FRACTIONAL:
		return 16;
	case USART_CTRLA_SAMPR_8_ARITHMETIC:
	case USART_CTRLA_SAMPR_8_FRACTIONAL:
		return 8;
	case USART_CTRLA_SAMPR_3_ARITHMETIC:
		return 3;
	}
	__stop_program();
	return 0;
}

void
usart_set_baud_rate(struct zmcu_usart *usart, uint32_t baud_hz)
{
	uint8_t samples = usart_get_sample_num(usart);
	uint32_t clock_hz = usart_get_clock_rate_hz(usart);

	usart->BAUD = 0x10000 - 0x10000 * samples / clock_hz * baud_hz;
}

void
usart_mode_internal_async(struct zmcu_usart *usart)
{
	/* setup SERCOMn for use with USART with internal clock */
	BITWRITE(usart->CTRLA, USART_CTRLA_MODE, USART_INT_CLK);

	/* setup SERCOMn for use with USART in asynchronous mode */
	usart->CTRLA &= ~BIT(USART_CTRLA_CMODE);
}

void
usart_set_pinout(struct zmcu_usart *usart, uint8_t txpo, uint8_t rxpo)
{
	usart->CTRLA = (usart->CTRLA & ~BITMASK(USART_CTRLA_TXPO))
	  | txpo << USART_CTRLA_TXPO_lsb;

	usart->CTRLA = (usart->CTRLA & ~BITMASK(USART_CTRLA_RXPO))
	  | rxpo << USART_CTRLA_RXPO_lsb;
}

void
usart_set_frame_size(struct zmcu_usart *usart, uint8_t bits)
{
	switch (bits) {
	case 8:
		BITWRITE(usart->CTRLB, USART_CTRLB_CHSIZE, 8BITS);
		break;
	case 9:
		BITWRITE(usart->CTRLB, USART_CTRLB_CHSIZE, 9BITS);
		break;
	default:
		__stop_program();
	}
}

void
usart_enable(struct zmcu_usart *usart)
{
	/* enable the receiver and transmitter */
	usart->CTRLB |= BIT(USART_CTRLB_RXEN) | BIT(USART_CTRLB_TXEN);
	while (usart->SYNCBUSY & BIT(USART_SYNCBUSY_CTRLB));

	/* enable the USART *after* it is configured (#25.6.2) */
	usart->CTRLA |= BIT(USART_CTRLA_ENABLE);
	while (usart->SYNCBUSY & USART_SYNCBUSY_ENABLE);
}

void
usart_send_byte(struct zmcu_usart *usart, uint8_t byte)
{
	usart->DATA = byte;
	while (usart->SYNCBUSY & BIT(USART_SYNCBUSY_CTRLB));
}
