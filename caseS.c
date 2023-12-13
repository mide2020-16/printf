#include "main.h"   /* Include the main header file */
#include <stdarg.h> /* Include the standard arguments library */

/**
 * case_S - Handles the 'S' format specifier
 * @args: The list of arguments
 * @format: The format string
 *
 * Return: The number of characters printed
 *
 * This function handles the 'S' format specifier for _printf. It prints a string to stdout,
 * but non-printable characters (0 <= ascii value < 32 or ascii value >= 127) are printed as \x followed by the ASCII code value in hexadecimal.
 * The format string is incremented to skip the 'S' character.
 * For example, _printf("%S", "Hello\nWorld!") will print "Hello\x0aWorld!".
 */
int case_S(va_list args, const char *format)
{
  int count = 0;          /* Initialize count */
  unsigned int str_count; /* Declare variable for the count of string characters */

  char *string = va_arg(args, char *); /* Get the string from the arguments list */

  str_count = _put_String(string); /* Print the string and get the count of string characters */
  count += str_count;              /* Add the count of string characters to the total count */

  format++; /* Increment the format string to skip the 'S' character */

  return (count); /* Return the count */
}