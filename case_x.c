#include "main.h"   /* Include the main header file */
#include <stdarg.h> /* Include the standard arguments library */

/**
 * case_x - Handles the 'x' and 'X' format specifiers
 * @args: The list of arguments
 * @length_mod: The length modifier
 * @flag_hash: The hash flag
 * @field_width: The field width
 * @uppercase: The uppercase flag
 *
 * Return: The number of characters printed
 *
 * This function handles the 'x' and 'X' format specifiers for _printf. It prints a hexadecimal number to stdout.
 * The length modifier can be 2 for long int, 1 for short int, or 0 for int.
 * The hash flag indicates whether to print a '0x' or '0X' prefix for non-zero hexadecimal numbers.
 * The field width specifies the minimum number of characters to print.
 * The uppercase flag indicates whether to print the hexadecimal digits in uppercase or lowercase.
 * For example, _printf("%#5x", 42) will print "  0x2a", and _printf("%#5X", 42) will print "  0X2A".
 */
int case_x(va_list args, int length_mod, int flag_hash, int field_width, int uppercase)
{
  int count = 0;                       /* Initialize count */
  unsigned long int l_hexa;            /* Declare variable for long int */
  unsigned short int s_hexa;           /* Declare variable for short int */
  unsigned int sm_hexa_count, sm_hexa; /* Declare variables for the hexadecimal number and the count of hexadecimal digits */

  /* Check the length modifier */
  if (length_mod == 2)
  {
    l_hexa = va_arg(args, unsigned long int);                            /* Get the long int from the arguments list */
    sm_hexa_count = _put_hex(l_hexa, uppercase, flag_hash, field_width); /* Print the long int in hexadecimal and get the count of hexadecimal digits */
    count += sm_hexa_count;                                              /* Add the count of hexadecimal digits to the total count */
  }
  else if (length_mod == 1)
  {
    s_hexa = va_arg(args, int);                                          /* Get the short int from the arguments list */
    sm_hexa_count = _put_hex(s_hexa, uppercase, flag_hash, field_width); /* Print the short int in hexadecimal and get the count of hexadecimal digits */
    count += sm_hexa_count;                                              /* Add the count of hexadecimal digits to the total count */
  }
  else
  {
    sm_hexa = va_arg(args, unsigned int);                                 /* Get the int from the arguments list */
    sm_hexa_count = _put_hex(sm_hexa, uppercase, flag_hash, field_width); /* Print the int in hexadecimal and get the count of hexadecimal digits */
    count += sm_hexa_count;                                               /* Add the count of hexadecimal digits to the total count */
  }

  return (count); /* Return the count */
}