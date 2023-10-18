#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include "shell.h"
int main(void) 
{
char *command;
char prompt[] = "#cisfun$ ";

while (1) 
{
printf("%s", prompt);
command = NULL;
size_t bufsize = 0;
getline(&command, &bufsize, stdin);

if (command[0] == '\n') 
{
free(command);
continue;
}

command[strlen(command) - 1] = '\0';

pid_t pid = fork();
if (pid == 0) 
{
char* args[] = {command, NULL};
if (execve(command, args, NULL) == -1) 
{
perror("./shell");
exit(EXIT_FAILURE);
}
}
else if (pid < 0) 
{
perror("fork");
}
else 
{
waitpid(pid, NULL, 0);
}
free(command);
}
return (0);
}
