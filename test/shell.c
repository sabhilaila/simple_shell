#include "main.h"
#include <string.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
/**
 * handle_command - enter point
 * @input: input
 */
void handle_command(char *input)
{
if (strcmp(input, "exit") == 0)
{
exit(0);
}
else
{
handle_path(input);
}
}
/**
 * main - entry point
 * @main: input
 */
int main(void)
{
char input[MAX_INPUT_SIZE];

while (1)
{
display_prompt();

if (fgets(input, MAX_INPUT_SIZE, stdin) == NULL)
{
handle_eof();
}

input[strcspn(input, "\n")] = '\0';

handle_command(input);
}
return (0);
}

