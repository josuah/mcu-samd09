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
void interrupt_sercom0(void);
void interrupt_sercom1(void);


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
void port_set_peripheral_input(uint8_t pin, uint8_t pmux);

/* set `pin` for peripheral use in output mode */
void port_set_peripheral_output(uint8_t pin, uint8_t pmux);

/* set `pin` electric value to up */
void port_set_pin_up(uint8_t pin);

/* set `pin` electric value to down */
void port_set_pin_down(uint8_t pin);

/* set `pin` with an internal pull-up resistor */
void port_set_pull_up(uint8_t pin);

/* set `pin` with an internal pull-down resistor */
void port_set_pull_down(uint8_t pin);


/* sercom */

/* convert a pointer to a sercom base address into a ID number */
uint8_t sercom_get_number(void *sercom);

/* return the clock rate for the already configured `sercom` */
uint32_t sercom_get_clock_rate_hz(void *sercom);

/* set `sercom` to be an I2C peripheral in master mode */
void sercom_set_mode_i2c_master(struct sdk_sercom *sercom);

/* set `sercom` to be an USART peripheral with internal clock */
void sercom_set_mode_usart_internal(struct sdk_sercom *sercom);


/* usart */

/* set `usart` to not use any clock pin */
void usart_set_asynchronous(struct sdk_usart *usart);

/* set `usart` to use an extra clock pin */
void usart_set_synchronous(struct sdk_usart *usart);

/* set `usart` number of data bits per frame (either 8 or 9) */
void usart_set_data_bits(struct sdk_usart *usart, uint8_t bits);

/* set `usart` baud rate to `baud_hz`, reading its SERCOM clock rate */
void usart_set_baud_rate(struct sdk_usart *usart, uint32_t baud_hz);

/* set `usart` pinout within the pad for TX */
void usart_set_pinout_tx(struct sdk_usart *usart, uint8_t txpo);

/* set `usart` pinout within the pad for RX */
void usart_set_pinout_rx(struct sdk_usart *usart, uint8_t rxpo);

/* set `usart` number of stop bits (1 or 2) */
void usart_set_stop_bits(struct sdk_usart *usart, uint8_t bits);

/* set `usart` to parity mode with "odd" parity */
void usart_set_parity_odd(struct sdk_usart *usart);

/* set `usart` to parity mode with "even" parity */
void usart_set_parity_even(struct sdk_usart *usart);

/* set `usart` data order to MSB first */
void usart_set_most_significant_bit_first(struct sdk_usart *usart);

/* set `usart` data order to LSB first */
void usart_set_least_significant_bit_first(struct sdk_usart *usart);

/* enable the usart, to call last before sending data */
void usart_enable(struct sdk_usart *usart);

/* transmit one byte over `usart` */
void usart_tx_queue(struct sdk_usart *usart, uint8_t const *buf, size_t len);

/* wait for `usart` transmission to complete */
void usart_tx_wait(struct sdk_usart *usart);

/* receive one byte over `usart` */
void usart_rx_queue(struct sdk_usart *usart, uint8_t *buf, size_t len);

/* interrupt coming from SERCOM0 or SERCOM1 */
void usart_interrupt(struct sdk_usart *usart);


/* i2c in master mode */

/* set `i2cm` baud rate to `baud_hz`, reading its SERCOM clock rate */
void i2cm_set_baud_rate(struct sdk_i2cm *i2cm, uint32_t baud_hz);

/* set `i2cm` to I2C Master mode */
void i2cm_set_master(struct sdk_i2cm *i2cm);

/* enable `i2cm` after it was configured */
void i2cm_enable(struct sdk_i2cm *i2cm);


/* power */

/* power-on/off each module */
void power_on_sercom0(void);
void power_on_sercom1(void);
void power_on_osc8m(void);


/* sysctrl */

/* power-on the high-speed (8 MHz) internal oscillator */
void sysctrl_osc8m_enable(void);


#endif
