/*
** EPITECH PROJECT, 2018
** setup_env.c
** File description:
** setup empty env
*/

#include "my.h"
#include "shell.h"

char	**fill_env(char **env, char **new)
{
	int	i = 0;

	for (i = 0; env[i] != 0; i++)
		new[i] = my_strdup(env[i]);
	new[i] = NULL;
	return (new);
}

char	**create_env(char **env)
{
	int	size = 0;
	char	**newenv = NULL;

	while (env[size] != NULL)
		size++;
	newenv = malloc(sizeof(char *) * (size + 2));
	if (newenv == NULL)
		return (NULL);
	newenv = fill_env(env, newenv);
	return (newenv);
}

char	**no_env(void)
{
	char	**env = malloc(sizeof(char *) * NO_ENV);
	char	*currentdir = NULL;
	size_t	size = 0;

	currentdir = getcwd(currentdir, size);
	if (env == NULL || currentdir == NULL)
		return (NULL);
	env[0] = my_strdup(REF_PATH);
	env[1] = my_strcat(REF_PWD, currentdir);
	env[2] = my_strdup(REF_OLDPWD);
	env[3] = NULL;
	return (env);
}

int	start_env(char **env, env_t *newenv)
{
	if (env[0] == NULL) {
		newenv->env = no_env();
		get_bin(newenv->env, newenv);
		return (-1);
	}
	newenv->env = create_env(env);
	if (find_str("PATH", newenv->env) == -1)
		return (-2);
	get_bin(env, newenv);
	return (0);
}
