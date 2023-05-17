#include "shell.h"

/**
 * _strleny - returns the length of a string
 * @st: the string whose lenght to check
 * Return: integer lenght of string
 */

int _strleny(char *st)
{
	int j = 0;

	if (!st)
		return (0);

	while (*st++)
		j++;
	return (j);
}

/**
 * _strcomp - performs lexicographic comparison of two strangs
 * @z1: the first strang
 * @z2: the second strang
 * Return: positive if z1 > z2
 * negative if z1 < z2
 * zeo if z1 == z2
 */

int _strcompy(char *z1, char *z2)
{
	while (*z1 && *z2)
	{
		if (*z1 != *z2)
			return (*z1 - *z2);
		z1++;
		z2++;
	}
	if (*z1 == *z2)
		return (0);
	else
		return (*z1 < *z2 ? -1 : 1);
}

/**
 * starts_withy - checks if needle starts with haystack
 * @hay: string string to search
 * @ned: the substring to find
 * Return: address of next char of haystack or Null
 */

char *starts_withy(const char *hay, const char *ned)
{
	while (*ned)
		if (*ned++ != *hay++)
			return (NULL);
	return ((char *) hay);
}

/**
 * _strcaty - concatenates twa strings
 * @des: the destination buffer
 * @sr: the source buffer
 * Return: pointer to destination buffer
 */

char *_strcaty(char *des, char *sr)
{
	char *r = des;

	while (*des)
		des++;
	while (*sr)
		*des++ = *sr++;
	*des = *sr;
	return (r);
}
