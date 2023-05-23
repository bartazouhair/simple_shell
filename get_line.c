#include "shell.h"

/**
 * get_line - Read a line from stdin.
 *
 * Return: Pointer that points to a string with the line content.
 */
char *get_line(void)
{
    char *line = NULL;
    size_t size = 0;

    if (getline(&line, &size, stdin) == -1)
    {
        if (feof(stdin))
        {
            free(line);
            exit(EXIT_SUCCESS);
        }
        else
        {
            free(line);
            perror("Error while reading the line from stdin");
            exit(EXIT_FAILURE);
        }
    }

    return (line);
}
