#include "main.h"   /* Include the main header file */
#include <stdarg.h> /* Include the standard arguments library */

/**
 * case_o - Handles the 'o' format specifier
 * @args: The list of arguments
 * @length_mod: The length modifier
 * @flag_hash: The hash flag
 * @field_width: The field width
 *
 * Return: The number of characters printed
 *
 * This function handles the 'o' format specifier for _printf. It prints an octal number to stdout.
 * The length modifier can be 2 for long int, 1 for short int, or 0 for int.
 * The hash flag indicates whether to print a '0' prefix for non-zero octal numbers.
 * The field width specifies the minimum number of characters to print.
 * For example, _printf("%#5o", 42) will print "  052".
 */

int case_o(va_list args, int length_mod, int flag_hash, int field_width)
{
  int count = 0;                   /* Initialize count */
  unsigned long int l_octal;       /* Declare variable for long int */
  unsigned short int s_octal;      /* Declare variable for short int */
  unsigned int octal, octal_count; /* Declare variables for the octal number and the count of octal digits */

  /* Check the length modifier */
  if (length_mod == 2)
  {
    l_octal = va_arg(args, unsigned long int);                 /* Get the long int from the arguments list */
    octal_count = _put_octal(l_octal, flag_hash, field_width); /* Print the long int in octal and get the count of octal digits */
    count += octal_count;                                      /* Add the count of octal digits to the total count */
  }
  else if (length_mod == 1)
  {
    s_octal = va_arg(args, int);                               /* Get the short int from the arguments list */
    octal_count = _put_octal(s_octal, flag_hash, field_width); /* Print the short int in octal and get the count of octal digits */
    count += octal_count;                                      /* Add the count of octal digits to the total count */
  }
  else
  {
    octal = va_arg(args, unsigned int);                      /* Get the int from the arguments list */
    octal_count = _put_octal(octal, flag_hash, field_width); /* Print the int in octal and get the count of octal digits */
    count += octal_count;                                    /* Add the count of octal digits to the total count */
  }

  return (count); /* Return the count */
}
