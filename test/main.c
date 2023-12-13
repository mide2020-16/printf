#include <limits.h>
#include <stdio.h>
#include "main.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */

int main2(void)
{
	int len;
	unsigned int ui;
	char *str;

	/* Test for simple string */
	len = _printf("Let's try to printf a simple sentence.\n");
	printf("Length:[%d]\n", len);

	/* Test for integer */
	len = _printf("Integer:[%d]\n", 12345);
	printf("Length:[%d]\n", len);

	/* Test for unsigned integer */
	ui = (unsigned int)INT_MAX + 1024;
	len = _printf("Unsigned:[%u]\n", ui);
	printf("Length:[%d]\n", len);

	/* Test for octal */
	len = _printf("Unsigned octal:[%o]\n", ui);
	printf("Length:[%d]\n", len);

	/* Test for hexadecimal */
	len = _printf("Unsigned hexadecimal:[%#x, %#X]\n", ui, ui);
	printf("Length:[%d]\n", len);

	/* Test for character */
	len = _printf("Character:[%c]\n", 'H');
	printf("Length:[%d]\n", len);

	/* Test for string */
	str = "I am a string !";
	len = _printf("String:[%s]\n", str);
	printf("Length:[%d]\n", len);

	/* Test for percent */
	len = _printf("Percent:[%%]\n");
	printf("Length:[%d]\n", len);

	/* Test for multiple formats */
	len = _printf("Multiple formats:[%d, %u, %o, %#x, %#X, %c, %s, %%]\n", 12345, ui, ui, ui, ui, 'H', str);
	printf("Length:[%d]\n", len);

	return (0);
}
