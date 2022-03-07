#include "libc.h"
#include "registers.h"
#include "functions.h"

static struct sdk_usart_buffer {
	uint8_t *mem;
	size_t len;
	uint8_t volatile done;
} usart_rx[2], usart_tx[2];

void
usart_set_baud_rate(struct sdk_usart *usart, uint32_t baud_hz)
{
	uint32_t clock_hz = sercom_get_clock_rate_hz(usart);

	/* set to fractionnal mode baud rate calculation for better accuracy */
	usart->CTRLA = (usart->CTRLA & ~MASK(USART_CTRLA_SAMPR))
	 | BITS(USART_CTRLA_SAMPR, USART_CTRLA_SAMPR_16_FRACTIONAL);

	usart->BAUD = 0
	 | BITS(USART_BAUD_IP, clock_hz / 16 / baud_hz / 8)
	 | BITS(USART_BAUD_FP, clock_hz / 16 / baud_hz % 8);
}

void
usart_set_pinout_tx(struct sdk_usart *usart, uint8_t txpo)
{
	usart->CTRLA = (usart->CTRLA & ~MASK(USART_CTRLA_TXPO))
	 | BITS(USART_CTRLA_TXPO, txpo);
}

void
usart_set_pinout_rx(struct sdk_usart *usart, uint8_t rxpo)
{
	usart->CTRLA = (usart->CTRLA & ~MASK(USART_CTRLA_RXPO))
	 | BITS(USART_CTRLA_RXPO, rxpo);
}

void
usart_set_data_bits(struct sdk_usart *usart, uint8_t bits)
{
	usart->CTRLB = (usart->CTRLB & ~MASK(USART_CTRLB_CHSIZE))
	 | BITS(USART_CTRLB_CHSIZE, bits % 8);
}

void
usart_set_asynchronous(struct sdk_usart *usart)
{
	usart->CTRLA &= ~BIT(USART_CTRLA_CMODE);
}

void
usart_set_synchronous(struct sdk_usart *usart)
{
	usart->CTRLA |= BIT(USART_CTRLA_CMODE);
}

static inline void
usart_set_parity(struct sdk_usart *usart)
{
	usart->CTRLA = (usart->CTRLA & ~MASK(USART_CTRLA_FORM))
	 | BITS(USART_CTRLA_FORM, USART_CTRLA_FORM_NORMAL_PARITY);
}

void
usart_set_parity_odd(struct sdk_usart *usart)
{
	usart_set_parity(usart);
	usart->CTRLB |= BIT(USART_CTRLB_PMODE);
}

void
usart_set_parity_even(struct sdk_usart *usart)
{
	usart_set_parity(usart);
	usart->CTRLB &= ~BIT(USART_CTRLB_PMODE);
}

void
usart_set_stop_bits(struct sdk_usart *usart, uint8_t bits)
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
usart_set_most_significant_bit_first(struct sdk_usart *usart)
{
	usart->CTRLA &= ~BIT(USART_CTRLA_DORD);
}

void
usart_set_least_significant_bit_first(struct sdk_usart *usart)
{
	usart->CTRLA |= BIT(USART_CTRLA_DORD);
}

void
usart_enable(struct sdk_usart *usart)
{
	/* enable the receiver and transmitter */
	usart->CTRLB |= BIT(USART_CTRLB_RXEN) | BIT(USART_CTRLB_TXEN);
	while (usart->SYNCBUSY & BIT(USART_SYNCBUSY_CTRLB));

	/* enable the USART *after* it is configured (#25.6.2) */
	usart->CTRLA |= BIT(USART_CTRLA_ENABLE);
	while (usart->SYNCBUSY & USART_SYNCBUSY_ENABLE);
}

void
usart_tx_queue(struct sdk_usart *usart, uint8_t const *mem, size_t len)
{
	struct sdk_usart_buffer *tx = &usart_tx[sercom_get_id(usart)];

	tx->done = 0;
	tx->mem = (uint8_t *)mem;
	tx->len = len;

	usart->INTENSET = BIT(USART_INTENSET_DRE);
	NVIC->ISER = BIT(9 + sercom_get_id(usart));
}

void
usart_tx_wait(struct sdk_usart *usart)
{
	struct sdk_usart_buffer *tx = &usart_tx[sercom_get_id(usart)];

	while (!tx->done);
}

void
usart_rx_queue(struct sdk_usart *usart, uint8_t *mem, size_t len)
{
	struct sdk_usart_buffer *rx = &usart_rx[sercom_get_id(usart)];

	rx->done = 0;
	rx->mem = mem;
	rx->len = len;

	usart->INTENSET = BIT(USART_INTENSET_RXC);
}

static inline void
usart_interrupt_tx_data_register_empty(struct sdk_usart *usart)
{
	struct sdk_usart_buffer *tx = &usart_tx[sercom_get_id(usart)];

	if (tx->len == 0) {
		usart->INTENCLR = BIT(USART_INTENSET_DRE);
		usart->INTENSET = BIT(USART_INTENSET_TXC);
	} else {
		usart->DATA = *tx->mem++;
		tx->len--;
	}
}

static inline void
usart_interrupt_tx_complete(struct sdk_usart *usart)
{
	struct sdk_usart_buffer *tx = &usart_tx[sercom_get_id(usart)];

	if (tx->len == 0) {
		usart->INTENCLR = BIT(USART_INTENSET_TXC);
		tx->done = 1;
	}
}

static inline void
usart_interrupt_rx_complete(struct sdk_usart *usart)
{
	struct sdk_usart_buffer *rx = &usart_rx[sercom_get_id(usart)];

	(void)rx;
}

static inline void
usart_interrupt_rx_start(struct sdk_usart *usart)
{
	struct sdk_usart_buffer *rx = &usart_rx[sercom_get_id(usart)];

	(void)rx;
}

static inline void
usart_interrupt_rx_clear_to_send(struct sdk_usart *usart)
{
	struct sdk_usart_buffer *rx = &usart_rx[sercom_get_id(usart)];

	(void)rx;
}

static inline void
usart_interrupt_rx_break(struct sdk_usart *usart)
{
	struct sdk_usart_buffer *rx = &usart_rx[sercom_get_id(usart)];

	(void)rx;
}

static inline void
usart_interrupt_error(struct sdk_usart *usart)
{
	(void)usart;
}

void
usart_interrupt(struct sdk_usart *usart)
{
	uint32_t reg = usart->INTFLAG;

	if (reg & BIT(USART_INTFLAG_DRE))
		usart_interrupt_tx_data_register_empty(usart);
	if (reg & BIT(USART_INTFLAG_TXC))
		usart_interrupt_tx_complete(usart);
	if (reg & BIT(USART_INTFLAG_RXC))
		usart_interrupt_rx_complete(usart);
	if (reg & BIT(USART_INTFLAG_RXS))
		usart_interrupt_rx_start(usart);
	if (reg & BIT(USART_INTFLAG_CTSIC))
		usart_interrupt_rx_clear_to_send(usart);
	if (reg & BIT(USART_INTFLAG_RXBRK))
		usart_interrupt_rx_break(usart);
	if (reg & BIT(USART_INTFLAG_ERROR))
		usart_interrupt_error(usart);
}
