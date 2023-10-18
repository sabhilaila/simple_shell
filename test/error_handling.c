#include <stdio.h>
#include <stdlib.h>
#include "main.h"
/**
 * handle_error - entry point
 * @message: input:wq
 *
 */
void handle_error(char *message)
{
	perror(message);
	exit(EXIT_FAILURE);
}

