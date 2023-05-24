#include "shell.h"

/**
 * line_split - Split a string into multiple strings.
 * @line: String to be split.
 *
 * Return: Pointer that points to the new array.
 */
char **line_split(char *line)
{
	int size = 64;
	int i = 0;
	char **tokens = malloc(size * sizeof(char *));
	char *token;

	if (!tokens)
	{
		fprintf(stderr, "Allocation error in line_split: tokens\n");
		exit(EXIT_FAILURE);
	}

	token = strtok(line, TOK_DELIM);
	while (token != NULL)
	{
		if (token[0] == '#')
		{
			break;
		}
		tokens[i] = token;
		i++;
		if (i >= size)
		{
			size += size;
			tokens = realloc(tokens, size * sizeof(char *));
			if (!tokens)
			{
				fprintf(stderr, "Reallocation error in line_split: tokens\n");
				exit(EXIT_FAILURE);
			}
		}
		token = strtok(NULL, TOK_DELIM);
	}

	tokens[i] = NULL;
	return (tokens);
}
