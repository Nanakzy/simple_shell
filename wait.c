#include "shell.h"

/**
 * wait_for_child_process - wait for child to terminate
 * @pid: the process to be created
 * Return: void
 */
void wait_for_child_process(pid_t pid)
{
	int status;

	if (waitpid(pid, &status, 0) == -1)
	{
		perror("Wait failed");
	}
}
