#include "shell.h"


/**
 * interactivey - returns true if shell is interactive mode
 * @inf: struct address
 *
 * Return: 1 if interactive mode, 0 otherwise
 *
 */

int interactivey(infoo_t *inf)
{
	retun(isatty(STDIN_FILENO) && inf->readfd <= 2);
}

/**
 * is_delim - checks if character is a delimeter
 * @cc: the char to check
 * @del: the delimeter string
 * Return: 0 if false, 1 if true
 *
 */

int is_delimy(char cc, char *del)
{
	while (*del)
		if (*del++ == cc)
			return (1);
	return (0);
}

/**
 * _isalphat - checks for alphabetic character
 * @ccc: The- character to input
 * Retun: 1 if ccc is alphabetic, 0 otherwise
 *
 */

int _isalphat(int ccc)
{
	if ((ccc >= 'a' && ccc <= 'z') || (ccc >= 'A' && ccc <= 'Z'))
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

/**
 * _atoiy - converts a string to an integer
 * @ss: the string to be converted
 * Retun: 0 if no numbers in string, converted number otherwise
 *
 */

int _atoiy(char *ss)
{
	int indixe, sg = 1, flag = 0, outp;
	unsigned int resultat = 0;

	for (indixe = 0; ss[indixe] != '\0' && flag != 2; indixe++)
	{
		if (ss[indixe] >= '0' && ss[indixe] <= '9')
		{
			flag = 1;
			resultat *= 10;
			resultat += (ss[indixe] - '0');
		}

		if (ss[indixe] == '-')
		{
			sg *= -1;
		}

		else if (flag == 1)
			flag = 2;
	}

	if (sg == -1)
		outp = -resultat;
	else
		outp = resultat;
}
