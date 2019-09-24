/*
** EPITECH PROJECT, 2018
** get_bin.c
** File description:
** get bin path from env
*/

#include "my.h"
#include "shell.h"

int	path_nb(char *paths)
{
	int	i = 0;
	int	nb = 0;

	while (paths[i] != '\0') {
		if (paths[i] == ':')
			nb++;
		i++;
	}
	return (nb + 1);
}

int	path_len(char *paths)
{
	static int	i = 0;
	int		len = 0;

	while (paths[i] != ':' && paths[i] != '\0') {
		i++;
		len++;
	}
	i++;
	return (len);
}

void	fill_path(env_t *env, char *copy)
{
	int	i = 0;
	int	j = 0;
	int	k = 0;

	while (j != path_nb(copy) - 1) {
		while (copy[k] != ':') {
			env->paths[j][i] = copy[k];
			k++;
			i++;
		}
		env->paths[j][i] = '\0';
		i = 0;
		k++;
		j++;
	}
	env->paths[j + 1] = NULL;
}

void	path_set(char *copy, env_t *env)
{
	env->paths = malloc(sizeof(char *) * (path_nb(copy) + 1));
	if (env->paths == NULL)
		return;
	for (int i = 0; i != path_nb(copy); i++) {
		env->paths[i] = malloc(sizeof(char) * (path_len(copy) + 1));
		if (env->paths[i] == NULL)
			return;
	}
	fill_path(env, copy);
}

void	get_bin(char **envp, env_t *env)
{
	int	line = 0;
	char	*copy;
	char	*first;

	if (find_str("PATH", envp) != -1) {
		line = find_str("PATH", envp);
		copy = my_strdup(envp[line]);
	}
	first = copy;
	while (*copy != '=')
		copy++;
	copy++;
	path_set(copy, env);
	free(first);
}
