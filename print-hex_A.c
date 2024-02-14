#include <stdarg.h>
#include "main.h"


/**
 * print_hex_A - converts decimal to octal
 * @args: decimal number to print octal from
 *
 * Return: returns hexvalue
 */
int print_hex_A(va_list args)
{

	int remainder, decimal, position = 0, i, d;
	char hex_array[100];

	d = va_arg(args, int);



	decimal = d;

	while (decimal > 0)
	{
		remainder = decimal % 16;
		decimal /= 16;
		if (remainder > 9)
		{
			hex_array[++position] = remainder + 55;
		}
		else
		{
			hex_array[++position] = remainder + 48;

		}
	}

	for (i = position; i > 0; --i)
	{
		_putchar(hex_array[i]);
	}

	return (position);
}
