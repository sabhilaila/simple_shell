#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "shell.h"

void execute_command(char **args) {
    pid_t pid;
    int status;

    pid = fork();
    if (pid == 0) {
        if (execvp(args[0], args) == -1) {
            perror("Error");
        }
        exit(EXIT_FAILURE);
    } else if (pid < 0) {
        perror("Error");
    } else {
        do {
            waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }
}

void run_shell() {
    char input[MAX_INPUT_SIZE];
    char *args[MAX_ARGS];
    int i;
char *token = strtok(input, " \t\n");

    while (1) {
        printf("($) ");
        fgets(input, sizeof(input), stdin);

      
        i = 0;
        while (token != NULL && i < MAX_ARGS - 1) {
            args[i] = token;
            token = strtok(NULL, " \t\n");
            i++;
        }
        args[i] = NULL;

        if (i > 0) {
            if (strcmp(args[0], "exit") == 0) {
                exit(0);
            }
            execute_command(args);
        }
    }
}
