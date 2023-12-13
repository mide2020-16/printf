#include "main.h"   /* Include the main header file */
#include <stdarg.h> /* Include the standard arguments library */

/**
 * case_d_i - Handles the 'd' and 'i' format specifiers
 * @args: The list of arguments
 * @length_mod: The length modifier
 * @flag_plus: The plus flag
 * @flag_space: The space flag
 * @field_width: The field width
 *
 * Return: The number of characters printed
 *
 * This function handles the 'd' and 'i' format specifiers for _printf. It prints an integer to stdout.
 * The length modifier can be 2 for long int, 1 for short int, or 0 for int.
 * The plus flag indicates whether to print a plus sign for positive numbers.
 * The space flag indicates whether to print a space before positive numbers.
 * The field width specifies the minimum number of characters to print.
 * For example, _printf("%+5d", 42) will print "  +42".
 */
int case_d_i(va_list args, int length_mod, int flag_plus, int flag_space, int field_width)
{
  int count = 0;                /* Initialize count */
  unsigned long int l_integer;  /* Declare variable for long int */
  unsigned short int s_integer; /* Declare variable for short int */
  unsigned int int_count;       /* Declare variable for the count of integer digits */

  /* Check the length modifier */
  if (length_mod == 2) /* If the length modifier is 2 */
  {
    l_integer = va_arg(args, long int);                                  /* Get the long int from the arguments list */
    int_count = _put_int(l_integer, flag_plus, flag_space, field_width); /* Print the long int and get the count of integer digits */
    count += int_count;                                                  /* Add the count of integer digits to the total count */
  }
  else if (length_mod == 1) /* If the length modifier is 1 */
  {
    s_integer = va_arg(args, int);                                       /* Get the short int from the arguments list */
    int_count = _put_int(s_integer, flag_plus, flag_space, field_width); /* Print the short int and get the count of integer digits */
    count += int_count;                                                  /* Add the count of integer digits to the total count */
  }
  else
  {
    int integer = va_arg(args, int);                                   /* Get the int from the arguments list */
    int_count = _put_int(integer, flag_plus, flag_space, field_width); /* Print the int and get the count of integer digits */
    count += int_count;                                                /* Add the count of integer digits to the total count */
  }

  return (count); /* Return the count */
}