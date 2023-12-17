#include "main.h"
#include <unistd.h>

#define BUFFER_SIZE 1024 /* Define the buffer size */

/**
 * print_integer - Prints an integer
 * @number: The integer
 * @flag_plus: The plus flag
 * @flag_space: The space flag
 * @field_width: The field width
 * Return: The number of characters printed
 */
int print_integer(int number, int flag_plus, int flag_space, int field_width)
{
  int count = 0;
  int i, j, temp, f, buf_count = 0;
  char buffer[BUFFER_SIZE];

  temp = number;

  /* Check if the temporary integer is negative */
  if (temp < 0)
  {
    write(1, "-", 1);
    temp = -temp;
    count++;
  }

  /* Print spaces for the field width */
  for (f = 0; f < field_width; f++)
  {
    write(1, " ", 1);
    count++;
  }

  /* Check if the plus flag is set */
  if (flag_plus == 1)
  {
    write(1, "+", 1);
    count++;
  }

  /* Check if the space flag is set */
  if (flag_space == 1)
  {
    write(1, " ", 1);
    count++;
  }

  /* Convert the temporary integer to a string in reverse order and store it in the buffer */
  do
  {
    if (buf_count < BUFFER_SIZE)
    {
      buffer[buf_count++] = (temp % 10) + '0';
    }
    temp /= 10;
  } while (temp > 0);

  /* Reverse the string in the buffer */
  for (i = 0, j = buf_count - 1; i < j; i++, j--)
  {
    char temp = buffer[i];
    buffer[i] = buffer[j];
    buffer[j] = temp;
  }

  /* Write the buffer content */
  write(1, buffer, buf_count);

  /* Update the total count */
  count += buf_count;

  return count;
}
