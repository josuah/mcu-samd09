OBJCOPY = arm-none-eabi-objcopy
OBJDUMP = arm-none-eabi-objdump
CC = arm-none-eabi-gcc -mthumb -mcpu=cortex-m0plus -msoft-float -S
LD = arm-none-eabi-gcc -mthumb -mcpu=cortex-m0plus -msoft-float
AS = arm-none-eabi-as -mthumb
AR = arm-none-eabi-ar
CPP = arm-none-eabi-cpp
GDB = arm-none-eabi-gdb
OPENOCD = openocd -c 'set CPUTAPID 0x0bc11477' -f interface/stlink.cfg -f target/at91samdXX.cfg

SDK_OBJ = ${SDK}/init.o ${SDK}/port.o ${SDK}/clock.o ${SDK}/usart.o \
	${SDK}/libc.o ${SDK}/arm32_aeabi_divmod.o
SDK_CFLAGS = -ffunction-sections -fdata-sections
SDK_LDFLAGS = -T${SDK}/script.ld -nostartfiles -nostdlib -static -Wl,--gc-sections
SDK_CPPFLAGS = -I${SDK}

all: firmware.elf firmware.asm

clean:
	rm -f *.[os] ${SDK}/*.[os] *.asm *.elf *.map *.hex *.bin *.uf2

ocd:
	${OPENOCD}

gdb:
	${GDB} -x ${SDK}/script.gdb

firmware.elf: ${SDK_OBJ} ${OBJ}
	${LD} ${SDK_LDFLAGS} ${LDFLAGS} -o $@ ${SDK_OBJ} ${OBJ}

flash.avrdude: firmware.hex
	${AVRDUDE} -qu -P ${PORT} -U flash:w:firmware.hex

flash.dfuutil: firmware.bin
	${DFUUTIL} -D firmware.bin

flash.mount: firmware.uf2
	mount /mnt && cp firmware.uf2 /mnt

flash.openocd: firmware.hex
	${OPENOCD} -c 'program firmware.hex verify reset exit'

.SUFFIXES: .c .s .S .o .elf .bin .asm .hex .uf2

.c.o:

.c.s:
	${CC} ${SDK_CPPFLAGS} ${CPPFLAGS} ${SDK_CFLAGS} ${CFLAGS} -c -o $@ $<

.S.s:
	${CPP} ${SDK_CPPFLAGS} ${CPPFLAGS} -c -o $@ $<

.s.o:
	${AS} ${SDK_ASFLAGS} ${ASFLAGS} -c -o $@ $<

.elf.asm:
	${OBJDUMP} -z -d $< >$@

.elf.hex:
	${OBJCOPY} -j .text -j .data -O ihex $< $@

.elf.bin:
	${OBJCOPY} -j .text -j .data -O binary $< $@

.elf.uf2:
	elf2uf2 $< $@
