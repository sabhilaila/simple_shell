#include "main.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

void handle_path(char *command)
{
	char *path = getenv("PATH");
	char *path_copy = strdup(path);
	char *token = strtok(path_copy, ":");

	while (token != NULL)
	{
		char *full_path = malloc(strlen(token) + strlen(command) + 2);

		sprintf(full_path, "%s/%s", token, command);

		if (access(full_path, X_OK) != -1)
		{
			execute_command(full_path);
			free(full_path);
			free(path_copy);
			return;
		}

		free(full_path);
		token = strtok(NULL, ":");
	}

	handle_error("Command not found");
	free(path_copy);
}
