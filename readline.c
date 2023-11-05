#include "shell.h"

/*
 * readline - readline
 * @n: number of parameters
 * @argv: array of strings (the command)
 **/

char *read_line(void)
{
    char *line = NULL;
    size_t len = 0; /* unsigned int represent object in memory*/
    ssize_t char_n; /* signed int similar to size_t */

    write(STDOUT_FILENO, "$ ", 2);
    char_n = getline(&line, &len, stdin); /* retrieve number of chars*/
    if (char_n == EOF) /* return -1*/
    {
        free(line);
        return (NULL);
    }

    return (line);

}
