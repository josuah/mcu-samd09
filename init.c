#include "libc.h"
#include "registers.h"
#include "functions.h"

static inline void
__interrupt_sercom(struct sdk_sercom *sercom)
{
	switch (FIELD(sercom->CTRLA, SERCOM_CTRLA_MODE)) {
	case SERCOM_CTRLA_MODE_USART_INT_CLK:
		usart_interrupt((struct sdk_usart *)sercom);
		break;
	case SERCOM_CTRLA_MODE_I2C_MASTER:
		i2cm_interrupt((struct sdk_i2cm *)sercom);
		break;
	case SERCOM_CTRLA_MODE_USART_EXT_CLK:
	case SERCOM_CTRLA_MODE_SPI_SLAVE:
	case SERCOM_CTRLA_MODE_SPI_MASTER:
	case SERCOM_CTRLA_MODE_I2C_SLAVE:
		break;
	}
}

static void
__interrupt_sercom0(void)
{
	__interrupt_sercom(SERCOM0);
}

static void
__interrupt_sercom1(void)
{
	__interrupt_sercom(SERCOM1);
}

void
__reset_handler(void)
{
	extern int main(void);
	extern char __data_start, __data_end, __data_load_start;
	extern char __bss_start, __bss_end;
	volatile char *src = &__data_load_start, *dst;

	for (dst = &__data_start; dst < &__data_end; *dst++ = *src++);
	for (dst = &__bss_start; dst < &__bss_end; *dst++ = 0);
	main();
	__stop_program();
}

void
__stop_program(void)
{
	for (int volatile i = 0 ;; i++);
}

extern char __stack_top;
void *__stack_pointer = &__stack_top;	/* 0x00 */

void (*__vectors[])(void) = {
	&__reset_handler,		/* 0x04 -15 ARM Reset */
	&__stop_program,		/* 0x08 -14 ARM NonMaskableInt */
	&__stop_program,		/* 0x0C -13 ARM HardFault */
	&__stop_program,		/* 0x10 -12 ARM MemoryManagement */
	&__stop_program,		/* 0x14 -11 ARM BusFault */
	&__stop_program,		/* 0x18 -10 ARM UsageFault */
	&__stop_program,		/* 0x1C -9 ARM SecureFault */
	&__stop_program,		/* 0x20 -8 Reserved */
	&__stop_program,		/* 0x24 -7 Reserved */
	&__stop_program,		/* 0x28 -6 Reserved */
	&__stop_program,		/* 0x2C -5 ARM SVCall */
	&__stop_program,		/* 0x30 -4 ARM DebugMonitor */
	&__stop_program,		/* 0x34 -3 Reserved */
	&__stop_program,		/* 0x38 -2 ARM PendSV */
	&__stop_program,		/* 0x3C -1 ARM SysTick */
	&__stop_program,		/* 0x40 #0 PM */
	&__stop_program,		/* 0x44 #1 SYSCTRL */
	&__stop_program,		/* 0x48 #2 WDT */
	&__stop_program,		/* 0x4C #3 RTC */
	&__stop_program,		/* 0x50 #4 EIC */
	&__stop_program,		/* 0x54 #5 NVMCTRL */
	&__stop_program,		/* 0x58 #6 DMAC */
	&__stop_program,		/* 0x5C #7 Reserved */
	&__stop_program,		/* 0x60 #8 EVSYS */
	&__interrupt_sercom0,		/* 0x64 #9 SERCOM0 */
	&__interrupt_sercom1,		/* 0x68 #10 SERCOM1 */
	&__stop_program,		/* 0x6C #11 Reserved */
	&__stop_program,		/* 0x70 #12 Reserved */
	&__stop_program,		/* 0x74 #13 TC1 */
	&__stop_program,		/* 0x78 #14 TC2 */
	&__stop_program,		/* 0x7C #15 ADC */
	&__stop_program,		/* 0x80 #16 Reserved */
	&__stop_program,		/* 0x84 #17 Reserved */
	&__stop_program,		/* 0x88 #18 Reserved */
};
