#include "libc.h"

void *
memset(void *mem, int val, size_t sz)
{
	for (char *mp = mem; sz > 0; sz--, mp++)
		*mp = val;
	return mem;
}

void *
memcpy(void *mem, void const *src, size_t sz)
{
	for (char *mp = mem, *sp = (char *)src; sz > 0; mp++, sp++)
		*mp = *sp;
	return mem;
}

size_t
strlen(char *str)
{
	for (size_t len = 0 ;; str++, len++)
		if (*str == '\0')
			return len;
}
