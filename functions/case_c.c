#include "main.h"
#include <stdarg.h>

int case_c(va_list args)
{
	int count = 0;
	char character = (char)va_arg(args, int);
	_putchar(character);
	count++;
	return (count);
}