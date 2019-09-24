/*
** EPITECH PROJECT, 2018
** cd.c
** File description:
** func to exe cd
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include "my.h"
#include "shell.h"
#include "printf.h"

void	old_pwd(env_t *env)
{
	int	oldpwd = find_str("OLDPWD", env->env);
	char	*copy = my_strdup(env->env[oldpwd]);
	char	*first = copy;

	if (oldpwd == -1 || my_strlen(env->env[oldpwd]) == 7) {
		puterr("cd: OLDPWD not set\n");
		return;
	}
	while (*copy != '=')
		copy++;
	copy++;
	chdir(copy);
	free(first);
}

void	go_home(env_t *env)
{
	int	home = find_str("HOME", env->env);
	char	*copy;
	char	*first;

	if (home == -1) {
		puterr("cd: No home directory.\n");
		return;
	}
	copy = my_strdup(env->env[home]);
	first = copy;
	while (*copy != '=')
		copy++;
	copy++;
	chdir(copy);
	free(first);
}

void	set_cd(env_t *env, char *oldir)
{
	size_t	size = 0;
	int	newline = find_str("PWD", env->env);
	int	oldline = find_str("OLDPWD", env->env);
	char	*currentdir = NULL;

	currentdir = getcwd(currentdir, size);
	if (newline != -1)
		env->env[newline] = my_strcat("PWD=", currentdir);
	if (oldline != -1)
		env->env[oldline] = my_strcat(REF_OLDPWD, oldir);
}

void	cd_dir(char **arg, env_t *env)
{
	struct stat	s;
	char		*currentdir = NULL;
	size_t		size = 0;
	int		flag = 0;

	currentdir = getcwd(currentdir, size);
	if (arg[1] == NULL)
		go_home(env);
	else if (my_strlen(arg[1]) == 1 && arg[1][0] == '-')
		old_pwd(env);
	else
		flag = chdir(arg[1]);
	set_cd(env, currentdir);
	if (flag == -1) {
		puterr(arg[1]);
		stat(arg[1], &s);
		puterr(S_ISREG(s.st_mode) ? ": Not a directory.\n" :
					": No such file or directory.\n");
	}
}
