#include "main.h" /* Include the main header file */
#include <unistd.h> /* Include the unistd library for write() */
#define BUFFER_SIZE 1024 /* Define the buffer size */

/**
 * _put_int - Prints an integer
 * @number: The integer
 * @flag_plus: The plus flag
 * @flag_space: The space flag
 * @field_width: The field width
 * 
 * Return: The number of characters printed
 *
 * This function prints an integer to stdout.
 * It prints spaces for the field width, a '+' character if the plus flag is set, or a ' ' character if the space flag is set.
 * If the integer is negative, it prints a '-' character and makes the integer positive.
 * Then it converts the integer to a string in reverse order and stores it in a buffer.
 * Finally, it reverses the string in the buffer and writes it to stdout.
 */
int _put_int(int number, int flag_plus, int flag_space, int field_width)
{
    int count = 0; /* Initialize count */
    int i, j; /* Declare variables for the loop counters */
    char buffer[BUFFER_SIZE]; /* Declare a buffer */
    int temp, f; /* Declare variables for the temporary integer and the loop counter */
    temp = number; /* Initialize the temporary integer with the integer */

    /* Print spaces for the field width */
    for (f = 0; f < field_width; f++)
    {
        _putchar(' '); /* Print a space */
        count++; /* Increment the count */
    }

    /* Check if the plus flag is set */
    if (flag_plus)
    {
        _putchar('+'); /* Print a '+' character */
        count++; /* Increment the count */
    }
    /* Check if the space flag is set */
    else if (flag_space)
    {
        _putchar(' '); /* Print a ' ' character */
        count++; /* Increment the count */
    }

    /* Check if the temporary integer is negative */
    if (temp < 0)
    {
        write(1, "-", 1); /* Print a '-' character */
        temp = -temp; /* Make the temporary integer positive */
    }

    /* Convert the temporary integer to a string in reverse order and store it in the buffer */
    do
    {
        buffer[count++] = (temp % 10) + '0'; /* Get the last digit of the temporary integer and store it in the buffer */
        temp /= 10; /* Remove the last digit of the temporary integer */
    } while (temp > 0); /* Repeat while the temporary integer is greater than 0 */

    /* Reverse the string in the buffer */
    for (i = 0, j = count - 1; i < j; i++, j--)
    {
        char temp = buffer[i]; /* Store the character at the current position in a temporary variable */
        buffer[i] = buffer[j]; /* Replace the character at the current position with the character at the opposite position */
        buffer[j] = temp; /* Replace the character at the opposite position with the character from the temporary variable */
    }

    write(1, buffer, count); /* Write the string in the buffer to stdout */

    return (count); /* Return the count */
}