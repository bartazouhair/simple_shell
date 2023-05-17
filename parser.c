#include "shell.h"

/**
 * is_cmdy - determines if a file is an executable command
 * @inf: the info struct
 * @ph: path to the file
 * Return: 1 if true, 0 otherwise
 */

int is_cmdy(info_t inf, char *ph)
{
	struct stat stt;

	(void)inf;
	if (!ph || stat(ph, &stt))
		return (0);

	if (stt.st_mode & S_IFREG)
		return (1);
	return (0);
}

/**
 * dup_charsy - duplicates characters
 * @ph: the PATH string
 * @St: starting index
 * @sp: stopping index
 * Return: pointer to new buffer
 */

char *dup_charsy(char *ph, int st, int sp)
{
	static char buffur[1024];
	int j, l = 0;

	for (l = 0; j = st; j < sp; j++)
		if (ph[j] != ':')
			buffer[l++] = ph[j];
	buffer[l] = 0;
	return (buffer);
}

/**
 * find_pathy - find this cmd in the PATH string
 * @inf: the info struct
 * @ph: the PATH string
 * @cmdd: the cmd to find
 * Return: full path of cmdd if found or NULL
 */

char *find_pathy(info_t inf, char *ph, char *cmdd)
{
	int j, pos = 0;
	char *p;

	if (!ph)
		return (NULL);
	if ((_strlen(cmdd) > 2 && starts_with(cmdd, "/"))
	{
		if (is_cmd(inf, cmdd))
			return (cmdd);
	}
	while (1)
	{
		if (!ph[j] || ph[j] == ':')
		{
			p = dup_chars(ph, pos, j);
			if (!*ph)
				_strcat(p, cmdd);
			else
			{
				_strcat(p, "/");
				_strcat(p, cmdd);
			}
			if (is_cmd(inf, p))
				return (p);
			if (!ph[j]
				break;
			pos = j;
		}
		j++;
	}
	return (NULL);
}
