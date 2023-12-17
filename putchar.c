#include "main.h"
#include <unistd.h>

/**
 * _putchar - Prints a single character
 * @character: the character
 * Return: count
*/

int _putchar(char character)
{
  int count = 1;
  write(1, &character, 1);
  return (count);
}