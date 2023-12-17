#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <stddef.h>

int _printf(const char *format, ...);
int _putchar(char character);
int print_string(char *string);
int print_integer(int number, int flag_plus, int flag_space, int field_width);
int print_binary(unsigned int number);
#endif /*MAIN_H*/