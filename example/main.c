#include <port.h>

#define LED		27

int
main(void)
{
	uint32_t reg;

	/* turn led on */
	PORT->DIRSET = 1 << LED;
	PORT->OUTSET = 1 << LED;

	return 0;
}
