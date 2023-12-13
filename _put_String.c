#include "main.h" /* Include the main header file */
#include <unistd.h> /* Include the unistd library for write() */

/**
 * _put_String - Prints a string
 * @string: The string
 * 
 * Return: The number of characters printed
 *
 * This function prints a string to stdout.
 * It iterates over each character in the string until it reaches the null character.
 * If the ASCII value of the character is less than 32 or greater than or equal to 127, it prints '\\x' and then calls _put_hex with the ASCII value of the character.
 * Otherwise, it prints the character.
 */
int _put_String(char *string)
{
    int count = 0; /* Initialize count */

    /* Iterate over each character in the string until the null character */
    while(*string != '\0')
    {
        /* Check if the ASCII value of the character is less than 32 or greater than or equal to 127 */
        if (*string < 32 || *string >= 127)
        {
            _putchar('\\'); /* Print '\\' */
            _putchar('x'); /* Print 'x' */
            count += 2; /* Increment the count by 2 */
            _put_hex(*string, 1, 0, 0); /* Call _put_hex with the ASCII value of the character */
            count += 2; /* Increment the count by 2 */
        }
        else
        {
            _putchar(*string); /* Print the character */
            count++; /* Increment the count */
        }

        string++; /* Move to the next character */
    }

    return (count); /* Return the count */
}