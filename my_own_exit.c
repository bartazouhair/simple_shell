#include "shell.h"

/**
 * my_own_exit - couses normal process termination
 * @argm: empty argm
 *
 * Return: 0 to terminate the process
 */
int my_own_exit(char **argm)
{
	if (argm[1])
	{
		return (atoi(argm[1]));
	}
	else
	{
		return (0);
	}
}
