#include "main.h"
#include <stdarg.h>


int case_p(va_list args, const char *format)
{
  int count = 0;
  unsigned int ptr_count;
  void *ptr = va_arg(args, void *);
  ptr_count = _put_pointer(ptr);
  count += ptr_count;
  format++;

  return (count);
}