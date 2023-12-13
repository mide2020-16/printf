#include <unistd.h> /* Include the unistd library for write() */
#include "main.h"   /* Include the main header file */

/**
 * _rec_put_bin - Recursively prints a binary number
 * @binary: The binary number
 *
 * Return: The number of characters printed
 *
 * This function recursively prints a binary number to stdout.
 * It divides the binary number by 2 and calls itself with the quotient until the binary number is 0.
 * Then it prints the remainder of the binary number divided by 2.
 */
int _rec_put_bin(unsigned int binary)
{
  int check, count; /* Declare variables for the quotient and the count of binary digits */

  /* Check if the binary number is 0 */
  if (binary == 0)
  {
    return (1); /* Return 1 if the binary number is 0 */
  }

  check = binary / 2;          /* Divide the binary number by 2 */
  count = _rec_put_bin(check); /* Call itself with the quotient */
  _putchar(binary % 2 + '0');  /* Print the remainder of the binary number divided by 2 */

  return (count); /* Return the count */
}

/**
 * _put_bin - Prints a binary number
 * @binary: The binary number
 *
 * Return: The number of characters printed
 *
 * This function prints a binary number to stdout.
 * It calls _rec_put_bin with the binary number and returns the count of binary digits.
 */
int _put_bin(unsigned int binary)
{
  unsigned int count = 0; /* Initialize count */

  count += _rec_put_bin(binary); /* Call _rec_put_bin with the binary number and add the count of binary digits to the total count */

  return (count); /* Return the count */
}