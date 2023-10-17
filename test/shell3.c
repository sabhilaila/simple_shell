#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include "shell.h"
#define MAX_COMMAND_LENGTH 100
#define MAX_ARGUMENTS 10

int shell2(void) 
{
char command[MAX_COMMAND_LENGTH];
char *arguments[MAX_ARGUMENTS];
char *token;
int arg_count;
pid_t pid;

while (1) 
{
printf(":) ");
if (fgets(command, sizeof(command), stdin) == NULL) 
{
printf("\n");
break;
}
command[strcspn(command, "\n")] = '\0';
token = strtok(command, " ");
arg_count = 0;
while (token != NULL && arg_count < MAX_ARGUMENTS - 1) 
{
arguments[arg_count++] = token;
token = strtok(NULL, " ");
}
arguments[arg_count] = NULL;

pid = fork();
if (pid < 0) 
{
perror("fork");
exit(EXIT_FAILURE);
}
 else if (pid == 0) 
{
if (execvp(arguments[0], arguments) == -1) 
{
printf("%s: command not found\n", arguments[0]);
exit(EXIT_FAILURE);
}
}
else
{
wait(NULL);
}
}
return (0);
}
