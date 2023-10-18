#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

#define MAX_COMMAND_LENGTH 100
/**
 * shell - entry point
 *
 * Return: 0 for success
 */
int shell(void)
{
char command[MAX_COMMAND_LENGTH];
while (1)
{
printf("#cisfun$ ");
if (fgets(command, MAX_COMMAND_LENGTH, stdin) == NULL)
{
printf("\n");
break;
}
command[strlen(command) - 1] = '\0';
if (fork() == 0)
{
execlp(command, command, (char *)NULL);
perror(command);
exit(EXIT_FAILURE);
}
wait(NULL);
}
return (0);
}

