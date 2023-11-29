#include "shell.h"


/**
 * main - Entry point of the shell program
 *
 * Return: Always 0
 */
int main(void)
{
    char command[128];

    while (1)
    {
        display_prompt();
        user_input(command, sizeof(command));

        if (check_exit(command))
        {
            break;
        }
        

        execute_command(command);
    }

    return 0;
}