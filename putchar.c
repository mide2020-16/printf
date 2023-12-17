#include "main.h"
#include <unistd.h>


int _putchar(char character)
{
  return (write(1, &character, 1));
}