#include <unistd.h> /* Include the unistd library for write() */

#define BUFFER_SIZE 1024 /* Define the buffer size */

char buffer[BUFFER_SIZE]; /* Declare a buffer of size BUFFER_SIZE */
int buffer_index = 0;			/* Initialize the buffer index to 0 */

/**
 * flush_buffer - Writes the buffer to stdout and resets the buffer index
 *
 * This function writes the buffer to stdout using the write function if the buffer index is greater than 0.
 * It then resets the buffer index to 0.
 */
void flush_buffer()
{
	/* Check if the buffer index is greater than 0 */
	if (buffer_index > 0)
	{
		write(1, buffer, buffer_index); /* Write the buffer to stdout */
		buffer_index = 0;								/* Reset the buffer index to 0 */
	}
}

/**
 * _putchar - Adds a character to the buffer and writes the buffer to stdout if it is full
 * @character: The character to add
 *
 * Return: The number of characters added
 *
 * This function adds a character to the buffer.
 * If the buffer is full, it writes the buffer to stdout using the flush_buffer function and then adds the character to the buffer.
 */
int _putchar(char character)
{
	/* Check if the buffer is full */
	if (buffer_index >= BUFFER_SIZE)
	{
		flush_buffer(); /* Write the buffer to stdout */
	}

	buffer[buffer_index++] = character; /* Add the character to the buffer */

	return 1; /* Return the number of characters added */
}