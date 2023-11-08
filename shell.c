#include "shell.h"

/**
 * display_prompt - Prints the shell prompt to the standard output
 */
void display_prompt(void) {
    const char *prompt = "$ ";
    write(STDOUT_FILENO, prompt, strlen(prompt));
}

/**
 * user_input - Reads a line of input from the user
 * @command: Buffer to store the input
 * @size: Size of the buffer
 */
void user_input(char *command, size_t size) {
    ssize_t bytes_read = read(STDIN_FILENO, command, size);
    if (bytes_read == -1) {
        perror("read");
        exit(EXIT_FAILURE);
    }
    command[strcspn(command, "\n")] = '\0'; /* Remove newline */
}

/**
 * execute_command - Executes a shell command
 * @command: The command to execute
 */
void execute_command(char *command) {
    pid_t child_pid;
    char *argv[2];
    argv[0] = command;
    argv[1] = NULL;

    child_pid = fork();
    if (child_pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    } else if (child_pid == 0) {
        /* Child process */
        if (execve(command, argv, NULL) == -1) {
            perror(command);
            exit(EXIT_FAILURE);
        }
    } else {
        /* Parent process */
        int status;
        waitpid(child_pid, &status, 0);
    }
}