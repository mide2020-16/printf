#include "main.h"
#include <unistd.h>

int _putstr(char *string)
{
        int count = 0;

        if (string != NULL && *string != '\0')
        {
                while (*string)
                {
                        _putchar(*string);
                        count++;
                        string++;
                }
        }
        return (count);
}