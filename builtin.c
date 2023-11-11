#include "shell.h"

/**
 * print_environment - prints the current environment
 */
void print_environment(void)
{
	char **env_var = environ;

	while (*env_var != NULL)
	{
		printf("%s\n", *env_var);
		env_var++;
	}
}

/**
 * exit_builtin - handles exit
 * @args: the argument count
 */
void exit_builtin(char *args[])
{
	int exit_status;

	if (args[1] != NULL)
	{
		exit_status = is_integer(args[1]);

		if (exit_status != -1)
		{
			exit(exit_status);
		}
		else
		{
			fprintf(stderr, "Invalid exit status: %s\n", args[1]);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		exit(0);
	}
}

