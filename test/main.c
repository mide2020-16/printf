#include <limits.h>
#include <stdio.h>
#include "main.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */

int main(void)
{
  int len, len2;

  len = _printf("Let's try to printf a simple sentence.\n");
  len2 = printf("Let's try to printf a simple sentence.\n");
  _printf("String:[%s] %% \n", "I am a string !");
  printf("String:[%s] %% \n", "I am a string !");
  _printf("Length:[%d, %i, %i]\n", len, len, -12222222);
  printf("Length:[%+d, %+i]\n", len2, len2);
  _printf("%b\n", "101");
  printf("%b\n", "101");
  return (0);
}