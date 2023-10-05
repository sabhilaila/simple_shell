#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_LENGTH 1024

/* Declare the external environment variable */
extern char **environ;

int main(void) {
    char input[MAX_INPUT_LENGTH];

    while (1) {
        /* Display the prompt */
        printf("$ ");
        fflush(stdout);

        /* Read user input */
        if (fgets(input, sizeof(input), stdin) == NULL) {
            printf("\n"); /* Print a newline when Ctrl+D is pressed to match the prompt */
            break; /* End of input (Ctrl+D was pressed) */
        }

        /* Remove the newline character from the input */
        input[strcspn(input, "\n")] = '\0';

        /* Check if the user entered "exit" */
        if (strcmp(input, "exit") == 0) {
            printf("Exiting the shell.\n");
            break;
        }

        /* Check if the user entered "env" to print the current environment */
        if (strcmp(input, "env") == 0) {
            char **env = environ;
            while (*env) {
                printf("%s\n", *env);
                env++;
            }
            continue;
        }

        /* Handle other commands or execute them as needed */

        /* For demonstration, let's just echo the input */
        printf("You entered: %s\n", input);
    }

    return 0;
}

