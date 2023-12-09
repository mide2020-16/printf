



int case_o(va_list args, int length_mod, int flag_hash, int field_width)
{
  int count = 0;

  unsigned long int l_octal;
  unsigned short int s_octal;
  unsigned int octal, octal_count;

  if (length_mod == 2)
  {
    l_octal = va_arg(args, unsigned long int);
    octal_count = _put_octal(l_octal, flag_hash, field_width);
    count += octal_count;
  }
  else if (length_mod == 1)
  {
    s_octal = va_arg(args, int);
    octal_count = _put_octal(s_octal, flag_hash, field_width);
    count += octal_count;
  }
  else
  {
    octal = va_arg(args, unsigned int);
    octal_count = _put_octal(octal, flag_hash, field_width);
    count += octal_count;
  }
}