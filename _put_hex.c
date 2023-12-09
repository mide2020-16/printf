#include "main.h"
#include <unistd.h>


int _rec_put_hex(unsigned int hexa, int uppercase)
{
  int count = 0;
  unsigned int remainder;

  if (hexa == 0)
  {
    return (0);
  }
	count += _rec_put_hex(hexa / 16, uppercase);
	remainder = hexa % 16;

	if (remainder < 10)
	{
		_putchar(remainder + '0');
	}
	else
	{
		char hexChar = (uppercase) ? 'A' + remainder - 10 : 'a' + remainder - 10;
		_putchar(hexChar);
	}
	return (count + 1);
}

int _put_hex(unsigned int hexa, int uppercase, int flag_hash, int field_width)
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
  
  if (hexa == 0)
  {
    _putchar('0');
    count++;
  }
  count += _rec_put_hex(hexa, uppercase);

  return (count);

}