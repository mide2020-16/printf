#include "main.h"
#include <stdarg.h>

/**
 * _printf - Pirnts content to stdout
 * @format - format to print
 * Return - number of counts
*/
int _printf(const char *format, ...)
{
  unsigned int count = 0, str_count;
  unsigned int int_count;
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
				case 'c':
				{
					char character = (char)va_arg(args, int);
					_putchar(character);
					count++;
					break;
				}
				case 's':
				{
					char *string = va_arg(args, char *);

					if (string != NULL && *string != '\0')
					{
						str_count = _putstr(string);
						count += str_count;
					}
					break;
				}
				case '%':
				{
					_putchar('%');
					count++;
				}
				case 'd':
       	case 'i':
				{
					int integer = va_arg(args, int);
					int_count = _put_int(integer);
					count += int_count;
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

}
