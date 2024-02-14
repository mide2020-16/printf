#include <stdarg.h>
#include "main.h"

/**
 * print_binary - print a decimal number in binary form
 * @args: decimal number to print binary from
 *
 * Return: number of character printed
 */
int print_binary(va_list args)
{
	int d, printed, binary;

	d = va_arg(args, int);


	binary = convert_dec_to_bin(d);

	printed = count_number(binary);

	print_number(binary);

	return (printed);
}

/**
 * convert_dec_to_bin - converts decimal to binary
 * @n: number to convert
 *
 * Return: returns binary value
 */
int convert_dec_to_bin(int n)
{
	int binary = 0, remainder, decimal, position = 1;


	decimal = n;

	while (decimal > 0)
	{
		remainder = decimal % 2;
		decimal /= 2;
		binary += remainder * position;
		position *= 10;
	}

	return (binary);
}
