/*
** EPITECH PROJECT, 2018
** setenv.c
** File description:
** func for setenv
*/

#include "my.h"
#include "shell.h"
#include "printf.h"

void	add_line(char **ref, char **tmp, env_t *env)
{
	char	*str;
	int	lines = 0;
	int	i;

	while (tmp[lines] != NULL)
		lines++;
	env->env = malloc(sizeof(char *) * (lines + 2));
	for (i = 0; tmp[i] != NULL; i++)
		env->env[i] = my_strdup(tmp[i]);
	str = my_strcat(ref[1], "=");
	if (ref[2] != NULL)
		str = my_strcat(str, ref[2]);
	env->env[i] = str;
	env->env[i + 1] = NULL;
}

void	find_add_env(char **ref, env_t *env)
{
	int	line = find_str(ref[1], env->env);
	char	*str;

	str = my_strcat(ref[1], "=");
	if (ref[2] != NULL)
		str = my_strcat(str, ref[2]);
	env->env[line] = str;
	free(str);
}

void	fillplus_env(char **env, char **new)
{
	int	line = 0;

	for (int i = 0; env[i] != NULL; i++) {
		new[i] = my_strdup(env[i]);
		line++;
	}
}

void	my_setenv(char **ref, env_t *env)
{
	char	**tmp;
	int	lines = 0;

	if (alphanum(ref[1]) == -1) {
		setenv_err();
		return;
	}
	while (env->env[lines] != NULL)
		lines++;
	tmp = malloc(sizeof(char *) * (lines + 2));
	if (tmp == NULL)
		return;
	fillplus_env(env->env, tmp);
	if (find_str(ref[1], tmp) == -1)
		add_line(ref, tmp, env);
	else
		find_add_env(ref, env);
	if (find_str("PATH", env->env) != -1)
		get_bin(env->env, env);
}
