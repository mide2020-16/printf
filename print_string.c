#include "main.h"
#include <unistd.h>

#define BUF_SIZE 1024

/**
 * print_string - Prints a whole string to stdout
 * @string: the string to print out
 * Return: counts
*/
int print_string(char *string)
{
  char buffer[BUF_SIZE];
  int count, buf_count;

  count = 0;
  buf_count = 0;


  while (string != NULL && *string != '\0')
  {

    buffer[buf_count++] = *string;
    count++;
    string++;

    if (buf_count >= BUF_SIZE)
    {
      write(1, buffer, buf_count);
      buf_count = 0;
    }
  }

  if (buf_count > 0)
  {
    write(1, buffer, count);
  }

  return (count);
}