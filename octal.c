#include <stdarg.h>
#include "main.h"

/**
 * print_octal - print a decimal number in octal form
 * @args: decimal number to print octal from
 *
 * Return: number of character printed
 */
int print_octal(va_list args)
{
	int d, printed, octal;

	d = va_arg(args, int);


	octal = convert_dec_to_octal(d);

	printed = count_number(octal);

	print_number(octal);

	return (printed);
}

/**
 * convert_dec_to_octal - converts decimal to octal
 * @n: number to convert
 *
 * Return: returns octal value
 */
int convert_dec_to_octal(int n)
{
	int octal = 0, remainder, decimal, position = 1;


	decimal = n;

	while (decimal > 0)
	{
		remainder = decimal % 8;
		decimal /= 8;
		octal += remainder * position;
		position *= 10;
	}

	return (octal);
}
