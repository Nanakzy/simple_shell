#include "shell.h"

/**
 * main - entry point of code
 *
 * Return: void
 */
int main(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t chars_read;
	int result = 0;

	while (1)
	{
		show_prompt();
		chars_read = getline(&line, &len, stdin);

		if (chars_read == -1)
		{
			printf("\n");
			break;
		}
		if (line[chars_read - 1] == '\n')
		{
			line[chars_read - 1] = '\0';
		}
		result = parse_and_execute(line);

		if (result == -1)
		{
			handle_execution_error();
		}
	}
	free(line);
	return (0);
}

