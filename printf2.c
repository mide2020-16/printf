#include "main.h"
#include <stdlib.h>

/**
 * _printf - pass the content of value to stdout
 *
 * @format: the content to display
 * Return : value
 *
 */

int _printf(const char *format, ...)
{
	unsigned int i, count;
	va_list args;
	
	va_start(args, format);
	while (format != NULL && *format != '\0')
	{
		if (*format == '%')
		{
			format++;
			count++;
			if (*format == 'd' || *format == 'i')
				{
					int integer = va_arg(args, int);			
					int digit = _print_int(integer)
					count += digit;
					format++;
				}
		}
		else
		{
			_putchar(*format);
			count++;
			format++;
		}
		format++;
	}
	va_end(args);
	return (count);
}