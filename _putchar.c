#include "main.h"
#include <unistd.h>

/**
 * _putchar - displays a character of type char to stdout
 *
 * @c: the character
 *
 * Return: c to stdout as a SUccess
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}
