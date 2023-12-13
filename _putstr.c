#include "main.h" /* Include the main header file */
#include <unistd.h> /* Include the unistd library for write() */

/**
 * _putstr - Prints a string to stdout
 * @string: The string to print
 * 
 * Return: The number of characters printed
 *
 * This function prints a string to stdout using the _putchar function.
 * It checks if the string is not NULL and not empty, and then iterates over each character in the string.
 * For each character, it calls _putchar and increments the count.
 * Finally, it returns the count.
 */
int _putstr(char *string)
{
    int count = 0; /* Initialize count */

    /* Check if the string is not NULL and not empty */
    if (string != NULL && *string != '\0')
    {
        /* Iterate over each character in the string */
        while (*string)
        {
            _putchar(*string); /* Print the character */
            count++; /* Increment the count */
            string++; /* Move to the next character */
        }
    }

    return (count); /* Return the count */
}
