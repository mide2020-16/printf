#include "main.h"
#include <stdarg.h>

/**
 * _printf - Prints content to stdout
 * @format: The format to print the content in
 * Return: Number of characters printed (excluding the null byte used to end output to strings
 *
 * This function is similar to printf. For example, _printf("Hello %s", "World") will print "Hello World".
 */

int _printf(const char *format, ...)
{
  unsigned long int long_integer;
  unsigned short int short_integer;
  unsigned int binary;
  char character;
  char *string;
  int count = 0, length_modifier = 0, flag_space = 0, flag_plus = 0, field_width = 0, integer;
  va_list args;

  va_start(args, format);

  if (format == NULL)
  {
    return 0;
  }

  while (*format != '\0')
  {
    if (*format == '%')
    {
      format++;
      count++;

      /*Flag adjuster*/
      while (*format == '+' || *format == ' ')
      {
        if (*format == '+')
          flag_plus = 1;
        else if (*format == ' ')
          flag_space = 1;
      }
      /*Calculate field width*/
      while (*format >= '0' && *format <='9')
        field_width = field_width * 10 + (*format - '0');

      /*Calculate length modifier*/
      while (*format == 'h' || *format == 'l')
      {
        if (*format == 'h')
          length_modifier = (length_modifier > 1) ? 1 : 2;
      }

      switch (*format)
      {
      case 'c':
        character = (char)va_arg(args, int);
        count += _putchar(character);
        break;

      case 's':
        string = va_arg(args, char *);
        count += print_string(string);
        break;

      case '%':
        _putchar('%');
        count++;
        format++;
        break;

      case 'd':
      case 'i':
      {
        if (length_modifier == 2)
        {
          long_integer = va_arg(args, long int);
          count += print_integer(long_integer, flag_plus, flag_space, field_width);
        }
        else if (length_modifier == 1)
        {
          short_integer = va_arg(args, int);
          count += print_integer(short_integer, flag_plus, flag_space, field_width);
        }
        else
        {
          integer = va_arg(args, int);
          count += print_integer(integer, flag_plus, flag_space, field_width);
        }
      }
      break;

      case 'b':
        binary = va_arg(args, unsigned int);
        count += print_binary(binary);
        break;
      default:
        _putchar(*format);
        count++;
        break;
      }

      field_width = 0;
      flag_plus = 0;
      flag_space = 0;
    }
    else
    {
      count += _putchar(*format);
    }

    format++;
  }

  va_end(args);

  return (count - 1);
}