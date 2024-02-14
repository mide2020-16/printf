#include "main.h"

/**
 * _strlen - returns length of string
 * @s: string to check
 *
 * Return: length of string
 */
int _strlen(const char *s)
{
	int i, size = 0;

	for (i = 0; s[i] != '\0'; ++i)
	{
		++size;
	}
	return (size);
}
