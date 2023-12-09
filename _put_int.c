#include "main.h"
#include <unistd.h>
#define BUFFER_SIZE 20

int _put_int(int number, int flag_plus, int flag_space, int field_width)
{
	int count = 0;
	int i, j;
	char buffer[BUFFER_SIZE];
	int temp, f;
	temp = number;
	
	for (f = 0; f < field_width; f++)
	{
		_putchar(' ');
		count++;
	}
		if (flag_plus)
		{
			_putchar('+');
			count++;
		}
		else if (flag_space)
		{
			_putchar(' ');
			count++;
		}

	if (temp < 0)
	{
		write(1, "-", 1);
		temp = -temp;
	}

	do
	{
		buffer[count++] = (temp % 10) + '0';
		temp /= 10;
	} while (temp > 0);

	/*Reverse*/
		for (i = 0, j = count -1; i < j; i++, j--)
		{
			char temp = buffer[i];
			buffer[i] = buffer[j];
			buffer[j] = temp;
		}
		write(1, buffer, count);
		
		return (count);
}