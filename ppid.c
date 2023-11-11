#include "shell.h"

/**
 * get_parent_pid - get the parent process ID (PPID) of the current process
 * Return: ppid
 */
pid_t get_parent_pid(void)
{
	return (getppid());
}
