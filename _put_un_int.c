#include "main.h"
#include <unistd.h>
#define BUFFER_SIZE 20

/*int _put_un_int(unsigned int un_integer)
{
  int count = 0;
  unsigned int base_value = 0;
  int i, j;
  char buffer[BUFFER_SIZE];
  unsigned int temp;
  temp = un_integer;


  do
  {
    buffer[count++] = (temp % 10) + '0';
    temp /= 10;
  } while (temp > base_value);

  Reverse */
  /*for (i = 0, j = count - 1; i < j; i++, j--)
  {
    char temp = buffer[i];
    buffer[i] = buffer[j];
    buffer[j] = temp;
  }
  write(1, buffer, count);

  return (count);
} */

int _rec_put_un_int(unsigned int un_integer)
{
  int count = 0;

  if (un_integer == 0)
  {
    return (1);
  }

  count += _rec_put_un_int(un_integer / 10);
  _putchar(un_integer % 10 + '0');

  return (count + 1);
}

int _put_un_int(unsigned int un_integer, int flag_hash, int field_width)
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
  if (un_integer == 0)
  {
    _putchar('0');
    count++;

  }

    count += _rec_put_un_int(un_integer);

  return (count);
}