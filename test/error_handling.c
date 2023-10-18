#include <stdio.h>
#include <stdlib.h>
#include "main.h"
void handle_error(char *message) {
    perror(message);
    exit(EXIT_FAILURE);
}

