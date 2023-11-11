#include "shell.h"

/**
 * read_user_input - function to read user input
 * @line: the input to read
 * @len: the size of input
 */
void read_user_input(char **line, size_t *len)
{
	ssize_t chars_read = getline(line, len, stdin);

	if (chars_read == -1)
	{
		printf("\n");
	}
	else if ((*line)[chars_read - 1] == '\n')
	{
		(*line)[chars_read - 1] = '\0';
	}
}
