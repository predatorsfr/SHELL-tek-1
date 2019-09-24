/*
** EPITECH PROJECT, 2018
** unset_exe.c
** File description:
** unset env mgl
*/

#include "my.h"
#include "shell.h"

void	fill_unset(char *name, env_t *env)
{
	int	i = find_str(name, env->env);

	while (env->env[i] != NULL) {
		env->env[i] = env->env[i + 1];
		i++;
	}
	env->env[i] = NULL;
}

void	my_unset(char **ref, env_t *env)
{
	if (ref[1] == NULL || find_str(ref[1], env->env) == -1)
		return;
	fill_unset(ref[1], env);
}
