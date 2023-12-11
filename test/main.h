#ifndef MAIN_H /*THis is to ensure that the functions in the main header file is not repeated twice during compilation*/
#define MAIN_H /*This defines the header file with include guarded*/

#include <stdarg.h> /*Standard C library for variadic functions*/
#include <unistd.h> /*Standard C library for write function*/
#include <stddef.h>

int _printf(const char *format, ...);
int _putchar(char character);
int _putstr(char *string);
int _put_int(int number, int flag_plus, int flag_space);
int _put_bin(unsigned int binary);
int _put_un_int(unsigned int un_integer, int flag_hash);
int _put_octal(unsigned int octal, int flag_hash);
int _put_hex(unsigned int hexa, int uppercase, int flag_hash);
int _put_String(char *string);
int _put_pointer(void *ptr);

#endif
