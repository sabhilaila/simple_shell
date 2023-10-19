#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <fcntl.h>

#define MAX_COMMAND_LENGTH 100
#define MAX_ARGUMENTS 10

void execute_command(char *args[], int background) {
    pid_t pid = fork();
    if (pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        if (background) {
            int devnull = open("/dev/null", O_RDWR);
            dup2(devnull, STDIN_FILENO);
            dup2(devnull, STDOUT_FILENO);
            close(devnull);
        }
        execvp(args[0], args);
        perror("execvp");
        exit(EXIT_FAILURE);
    } else {
        if (!background) {
            waitpid(pid, NULL, 0);
        }
    }
}

int main(void) {
    char command[MAX_COMMAND_LENGTH];
    char *args[MAX_ARGUMENTS];
        char *token = strtok(command, " ");
        int arg_count = 0;
        int background = 0;

    while (1) {
        printf("#cisfun$ ");
        if (fgets(command, MAX_COMMAND_LENGTH, stdin) == NULL) {
            printf("\n");
            break;
        }
        command[strlen(command) - 1] = '\0';
         
        while (token != NULL) {
            if (strcmp(token, "&") == 0) {
                background = 1;
            } else {
                args[arg_count] = token;
                arg_count++;
            }
            token = strtok(NULL, " ");
        }
        args[arg_count] = NULL;
        
        if (arg_count > 0) {
            if (strcmp(args[0], "cd") == 0) {
                if (arg_count >= 2) {
                    if (chdir(args[1]) != 0) {
                        perror("cd");
                    }
                } else {
                    printf("cd: missing argument\n");
                }
            } else if (strcmp(args[0], "exit") == 0) {
                exit(EXIT_SUCCESS);
            } else {
                execute_command(args, background);
            }
        }
    }
    return (0);
}
