#include "main.h"
#include <unistd.h>

int _put_pointer(void *ptr)
{
  int count = 0;
  unsigned long address = (unsigned long)ptr;

  _putchar('0');
  _putchar('x');
  count += 2;

  count += _put_hex(address, 1, 0, 0);

  return (count);
}