#include "shell.h"

/**
 * execute_command - Executes a command
 * @command: The command to execute
 */
void execute_command(char *command) {
    pid_t child_pid;
    char *argv[128];

    tokenize_command(command, argv);

    child_pid = fork();
    if (child_pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    } else if (child_pid == 0) {
        /* Child process */
        if (argv[0][0] == '/' || argv[0][0] == '.') {
            /* Absolute or relative path */
            execute_directly(argv[0], argv);
        } else {
            /* Search PATH */
            execute_from_path(argv[0], argv);
        }

        perror(argv[0]);
        exit(EXIT_FAILURE);
    } else {
        /* Parent process */
        int status;
        waitpid(child_pid, &status, 0);
    }
}