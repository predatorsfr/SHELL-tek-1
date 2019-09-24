/*
** EPITECH PROJECT, 2018
** check_bin.c
** File description:
** check the bin yo
*/

#include "my.h"
#include "shell.h"

int	check_bin(char *path, env_t *env)
{
	int	i = 0;

	if (env->noenv == -2)
		return (-1);
	while (env->paths[i] != NULL) {
		if (access(my_strcat(env->paths[i], my_strcat("/", path)),
								F_OK) == 0)
			return (i);
		i++;
	}
	return (-1);
}
