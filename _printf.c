#include "main.h" /* Include the main header file */
#include <stdarg.h> /* Include the standard arguments library */

/**
 * _printf - Prints content to stdout
 * @format: The format to print the content in
 * Return: Number of characters printed (excluding the null byte used to end output to strings
 *
 * This function is similar to printf. For example, _printf("Hello %s", "World") will print "Hello World".
 */
int _printf(const char *format, ...) /* The ellipsis indicates that there are a variable number of arguments */
{
	int count = 0; /* Initialize count to 0 */

	/* Declare and initialize variables */
	int flag_plus = 0, flag_space = 0, flag_hash = 0, length_mod = 0, field_width = 0; /* These are variables to handle various flags and conditions*/
	va_list args; /* Declare variable args of type va_list */

	va_start(args, format); /* Initialize args */

	/* Loop through the format string */
	while (format != NULL && *format != '\0') /* While the format string is not NULL or the end of the string */
	{
		/* Check if the current character is '%' */
		if (*format == '%') /* If the current character is '%' */
		{
			format++; /* Increment the pointer */
			count++; /* Increment the count */

			/* Reset the flags and modifiers */
			flag_plus = 0, flag_space = 0, flag_hash = 0, field_width = 0, length_mod = 0; /* Reset the flags and modifiers */

			/* Loop through the flags */
			while (*format == '+' || *format == ' ' || *format == '#') /* While the current character is a flag */
			{
				/* Set the appropriate flag */
				if (*format == '+') /* If the flag is '+' */
					flag_plus = 1; /* If the flag is '+' */
				else if (*format == ' ') /* If the flag is ' ' */
					flag_space = 1; /* Set the appropriate flag */
				else if (*format == '#') /* If the flag is '#' */
					flag_hash = 1; /* Set the appropriate flag */

				format++; /* Increment the pointer */
			}

			/* Calculate the field width */
			while (*format >= '0' && *format <= '9')
			{
				field_width = field_width * 10 + (*format - '0');
				count++;
			}

			/* Determine the length modifier */
			while (*format == 'h' || *format == 'l')
			{
				if (*format == 'h') /* If the length modifier is 'h' */
					length_mod = (length_mod < 1) ? 1 : 2; /* If length_mod is less than 1, set it to 1, otherwise set it to 2 */
				else /* If the length modifier is 'l' */
					length_mod = 2; /* Set length_mod to 2 */

				count++; /* Increment the count */
			}

			/* Switch case to handle different format specifiers */
			switch (*format) /*Similar to if (*format == c) {do this}*/
			{
				case 'c': /*Format specifier for a single character*/
					case_c(args); /*Function to handle this case*/
					break;

				case 's': /*Format specifier for a string*/
					case_s(args); /*Function to handle this case*/
					break;

				case 'd': /*Format specifier for a signed integer*/
				case 'i': /*Format specifier for a signed integer*/
					case_d_i(args, length_mod, flag_plus, flag_space, field_width); /*Function to handle this case*/
					break;

				case 'b': /*Format specifier for a binary number*/
					case_b(args); /*Function to handle this case*/
					break;

				case 'u': /*Format specifier for an unsigned integer*/
					case_u(args, length_mod, flag_hash, field_width); /*Function to handle this case*/
					break;

				case 'o': /*Format specifier for an octal number*/
					case_o(args, length_mod, flag_hash, field_width); /*Function to handle this case*/
					break;

				case 'x': /*Format specifier for a hexadecimal number*/
					case_x(args, length_mod, flag_hash, field_width, 0); /* 0 for lowercase */ /*Function to handle this case*/
					break;

				case 'X': /*Format specifier for a hexadecimal number*/
					case_X(args, length_mod, flag_hash, field_width, 1); /* 1 for uppercase */ /*Function to handle this case*/
					break;

				case 'S': /*Format specifier for a string*/
					case_S(args, format); /*Function to handle this case*/
					break;

				case 'p': /*Format specifier for a pointer*/
					case_p(args, format); /*Function to handle this case*/
					break;

				case '%': /*Format specifier for a percent sign*/
					_putchar('%'); /* Print the percent sign */
					count++; /* Increment the count */
					format++; /* Increment the pointer */
					break;

				default: /*If the format specifier is not recognized*/
					_putchar(*format); /* Print the current character */
					count++; /* Increment the count */
					break;
			}
		}
		else /* If the current character is not '%' */
		{
			_putchar(*format); /* Print the current character */
			count++; /* Increment the count */
		}

		format++; /* Increment the pointer */
	}

	va_end(args); /* Clean up the list */

	return (count); /* Return the count */
}