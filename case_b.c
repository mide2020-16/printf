#include "main.h"   /* Include the main header file */
#include <stdarg.h> /* Include the standard arguments library */

/**
 * case_b - Handles the 'b' format specifier
 * @args: The list of arguments
 *
 * Return: The number of characters printed
 *
 * This function handles the 'b' format specifier for _printf. It prints a binary number to stdout.
 * For example, _printf("%b", 5) will print "101".
 */

int case_b(va_list args)
{
  int count = 0; /* Initialize count */
  unsigned int binary, bin_count; /* Declare variables for the binary number and the count of binary digits */

  binary = va_arg(args, unsigned int); /* Get the binary number from the arguments list */
  bin_count = _put_bin(binary); /* Print the binary number and get the count of binary digits */
  count += bin_count; /* Add the count of binary digits to the total count */

  return (count); /* Return the count */
}