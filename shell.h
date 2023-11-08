#ifndef SHELL_H
#define SHELL_H
#define STDIN 0
#define STDOUT 0
#define STDERROR 0
#define true 1
#define false 0


#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>

#define MAX_COMMAND_SIZE 256

void display_prompt(void);
void user_input(char *command, size_t size);
void execute_command(char *command);
void print(const char *string);

#endif /* SHELL_H */
