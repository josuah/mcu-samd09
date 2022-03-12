#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#define FF(o)			(0xFFFFFFFFu >> (31 - (o)))
#define MASK(fld)		(FF(fld##_Msb) ^ FF(fld##_Lsb) ^ BIT(fld##_Lsb))
#define BIT(fld)		(1u << (fld))
#define BITS(fld, val)		((val) << fld##_Lsb)
#define FIELD(reg, fld)		(((reg) & FF(fld##_Msb)) >> fld##_Lsb)

/*** USART ***/

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

/*** I²C Master ***/

/* set `i2cm` to I²C Master mode */
void i2cm_set_master(struct sdk_i2cm *i2cm);

/* configure and init `i2cm` */
void i2cm_init(struct sdk_i2cm *i2cm, uint32_t baud_hz, uint8_t pin_clk, uint8_t pin_sda);

/* receive `i2cm` interrupt from SERCOM0 or SERCOM1 */
void i2cm_interrupt(struct sdk_i2cm *i2cm);

/* queue a transmission of `buf` of size `sz` to `addr` over `i2cm` */
void i2cm_queue_tx(struct sdk_i2cm *i2cm, uint8_t addr, uint8_t const *mem, size_t sz);

/* queue a transmission of `buf` of size `sz` to `addr` over `i2cm` */
void i2cm_queue_rx(struct sdk_i2cm *i2cm, uint8_t addr, uint8_t *mem, size_t sz);

/* wait for `i2cm` to complete transmission or reception */
int i2cm_wait(struct sdk_i2cm *i2cm);

/*** SPI Master ***/

/* configure and init `i2cm` */
void spim_init(struct sdk_spi *spim, uint32_t baud_hz, uint8_t pin_sck,
	uint8_t pin_miso, uint8_t pin_mosi, uint8_t pin_ss,
	uint8_t dipo, uint8_t dopo);

/*** CLOCK ***/

/* give the clock-rate for selected clock channel `clkid` */ 
uint32_t clock_get_hz(uint8_t clkid);

/* init a clock generator `genid`, plugging it a source `srcid` divided by `div` */
void clock_init_generator(uint8_t genid, uint8_t srcid, uint16_t div);

/* output the signal of clock `genid` to an external pin directly */
void clock_enable_generator_output(uint8_t genid);

/* init a clock channel `clkid`, plugging it a clock generator `genid` */
void clock_init(uint8_t clkid, uint8_t genid);

/*** POWER ***/

static inline void
power_on_sercom(uint8_t id)
{
	PM->APBCMASK |= BIT(PM_APBCMASK_SERCOM0 + id);
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
	/* associate the pin to the chosen module */
	PORT->PMUX[pin/2] = (PORT->PMUX[pin/2] & ~PORT_PMUX(pin, 0xFu))
	 | PORT_PMUX(pin, pmux);
}

static inline void
port_set_output(uint8_t pin)
{
	PORT->DIRSET |= BIT(pin);
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

#endif
