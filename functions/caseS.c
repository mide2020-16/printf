#include "main.h"
#include <stdarg.h>

int case_S(va_list args, const char *format)
{
  int count = 0;
  unsigned int str_count;
  char *string = va_arg(args, char *);
  str_count = _put_String(string);
  count += str_count;
  format++;
  return (count);
}