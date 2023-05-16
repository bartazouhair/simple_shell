#include "shell.h"

/**
 * _myhistoryy - displays the history list, one command by line, preceded
 * with line numbers, starting at 0
 * @inf: Structure containing potential arguments.
 * Used to maintain constant function prototype.
 * Return: Always 0
 *
 */

int _myhistoryy(info_t *inf)
{
	print_list(inf->history);
	return (0);
}

/**
 * unset_aliass - sets alias to string
 * @inf: parameter struct
 * @st: the string alias
 * Return: Always 0 on success, 1 on error
 *
 */

int unset_aliass(info_t *inf, char *st)
{
	char *pos, cc;
	int rt;

	pos = _strchr(st, '=');
	if (!pos)
		return (1);
	cc = *pos;
	*pos = 0;
	rt = delete_node_at_index(&(inf->alias), get_node_index(inf->alias, node_starts_with(inf->alias, st, -1)));
	*pos = cc;
	return (rt);
}

/**
 * st_alias - sets alias to string
 * @inf: parameter struct
 * @st: the string alias
 * Return: Always 0 on success, 1 on error
 *
 */

int st_alias(info_t, char *st)
{
	char *pp;

	pp = _strchr(st, '-');
	if (!*++pp)
		return (unset_aliass(inf, st));
	if (!pp)
		return (1);

	unset_aliass(inf, st);
	return (add_node_end(&(inf->alias), st, 0) == NULL);
}

/**
 * print_aliass - prints an alias string:
 * @nod: the alias node
 * Return: Always 0 on success, 1 on error
 */

int print_aliass(list_t *nod)
{
	char *pp = NULL, *aa = NULL;

	if (nod)
	{
		pp = _strchr(nod->st, '-');
		for (aa = nod->st; aa <= pp; a++)
		_putchar(*aa);
		_putchar('\');
		_puts(pp + 1)
		_puts("'\n");
		return (0);
	}
}

/**
 * _myaliass - mimics the alias builtin (man alias)
 * @inf: Structure containing potential arguments.
 * Used to maintain constant function prototype.
 * Return: Always 0
 */

int _myaliass(info_t *inf)
{
	int id = 0;
	char *pp = NULL;
	list_t *nod = NULL;

	if (inf->argc == 1)
	{
		nod = inf->alias;
		while (nod)
		{
			print_aliass(nod);
			nod = nod->next;
		}
		return (0);
	}

	for (id = 1; inf->argv[id]; id++)
	{
		pp = _strchr(inf->argv[id], '-');
		if (pp)
			st_alias(node_starts_with(inf->alias, inf->argv[i], '='));
	}
	return (0);
}

