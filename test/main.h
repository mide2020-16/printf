#ifndef MAIN_H /* If MAIN_H is not defined */
#define MAIN_H /* Define MAIN_H */

#include <stdarg.h> /* Standard C library for variadic functions */
#include <unistd.h> /* Standard C library for write function */
#include <stddef.h> /* Standard C library for NULL and size_t definitions */

/* Function prototypes for handling different format specifiers in _printf */

int case_c(va_list args); /* Handles 'c' format specifier */

int case_s(va_list args); /* Handles 's' format specifier */

int case_d_i(va_list args, int length_mod, int flag_plus, int flag_space, int field_width); /* Handles 'd' and 'i' format specifiers */

int case_b(va_list args); /* Handles 'b' format specifier */

int case_x(va_list args, int length_mod, int flag_hash, int field_width, int uppercase); /* Handles 'x' format specifier */

int case_S(va_list args, const char *format); /* Handles 'S' format specifier */

/*********************************************************************************************/
/* Function prototype for _printf */
int _printf(const char *format, ...);

/********************************************************************************************/

/* Function prototypes for helper functions */

int _putchar(char character); /* Writes a character to stdout */

int _putstr(char *string); /* Writes a string to stdout */

int _put_int(int number, int flag_plus, int flag_space, int field_width); /* Writes an integer to stdout */

int _put_bin(unsigned int binary); /* Writes a binary number to stdout */

int _put_un_int(unsigned int un_integer, int flag_hash, int field_width); /* Writes an unsigned integer to stdout */

int _put_octal(unsigned int octal, int flag_hash, int field_width); /* Writes an octal number to stdout */

int _put_hex(unsigned int hexa, int uppercase, int flag_hash, int field_width); /* Writes a hexadecimal number to stdout */

int _put_String(char *string); /* Writes a string to stdout, escaping non-printable characters */

int _put_pointer(void *ptr); /* Writes a pointer to stdout */

#endif /* MAIN_H */