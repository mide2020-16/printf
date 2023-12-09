#include "main.h"
#include <unistd.h>


int _rec_put_octal(unsigned int octal)
{
  int count = 0;

  if (octal == 0)
  {
    count++;
  }
  else
  {
    count += _rec_put_octal(octal / 8);
    _putchar(octal % 8 + '0');

  }

  return (count);
}
int _put_octal(unsigned int octal, int flag_hash, int field_width)
{
  int count = 0;
  int f;

  for (f = 0; f < field_width; f++)
  {
    _putchar(' ');
    count++;
  }
  if (flag_hash)
  {
    _putchar('#');
    count++;
  }
  if (octal == 0)
  {
    _putchar('0');
    count++;
  }

  count += _rec_put_octal(octal);

  return (count);
}