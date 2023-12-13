#include "main.h"		/* Include the main header file */
#include <stdarg.h> /* Include the standard arguments library */

/**
 * case_s - Handles the 's' format specifier
 * @args: The list of arguments
 *
 * Return: The number of characters printed
 *
 * This function handles the 's' format specifier for _printf. It prints a string to stdout.
 * For example, _printf("%s", "Hello, World!") will print "Hello, World!".
 */
int case_s(va_list args)
{
	int count = 0;					/* Initialize count */
	unsigned int str_count; /* Declare variable for the count of string characters */

	char *string = va_arg(args, char *); /* Get the string from the arguments list */

	/* Check if the string is not NULL and not empty */
	if (string != NULL && *string != '\0')
	{
		str_count = _putstr(string); /* Print the string and get the count of string characters */
		count += str_count;					 /* Add the count of string characters to the total count */
	}

	return (count); /* Return the count */
}