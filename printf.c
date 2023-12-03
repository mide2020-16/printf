#include "main.h"
#include <stdlib.h>
#include <stdarg.h>

/**
 * _printf - Prints a format to stdout
 *
 * @format: the strig to parse
 *
 * Return: Count as Success
 */

int _printf(const char *format, ...)
{
	unsigned int str_count = 0, count = 0;
	va_list args;

	va_start(args, format);

	while (*format != '\0' && format != NULL)
	{
		if (*format == '%')
		{
			format++;
			count++;
			switch (*format)
			{
				case 'c':
					char chr = (char)va_arg(args, int);

					_putchar(chr);
					format++;
					count++;					}
				break;
				case 's':
				{
					char *str = va_arg(args, char *);

					str_count = _putsstr(*str);
					count = count + str_count;
					_putsstr(*str);
					format++;
					break;
				}
				case '%':
					_putchar('%');
					break;
				default:
					break;
			}
		_putchar(*format);
		*format++;
	}
	va_end(args);
	return (count);
}
