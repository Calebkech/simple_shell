#include "shell.h"

/**
 * tokenize_command - Tokenizes a command into arguments
 * @command: The command to tokenize
 * @argv: The array to store the arguments
 */
void tokenize_command(char *command, char **argv)
{
    int i = 0;
    char *token_start = command;

    while (1)
    {
        char c = *command;

        if (c == ' ' || c == '\0')
        {
            size_t length = command - token_start;
            char *token = malloc(length + 1);
            strncpy(token, token_start, length);
            token[length] = '\0';
            argv[i++] = token;

            if (c == '\0')
            {
                break;
            }

            token_start = command + 1;
        }

        command++;
    }

    argv[i] = NULL;
}