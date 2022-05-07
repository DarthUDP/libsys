#include <sys_string.h>

volatile size_t __rsize_max = SIZE_MAX/2;


void *strcpy(char *__restrict dest, const char *__restrict src)
{
	while ((*dest++ = *src++))
		continue ;

	return dest;
}

void *strcpyn(char *__restrict dest, const char *__restrict src, rsize_t count)
{
	rsize_t i;
	i = 0;

	while ((*dest++ = *src++) && i++ < count)
		continue ;

	return dest;
}

void *memcpy(void *__restrict dest, const void * __restrict src, size_t count)
{
	rsize_t i;

	for (i = 0; i < count; i++)
		*((uint8_t *)dest + i) = *((uint8_t *)src + i);

	return dest;
}

errno_t memcpy_s(void *__restrict dest, rsize_t destsz, const void *__restrict src, rsize_t count)
{
	// Assert we have the handler set before doing anything else
	SYS_ASSERT_HANDLER()

	// Safety checks
	if (dest == NULL)
		__sys_current_constraint_handler("Destination was a NULL", NULL, 1);

	if (src == NULL)
		__sys_current_constraint_handler("Source was a NULL", NULL, 1);

	if (destsz > RSIZE_MAX)
		__sys_current_constraint_handler("Provided destsz is bigger than RSIZE_MAX", NULL, 2);

	if (count > RSIZE_MAX)
		__sys_current_constraint_handler("Provided count is bigger than RSIZE_MAX", NULL, 2);

	memcpy(dest, src, count);

	return 0;
}

rsize_t strlen(const char *__restrict str, rsize_t max)
{
	rsize_t i;

	for (i = 0; i < max; i++)
		if (str[i] == 0)
			return i;

	return SIZE_MAX;
}
