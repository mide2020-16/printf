#include <unistd.h>

int _print_int(int num)
{
	char buffer[20];
	int length = 0;
	int temp;
	int i, j;

	temp = num;
	/* handles negative numbers */
	if (temp < 0)
	{
		write(1, "-", 1);
		temp = -temp;	/*Make the number positive for further processing*/
	}
	do {
		buffer[length++] = temp % 10 + '0';
		temp /= 10;
	} while (temp > 0);

	for (i = 0, j = length - 1; i < j; i++, j--)
	{
		char temp = buffer[i];

		buffer[i] = buffer[j];
		buffer[j] = temp;
	}
	write(1, buffer, length);

	return length;
}
