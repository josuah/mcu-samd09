
ENTRY(__reset_handler)

SECTIONS {
	.text : {
		KEEP(*(.data.__bootloader))
		KEEP(*(.data.__stack_pointer))
		KEEP(*(.data.__vectors))
		. = ALIGN(4);
		*(.text .text.*)
		KEEP(*(.text.interrupt_*))
		*(.rodata .rodata.*)
	} > ROM

	.data : {
		PROVIDE(__data_start = .);
		*(.data .data.*)
		PROVIDE(__data_end = .);
	} > RAM AT> ROM

	.bss ADDR(.data) + SIZEOF (.data) : AT (ADDR (.bss)) {
		PROVIDE(__bss_start = .);
		*(.bss)
		PROVIDE(__bss_end = .);
	} > RAM

	__data_load_start = LOADADDR(.data);
	__data_load_end = __data_load_start + SIZEOF(.data);
	__stack_top = ORIGIN(RAM) + LENGTH(RAM);
}
