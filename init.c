#include "libc.h"
#include "main.h"

extern int main(void);
extern void __reset_handler(void);

extern char __data_start, __data_end, __data_load_start;
extern char __bss_start, __bss_end, __stack_top;

void *__stack_pointer = &__stack_top;	/* 0x00 */
void (*__vectors[])(void) = {
	&__reset_handler,		/* 0x04 */
	&__stop_program,		/* 0x08 */
	&__stop_program,		/* 0x0C: hardfault */
	&__stop_program,		/* 0x10: memorymanagement */
	&__stop_program,		/* 0x14: busfault */
	&__stop_program,		/* 0x18: usagefault */
	NULL,				/* 0x1C */
	NULL,				/* 0x20 */
	NULL,				/* 0x24 */
	NULL,				/* 0x28 */
	&__stop_program,		/* 0x2C: svc */
	&__stop_program,		/* 0x30: debugmon */
	NULL,				/* 0x34 */
	&__stop_program,		/* 0x38: pendsv */
	&__stop_program,		/* 0x3C: systick */
	&__stop_program,		/* 0x40: powerclock */
	&__stop_program,		/* 0x44: radio */
	&__stop_program,		/* 0x48: uarte0uart0 */
	&__stop_program,		/* 0x4C: spim0spis0twim0twis0spi0twi0 */
	&__stop_program,		/* 0x50: spim1spis1twim1twis1spi1twi1 */
	&__stop_program,		/* 0x54: nfct */
	&__stop_program,		/* 0x58: gpiote */
	&__stop_program,		/* 0x5C: saadc */
	&__stop_program,		/* 0x60: timer0 */
	&__stop_program,		/* 0x64: timer1 */
	&__stop_program,		/* 0x68: timer2 */
	&__stop_program,		/* 0x6C: rtc0 */
	&__stop_program,		/* 0x70: temp */
	&__stop_program,		/* 0x74: srng */
};

void
__reset_handler(void)
{
	volatile char *src, *dst;

	src = &__data_load_start;
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
