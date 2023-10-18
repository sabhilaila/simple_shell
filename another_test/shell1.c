/* shell.c */
#include "shell.h"
#include <stdio.h>
#include <stdlib.h>

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
            /* Handle command with arguments here */
        }
    }
}

