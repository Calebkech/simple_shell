#include "shell.h"

/**
 * main - Entry point of the shell program
 *
 * Return: Always 0
 */
int main(void)
{
    char *command;
    char *argv[128];

    while (1)
    {
        display_prompt();
        command = _getline();
        tokenize_command(command, argv);

        if (check_exit(argv))
        {
            break;
        }

        execute_command(command);
        free(command);
    }

    return 0;
}