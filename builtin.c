#include "shell.h"

/**
 * _myexity - exits the shell
 * @inf: Structure containing potential arhuments.
 * Used to maintian constant function prototype.
 * Return : exits with a given exit status
 * (0) if inf.argv[0] != "exit"
 *
 */

int _myexity(info_t *inf)
{
	int ec;

	if (inf->argv[1])
	{
		ec = _erratoi(inf->argv[1]);
		if (ec == -1)
		{
			inf->status = 2;
			print_error(inf, "Illegal number : ");
			_eputs(inf->argv[1]);
			_eputchar("\n");
			return (1);
		}
		inf->err_num = _erratoi(inf->argv[1];
				return (-2);
	}
	inf->err_num = -1;
	return (-2);
}

/**
 * _mycdy - changes the current directory of the process
 * @inf : Structure containing potential arguments.
 * Used to maintain constant function prototype.
 * Return: Always 0
 *
 */

int _mycdy(info_t *inf)
{
	char *ss, *dr, buffer[1024];
	int ret;

	ss = getcwd(buffer, 1024);
	if (!ss)
	{
		_puts("TODO: >> gecwd failure emsg here <<\n");
	}
	if (!inf->argv[1])
	{
		dr = _getenv(inf, "HOME=");
		if (!dr)
			ret = chdir((dr = _getenv(inf, "PWD=")) ? dr : "/");
		else
			ret = chdir(dr);
	}
	else if (_strcmp(inf->argv[1], "-") == 0)
	{
		if (!_getenv(inf, "OLDPWD="))
		{
			_puts(ss);
			_putchar('\n');
			return (1);
		}
		_puts(_getenv(inf, "OLDPWD=")), _putchar('\n');
		ret = chdir((dr = _getenv(inf, "OLDPWD")) ? dr : "/");
	}
	else
		ret = chdir(inf->argv[1]);
	if (ret != -1)
	{
		_setenv(inf, "OLDPWD", _getenv(inf, "PWD="));
		_setenv(inf, "PWD", getcwd(buffer, 1024));
	}
	else
	{
		print_error(inf, "can't cd to ");
		_eputs(inf->argv[1]), _eputchar('\n');
	}
	return (0);
}

