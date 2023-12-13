#include "main.h"      /* Include the main header file */
#include <unistd.h>    /* Include the unistd library for write() */

/**
 * _rec_put_un_int - Recursively prints an unsigned integer
 * @un_integer: The unsigned integer
 *
 * Return: The number of characters printed
 *
 * This function recursively prints an unsigned integer to stdout.
 * It divides the unsigned integer by 10 and calls itself with the quotient until the unsigned integer is 0.
 * Then it prints the remainder of the unsigned integer divided by 10.
 */
int _rec_put_un_int(unsigned int un_integer)
{
  int count = 0; /* Initialize count */

  /* Check if the unsigned integer is 0 */
  if (un_integer == 0)
  {
    return (1); /* Return 1 */
  }

  count += _rec_put_un_int(un_integer / 10); /* Divide the unsigned integer by 10 and call itself with the quotient */
  _putchar(un_integer % 10 + '0');           /* Print the remainder of the unsigned integer divided by 10 */

  return (count + 1); /* Return the count plus 1 */
}

/**
 * _put_un_int - Prints an unsigned integer
 * @un_integer: The unsigned integer
 * @flag_hash: The hash flag
 * @field_width: The field width
 *
 * Return: The number of characters printed
 *
 * This function prints an unsigned integer to stdout.
 * It prints spaces for the field width, a '#' character if the hash flag is set, and a '0' character if the unsigned integer is 0.
 * Then it calls _rec_put_un_int with the unsigned integer and returns the count of digits.
 */
int _put_un_int(unsigned int un_integer, int flag_hash, int field_width)
{
  int count = 0; /* Initialize count */
  int f;         /* Declare variable for the loop counter */

  /* Print spaces for the field width */
  for (f = 0; f < field_width; f++)
  {
    _putchar(' '); /* Print a space */
    count++;       /* Increment the count */
  }

  /* Check if the hash flag is set */
  if (flag_hash)
  {
    _putchar('#'); /* Print a '#' character */
    count++;       /* Increment the count */
  }

  /* Check if the unsigned integer is 0 */
  if (un_integer == 0)
  {
    _putchar('0'); /* Print a '0' character */
    count++;       /* Increment the count */
  }

  count += _rec_put_un_int(un_integer); /* Call _rec_put_un_int with the unsigned integer and add the count of digits to the total count */

  return (count); /* Return the count */
}