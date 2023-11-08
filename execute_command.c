#include "shell.h"

/**
 * execute_command - Executes a command
 * @command: The command to execute
 */
void execute_command(char *command)
{
	pid_t child_pid;
	char *argv[2];

	argv[0] = command;
	argv[1] = NULL;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (child_pid == 0)
	{
		/* Child process */
		if (command[0] == '/' || command[0] == '.')
		{
			/* Absolute or relative path */
			execute_directly(command, argv);
		}
		else
		{
			/* Search PATH */
			execute_from_path(command, argv);
		}

		perror(command);
		exit(EXIT_FAILURE);
	}
	else
	{
		/* Parent process */
		int status;
		waitpid(child_pid, &status, 0);
	}
}