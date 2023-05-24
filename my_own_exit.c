#include "shell.h"

/**
 * my_own_exit - Causes normal process termination.
 * @argm: Arguments.
 *
 * Return: 0 to terminate the process.
 */
int my_own_exit(char **argm)
{
	int exit_status = 0;

	if (argm[1] != NULL)
	{
		exit_status = atoi(argm[1]);
		if (exit_status == 0 && strcmp(argm[1], "0") != 0)
		{
			fprintf(stderr, "Invalid exit status: %s\n", argm[1]);
			return (-1);
		}
	}

	exit(exit_status);
	return (0);
}
