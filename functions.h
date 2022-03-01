

/* clock */

/* give the clock-rate for selected clock ID (GCLK_CLKCTRL_ID_*)
 * after looking-up the right clock generator, and divisors */
uint32_t clock_get_rate_hz(uint8_t clkid);

/* plug a clock generator `genid` to a clock socket `clkid` */
void clock_set_generator(uint8_t clkid, uint8_t genid);


/* port */

/* set the port to ouput mode like GPIO */
void port_mode_gpio_output(uint8_t pin);

/* set `pin` for peripheral use in input mode */
void port_mode_periph_input(uint8_t pin, uint8_t fn);

/* set `pin` for peripheral use in output mode */
void port_mode_periph_output(uint8_t pin, uint8_t fn);

/* set `pin` electric value to up */
void port_pin_set(uint8_t pin);

/* set `pin` electric value to down */
void port_pin_clear(uint8_t pin);


/* usart */

/* set a SERCOM to USART mode with internal clock rate, without a clock pin */
void usart_mode_internal_async(struct zmcu_usart *usart);

/* set either 8 or 9 bits per byte */
void usart_set_frame_size(struct zmcu_usart *usart, uint8_t bits);

/* set `usart` baud rate by reading the current clock rate */
void usart_set_baud_rate(struct zmcu_usart *usart, uint32_t baud_hz);

/* enable the usart, to call last before sending data */
void usart_enable(struct zmcu_usart *usart);

/* transmit one byte over the already configured usart */
void usart_send_byte(struct zmcu_usart *usart, uint8_t byte);
