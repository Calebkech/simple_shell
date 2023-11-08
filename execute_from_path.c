#include "shell.h"

extern char **environ;

/**
 * execute_from_path - Executes a command from the PATH
 * @command: The command to execute
 * @argv: The arguments for the command
 */
void execute_from_path(char *command, char **argv)
{
    char *path = getenv("PATH");
    char *path_copy;
    char *dir;

    if (!path)
    {
        perror("getenv");
        exit(EXIT_FAILURE);
    }

    path_copy = strdup(path);
    if (!path_copy)
    {
        perror("strdup");
        exit(EXIT_FAILURE);
    }

    dir = strtok(path_copy, ":");
    while (dir)
    {
        char *cmd_path = malloc(strlen(dir) + strlen(command) + 2);
        if (!cmd_path)
        {
            perror("malloc");
            exit(EXIT_FAILURE);
        }

        strcpy(cmd_path, dir);
        strcat(cmd_path, "/");
        strcat(cmd_path, command);

        if (access(cmd_path, X_OK) == 0)
        {
            execve(cmd_path, argv, environ);
        }

        free(cmd_path);
        dir = strtok(NULL, ":");
    }

    free(path_copy);
}