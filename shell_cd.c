#include "shell.h"

/**
 * shell_cd - Change the current directory of the process.
 * @args: Array of command arguments (args[0] is the command itself).
 * Return: Always returns 1 to continue the shell loop.
 */
int shell_cd(char **args)
{
    char *new_dir;
    int check;

    if (args[1] == NULL || strcmp(args[1], "~") == 0)
    {
        /* If no argument is given or if "~" is given, change to the home directory */
        new_dir = getenv("HOME");
        if (new_dir == NULL)
        {
            perror("Error retrieving home directory");
            return 1;
        }
    }
    else if (strcmp(args[1], "-") == 0)
    {
        /* If the argument is "-", change to the previous directory */
        new_dir = getenv("OLDPWD");
        if (new_dir == NULL)
        {
            perror("Error retrieving previous directory");
            return 1;
        }
    }
    else
    {
        /* Change to the specified directory */
        new_dir = args[1];
    }

    check = chdir(new_dir);
    if (check != 0)
    {
        perror("Error changing directory");
    }
    else
    {
        /* Update the PWD and OLDPWD environment variables */
        setenv("OLDPWD", getenv("PWD"), 1);
        setenv("PWD", new_dir, 1);
    }

    free(args); /* Perform the free operation here, after the last usage of args */

    return 1;
}
