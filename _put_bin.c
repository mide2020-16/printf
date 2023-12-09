#include <unistd.h>
#include "main.h"

int _rec_put_bin(unsigned int binary)
{
  int check, count;
  if (binary == 0)
  {
    return (1);
  }
  check = binary / 2;
  count = _rec_put_bin(check);
  _putchar(binary % 2 + '0');

  return (count);
}


int _put_bin(unsigned int binary)
{
  unsigned int count = 0;
  count += _rec_put_bin(binary);
  return (count);
}

