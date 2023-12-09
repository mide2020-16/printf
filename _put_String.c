#include "main.h"
#include <unistd.h>

int _put_String(char *string)
{
  int count = 0;
  while(*string != '\0')
  {
    if (*string < 32 || *string >= 127)
    {
      _putchar('\\');
      _putchar('x');
      count += 2;
      _put_hex(*string, 1, 0, 0);
      count += 2;
    }
    else
    {
      _putchar(*string);
      count++;
    }
  }
  return (count);
}