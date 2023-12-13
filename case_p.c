#include "main.h"   /* Include the main header file */
#include <stdarg.h> /* Include the standard arguments library */

/**
 * case_p - Handles the 'p' format specifier
 * @args: The list of arguments
 * @format: The format string
 *
 * Return: The number of characters printed
 *
 * This function handles the 'p' format specifier for _printf. It prints a pointer to stdout.
 * The format string is incremented to skip the 'p' character.
 * For example, _printf("%p", &var) will print something like "0x7fffc6a04b58".
 */

int case_p(va_list args, const char *format)
{
  int count = 0;                    /* Initialize count */
  unsigned int ptr_count;           /* Declare variable for the count of pointer digits */
  void *ptr = va_arg(args, void *); /* Get the pointer from the arguments list */

  ptr_count = _put_pointer(ptr); /* Print the pointer and get the count of pointer digits */
  count += ptr_count;            /* Add the count of pointer digits to the total count */

  format++; /* Increment the format string to skip the 'p' character */

  return (count); /* Return the count */
}