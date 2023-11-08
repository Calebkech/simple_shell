#include "shell.h"

/**
 * print - Prints a string to the standard output
 * @string: The string to be printed
 */
void print(const char *string)
{
    write(STDOUT_FILENO, string, strlen(string));
}