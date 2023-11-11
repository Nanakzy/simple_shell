#include "shell.h"

/**
 * execute_command - executes the command
 * @command: the command to be executed
 * @args: the number of arguments
 * Return: 0
 */
int execute_command(const char *command, char *args[])
{
	int status;
	pid_t cmd_pid = fork();

	if (cmd_pid == -1)
	{
		perror("Fork failed");
		return (-1);
	}
	else if (cmd_pid == 0)
	{
		if (args != NULL)
		{
			execvp(command, args);
		}
		else
		{
			execlp(command, command, (char *)0);
		}
		perror("Execution failed");
		exit(1);
	}
	else
	{
		wait(&status);

		if (WIFEXITED(status) && WEXITSTATUS(status) != 0)
		{
			write(STDERR_FILENO, "Execution failed: ", 18);
			perror(strerror(WEXITSTATUS(status)));
			return (-1);
		}
	}
	return (0);
}


