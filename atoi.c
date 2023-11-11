#include "shell.h"

/**
 * is_integer - converts string to integer
 * @str: the string to be converte
 * Return: the converted string
 */
int is_integer(const char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (!isdigit((unsigned char)str[i]))
		{
			return (-1);
		}
	}
	return (atoi(str));
}
