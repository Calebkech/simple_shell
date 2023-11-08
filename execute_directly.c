#include "shell.h"

extern char **environ;

/**
 * execute_directly - Executes a command directly
 * @command: The command to execute
 * @argv: The arguments for the command
 */
void execute_directly(char *command, char **argv)
{
    if (access(command, X_OK) == 0)
    {
        execve(command, argv, environ);
    }
}