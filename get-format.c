#include <stdarg.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include "main.h"

/**
 * get_format_function - gets the right function for a format
 * specifier
 * @c: character of the specifier
 *
 * Return: number of characters printed
 */
int (*get_format_function(char c))(va_list args)
{
	size_t i, array_length;
	sp_f formats[] = {
		{'c', print_char},
		{'s', print_string},
		{'d', print_decimal},
		{'i', print_integer},
		{'%', print_percent},
		{'b', print_binary},
		{'o', print_octal},
		{'u', print_u_int},
		{'x', print_hex_a},
		{'X', print_hex_A}
	};

	array_length = sizeof(formats) / sizeof(formats[0]);

	for (i = 0; i < array_length; ++i)
	{
		if (formats[i].format == c)
			return (formats[i].f);
	}
	return (NULL);
}
