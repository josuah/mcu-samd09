#ifndef LIBC_H
#define LIBC_H

/* <stddef.h> */

#define NULL ((void *)0)
typedef unsigned int size_t;
typedef signed int ssize_t;

/* <stdint.h> */

typedef unsigned char	uint8_t;
typedef unsigned short	uint16_t;
typedef unsigned int	uint32_t;
typedef unsigned long	uint64_t;
typedef signed char	int8_t;
typedef signed short	int16_t;
typedef signed int	int32_t;
typedef signed long	int64_t;
#define UINT8_MAX	0xFFu
#define UINT16_MAX	0xFFFFul
#define UINT32_MAX	0xFFFFFFFFul
#define UINT64_MAX	0xFFFFFFFFFFFFFFFFull

/* <string.h> */

void *memset(void *mem, int val, size_t sz);
size_t strlen(char *str);

/* <assert.h> */

#ifdef NDEBUG
#define assert(expr)	0
#else /* endless loop visible in-place with a debugger */
#define assert(expr)	if (!(expr)) for (char volatile i ;; i++)
#endif

#endif
