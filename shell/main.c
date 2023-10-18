#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "shell.h"

int main(void)
{
    char line[100];

    while (1) {
        printf("$ "); // Display the prompt
        fgets(line, sizeof(line), stdin); // Read the user input

        if (line[0] == '\n') {
            continue; // Ignore empty lines
        }

        line[strcspn(line, "\n")] = '\0'; // Remove the newline character

        if (strcmp(line, "exit") == 0) {
            break; // Exit the shell if the user enters "exit"
        }

        if (execute_command(line) == -1) {
            printf("Command not found: %s\n", line);
        }
    }

    return EXIT_SUCCESS;
}
