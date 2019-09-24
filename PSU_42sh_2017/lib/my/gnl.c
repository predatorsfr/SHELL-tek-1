/*
** EPITECH PROJECT, 2018
** gnl
** File description:
** frigging line
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "my.h"

int	lenlen(char const *str)
{
	int	i = 0;

	if (str == NULL)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

static char	*my_cat(char *dest, char const *str)
{
	char	*final;
	int	i = 0;
	int	j = 0;

	final = malloc(sizeof(char) * (lenlen(dest) + lenlen(str) + 1));
	if (final == NULL)
		return (NULL);
	if (dest == NULL) {
		for (int i = 0; i < lenlen(str); i++)
			final[i] = str[i];
		return (final);
	}
	for (i = 0; dest[i] != '\0'; i++)
		final[i] = dest[i];
	for (j = 0; str[j] != '\0'; j++) {
		final[i] = str[j];
		i++;
	}
	final[i] = '\0';
	return (final);
}

int find_return(char *str)
{
	int i = 0;

	if (str == NULL)
		return (-1);
	while (i != lenlen(str)) {
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*extract(char *str)
{
	char *final = malloc(sizeof(char) * lenlen(str));
	int i;

	if (final == NULL)
		return (NULL);
	for (i = 0; str[i] != '\n'; i++)
		final[i] = str[i];
	final[i] = '\0';
	return (final);
}

char	*gnl(int fd)
{
	char		buff[100 + 1];
	static char	*str = "";
	char		*final;
	int		file;

	while (find_return(str) == -1) {
		file = read(fd, buff, 100);
		buff[file] = '\0';
		if (file <= 0)
			return (NULL);
		str = my_cat(str, buff);
	}
	final = extract(str);
	while (*str != '\n')
		str++;
	str++;
	return (final);
}
