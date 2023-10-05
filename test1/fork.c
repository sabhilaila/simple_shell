#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define MAX_ARGS 100

int my_main(int argc, char *argv[]) {
    char *command;
    pid_t pid;
    char *path;
    char *token;
    int num_args;  /* Declare 'num_args' here */
    int i;          /* Declare 'i' here */

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <command> [arg1] [arg2] ...\n", argv[0]);
        return EXIT_FAILURE;
    }

    command = argv[1];

    /* Check if the command exists in the PATH */
    path = getenv("PATH");
    token = strtok(path, ":");

    while (token != NULL) {
        char cmd_path[1024];
        snprintf(cmd_path, sizeof(cmd_path), "%s/%s", token, command);

        if (access(cmd_path, X_OK) == 0) {
            /* Create an array of pointers to arguments (including the command) */
            char *args[MAX_ARGS];  /* Fixed-size array */
            args[0] = command;

            num_args = argc - 1;
            if (num_args > MAX_ARGS - 1) {
                fprintf(stderr, "Error: Too many arguments provided.\n");
                return EXIT_FAILURE;
            }

            for (i = 1; i <= num_args; i++) {
                args[i] = argv[i + 1];
            }

            args[num_args] = NULL;  /* NULL-terminate the argument list */

            /* Fork a new process to execute the command */
            pid = fork();

            if (pid == -1) {
                perror("fork");
                exit(EXIT_FAILURE);
            } else if (pid == 0) { /* Child process */
                /* Execute the command with the provided arguments */
                if (execv(cmd_path, args) == -1) {
                    perror("execv");
                    exit(EXIT_FAILURE);
                }
            } else { /* Parent process */
                /* Wait for the child process to complete */
                int status;
                if (wait(&status) == -1) {
                    perror("wait");
                    exit(EXIT_FAILURE);
                }

                if (WIFEXITED(status)) {
                    int exit_status = WEXITSTATUS(status);
                    printf("Child process exited with status %d\n", exit_status);
                }
            }

            return 0;
        }

        token = strtok(NULL, ":");
    }

    /* The command was not found in the PATH */
    fprintf(stderr, "Error: Command '%s' not found in the PATH.\n", command);
    return EXIT_FAILURE;
}

