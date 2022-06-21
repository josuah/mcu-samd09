CFLAGS = -Wall -Wextra -std=c99 -pedantic -ggdb
OBJ = arm32_aeabi_divmod.o arm32_aeabi_divmod_a32.o libc.o libsamd09.o \
	example.o
include libsamd09.mk
