#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#define MAX_COMMAND_LENGTH 100
/**
 * main - entry point
 *
 * Return: 0 for success
 */
int main(void)
{
char command[MAX_COMMAND_LENGTH];
pid_t child_pid;
int status;

while (1)
{
printf("#cisfun$ ");
if (fgets(command, sizeof(command), stdin) == NULL)
{
exit(0);
}
size_t command_length = strlen(command);
if (command[command_length - 1] == '\n')
{
command[command_length - 1] = '\0';
}
child_pid = fork();
if (child_pid < 0)
{
perror("Fork error");
exit(1);
}
if (child_pid == 0)
{
char *args[] = {command, NULL};
execvp(command, args);
perror("Error");
exit(1);
}
else
{
waitpid(child_pid, &status, 0);
if (!WIFEXITED(status) || WEXITSTATUS(status) != 0)
{
exit(0);
}
}
}
return (0);
}

