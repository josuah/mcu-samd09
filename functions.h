#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#define FIELD(reg, fld)		(((reg) & fld##_Msk) >> fld##_Pos)

/*** USART ***/

/* init the usart, to call last before sending data */
void usart_init(struct mcu_usart *usart, uint32_t baud_hz, uint8_t txpo, uint8_t rxpo);

/* queue a transmission of `buf` of size `sz` over `usart` TX pin */
void usart_queue_tx(struct mcu_usart *usart, uint8_t const *buf, size_t sz);

/* queue a reception to `buf` of size `sz` over `usart` RX pin */
void usart_queue_rx(struct mcu_usart *usart, uint8_t *buf, size_t sz);

/* wait for `usart` transmission to complete */
void usart_wait_tx(struct mcu_usart *usart);

/* wait for `usart` reception to complete */
void usart_wait_rx(struct mcu_usart *usart);

/* interrupt coming from a generic SERCOM interface */
void usart_interrupt(struct mcu_usart *usart);

/*** I²C Master ***/

/* set `i2c_master` to I²C Master mode */
void i2c_master_set_master(struct mcu_i2c_master *i2c_master);

/* configure and init `i2c_master` */
void i2c_master_init(struct mcu_i2c_master *i2c_master, uint32_t baud_hz, uint8_t pin_clk, uint8_t pin_sda);

/* receive `i2c_master` interrupt from SERCOM0 or SERCOM1 */
void i2c_master_interrupt(struct mcu_i2c_master *i2c_master);

/* queue a transmission of `buf` of size `sz` to `addr` over `i2c_master` */
void i2c_master_queue_tx(struct mcu_i2c_master *i2c_master, uint8_t addr, uint8_t const *mem, size_t sz);

/* queue a transmission of `buf` of size `sz` to `addr` over `i2c_master` */
void i2c_master_queue_rx(struct mcu_i2c_master *i2c_master, uint8_t addr, uint8_t *mem, size_t sz);

/* wait for `i2c_master` to complete transmission or reception */
int i2c_master_wait(struct mcu_i2c_master *i2c_master);

/*** SPI Master ***/

/* configure and init `i2c_master` */
void spi_master_init(struct mcu_spi *spi_master, uint32_t baud_hz, uint8_t pin_sck,
	uint8_t pin_miso, uint8_t pin_mosi, uint8_t pin_ss,
	uint32_t dipo, uint32_t dopo);

/*** CLOCK ***/

/* give the clock-rate for selected clock channel `clkid` */ 
uint32_t clock_get_hz(uint8_t clkid);

/* init a clock generator `genid`, plugging it a source `srcid` divided by `div` */
void clock_init_generator(uint8_t genid, uint32_t srcid, uint32_t div);

/* output the signal of clock `genid` to an external pin directly */
void clock_enable_generator_output(uint8_t genid);

/* init a clock channel `clkid`, plugging it a clock generator `genid` */
void clock_init(uint8_t clkid, uint8_t genid);

/*** PWM ***/

/* setup a timer/counter of resolution 8 `tc` for use with PWM on `pin` */
void pwm_init(struct mcu_tc_count8 *tc, uint32_t ctrla_prescaler);

/* setup `pin` for use as a counter output */
void pwm_init_counter(uint8_t pin);

/* set `tc` duration of time with pin "up" out of UINT8_MAX to `duty_cycle` */
void pwm_set_duty_cycle(struct mcu_tc_count8 *tc, uint8_t counter_id, uint8_t duty_cycle);

/*** POWER ***/

static inline void
power_on_sercom(uint8_t id)
{
	PM->APBCMASK |= PM_APBCMASK_SERCOM0 << id;
}

static inline void
power_on_osc8m(void)
{
	SYSCTRL->OSC8M |= SYSCTRL_OSC8M_ENABLE;
}

static inline void
power_on_dfll48m(void)
{
	SYSCTRL->OSC8M |= SYSCTRL_DFLLCTRL_ENABLE;
}

/*** PORT ***/

static inline void
port_set_pmux(uint8_t pin, uint8_t pmux)
{
	if (pin % 2 == 0) {
		/* even */
		PORT->PMUX[pin/2] = (PORT->PMUX[pin/2] & ~0x0F) | (pmux << 0);
	} else {
		/* odd */
		PORT->PMUX[pin/2] = (PORT->PMUX[pin/2] & ~0xF0) | (pmux << 4);
	}
}

static inline void
port_set_output(uint8_t pin)
{
	PORT->DIRSET |= (1 << pin);
}

/*** SERCOM ***/

static inline uint8_t
sercom_get_id(void *ptr)
{
	if (ptr == SERCOM0) return 0;
	if (ptr == SERCOM1) return 1;
	assert(!"unknown sercom");
	return 0xFF;
}

static inline uint32_t
sercom_get_clock_hz(uint8_t id)
{
	return clock_get_hz(GCLK_CLKCTRL_ID_SERCOM0_CORE + id);
}

/*** Timer/Counter ***/

static inline uint8_t
tc_get_id(void *ptr)
{
	if (ptr == (void *)TC1_BASE) return 1;
	if (ptr == (void *)TC2_BASE) return 2;
	assert(!"unknown timer/counter");
	return 0xFF;
}

#endif
