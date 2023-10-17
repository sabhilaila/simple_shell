#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 100

int shell0(void) 
{
char command[MAX_COMMAND_LENGTH];
pid_t pid;
while (1) 
{
printf("#cisfun$ ");
if (fgets(command, sizeof(command), stdin) == NULL) 
{
printf("\n");
break;
}
command[strcspn(command, "\n")] = '\0';

pid = fork();
if (pid < 0) {
perror("fork");
exit(EXIT_FAILURE);
}
 else if (pid == 0) 
{
if (execlp(command, command, NULL) == -1) 
{
perror("execlp");
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
