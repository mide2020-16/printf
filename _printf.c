#include "main.h"
#include <stdarg.h>

/**
 * _printf - Prints content to stdout
 * @format - format to print
 * Return - number of counts
*/
int _printf(const char *format, ...)
{
	int flag_plus, flag_space, flag_hash, length_mod = 0, field_width = 0;
	va_list args;
	va_start(args, format);

	while (format != NULL && *format != '\0')
	{
		if (*format == '%')
		{
			format++;
			count++;
			flag_plus = 0, flag_space = 0, flag_hash = 0, field_width = 0, length_mod = 0;
			while (*format == '+' || *format == ' ' || *format == '#')
			{
				if (*format == '+')
					flag_plus = 1;
				else if (*format == ' ')
					flag_space = 1;
				else if (*format == '#')
					flag_hash = 1;
				format++;

			}
			while (*format >= '0' && *format <= '9')
			{
				field_width = field_width * 10 + (*format - '0');
				count++;
			}
			while (*format == 'h' || *format == 'l')
			{
				if (*format == 'h')
					length_mod = (length_mod < 1) ? 1 : 2;
				else 
					length_mod = 2;
				count++;
			}
			switch (*format)
			{
				case 'c':
					case_c(args);
					break;
				case 's':
					case_s(args)
					break;
				case 'd':
				case 'i':
					case_d_i(args, length_mod, flag_plus, flag_space, field_width);
					break;
				case 'b':
					case_b(args);
					break;
				case 'u':
					case_u(args, length_mod, flag_hash, field_width)
					break;
				case 'o':
					case_o(args, length_mod, flag_hash, field_width);
					break;
				case 'x':
					int case_x(args, length_mod, flag_hash, field_width, uppercase) 
					break;
				case 'X':
					int case_X(args, length_mod, flag_hash, field_width, uppercase);
					break;
				case 'S':
					int case_S(args, format);
					break;
				case 'p':
					int case_p(args, format);
					break;
				case '%':
				{
					_putchar('%');
					count++;
					format++;
				}
				default:
				{
					_putchar(*format);
					count++;
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
