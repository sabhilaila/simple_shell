#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include "shell.h"

int execute_command1(char *line)
{
char *args[10];
int num_args = 0;

char *token = strtok(line, " ");
while (token != NULL && num_args < 10) 
{
args[num_args] = token;
token = strtok(NULL, " ");
num_args++;
}

args[num_args] = NULL;

pid_t pid;
int status;

pid = fork();
if (pid == 0) 
{
if (execvp(args[0], args) == -1) 
{
return (-1);
}
} else if (pid < 0) 
{
perror("Error");
return (-1);
}
else
{
waitpid(pid, &status, 0);
}
return (0);
}
