#include "shell.h"

/**
 * stream_reading - Read a line from the stream
 *
 * Description: This function reads a line from the stream, dynamically
 * allocating memory as needed to accommodate the line. It continues reading
 * until a newline character is encountered or the end of file (EOF) is reached.
 *
 * Return: Pointer to the read line
 */
char *stream_reading(void)
{
	int size = 1024;
	int num = 0;
	char *line = malloc(sizeof(char) * size);
	int chart;

	if (line == NULL)
	{
		fprintf(stderr, "allocation error in stream_reading");
		exit(EXIT_FAILURE);
	}

	while (1)
	{
		chart = getchar(); /* Read first character from the stream */

		if (chart == EOF)
		{
			free(line);
			exit(EXIT_SUCCESS);
		}
		else if (chart == '\n')
		{
			line[num] = '\0';
			return (line);
		}
		else
		{
			line[num] = chart;
		}

		num++;

		if (num >= size)
		{
			size += size;
			line = realloc(line, size);

			if (line == NULL)
			{
				fprintf(stderr, "reallocation error in stream_reading");
				exit(EXIT_FAILURE);
			}
		}
	}
}
