#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include "shell.h"

int execute_command(char *command, char *args)
{
pid_t pid;
int status;
pid = fork();
if (pid == 0)
{
if (execlp(command, command, args, NULL) == -1) 
{       
return (-1);
}} 
else if (pid < 0) 
{
perror("Error");    
return (-1);
} 
else
{
waitpid(pid, &status, 0);}
return (0);
}
