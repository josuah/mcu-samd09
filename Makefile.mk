OBJCOPY = arm-none-eabi-objcopy
OBJDUMP = arm-none-eabi-objdump
CC = arm-none-eabi-gcc -mcpu=cortex-m0plus -mthumb -msoft-float --specs=nosys.specs
AR = arm-none-eabi-ar
GDB = arm-none-eabi-gdb
OPENOCD = openocd -c 'set CPUTAPID 0x0bc11477' -f interface/stlink.cfg -f target/at91samdXX.cfg

SDK_OBJ = ${SDK}/init.o
SDK_CFLAGS = -ffunction-sections -fdata-sections
SDK_LDFLAGS = -T${SDK}/script.ld -nostartfiles -static -Wl,--gc-sections
SDK_CPPFLAGS = -I${SDK}

all: firmware.elf firmware.asm

clean:
	rm -f *.o ${SDK}/*.o *.asm *.elf *.map *.hex *.bin *.uf2

ocd:
	${OPENOCD}

gdb:
	${GDB} -x ${SDK}/script.gdb

firmware.elf: ${SDK_OBJ} ${OBJ}
	${CC} ${SDK_LDFLAGS} ${LDFLAGS} -o $@ ${SDK_OBJ} ${OBJ}

flash.avrdude: firmware.hex
	${AVRDUDE} -qu -P ${PORT} -U flash:w:firmware.hex

flash.dfuutil: firmware.bin
	${DFUUTIL} -D firmware.bin

flash.mount: firmware.uf2
	mount /mnt && cp firmware.uf2 /mnt

flash.openocd: firmware.hex
	${OPENOCD} -c 'program firmware.hex verify reset exit'

.SUFFIXES: .c .S .o .elf .bin .asm .hex .uf2

.c.o:
	${CC} ${SDK_CPPFLAGS} ${CPPFLAGS} ${SDK_CFLAGS} ${CFLAGS} -c -o $@ $<

.S.o:
	${CC} ${SDK_CPPFLAGS} ${CPPFLAGS} ${SDK_CFLAGS} ${CFLAGS} -c -o $@ $<

.elf.asm:
	${OBJDUMP} -z -d $< >$@

.elf.hex:
	${OBJCOPY} -j .text -j .data -O ihex $< $@

.elf.bin:
	${OBJCOPY} -j .text -j .data -O binary $< $@

.elf.uf2:
	elf2uf2 $< $@
