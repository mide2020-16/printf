#include <unistd.h>
#include "main.h"

/**
 * _putsstr - Prints a string to stdout and return number of byte
 *
 * @str: A string of characters
 *
 * Return: Return the string
 */

int _putsstr(char *str)
{
	int count = 0;

	while (*str != '\0')
	{
		_putchar(*str);

		count++;

		str++;
	}
	return (count);
}
