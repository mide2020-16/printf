#include "main.h"
#include <stdarg.h>

int case_x(va_list args, int length_mod, int flag_hash, int field_width, int uppercase)
{
  int count = 0;

  unsigned long int l_hexa;
  unsigned short int s_hexa;
  unsigned int sm_hexa_count, sm_hexa;
  if (length_mod == 2)
  {
    l_hexa = va_arg(args, unsigned long int);
    sm_hexa_count = _put_hex(l_hexa, 0, flag_hash, field_width);
    count += sm_hexa_count;
  }
  else if (length_mod == 1)
  {
    s_hexa = va_arg(args, int);
    sm_hexa_count = _put_hex(s_hexa, 0, flag_hash, field_width);
    count += sm_hexa_count;
  }
  else
  {
    sm_hexa = va_arg(args, unsigned int);
    sm_hexa_count = _put_hex(sm_hexa, 0, flag_hash, field_width);
    count += sm_hexa_count;
  }
}