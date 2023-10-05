#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void checkExitAndExitShell(const char *input) {
    /* Exit the shell if the user enters "exit" */
    if (strcmp(input, "exit") == 0) {
        printf("Exiting the shell.\n");
        exit(EXIT_SUCCESS);
    }
}

