#include "shell.h"

/**
 * my_own_exit - Causes normal process termination.
 * @argm: Empty argm.
 *
 * Return: 0 to terminate the process.
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
