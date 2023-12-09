#include "main.h"
#include <stdarg.h>

/**
 * _printf - Pirnts content to stdout
 * @format - format to print
 * Return - number of counts
*/
int _printf(const char *format, ...)
{
	unsigned int count = 0, str_count, int_count, binary, bin_count, un_integer, un_int_count, octal,
							 octal_count, sm_hexa, sm_hexa_count, lg_hexa, lg_hexa_count, ptr_count;
	unsigned short int s_integer, s_un_integer, s_octal, s_hexa;
	unsigned long int l_integer, l_un_integer, l_octal, l_hexa;

	int flag_plus, flag_space, flag_hash, length_mod = 0, field_width = 0;
	va_list args;
	va_start(args, format);

	while (format != NULL && *format != '\0')
	{
		if (*format == '%')
		{
			format++;
			count++;

			flag_plus = 0;
			flag_space = 0;
			flag_hash = 0;

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
			field_width = 0;
			while (*format >= '0' && *format <= '9')
			{
				field_width = field_width * 10 + (*format - '0');
				count++;
			}

			length_mod = 0;
			while (*format == 'h' || *format == 'l')
			{
				if (*format == 'h')
				{
					length_mod = (length_mod < 1) ? 1 : 2;
				}
				else 
				{
					length_mod = 2;
				}
				count++;
			}
			
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
						break;
					}
					break;
				}
				case 'd':
				case 'i':
				{
					if (length_mod == 2)
					{
						l_integer = va_arg(args, long int);
						int_count = _put_int(l_integer, flag_plus, flag_space, field_width);
						count += int_count;
					}
					else if (length_mod == 1) 
					{
						s_integer = va_arg(args, int);
						int_count = _put_int(s_integer, flag_plus, flag_space, field_width);
						count += int_count;
					}
					else
					{
						int integer = va_arg(args, int);
						int_count = _put_int(integer, flag_plus, flag_space, field_width);
						count += int_count;
					}
					
					break;
				}
				case 'b':
				{
					binary = va_arg(args, unsigned int);
					bin_count = _put_bin(binary);
					count += bin_count;
					break;
				}
				case 'u':
				{
					if (length_mod == 2)
					{
						l_un_integer = va_arg(args, unsigned long int);
						un_int_count = _put_un_int(l_un_integer, flag_hash, field_width);
						count += un_int_count;
					}
					else if (length_mod == 1)
					{
						s_un_integer = va_arg(args, int);
						un_int_count = _put_un_int(s_un_integer, flag_hash, field_width);
						count += un_int_count;
					}
					else
					{
						un_integer = va_arg(args, unsigned int);
						un_int_count = _put_un_int(un_integer, flag_hash, field_width);
						count += un_int_count;
					}
					break;
				}
				case 'o':
				{
					if (length_mod == 2)
					{
						l_octal = va_arg(args, unsigned long int);
						octal_count = _put_octal(l_octal, flag_hash, field_width);
						count += octal_count;
					}
					else if (length_mod == 1)
					{
						s_octal = va_arg(args, int);
						octal_count = _put_octal(s_octal, flag_hash, field_width);
						count += octal_count;
					}
					else
					{
						octal = va_arg(args, unsigned int);
						octal_count = _put_octal(octal, flag_hash, field_width);
						count += octal_count;
					}
					break;
				}
				case 'x':
				{
					if (length_mod == 2)
					{
						l_hexa = va_arg(args, unsigned long int);
						sm_hexa_count = _put_hex(l_hexa, 0, flag_hash, field_width);
						count += sm_hexa_count;
					}
					else if (length_mod == 1)
					{
						s_hexa = va_arg(args, int);
						sm_hexa_count = _put_hex(s_hexa, 0, flag_hash, field_width);
						count += sm_hexa_count;
					}
					else
					{
						sm_hexa = va_arg(args, unsigned int);
						sm_hexa_count = _put_hex(sm_hexa, 0, flag_hash, field_width);
						count += sm_hexa_count;
					}
					break;
				}
				case 'X':
				{
					if (length_mod == 2)
					{
						l_hexa = va_arg(args, unsigned long int);
						lg_hexa_count = _put_hex(l_hexa, 1, flag_hash, field_width);
						count += lg_hexa_count;
					}
					if (length_mod == 1)
					{
						s_hexa = va_arg(args, int);
						lg_hexa_count = _put_hex(s_hexa, 1, flag_hash, field_width);
						count += lg_hexa_count;
					}
					else
					{
						lg_hexa = va_arg(args, unsigned int);
						lg_hexa_count = _put_hex(lg_hexa, 1, flag_hash, field_width);
						count += lg_hexa_count;
					}
					break;
				}
				case 'S':
				{
					char *string = va_arg(args, char *);
					str_count = _put_String(string);
					count += str_count;
					format++;
					break;
				}
				case 'p':
				{
					void *ptr = va_arg(args, void *);
					ptr_count = _put_pointer(ptr);
					count += ptr_count;
					format++;
					break;
				}
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