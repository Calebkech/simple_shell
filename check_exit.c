#include "shell.h"

/**
 * check_exit - Checks if the command is "exit"
 * @argv: The command to check
 *
 * Return: 1 if the command is "exit", 0 otherwise
 */
int check_exit(char **argv)
{
<<<<<<< HEAD
	if (strcmp(command, "exit") == 0)
	{
		return 1;
	}
	return 0;
}

=======
    if (strcmp(argv[0], "exit") == 0)
    {
        if (argv[1] != NULL)
        {
            int status = atoi(argv[1]);
            exit(status);
        }
        else
        {
            exit(EXIT_SUCCESS);
        }
    }
    return 0;
}
>>>>>>> parent of 9f62f07 (new update)
