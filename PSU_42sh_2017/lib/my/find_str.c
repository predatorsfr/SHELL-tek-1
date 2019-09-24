/*
** EPITECH PROJECT, 2018
** find_str.c
** File description:
** find str in strstr and return line where it is
*/

#include "my.h"

int	check_word(char *name, char **env, int j)
{
	int	i = 0;

	while (env[j][i] != '=' && env[j][i] != '\0') {
		if (env[j][i] != name[i])
			return (-1);
		i++;
	}
	return (j);
}

int	find_str(char *name, char **env)
{
	int	j = 0;

	while (env[j] != NULL) {
		if (check_word(name, env, j) == -1)
			j++;
		else
			return (j);
	}
	return (-1);
}
