#include "shell.h"

/**
 * print_env - Prints the current environment
 */
void print_env(void)
{
    extern char **environ;
    int i = 0;

    while (environ[i] != NULL)
    {
        printf("%s\n", environ[i]);
        i++;
    }
<<<<<<< HEAD
}
=======
}
>>>>>>> parent of 9f62f07 (new update)
