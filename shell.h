#ifndef SHELL_H
#define SHELL_H
#define STDIN 0
#define STDOUT 0
#define STDERROR 0
#define true 1
#define false 0


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


char *read_line(void);
#endif /* SHELL_H */
