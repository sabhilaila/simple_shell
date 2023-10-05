#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_INPUT_LENGTH 1024

/* Declare the external environment variable */
extern char **environ;

int main() {
    char input[MAX_INPUT_LENGTH];
    pid_t pid;

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

        /* Exit the shell if the user enters "exit" */
        if (strcmp(input, "exit") == 0) {
            break;
        }

        /* Fork a new process to execute the command */
        pid = fork();

        if (pid == -1) {
            perror("fork");
            exit(EXIT_FAILURE);
        } else if (pid == 0) { /* Child process */
            /* Create an array of pointers to arguments */
            char *args[2];
            args[0] = input;
            args[1] = NULL;

            /* Execute the command with the environment variables */
            if (execve(input, args, environ) == -1) {
                perror("execve");
                exit(EXIT_FAILURE);
            }
        } else { /* Parent process */
            /* Wait for the child process to complete */
            int status;
            if (waitpid(pid, &status, 0) == -1) {
                perror("waitpid");
                exit(EXIT_FAILURE);
            }

            /* Check if the child process exited normally */
            if (WIFEXITED(status)) {
                int exit_status = WEXITSTATUS(status);
                if (exit_status != 0) {
                    fprintf(stderr, "Error: Command exited with status %d\n", exit_status);
                }
            } else if (WIFSIGNALED(status)) {
                fprintf(stderr, "Error: Command terminated by signal %d\n", WTERMSIG(status));
            }
        }
    }

    printf("Exiting the shell.\n");

    return 0;
}
