#include "libc.h"
#include "registers.h"
#include "functions.h"

static volatile uint64_t systick_runtime_ms;

void
systick_init(void)
{
	/* set the number of ticks per milliseconds */
	SYSTICK->RVR = clock_get_generator_hz(0) / 1000;

	SYSTICK->CSR = 0
	/* enable the peripheral */
	 | SYSTICK_CSR_ENABLE
	/* use system clock as source for systick */
	 | SYSTICK_CSR_CLKSOURCE
	/* generate an interrupts on every tick */
	 | SYSTICK_CSR_TICKINT;
}

void
systick_interrupt(void)
{
	systick_runtime_ms++;
}

uint64_t
systick_get_runtime_ms(void)
{
	// TODO: make it callable from higher priority interrupt
	return systick_runtime_ms;
}

void
systick_sleep_ms(uint64_t duration_ms)
{
	uint64_t deadline_ms;

	deadline_ms = systick_get_runtime_ms() + duration_ms;
	while (systick_get_runtime_ms() < deadline_ms);
}
