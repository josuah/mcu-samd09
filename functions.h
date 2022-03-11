#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#define FF(o)			(0xFFFFFFFFu >> (31 - (o)))
#define MASK(fld)		(FF(fld##_msb) ^ FF(fld##_lsb) ^ BIT(fld##_lsb))
#define BIT(fld)		(1u << (fld))
#define BITS(fld, val)		((val) << fld##_lsb)
#define FIELD(reg, fld)		(((reg) & FF(fld##_msb)) >> fld##_lsb)

/* CLOCK */

/* give the clock-rate for selected clock channel `clkid` */ 
uint32_t clock_get_hz(uint8_t clkid);

/* init a clock generator `genid`, plugging it a source `srcid` divided by `div` */
void clock_init_generator(uint8_t genid, uint8_t srcid, uint16_t div);

/* output the signal of clock `genid` to an external pin directly */
void clock_enable_generator_output(uint8_t genid);

/* init a clock channel `clkid`, plugging it a clock generator `genid` */
void clock_init(uint8_t clkid, uint8_t genid);

/* PORT */

/* set the port to ouput mode like GPIO */
void port_set_gpio_output(uint8_t pin);

/* set `pin` for peripheral use */
void port_set_peripheral(uint8_t pin, uint8_t pmux);

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

/* SERCOM */

/* convert a pointer to a sercom base address into a ID number */
uint8_t sercom_get_id(void *sercom);

/* return the clock rate for the already configured `sercom` */
uint32_t sercom_get_clock_hz(void *sercom);

/* USART */

/* init the usart, to call last before sending data */
void usart_init(struct sdk_usart *usart, uint32_t baud_hz, uint8_t txpo, uint8_t rxpo);

/* queue a transmission of `buf` of size `sz` over `usart` TX pin */
void usart_queue_tx(struct sdk_usart *usart, uint8_t const *buf, size_t sz);

/* queue a reception to `buf` of size `sz` over `usart` RX pin */
void usart_queue_rx(struct sdk_usart *usart, uint8_t *buf, size_t sz);

/* wait for `usart` transmission to complete */
void usart_wait_tx(struct sdk_usart *usart);

/* wait for `usart` reception to complete */
void usart_wait_rx(struct sdk_usart *usart);

/* interrupt coming from a generic SERCOM interface */
void usart_interrupt(struct sdk_usart *usart);

/* I2CM */

/* set `i2cm` to I2C Master mode */
void i2cm_set_master(struct sdk_i2cm *i2cm);

/* init `i2cm` after it was configured */
void i2cm_init(struct sdk_i2cm *i2cm, uint32_t baud_hz, uint8_t clk, uint8_t sda);

/* receive `i2cm` interrupt from SERCOM0 or SERCOM1 */
void i2cm_interrupt(struct sdk_i2cm *i2cm);

/* queue a transmission of `buf` of size `sz` to `addr` over `i2cm` */
void i2cm_queue_tx(struct sdk_i2cm *i2cm, uint8_t addr, uint8_t const *mem, size_t sz);

/* queue a transmission of `buf` of size `sz` to `addr` over `i2cm` */
void i2cm_queue_rx(struct sdk_i2cm *i2cm, uint8_t addr, uint8_t *mem, size_t sz);

/* wait for `i2cm` to complete transmission or reception */
int i2cm_wait(struct sdk_i2cm *i2cm);

/* POWER */

/* power-on/off each module */
void power_on_sercom0(void);
void power_on_sercom1(void);
void power_on_osc8m(void);
void power_on_dfll48m(void);

/* SYSCTRL */

/* power-on the high-speed (8 MHz) internal oscillator */
void sysctrl_osc8m_enable(void);

#endif
