CFLAGS = -Wall -Wextra -std=c99 -pedantic -ggdb
OBJ = example.o ssd1306.o
SDK = .
include ${SDK}/script.mk
flash: flash.openocd
