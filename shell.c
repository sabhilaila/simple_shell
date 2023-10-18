#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "main.h"
#include <string.h>
#define MAX_COMMAND_LENGTH 100

int shell(void) 
{
char command[MAX_COMMAND_LENGTH];
pid_t pid;

while (1) 
{
printf("#cisfun$ ");
if (fgets(command, MAX_COMMAND_LENGTH, stdin) == NULL) 
{
printf("\n");
break;
}
command[strcspn(command, "\n")] = 0;
pid = fork();
if (pid == 0) 
{
execlp(command, command, (char *)NULL);
perror(command);
exit(EXIT_FAILURE);
}
else if (pid < 0) 
{
perror("fork");
exit(EXIT_FAILURE);
}
else 
{
int status;
wait(&status);
}
}
return (0);
}

