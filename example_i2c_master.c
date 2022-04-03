#include "libc.h"
#include "libssd1306.h"
#include "registers.h"
#include "functions.h"

#define I2C1_MASTER_SCL 23
#define I2C1_MASTER_SDA 22

int
ssd1306_fn_i2c_write(uint8_t addr, uint8_t const *buf, size_t sz)
{
	i2c_master_queue_tx(I2C1_MASTER, addr, buf, sz);
	return i2c_master_wait(I2C1_MASTER);
}

int
main(void)
{
	power_on_sercom(1);

	clock_init(GCLK_CLKCTRL_ID_SERCOM1_CORE, GCLK_GENCTRL_ID_GCLKGEN0);
	clock_init(GCLK_CLKCTRL_ID_SERCOMX_SLOW, GCLK_GENCTRL_ID_GCLKGEN1);

	i2c_master_init(I2C1_MASTER, 400000, I2C1_MASTER_SCL, I2C1_MASTER_SDA);
	ssd1306_init();

	ssd1306_draw_point(3, 3);
	ssd1306_flush();

	return 0;
}
