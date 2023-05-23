#include "shell.h"

/**
 * main - Function that checks if our shell is called from a new file.
 *
 * Return: 0 on success.
 */
int main(void)
{
    if (isatty(STDIN_FILENO) != 1)
    {
        mode_no_interactive();
    }
    else
    {
        mode_interactive();
    }

    return (0);
}
