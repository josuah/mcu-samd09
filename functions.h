#ifndef FUNCTIONS_H
#define FUNCTIONS_H

/* macros */
#define MASK32(o)		(o == 31 ? 0xFFFFFFFF : (1u << (o + 1)) - 1)
#define MASK(fld)		(MASK32(fld##_msb) ^ MASK32(fld##_lsb - 1))
#define BIT(fld)		(1u << (fld))
#define BITS(fld, val)		((val) << fld##_lsb)
#define FIELD(reg, fld)		(((reg) & MASK32(fld##_msb)) >> fld##_lsb)

/* halt the execution */
void __stop_program(void);

/* interrupts */
void irq_sercom0(void);
void irq_usart0(void); /* indirect */




/* clock */

/* give the clock-rate for selected clock channel `clkid` */ 
uint32_t clock_get_rate_hz(uint8_t clkid);

/* init a clock generator `genid`, plugging it a source `srcid` divided by `div` */
void clock_generator_init(uint8_t genid, uint8_t srcid, uint16_t div);

/* output the signal of clock `genid` to an external pin directly */
void clock_generator_enable_output(uint8_t genid);

/* init a clock channel `clkid`, plugging it a clock generator `genid` */
void clock_init(uint8_t clkid, uint8_t genid);


/* port */

/* set the port to ouput mode like GPIO */
void port_set_gpio_output(uint8_t pin);

/* set `pin` for peripheral use in input mode */
void port_set_periph_input(uint8_t pin, uint8_t fn);

/* set `pin` for peripheral use in output mode */
void port_set_periph_output(uint8_t pin, uint8_t fn);

/* set `pin` electric value to up */
void port_pin_set(uint8_t pin);

/* set `pin` electric value to down */
void port_pin_clear(uint8_t pin);


/* usart */

/* set `usart` to UART mode with internal clock rate and a clock pin */
void usart_set_internal_async(struct zmcu_usart *usart);

/* set `usart` number of data bits per frame (either 8 or 9) */
void usart_set_data_bits(struct zmcu_usart *usart, uint8_t bits);

/* set `usart` baud rate by reading the current clock rate */
void usart_set_baud_rate(struct zmcu_usart *usart, uint16_t baud_hz);

/* set `usart` pinout within the pad for TX */
void usart_set_pinout_tx(struct zmcu_usart *usart, uint8_t txpo);

/* set `usart` pinout within the pad for RX */
void usart_set_pinout_rx(struct zmcu_usart *usart, uint8_t rxpo);

/* set `usart` number of stop bits (1 or 2) */
void usart_set_stop_bits(struct zmcu_usart *usart, uint8_t bits);

/* set `usart` to parity mode with "odd" parity */
void usart_set_parity_odd(struct zmcu_usart *usart);

/* set `usart` to parity mode with "even" parity */
void usart_set_parity_even(struct zmcu_usart *usart);

/* set `usart` data order to MSB first */
void usart_set_most_significant_bit_first(struct zmcu_usart *usart);

/* set `usart` data order to LSB first */
void usart_set_least_significant_bit_first(struct zmcu_usart *usart);

/* enable the usart, to call last before sending data */
void usart_enable(struct zmcu_usart *usart);

/* transmit one byte over the already configured usart */
void usart_send_byte(struct zmcu_usart *usart, uint8_t byte);


/* power */
void power_on_sercom0(void);


/* sysctrl */
void sysctrl_osc8m_enable(void);

#endif
