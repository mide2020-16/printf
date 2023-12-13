#include "main.h"   /* Include the main header file */
#include <stdarg.h> /* Include the standard arguments library */

/**
 * case_u - Handles the 'u' format specifier
 * @args: The list of arguments
 * @length_mod: The length modifier
 * @flag_hash: The hash flag
 * @field_width: The field width
 *
 * Return: The number of characters printed
 *
 * This function handles the 'u' format specifier for _printf. It prints an unsigned integer to stdout.
 * The length modifier can be 2 for long int, 1 for short int, or 0 for int.
 * The hash flag is ignored for 'u' specifier.
 * The field width specifies the minimum number of characters to print.
 * For example, _printf("%5u", 42) will print "   42".
 */
int case_u(va_list args, int length_mod, int flag_hash, int field_width)
{
  int count = 0;                         /* Initialize count */
  unsigned long int l_un_integer;        /* Declare variable for long int */
  unsigned short int s_un_integer;       /* Declare variable for short int */
  unsigned int un_int_count, un_integer; /* Declare variables for the unsigned integer and the count of integer digits */

  /* Check the length modifier */
  if (length_mod == 2)
  {
    l_un_integer = va_arg(args, unsigned long int);                   /* Get the long int from the arguments list */
    un_int_count = _put_un_int(l_un_integer, flag_hash, field_width); /* Print the long int and get the count of integer digits */
    count += un_int_count;                                            /* Add the count of integer digits to the total count */
  }
  else if (length_mod == 1)
  {
    s_un_integer = va_arg(args, int);                                 /* Get the short int from the arguments list */
    un_int_count = _put_un_int(s_un_integer, flag_hash, field_width); /* Print the short int and get the count of integer digits */
    count += un_int_count;                                            /* Add the count of integer digits to the total count */
  }
  else
  {
    un_integer = va_arg(args, unsigned int);                        /* Get the int from the arguments list */
    un_int_count = _put_un_int(un_integer, flag_hash, field_width); /* Print the int and get the count of integer digits */
    count += un_int_count;                                          /* Add the count of integer digits to the total count */
  }

  return (count); /* Return the count */
}