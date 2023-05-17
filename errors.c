#include "shell.h"

/**
 * _eputsy - prints an input string
 * @st: the string to be printed
 * Return: Nothing
 */

void _eputsy(char *st)
{
	int j = 0;

	if (!st)
		return;
	while (st[j] != '\0')
	{
		_eputchar(st[j]);
		j++;
	}
}

/**
 * _eputchary - writes the character c to stderr
 * @cc: The character to print
 * Return: On success 1
 * On error -1
 */

int _eputchary(char cc)
{
	static int j;
	static char buff[WRITE_BUF_SIZE];

	if (cc == BUF_FLUSH || j >= WRITE_BUF_SIZE)
	{
		write(2, buff, j);
		j = 0;
	}
	if (cc != BUF_FLUSH)
		buff[j++] = cc;
	return (1);
}

/**
 * _putfdy - writes the character c to given fdd
 * @cc : The character to print
 * @fdd: The filedescriptor to write to
 * Return: On success 1
 * On error -1
 */

int _putfdy(char cc, int fdd)
{
	static int j;
	static char buff[WRITE_BUF_SIZE];

	if (cc == BUF_FLUSH || j >= WRITE_BUF_SIZE)
	{
		write(fdd, buff, j);
		j = 0;
	}
	if (cc != BUF_FLUSH)
		buff[j++] = cc;
	return (1);
}

/**
 * _putsfdy - print an input string
 * @st: the string to be printed
 * @fdd: the filedescriptor to write to
 * Return: the number of chars put
 */

int _putsfdy(char *st, int fdd)
{
	int j = 0;

	if (!st)
		return (0);
	while (*st)
		j += _putfdy(*st++, fdd);
	return (j);
}
