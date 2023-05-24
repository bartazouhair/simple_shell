#include "shell.h"

/**
 * my_own_env - Function that prints environment variables.
 * @argm: Arguments.
 *
 * Return: 1 on success, 0 otherwise.
 */
int my_own_env(char **argm)
{
	int num = 0;
	(void)(**argm);

	while (environ[num])
	{
		write(STDOUT_FILENO, environ[num], strlen(environ[num]));
		write(STDOUT_FILENO, "\n", 1);
		num++;
	}

	return (-1);
}
