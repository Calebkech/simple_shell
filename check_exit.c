#include "shell.h"

/**
 * check_exit - Checks if the command is "exit"
 * @command: The command to check
 *
 * Return: 1 if the command is "exit", 0 otherwise
 */
int check_exit(char *command)
{
	if (strcmp(command, "exit") == 0)
	{
		return 1;
	}
	return 0;
}

