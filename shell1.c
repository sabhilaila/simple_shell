#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

#define MAX_INPUT_SIZE 1024

int main(void) {
char input[MAX_INPUT_SIZE];
pid_t pid;

while (1) {
printf("#cisfun$ ");
if (fgets(input, MAX_INPUT_SIZE, stdin) == NULL) {
printf("\n");
break;
}

input[strcspn(input, "\n")] = '\0';

if (strcmp(input, "exit") == 0) {
break;
}

pid = fork();

if (pid == -1) {
perror("fork");
exit(EXIT_FAILURE);
}

if (pid == 0) {
if (execlp(input, input, (char *)NULL) == -1) {
perror(input);
}
exit(EXIT_FAILURE);
} else {
wait(NULL);
}
}

return (0);
}

