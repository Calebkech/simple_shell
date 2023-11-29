#include "shell.h"

/**
 * execute_command - Executes a command
 * @command: The command to execute
 */
void execute_command(char *command) {
<<<<<<< HEAD
	pid_t child_pid;
	char *argv[128];

	tokenize_command(command, argv);
=======
    pid_t child_pid;
    char *argv[128];
    char *cmd_copy = strdup(command);
    int cmd_exists = 0;

    tokenize_command(cmd_copy, argv);

    if (strcmp(argv[0], "env") == 0)
    {
        print_env();
        free(cmd_copy);
        return;
    }

    if (argv[0][0] == '/' || argv[0][0] == '.') {
        /* Absolute or relative path */
        if (access(argv[0], X_OK) == 0) {
            cmd_exists = 1;
        }
    } else {
        /* Search PATH */
        char *path = getenv("PATH");
        char *path_copy = strdup(path);
        char *dir = strtok(path_copy, ":");

        while (dir) {
            char *cmd_path = malloc(strlen(dir) + strlen(argv[0]) + 2);
            strcpy(cmd_path, dir);
            strcat(cmd_path, "/");
            strcat(cmd_path, argv[0]);

            if (access(cmd_path, X_OK) == 0) {
                cmd_exists = 1;
                free(cmd_path);
                break;
            }

            free(cmd_path);
            dir = strtok(NULL, ":");
        }

        free(path_copy);
    }

    if (!cmd_exists) {
        fprintf(stderr, "%s: command not found\n", argv[0]);
        free(cmd_copy);
        return;
    }
>>>>>>> 9f62f074df3f143afcfe9d15deb0547488faafc3

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (child_pid == 0) 
	{
		/* Child process */
		if (argv[0][0] == '/' || argv[0][0] == '.')
		{
			/* Absolute or relative path */
			execute_directly(argv[0], argv);
        }
		else
		{
			/* Search PATH */
			execute_from_path(argv[0], argv);
		}

        perror(argv[0]);
        exit(EXIT_FAILURE);
<<<<<<< HEAD
	}
	else
	{
		/* Parent process */
		int status;
		waitpid(child_pid, &status, 0);
	}
}
=======
    } else {
        /* Parent process */
        int status;
        waitpid(child_pid, &status, 0);
    }

    free(cmd_copy);
}
>>>>>>> 9f62f074df3f143afcfe9d15deb0547488faafc3
