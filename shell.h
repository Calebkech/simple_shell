#ifndef SHELL_H
#define SHELL_H

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>

#define MAX_COMMAND_SIZE 256
#define STDIN 0
#define STDOUT 1
#define STDERR 2
#define true 1
#define false 0

void display_prompt(void);
char *_getline(void);
void user_input(char *command, size_t size);
void execute_command(char *command);
void execute_directly(char *command, char **argv);
void execute_from_path(char *command, char **argv);
int check_exit(char *command);
void print(const char *string);
void tokenize_command(char *command, char **argv);
void print_env(void);

#endif /* SHELL_H */