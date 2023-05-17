#include "shell.h"

/**
 * _memsety - fills memory with a constant byte
 * @x: the pointer to the memory area
 * @y: the byte to fill *x with
 * @z: thz amount of bytes to be filled
 * Return: (x) a pointer to the memory area x
 */

char *_memsety(char *x, char y, unsigned int z)
{
	unsigned int j;

	for (j = 0; j < z; j++)
		x[j] = y;
	return (x);
}

/**
 * ffreey - frees a string of strings
 * @p: string of strings
 */

void ffreey(char **p)
{
	char **q = p;

	if (!p)
		return;
	while (*p)
		free(*p++);
	free(q);
}

/**
 * _reallocc - reallocates a block of memory
 * @pt: pointer to previous malloc ated block
 * @o: byte size of previous block
 * @n: byte size of new block
 * Return: pointer to da block nameen
 */

void *_reallocc(void *pt, unsigned int o, unsigned int n)
{
	char *pp;

	if (!pt)
		return (malloc(n));
	if (!n)
		return (free(pt), NULL);
	if (n == o)
		return (pt);

	pp = malloc(n);
	if (!pp)
		return (NULL);

	o = o < n ? o : n;
	while (o)
		pp[o] = ((char *)pt)[o];
	free(pt);
	return (pp);
}
