#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include "main.h"
#define MAX_INPUT_SIZE 1024
/**
 * execute_command - entry point
 * @input: input
 */
void execute_command(char *input)
{
pid_t pid = fork();

if (pid == -1)
{
handle_error("fork");
}

if (pid == 0)
{
char *args[MAX_INPUT_SIZE];
char *token = strtok(input, " ");
int i = 0;

while (token != NULL)
{
args[i++] = token;
token = strtok(NULL, " ");
}
args[i] = NULL;

if (execvp(args[0], args) == -1)
{
handle_error(args[0]);
}
exit(EXIT_FAILURE);
}
else
{
wait(NULL);
}
}
