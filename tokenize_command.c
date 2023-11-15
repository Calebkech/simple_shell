#include "shell.h"

/**
 * tokenize_command - Tokenizes a command into arguments
 * @command: The command to tokenize
 * @argv: The array to store the arguments
 */
void tokenize_command(char *command, char **argv)
{
    int i = 0;

    argv[i] = strtok(command, " ");
    while (argv[i] != NULL) {
        i++;
        argv[i] = strtok(NULL, " ");
    }
}
