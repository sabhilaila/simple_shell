#include <string.h>

void removeNewlineCharacter(char *input) {
    /* Remove the newline character from the input */
    input[strcspn(input, "\n")] = '\0';
}

