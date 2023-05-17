#include "shell.h"

/**
 * _erratoiy - converts a string to an integer
 * @Sg : the string to be converted
 * Return: 0 if no numbers in string
 * converted nulber otherwise
 * -1 on error
 */

int _erratoiy(char *sg)
{
	int j = 0;
	unsigned long int r = 0;

	if (*sg == '+')
		sg++;
	for (j = 0; sg[j] != '\0'; j++)
	{
		if (sg[j] >= '0' && sg[j] <= '9')
		{
			r *= 10;
			r += (sg[j] - '0');
			if (r > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (r);
}

/**
 * print_errory - prints an error message
 * @inf: the parameter & return info struct
 * @etr: string containing specified error type
 * Return: 0 if no numbers in string
 * converted number otherwise
 * -1 error
 */

void print_errory(info_t *inf, char *etr)
{
	_eputs(inf->fname);
	_eputs(": ");
	print_dy(inf->line_count, STDERR_FLIENO);
	_eputs(": ");
	_eputs(inf->argv[0]);
	_eputs(": ");
	_eputs(etr);
}

/**
 * print_dy - function prints a decimal (integer) number (base 10)
 * @inp: the input
 * @fdd: the filedescriptor to write to
 * Return: number of characters printed
 */

int print_dy(int inp, int fdd)
{
	int (*_putchar)(char) = _putchar;
	int j, cn = 0;
	unsigned int abs, curr;

	if (fdd == STDERR_FLIENO)
		_putchar = _eputchar;
	if (inp < 0)
	{
		abs = -inp;
		_putchar('-');
		cn++;
	}
	else
		abs = inp;
	curr = abs;
	for (j = 1000000000; j > 1; j /= 10)
	{
		if (abs / j)
		{
			_putchar('0' + curr / j);
			cn++;
		}
		curr %= j;
	}
	_putchar('0' + curr);
	cn++;

	return (cn);
}

/**
 * convert_numbery - converter function
 * @nbr: number
 * @bs: base
 * @fg: argument flags
 * TReturn: string
 */

char *convert_numbery(long int nbr, int bs, int fg)
{
	static char *arr;
	static char buffer[50];
	char sg = 0;
	char *pt;
	unsigned long l = nbr;

	if (!(fg & CONVERT_UNSIGNED) && nbr < 0)
	{
		nn = -nbr;
		sg = '-';
	}
	arr = fg & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	pt = &buffer[49];
	*pt = '\0';

	do {
		*--pt = arr[nn / bs];
		nn /= bs;
	} while (nn != 0);

	if (sg)
		*--pt = sg;
	return (pt);
}

/**
 * remove_commentsy - function replaces first instance of '#' with '\0'
 * @bf: address of the string to modify
 * Return: Always 0
 */

void remove_commentsy(char *bf)
{
	int j;

	for (j = 0; bf[j] != '\0'; j++)
		if (bf[j] == '#' && (!j || bf[j - 1] == ''))
		{
			bf[j] = '\0';
			break;
		}
}

