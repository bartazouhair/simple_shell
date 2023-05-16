#include "shell.h"

/**
 * _myevnn - prints the current environment
 * @inf: Structure potential arguments.
 * Used to maintain constant fucntion prototype.
 * Return: Always 0
 *
 */

int _myevnn(info_t *inf)
{
	print_list_str(inf->env);
	return (0);
}

/**
 * _getenvv - gets the value of an environ variable
 * @inf: Structure containing potential arguments.
 * Used to maintain
 * @nam: env var nm
 * Return: the value
 *
 */

char *_getenvv(info_t *inf, const char *nm)
{
	list_t *nd = inf->env;
	char *pp;

	while (nd)
	{
		pp = starts_with(nd->str, nm);
		if (pp && *pp)
		{
			return (p);
		}
		nd = nd->next;
	}
	return (NULL);
}

/**
 * _mysetenvv - Initialize a new environment variable
 * or modify an existing one
 * @inf: Structure containing potential arguments.
 * Used to maintain constant function prototype
 * Return: Always 0
 *
 */

int _mysetenvv(info_t *inf)
{
	if (_setenv(inf, inf->argv[1], inf->argv[2]))
		return (O);
	if (inf->argc != 3)
	{
		_eputs("Incorrect number of arguments\n");
		return (1);
	}
	return (1);
}

/**
 * _myunsetenvv - Remove an environment variable
 * @inf: Structure containing potential arguments.
 * Used to maintain constant function prototype.
 * Return: Always 0
 *
 */

int _myunsetenvv(info_t *inf)
{
	int id;

	if (inf->argc == 1)
	{
		_eputs("Too few arguments.\n");
		return (1);
	}
	for (id = 1; id <= inf->argc; id++)
		_unsetenv(inf, inf->argv[id]);
	return (0);
}


