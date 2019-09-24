/*
** EPITECH PROJECT, 2018
** exe.c
** File description:
** exe files
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include "my.h"
#include "shell.h"
#include "printf.h"

void	exe_func(char *path, char **arg, env_t *env)
{
	char	*str;
	int	exe = 0;

	if (check_file(path, env) == 2) {
		str = my_strcat("/", path);
		execve(my_strcat(env->paths[check_bin(path, env)], str)
							, arg, env->env);
	} else {
		exe = execve(path, arg, env->env);
		if (exe == -1) {
			puterr(path);
			puterr(" : Permission denied.\n");
			env->ret = 1;
		}
	}
}

int	exe2(char **arg, env_t *env)
{
	if (my_strcmp(arg[0], "setenv") == 0) {
		if (arg[1] == NULL && env->noenv != -2) {
			for (int i = 0; env->env[i] != 0; i++)
				my_printf("%s\n", env->env[i]);
			return (0);
		}
		my_setenv(arg, env);
		return (0);
	}
	if (my_strcmp(arg[0], "unsetenv") == 0 && env->noenv != -2) {
		my_unset(arg, env);
		return (0);
	}
	return (-1);
}

int	exe(char **arg, env_t *env)
{
	if (my_strcmp(arg[0], "exit") == 0) {
		if (arg[1] == NULL)
			exit(env->ret);
		exit(my_getnbr(arg[1]));
	}
	if (my_strcmp(arg[0], "cd") == 0) {
		cd_dir(arg, env);
		return (0);
	}
	if (my_strcmp(arg[0], "env") == 0 && env->noenv != -1) {
		for (int i = 0; env->env[i] != 0; i++)
			my_printf("%s\n", env->env[i]);
		return (0);
	}
	return (exe2(arg, env));
}
