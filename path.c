#include "shell.h"

/**
 * check_command_in_path - checks if the command exists in the PATH
 * @command: the command to check
 * Return: 1 if the command exists, 0 otherwise
 */
int check_command_in_path(const char *command)
{
	char *path = getenv("PATH");
	char *path_copy = strdup(path);
	char *token = strtok(path_copy, ":");

	while (token != NULL)
	{
		char *full_path = malloc(strlen(token) + strlen(command) + 2);

		if (full_path == NULL)
		{
			perror("Memory allocation failed");
			free(path_copy);
			return (0);
		}

		strcpy(full_path, token);
		strcat(full_path, "/");
		strcat(full_path, command);

		if (access(full_path, X_OK) == 0)
		{
			free(full_path);
			free(path_copy);
			return (1);
		}

		free(full_path);
		token = strtok(NULL, ":");
	}
	free(path_copy);
	return (0);
}
