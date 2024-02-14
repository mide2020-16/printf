#include <stdarg.h>
#include <stddef.h>
#include "main.h"


/**
 * print_string - prints a string from va_list args
 * @args: arguments to print string from
 *
 * Return: number of character printed
 */
int print_string(va_list args)
{
	char *s;
	int size = 0, i;
	char *nil = "(null)";

	s = va_arg(args, char *);

	if (s == NULL)
	{
		for (i = 0; nil[i] != '\0'; ++i)
		{
			_putchar(nil[i]);
			++size;
		}
	}
	else
	{
		for (i = 0; s[i] != '\0'; ++i)
		{
			_putchar(s[i]);
			++size;
		}
	}


	return (size);
}
