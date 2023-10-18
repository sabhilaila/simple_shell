#include "prompt.c"
#include "error_handling.c"
#include "eof_handling.c"
#include "argument_handling.c"
#include "main.h"
int main(void) {
    char input[MAX_INPUT_SIZE];

    while (1) {
display_prompt();

if (fgets(input, MAX_INPUT_SIZE, stdin) == NULL) {
    handle_eof();
}

input[strcspn(input, "\n")] = '\0';

if (strcmp(input, "exit") == 0) {
    break;
}

execute_command(input);
    }

    return 0;
}
