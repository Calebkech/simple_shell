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