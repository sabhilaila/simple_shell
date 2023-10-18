/* shell.c */
#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void run_shell(void)
{
    char *command = NULL;
    size_t len = 0;

    while (1)
    {
        printf(":) ");
        if (getline(&command, &len, stdin) == -1)
        {
            printf("\n");
            free(command);
            exit(0);
        }
        else
        {
            /* Handle exit, env, and execution here */
            if (strcmp(command, "exit\n") == 0)
            {
                free(command);
                exit(0);
            }
            else if (strcmp(command, "env\n") == 0)
            {
                system("env");
            }
        }
    }
}

