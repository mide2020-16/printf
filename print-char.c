#include <stdarg.h>
#include "main.h"

/**
 * print_char - prints a character from va_list args
 * @args: arguments to print character from
 *
 * Return: number of character printed
 */
int print_char(va_list args)
{
	char c;

	c = va_arg(args, int);

	_putchar(c);
	return (1);
}
