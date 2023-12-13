#include "main.h"		/* Include the main header file */
#include <stdarg.h> /* Include the standard arguments library */

/**
 * case_c - Handles the 'c' format specifier
 * @args: The list of arguments
 *
 * Return: The number of characters printed
 *
 * This function handles the 'c' format specifier for _printf. It prints a character to stdout.
 * For example, _printf("%c", 'A') will print "A".
 */

int case_c(va_list args)
{
	int count = 0; /* Initialize count */
	char character = (char)va_arg(args, int); /* Get the character from the arguments list */

	_putchar(character); /* Print the character */
	count++;						 /* Increment count */

	return (count); /* Return the count */
}