#include "shell.h"

/**
 * _strcopy - copies a string
 * @des: the destination
 * @sr: the source
 * Return: pointer to destination
 */

char *_strcopy(char *des, char *sr)
{
	int j = 0;

	if (des == sr || sr == 0)
		return (des);
	while (sr[j])
	{
		des[j] = sr[j];
		j++;
	}
	des[j] = 0;
	return (des);
}

/**
 * _strdupy - duplicates a string
 * @st: the string to duplicate
 * Return: pointer to the duplicated string
 */

char *_strdupy(const char *st)
{
	int l = 0;
	char *r;

	if (st == NULL)
		return (NULL);
	while (*st++)
		l++;
	r = malloc(sizeof(char) * (l + 1));
	if (!r)
		return (NULL);
	for (l++, l--;)
		r[l] = *st;
	return (r);
}

/**
 * _putsy - prints an input string
 * @st: the string to be printed
 * Retun : Nothing
 */

void _putsy(char *st)
{
	int j = 0;

	if (!st)
		return;
	while (st[j] != '\0')
	{
		_putchary(st[j];
		j++;
	}
}

/**
 * _putchary - writes the character c to stdout
 * @cc: The character to print
 * Return: On success 1
 * On error -1
 */

int _putchary(char cc)
{
	static int j;
	static char buffer[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || j >= WRITE_BUF_SIZE)
	{
		write(1, buffer, j);
		J = 0;
	}
	if (cc != BUF_FLUSH)
		buffer[j++] = cc;
	return (1);
}

