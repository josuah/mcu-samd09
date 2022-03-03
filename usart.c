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

void
usart_set_baud_rate(struct zmcu_usart *usart, uint16_t baud_hz)
{
	uint32_t clock_hz = usart_get_clock_rate_hz(usart);
	uint32_t baud_x8;

	/* set to fractionnal mode baud rate calculation for better accuracy */
	usart->CTRLA = (usart->CTRLA & ~MASK(USART_CTRLA_SAMPR))
	  | BITS(USART_CTRLA_SAMPR, USART_CTRLA_SAMPR_16_FRACTIONAL);

	/* baud_x8 = clock_hz * 8 / 16 / baud_hz */
	baud_x8 = clock_hz / 2 / baud_hz;
	usart->BAUD = 0
	  | BITS(USART_BAUD_IP, baud_x8 / 8)
	  | BITS(USART_BAUD_FP, baud_x8 % 8);
}

void
usart_set_internal_async(struct zmcu_usart *usart)
{
	/* setup SERCOMn for use with USART with internal clock */
	usart->CTRLA = (usart->CTRLA & ~MASK(USART_CTRLA_MODE))
	  | BITS(USART_CTRLA_MODE, USART_CTRLA_MODE_USART_INT_CLK);

	/* setup SERCOMn for use with USART in asynchronous mode */
	usart->CTRLA &= ~BIT(USART_CTRLA_CMODE);
}

void
usart_set_pinout_tx(struct zmcu_usart *usart, uint8_t txpo)
{
	usart->CTRLA = (usart->CTRLA & ~MASK(USART_CTRLA_TXPO))
	  | BITS(USART_CTRLA_TXPO, txpo);
}

void
usart_set_pinout_rx(struct zmcu_usart *usart, uint8_t rxpo)
{
	usart->CTRLA = (usart->CTRLA & ~MASK(USART_CTRLA_RXPO))
	  | BITS(USART_CTRLA_RXPO, rxpo);
}

void
usart_set_data_bits(struct zmcu_usart *usart, uint8_t bits)
{
	usart->CTRLB = (usart->CTRLB & ~MASK(USART_CTRLB_CHSIZE))
	  | BITS(USART_CTRLB_CHSIZE, bits % 8);
}

static inline void
usart_set_parity(struct zmcu_usart *usart)
{
	usart->CTRLA = (usart->CTRLA & ~MASK(USART_CTRLA_FORM))
	  | BITS(USART_CTRLA_FORM, USART_CTRLA_FORM_NORMAL_PARITY);
}

void
usart_set_parity_odd(struct zmcu_usart *usart)
{
	usart_set_parity(usart);
	usart->CTRLB |= BIT(USART_CTRLB_PMODE);
}

void
usart_set_parity_even(struct zmcu_usart *usart)
{
	usart_set_parity(usart);
	usart->CTRLB &= ~BIT(USART_CTRLB_PMODE);
}

void
usart_set_stop_bits(struct zmcu_usart *usart, uint8_t bits)
{
	switch (bits) {
	case 1:
		usart->CTRLB &= ~BIT(USART_CTRLB_SBMODE);
		return;
	case 2:
		usart->CTRLB |= BIT(USART_CTRLB_SBMODE);
		return;
	}
	__stop_program();
}

void
usart_set_most_significant_bit_first(struct zmcu_usart *usart)
{
	usart->CTRLA &= ~BIT(USART_CTRLA_DORD);
}

void
usart_set_least_significant_bit_first(struct zmcu_usart *usart)
{
	usart->CTRLA |= BIT(USART_CTRLA_DORD);
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
	while (usart->SYNCBUSY & USART_SYNCBUSY_ENABLE);
}
