#include "main.h"
#include <stdlib.h>

/**
 * print_binary - prints the binary representation of a number
 * @number: number to print in binary
 * Return: void
 */

int print_binary(unsigned int number)
{
  int count = 0;

  if (number > 1)
  {
		count += print_binary(number >> 1);
  }
	_putchar((number & 1) + '0');

  return (count + 1);
}