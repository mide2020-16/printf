#include <stdarg.h>
#include "main.h"
#include <stdio.h>

/**
 * print_u_int - prints a decimal from va_list args
 * @args: arguments to print u_int from
 *
 * Return: number of character printed
 */
int print_u_int(va_list args)
{
	int d, printed;

	d = va_arg(args, unsigned int);

	printf("the number is %d\n", d);

	printed = count_number(d);

	print_number(d);

	return (printed);
}
