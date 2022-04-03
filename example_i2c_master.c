#include "libc.h"
#include "registers.h"
#include "functions.h"
#include "ssd1306.h"

#define I2C1_MASTER_SDA	22
#define I2C1_MASTER_SCL	23

int
ssd1306_i2c_write(uint8_t addr, uint8_t const *buf, size_t len)
{
	i2c_master_queue_tx(I2C1_MASTER, addr, buf, len);
	return i2c_master_wait(I2C1_MASTER);
}

int
main(void)
{
	power_on_dfll48m();
	power_on_sercom(1);

	clock_init_generator(GCLK_GENCTRL_ID_GCLKGEN0, GCLK_GENCTRL_SRC_DFLL48M, 1);
	clock_init_generator(GCLK_GENCTRL_ID_GCLKGEN1, GCLK_GENCTRL_SRC_OSCULP32K, 1);
	clock_init(GCLK_CLKCTRL_ID_SERCOM1_CORE, GCLK_GENCTRL_ID_GCLKGEN0);
	clock_init(GCLK_CLKCTRL_ID_SERCOMX_SLOW, GCLK_GENCTRL_ID_GCLKGEN1);

	i2c_master_init(I2C1_MASTER, 400000, I2C1_MASTER_SCL, I2C1_MASTER_SDA);
	ssd1306_init();

	ssd1306_point(1, 1);
	ssd1306_flush();

	return 0;
}
