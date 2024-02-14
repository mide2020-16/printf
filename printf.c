#include "main.h" 
#include <stdio.h> 
#include <stdarg.h> 
  
/** 
 * _printf - custom implementation of printf function 
 * @format: string to be printed and format specifiers   * 
 * Return: number of characters printed 
*/ 
 int _printf(const char *format, ...) 
 { 
         int printed_size = 0, string_size = 0, i, spe_mode = 0, fmt_arr_size = 0; 
         char formats_array[] = {'c', 's', 'd', 'i', '%', 'b', 'u', 'o', 'x', 'X'}; 
         va_list args; 
  
         int (*printer)(va_list); 
  
         if (format == NULL) 
                 return (-1); 
         va_start(args, format); 
         fmt_arr_size = sizeof(formats_array) / sizeof(formats_array[0]); 
         string_size = _strlen(format); 
  
         for (i = 0; i < string_size; ++i) 
         { 
                 if (spe_mode == 1) 
                 { 
                         printer = get_format_function(format[i]); 
                         printed_size += printer(args); 
                         spe_mode = 0; 
                 } 
                 else 
                 { 
                         if (format[i] == '%') 
                         { 
                                 if (format[i + 1] == '\0' || format[i + 1] == ' ') 
                                         continue; 
                                 spe_mode = fmt_arr_checker(fmt_arr_size, formats_array, format[i + 1]); 
                                 if (spe_mode == 1) 
                                         continue; 
                         } 
                         _putchar(format[i]); 
                         ++printed_size; 
                 } 
         } 
         return (printed_size); 
 } 
  
  
 /** 
  * fmt_arr_checker - checks if a character is in the format array 
  * @size: size of array to check 
  * @array: array to check 
  * @character: character to check for 
  * 
  * Return: 1 if the character is present and 0 otherwise 
  */ 
 int fmt_arr_checker(int size, char array[], char character) 
 { 
         int i, result = 0; 
  
         for (i = 0; i < size; ++i) 
         { 
                 if (array[i] == character) 
                 { 
                         result = 1; 
                         break; 
                 } 
         }
  
         return (result);
 }
