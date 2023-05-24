#include "shell.h"

/**
 * my_own_cd - Changes the working directory of the current shell.
 * @argm: Target directory.
 *
 * Return: 1 on success, 0 otherwise.
 */
int my_own_cd(char **argm)
{
	if (argm[1] == NULL)
	{
		fprintf(stderr, "Expected argument to \"cd\"\n");
	}
	else
	{
		if (chdir(argm[1]) != 0)
		{
			perror("Error in my_own_cd: Changing directory\n");
		}
	}
	return (-1);
}
