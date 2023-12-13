#include "main.h"   /* Include the main header file */
#include <unistd.h> /* Include the unistd library for write() */

/**
 * _rec_put_octal - Recursively prints an octal number
 * @octal: The octal number
 *
 * Return: The number of characters printed
 *
 * This function recursively prints an octal number to stdout.
 * It divides the octal number by 8 and calls itself with the quotient until the octal number is 0.
 * Then it prints the remainder of the octal number divided by 8.
 */
int _rec_put_octal(unsigned int octal)
{
  int count = 0; /* Initialize count */

  /* Check if the octal number is 0 */
  if (octal == 0)
  {
    count++; /* Increment the count */
  }
  else
  {
    count += _rec_put_octal(octal / 8); /* Divide the octal number by 8 and call itself with the quotient */
    _putchar(octal % 8 + '0');          /* Print the remainder of the octal number divided by 8 */
  }

  return (count); /* Return the count */
}

/**
 * _put_octal - Prints an octal number
 * @octal: The octal number
 * @flag_hash: The hash flag
 * @field_width: The field width
 *
 * Return: The number of characters printed
 *
 * This function prints an octal number to stdout.
 * It prints spaces for the field width, a '#' character if the hash flag is set, and a '0' character if the octal number is 0.
 * Then it calls _rec_put_octal with the octal number and returns the count of octal digits.
 */
int _put_octal(unsigned int octal, int flag_hash, int field_width)
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

  /* Check if the octal number is 0 */
  if (octal == 0)
  {
    _putchar('0'); /* Print a '0' character */
    count++;       /* Increment the count */
  }

  count += _rec_put_octal(octal); /* Call _rec_put_octal with the octal number and add the count of octal digits to the total count */

  return (count); /* Return the count */
}