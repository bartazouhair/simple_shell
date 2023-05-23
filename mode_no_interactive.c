#include "shell.h"

/**
 * mode_no_interactive - Non-interactive mode UNIX command line interpreter
 *
 * Description: This function implements a non-interactive shell where commands
 * are read from a stream and processed by the handling_args function. It
 * continues in a loop until an exit condition is encountered.
 *
 * Return: void
 */
void mode_no_interactive(void)
{
	char *line;
	char **argv;
	int status = -1;

	do {
		line = stream_reading();
		argv = line_split(line);
		status = handling_args(argv);
		free(line);
		free(argv);
		if (status >= 0)
		{
			exit(status);
		}
	} while (status == -1);
}
