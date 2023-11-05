#include "shell.h"

/*
 * main - Execute a shell
 * @n: number of parameters
 * @argv: array of strings (the command)
 **/

int main(void)
{
	char *line = NULL;

    while (1) /* begin execute */
    {
        line = read_line();
        if (line == NULL)
            return (false);
    }
}
