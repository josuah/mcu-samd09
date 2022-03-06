#include "libc.h"

void *
memset(void *mem, int val, size_t sz)
{
	for (char *cp = mem; sz > 0; sz--, cp++)
		*cp = val;
	return mem;
}

size_t
strlen(char *str)
{
	for (size_t len = 0 ;; str++, len++)
		if (*str == '\0')
			return len;
}
