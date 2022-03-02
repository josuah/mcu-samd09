

/* clock */

/* give the clock-rate for selected clock socket `clkid` */ 
uint32_t clock_get_rate_hz(uint8_t clkid);

/* init a clock generator `genid`, plugging it a source `srcid` divided by `div` */
void clock_generator_init(uint8_t genid, uint8_t srcid, uint16_t div);

/* init a clock socket `clkid`, plugging it a clock generator `genid` */
void clock_init(uint8_t clkid, uint8_t genid);

/* output the signal of clock `genid` to an external pin directly */
void clock_generator_enable_output(uint8_t genid);


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
void usart_set_baud_rate(struct zmcu_usart *usart, uint16_t baud_hz);

/* select the pinout within the pad for `usart`, for TX */
void usart_set_pinout_tx(struct zmcu_usart *usart, uint8_t txpo);

/* select the pinout within the pad for `usart`, for RX */
void usart_set_pinout_rx(struct zmcu_usart *usart, uint8_t rxpo);

/* enable the usart, to call last before sending data */
void usart_enable(struct zmcu_usart *usart);

/* transmit one byte over the already configured usart */
void usart_send_byte(struct zmcu_usart *usart, uint8_t byte);


/* power */
void power_on_sercom0(void);


/* sysctrl */
void sysctrl_osc8m_enable(void);
