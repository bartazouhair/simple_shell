#include "shell.h"

/**
 * mode_interactive - Interactive mode UNIX command line interpreter
 *
 * Description: This function implements an interactive shell where the user
 * can enter commands and have them processed by the handling_args function.
 * It continues in a loop until an exit condition is encountered.
 *
 * Return: void
 */
void mode_interactive(void)
{
	char *line;
	char **arguments;
	int status = -1;

	do {
		printf("$ ");
		line = get_line();
		arguments = line_split(line);
		status = handling_args(arguments);

		free(line);
		free(arguments);

		if (status >= 0)
		{
			exit(status);
		}
	} while (status == -1);
}
