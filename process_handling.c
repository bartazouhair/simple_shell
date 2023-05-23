#include "shell.h"

/**
 * process_handling - Add a new process.
 * @argv: Array of strings that contains the command and its flags.
 *
 * Return: 1 if success, 0 otherwise.
 */
int process_handling(char **argv)
{
    pid_t child_pid;
    int status;

    child_pid = fork();
    if (child_pid == 0)
    {
        if (execvp(argv[0], argv) == -1)
        {
            perror("Error in process_handling: Child process");
        }
        exit(EXIT_FAILURE);
    }
    else if (child_pid < 0)
    {
        perror("Error in process_handling: Forking");
    }
    else
    {
        do
        {
            waitpid(child_pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }
    return (-1);
}
