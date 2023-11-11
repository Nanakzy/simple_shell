#include "shell.h"

/**
 * create_child_process - Function to fork a child process
 * Return: child pid
 */
pid_t create_child_process(void)
{
	pid_t pid = fork();

	if (pid == -1)
	{
		perror("Fork failed");
		exit(EXIT_FAILURE);
	}
	return (pid);
}
