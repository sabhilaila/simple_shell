#include <stdio.h>
#include <string.h>

#define MAX_INPUT_LENGTH 1000

void readUserInput() {
    char input[MAX_INPUT_LENGTH];

    while (1) {
        /* Read user input */
        if (fgets(input, sizeof(input), stdin) == NULL) {
            printf("\n"); /* Print a newline when Ctrl+D is pressed to match the prompt */
            break; /* End of input (Ctrl+D was pressed) */
        }

        /* Remove the newline character from the input */
        input[strcspn(input, "\n")] = '\0';

        /* Add your logic to handle the input */
        printf("You entered: %s\n", input);
    }
}

