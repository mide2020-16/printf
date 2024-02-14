#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>

/**
 * struct specifier_formats - struct holding the specifier format for printf
 * @format: character indicating format to be used
 * @f: function to be returned based on function
 */
typedef struct specifier_formats
{
	char format;
	int (*f)(va_list args);
} sp_f;

int _strlen(const char *s);
int _printf(const char *format, ...);
void _putchar(char c);
int print_char(va_list args);
int print_string(va_list args);
int print_decimal(va_list args);
int (*get_format_function(char c))(va_list args);
int print_integer(va_list args);
int print_number(int n);
int fmt_arr_checker(int fmt_arr_size, char formats_array[], char character);
int print_percent(va_list args);
int count_number(int n);
int convert_dec_to_bin(int n);
int print_binary(va_list args);
int print_octal(va_list args);
int convert_dec_to_octal(int n);
int print_u_int(va_list args);
int print_hex_a(va_list args);
int print_hex_A(va_list args);

#endif
