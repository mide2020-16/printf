#include "main.h"   /* Include the main header file */
#include <unistd.h> /* Include the unistd library for write() */

/**
 * _rec_put_hex - Recursively prints a hexadecimal number
 * @hexa: The hexadecimal number
 * @uppercase: The uppercase flag
 *
 * Return: The number of characters printed
 *
 * This function recursively prints a hexadecimal number to stdout.
 * It divides the hexadecimal number by 16 and calls itself with the quotient until the hexadecimal number is 0.
 * Then it prints the remainder of the hexadecimal number divided by 16.
 * If the remainder is less than 10, it prints the remainder as a digit.
 * Otherwise, it prints the remainder as a letter, in uppercase if the uppercase flag is set, or in lowercase otherwise.
 */
int _rec_put_hex(unsigned int hexa, int uppercase)
{
  int count = 0;          /* Initialize count */
  unsigned int remainder; /* Declare variable for the remainder */

  /* Check if the hexadecimal number is 0 */
  if (hexa == 0)
  {
    return (0); /* Return 0 if the hexadecimal number is 0 */
  }

  count += _rec_put_hex(hexa / 16, uppercase); /* Divide the hexadecimal number by 16 and call itself with the quotient */
  remainder = hexa % 16;                       /* Get the remainder of the hexadecimal number divided by 16 */

  /* Check if the remainder is less than 10 */
  if (remainder < 10)
  {
    _putchar(remainder + '0'); /* Print the remainder as a digit */
  }
  else
  {
    char hexChar = (uppercase) ? 'A' + remainder - 10 : 'a' + remainder - 10; /* Get the remainder as a letter, in uppercase if the uppercase flag is set, or in lowercase otherwise */
    _putchar(hexChar);                                                        /* Print the remainder as a letter */
  }

  return (count + 1); /* Return the count plus 1 */
}

/**
 * _put_hex - Prints a hexadecimal number
 * @hexa: The hexadecimal number
 * @uppercase: The uppercase flag
 * @flag_hash: The hash flag
 * @field_width: The field width
 *
 * Return: The number of characters printed
 *
 * This function prints a hexadecimal number to stdout.
 * It prints spaces for the field width, a '#' character if the hash flag is set, and a '0' character if the hexadecimal number is 0.
 * Then it calls _rec_put_hex with the hexadecimal number and the uppercase flag and returns the count of hexadecimal digits.
 */
int _put_hex(unsigned int hexa, int uppercase, int flag_hash, int field_width)
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

  /* Check if the hexadecimal number is 0 */
  if (hexa == 0)
  {
    _putchar('0'); /* Print a '0' character */
    count++;       /* Increment the count */
  }

  count += _rec_put_hex(hexa, uppercase); /* Call _rec_put_hex with the hexadecimal number and the uppercase flag and add the count of hexadecimal digits to the total count */

  return (count); /* Return the count */
}