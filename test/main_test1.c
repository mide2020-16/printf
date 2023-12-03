#include <stdio.h>
#include "main.h"

int main(void)
{
    int len;
    int len2;

    // Testcase 1: Basic string and character printing
    len = _printf("Hello, %s! This is a simple %c example.\n", "world", 'C');
    len2 = printf("Hello, %s! This is a simple %c example.\n", "world", 'C');
    printf("Len:[%d, %d]\n", len, len2);

    // Testcase 2: Printing a single character and a string
    len = _printf("Character: %c, String: %s\n", 'X', "Print Me");
    len2 = printf("Character: %c, String: %s\n", 'X', "Print Me");
    printf("Len:[%d, %d]\n", len, len2);

    // Testcase 3: Handling percent symbol
    len = _printf("Use two percent symbols: %%\n");
    len2 = printf("Use two percent symbols: %%\n");
    printf("Len:[%d, %d]\n", len, len2);

    // Testcase 4: Null string
    len = _printf("Null string: %s\n", NULL);
    len2 = printf("Null string: %s\n", NULL);
    printf("Len:[%d, %d]\n", len, len2);

    // Testcase 5: Empty string
    len = _printf("Empty string: %s\n", "");
    len2 = printf("Empty string: %s\n", "");
    printf("Len:[%d, %d]\n", len, len2);

    // Testcase 6: Mix of characters, strings, and percent symbols
    len = _printf("Mixing: %c, %s, %%\n", 'A', "Final Test", 123);
    len2 = printf("Mixing: %c, %s, %%\n", 'A', "Final Test", 123);
    printf("Len:[%d, %d]\n", len, len2);

    return (0);
}

