#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

/**
 * custom_getline - Reads a line from stdin & allocate memory
 * @line: the minput to be read
 * Return: the number of characters read, or -1 on error or EOF.
 */
ssize_t custom_getline(char **line)
{
	static char buffer[BUFFER_SIZE];
	static size_t buffer_index;
	static size_t buffer_size;
	size_t i = buffer_index;
	size_t line_length;
	size_t j;

	if (buffer_index >= buffer_size)
	{
		buffer_size = read(STDIN_FILENO, buffer, BUFFER_SIZE);
		{
			if (buffer_size <= 0)
			{
				return (buffer_size);
			}
			buffer_index = 0;
		}
		while (i < buffer_size && buffer[i] != '\n')
		{
			i++;
		}
		line_length = i - buffer_index;
		*line = (char *)malloc(line_length + 1);
		if (*line == NULL)
		{
			return (-1);
		}
		for (j = 0; j < line_length; j++)
		{
			(*line)[j] = buffer[buffer_index + j];
		}
		(*line)[line_length] = '\0';

		buffer_index += line_length + 1;
	}
	return (line_length);
}
