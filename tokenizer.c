#include "shell.h"

/**
 * tokenize_input - manually tokenizes the input string
 * @input: the user's command input
 * @args: array to store the tokens
 * Return: number of tokens
 */
int tokenize_input(char *input, char *args[])
{
	char *command = input;
	int arg_count = 0;

	while (*command == ' ' || *command == '\t')
	{
		command++;
	}

	while (*command != '\0')
	{
		args[arg_count++] = command;

		while (*command != ' ' && *command != '\t' && *command != '\0')
		{
			command++;
		}

		if (*command != '\0')
		{
			*command = '\0';
			command++;
		}

		while (*command == ' ' || *command == '\t')
		{
			command++;
		}
	}
	args[arg_count] = NULL;
	return (arg_count);
}
