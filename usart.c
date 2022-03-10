#include "libc.h"
#include "registers.h"
#include "functions.h"

static struct sdk_usart_buffer {
	uint8_t *mem;
	size_t len;
	uint8_t volatile done;
} usart_rx[2], usart_tx[2];

void
usart_init(struct sdk_usart *usart, uint32_t baud_hz, uint8_t txpo, uint8_t rxpo)
{
	uint32_t clock_hz = sercom_get_clock_hz(usart);

	usart->CTRLA = 0
	/* asynchronous usart with internal clock */
	 | BITS_(USART_CTRLA_MODE, USART_INT_CLK)
	/* most common way to use usart: least significant bit first */
	 | BIT(USART_CTRLA_DORD)
	/* set to fractionnal baud rate for better accuracy */
	 | BITS_(USART_CTRLA_SAMPR, 16_FRACTIONAL)
	/* pinout mapping for the `tx` pin */
	 | BITS(USART_CTRLA_TXPO, txpo)
	/* pinout mapping for the `rx` pin */
	 | BITS(USART_CTRLA_RXPO, rxpo);

	/* set the baud rate integer part (IP) and fractional part (FP) */
	usart->BAUD = 0
	 | BITS(USART_BAUD_IP, clock_hz / 16 / baud_hz / 8)
	 | BITS(USART_BAUD_FP, clock_hz / 16 / baud_hz % 8);

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
