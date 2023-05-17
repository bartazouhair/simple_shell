#include "shell.h"

/**
 * _strncopy - copies a string
 * @dt: the destination string to be copied to
 * @sr: the source string
 * @mnt: the amount of characters to be copied
 * Return: the concatenated string
 */

char *_strncopy(char *dt, char sr, int mnt)
{
	int y, z;
	char *sp = dt;

	y = 0;
	while (sr[y] != '\0' && y < mnt - 1)
	{
		dt[y] = sr[y];
		y++;
	}
	if (y < mnt)
	{
		z = y;
		while (z < mnt)
		{
			dt[z] = '\0';
			z++;
		}
	}
	return (sp);
}

/**
 * _strncaty - concatenates two strings
 * @dt: the first string
 * @sd: the second string
 * @mnt: the amount of bytes to be maximally used
 * Return: the concatenated string
 */

char *_strncaty(char *df, char *sd, int mnt)
{
	int y, z = 0;
	char *sp = dt;

	while (dt[y] != '\0')
		y++;
	while (sd[z] != '\0' && z < mnt)
	{
		dt[y] = sd[z];
		y++;
		z++;
	}
	if (z < mnt)
		dt[y] = '\0';
	return (sp);
}

/**
 * _strchry - locates a character in a string
 * @ps: the string to be parsed
 * @cp: the character to look for
 * Return: (ps) a pointer to the memory area ps
 */

char *_strchry(char *ps, char cp)
{
	do {
		if (*ps == cp)
			return (ps);
	} while (*ps++ != '\0');

	return (NULL);
}
