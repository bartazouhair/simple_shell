#include "shell.h"

/**
 * read_stream - read a line from the stream
 *
 * Return: pointer that points the the read line
 */
char *stream_reading(void)
{
	int size = 1024;
	int num = 0;
	char *line = malloc(sizeof(char) * size);
	int chart;

	if (line == NULL)
	{
		fprintf(stderr, "allocation error in read_stream");
		exit(EXIT_FAILURE);
	}
	while (1)
	{
		chart = getchar();
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
				fprintf(stderr, "reallocation error in read_stream");
				exit(EXIT_FAILURE);
			}
		}
	}
}
