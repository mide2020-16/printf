#include "main.h"
#include <stdarg.h>

int case_b(va_list args)
{
  int count = 0;
  unsigned int binary, bin_count;

  binary = va_arg(args, unsigned int);
  bin_count = _put_bin(binary);
  count += bin_count;

  return (count);
}