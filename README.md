# MyPrintf Project

## Description

MyPrintf is a custom implementation of the C programming language's `printf` function. This project aims to provide developers with a deeper understanding of how `printf` works by creating a simplified version from scratch.

## Features

- **Format Specifiers:** Supports a variety of format specifiers, such as `%d` for integers, `%s` for strings, `%c` for characters, `%f` for floating-point numbers, etc.

- **Variable Arguments:** Utilizes the `stdarg.h` library to handle variable arguments.

- **String Manipulation:** Implements string manipulation to process the format string and extract corresponding arguments.

- **Data Type Handling:** Properly handles different data types, including integers, floating-point numbers, characters, and strings.

- **Precision and Width:** Supports precision and width modifiers in format specifiers.

- **Error Handling:** Implements robust error handling, gracefully handling unknown format specifiers.

## Usage

1. Clone the repository:

    ```bash
    git clone https://github.com/yourusername/myprintf.git
    ```

2. Include the `myprintf.h` header file in your C code:

    ```c
    #include "myprintf.h"
    ```

3. Compile your code with the `myprintf.c` file:

    ```bash
    gcc yourcode.c myprintf.c -o yourprogram
    ```

4. Run your program:

    ```bash
    ./yourprogram
    ```

## Examples

```c
#include "myprintf.h"

int main() {
    myprintf("Hello, %s! This is a number: %d\n", "User", 42);
    return 0;
}

