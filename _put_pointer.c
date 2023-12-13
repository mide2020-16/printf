#include "main.h" /* Include the main header file */
#include <unistd.h> /* Include the unistd library for write() */

/**
 * _put_pointer - Prints a pointer
 * @ptr: The pointer
 * 
 * Return: The number of characters printed
 *
 * This function prints a pointer to stdout.
 * It prints '0x' and then calls _put_hex with the address of the pointer.
 */
int _put_pointer(void *ptr)
{
    int count = 0; /* Initialize count */
    unsigned long address = (unsigned long)ptr; /* Get the address of the pointer */

    _putchar('0'); /* Print '0' */
    _putchar('x'); /* Print 'x' */
    count += 2; /* Increment the count by 2 */

    count += _put_hex(address, 1, 0, 0); /* Call _put_hex with the address of the pointer and add the count of hexadecimal digits to the total count */

    return (count); /* Return the count */
}