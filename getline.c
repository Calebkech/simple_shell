#include "shell.h"

#define BUFFER_SIZE 1024

/**
 * _getline - Reads an entire line from standard input
 *
 * Return: A pointer to the line read, or NULL on error or when no more lines
 */
char *_getline(void)
{
    static char buffer[BUFFER_SIZE];
    static char *buffer_ptr = buffer;
    static int chars_left = 0;
    char *line = NULL;
    size_t line_size = 0;
    char *line_new;
    char c;

    while (1)
    {
        if (chars_left <= 0)
        {
            chars_left = read(STDIN_FILENO, buffer, BUFFER_SIZE);
            if (chars_left == -1)
            {
                if (line_size > 0)
                {
                    return line;
                }
                else
                {
                    free(line);
                    return NULL;
                }
            }
            else if (chars_left == 0)
            {
                free(line);
                return NULL;
            }
            buffer_ptr = buffer;
        }

        line_new = realloc(line, line_size + 2);
        if (!line_new)
        {
            free(line);
            return NULL;
        }
        line = line_new;

        c = *buffer_ptr++;
        chars_left--;

        line[line_size++] = c;

        if (c == '\n')
        {
            line[line_size] = '\0';
            return line;
        }
    }
<<<<<<< HEAD
}
=======
}
>>>>>>> parent of 9f62f07 (new update)
