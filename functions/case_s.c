#include "main.h"
#include <stdarg.h>

int case_s(va_list args)
{
	int count = 0;
	unsigned int str_count;

	char *string = va_arg(args, char *);

	if (string != NULL && *string != '\0')
	{
		str_count = _putstr(string);
		count += str_count;
	}
	return (count);
}