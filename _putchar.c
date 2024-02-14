#include <unistd.h>
#include "main.h"
/**
 * _putchar - prints a character to standard output
 * @c: character to print
 *
 */
void _putchar(char c)
{
	char add = c;

	write(STDOUT_FILENO, &add, sizeof(char));
}
