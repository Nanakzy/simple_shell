#include "shell.h"

/**
 * parse_and_execute - parse and execute a user command
 * @input: the user's command input
 * Return: 0 success
 */
int parse_and_execute(char *input)
{
	char *args[1024];
	int arg_count;

	arg_count = tokenize_input(input, args);

	args[arg_count] = NULL;

	if (arg_count > 0 && strcmp(args[0], "exit") == 0)
	{
		exit_builtin(args);
	}
	else if (arg_count > 0 && strcmp(args[0], "env") == 0)
	{
		print_environment();
	}
	else
	{
		execute_command(args[0], args);
	}
	return (0);
}
