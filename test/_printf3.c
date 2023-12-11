#include "main.h"
#include <stdarg.h>

/**
 * _printf - Pirnts content to stdout
 * @format - format to print
 * Return - number of counts
*/
int _printf(const char *format, ...)
{
	unsigned int count = 0, binary, bin_count;
	va_list args;
	va_start(args, format);

	while (format != NULL && *format != '\0')
	{
		if (*format == '%')
		{
			format++;
			count++;

			switch (*format)
			{
				case 'b':
        {
          binary = va_arg(args, unsigned int);
          bin_count = _put_bin(binary);
          count += bin_count;
          break;
        }
				default:
				{
					_putchar('%');
					_putchar(*format);
					count += 2;
				}
				break;
				}
		}
		else 
		{
			_putchar(*format);
			count++;
		}
		format++;
	}
	va_end(args);

	return (count);

)
