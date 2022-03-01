#include "libc.h"

void *
memset(void *mem, int val, size_t sz)
{
	for (char *cp = mem; sz > 0; sz--, cp++)
		*cp = val;
	return mem;
}
