#include "main.h"
#include <unistd.h>

/**
 * recursively_print_unsigned_integer - Recursively prints an unsigned integer
 * @integer: The unsigned integer
 * Return: The number of characters printed
 */

int recursively_print_unsigned_integer(unsigned int integer)
{
  int count = 0;

  /* Check if the unsigned integer is 0 */
  if (integer == 0)
  {
    return (1);
  }

  count += recursively_print_unsigned_integer(integer / 10);
  _putchar(integer % 10 + '0');

  return (count + 1);
}

/**
 * print_unsigned_int - Prints an unsigned integer
 * @integer: The unsigned integer
 * @flag_hash: The hash flag
 * @field_width: The field width
 * Return: The number of characters printed
 */

int print_unsigned_int(unsigned int integer, int flag_hash, int field_width)
{
  int count = 0;
  int f;

  /* Print spaces for the field width */
  for (f = 0; f < field_width; f++)
  {
    _putchar(' ');
    count++;
  }

  /* Check if the hash flag is set */
  if (flag_hash)
  {
    _putchar('#');
    count++;
  }

  /* Check if the unsigned integer is 0 */
  if (integer == 0)
  {
    _putchar('0');
    count++;
  }

  count += recursively_print_unsigned_integer(integer);

  return (count);
}