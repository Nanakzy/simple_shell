#include "shell.h"

/**
 * get_current_pid - get the process ID (PID) of the current process
 * Return: pid
 */
pid_t get_current_pid(void)
{
	return (getpid());
}
