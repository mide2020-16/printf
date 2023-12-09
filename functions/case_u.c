#include "main.h"
#include <stdarg.h>

int case_u(va_list args, int length_mod, int flag_hash, int field_width)
{
  int count = 0;

  unsigned long int l_un_integer;
  unsigned short int s_un_integer;
  unsigned int un_int_count, un_integer;

  if (length_mod == 2)
  {
    l_un_integer = va_arg(args, unsigned long int);
    un_int_count = _put_un_int(l_un_integer, flag_hash, field_width);
    count += un_int_count;
  }
  else if (length_mod == 1)
  {
    s_un_integer = va_arg(args, int);
    un_int_count = _put_un_int(s_un_integer, flag_hash, field_width);
    count += un_int_count;
  }
  else
  {
    un_integer = va_arg(args, unsigned int);
    un_int_count = _put_un_int(un_integer, flag_hash, field_width);
    count += un_int_count;
  }
}