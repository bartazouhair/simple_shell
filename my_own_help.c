#include "shell.h"

/**
 * my_own_help - Print help.
 * @argm: Arguments.
 *
 * Return: 1 on success, 0 otherwise.
 */
int my_own_help(char **argm)
{
    char *func_builtin[] = {
        "cd",
        "env",
        "help",
        "exit"
    };
    size_t num = 0;
    (void)(**argm);

    printf("\n---help simple_shell---\n");
    printf("Type a command and its arguments, then hit enter\n");
    printf("Built-in commands:\n");
    for (; num < sizeof(func_builtin) / sizeof(char *); num++)
    {
        printf("  -> %s\n", func_builtin[num]);
    }
    printf("Use the man command for information on other programs.\n\n");

    return (-1);
}
