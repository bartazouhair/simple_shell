#include "shell.h"

/**
 * handling_args - Map if a command is a builtin or a process.
 * @args: Command and its flags.
 *
 * Return: 1 on success, 0 otherwise.
 */
int handling_args(char **args)
{
    char *func_list_builtin[] = {
        "cd",
        "env",
        "help",
        "exit"
    };
    int (*func_builtin[])(char **) = {
        &my_own_cd,
        &my_own_env,
        &my_own_help,
        &my_own_exit
    };
    size_t num = 0;

    if (args[0] == NULL)
    {
        /* Empty command was entered */
        return (-1);
    }

    /* Find if the command is a builtin */
    for (; num < sizeof(func_list_builtin) / sizeof(char *); num++)
    {
        /* If there is a match, execute the builtin command */
        if (strcmp(args[0], func_list_builtin[num]) == 0)
        {
            return ((*func_builtin[num])(args));
        }
    }

    /* Create a new process */
    return (process_handling(args));
}
