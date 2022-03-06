#ifndef LIBC_H
#define LIBC_H

/* C standard library that fits in a single header and source file */


/* <stddef.h> */

#define NULL ((void *)0)


/* <string.h> */

typedef unsigned int size_t;
typedef signed int ssize_t;

void *memset(void *mem, int val, size_t sz);
size_t strlen(char *str);


/* <stdint.h> */

typedef unsigned char	uint8_t;
typedef unsigned short	uint16_t;
typedef unsigned int	uint32_t;
typedef unsigned long	uint64_t;

typedef signed char	int8_t;
typedef signed short	int16_t;
typedef signed int	int32_t;
typedef signed long	int64_t;

#endif
