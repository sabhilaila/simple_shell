#include <stdio.h>
#include <string.h>

int handleLoopExitCondition(const char *input) {
    /* Check if the user entered "exit" or Ctrl+D was pressed */
    if (input == NULL || strcmp(input, "exit") == 0) {
        return 1; /* Signal to exit the loop */
    }
    return 0; /* Continue the loop */
}

