

int case_d_i(va_list args, int length_mod, int flag_plus, int flag_space, int field_width)
{
  int count = 0;
  unsigned long int l_integer;
  unsigned short int s_integer;
  unsigned int int_count;

  if (length_mod == 2)
  {
    l_integer = va_arg(args, long int);
    int_count = _put_int(l_integer, flag_plus, flag_space, field_width);
    count += int_count;
  }
  else if (length_mod == 1)
  {
    s_integer = va_arg(args, int);
    int_count = _put_int(s_integer, flag_plus, flag_space, field_width);
    count += int_count;
  }
  else
  {
    int integer = va_arg(args, int);
    int_count = _put_int(integer, flag_plus, flag_space, field_width);
    count += int_count;
  }
  return (count);
}