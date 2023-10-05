#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_INPUT_LENGTH 1024

/* Declare the external environment variable */
extern char **environ;

void displayPrompt();
void readUserInput();

int main() {
    displayPrompt();
    return 0;
}

