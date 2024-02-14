#include <stdarg.h>
#include "main.h"

/**
 * print_integer - prints a integer from va_list args
 * @args: arguments to print integer from
 *
 * Return: number of character printed
 */
int print_integer(va_list args)
{
	int d, printed;

	d = va_arg(args, int);

	printed = count_number(d);

	if (d < 0)
	{
		_putchar('-');
		++printed;
	}
	d = -(d);
	print_number(d);

	return (printed);
}
