/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** main
*/

#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "my.h"
#include "shell.h"
#include "printf.h"

void	errors(int check, env_t *env)
{
	env->ret = check;
	if (WTERMSIG(check) == 11) {
	        my_printf("Segmentation fault\n");
		return;
	} else if (check == 136) {
		my_printf("Floating point exception\n");
	}
}

void	intrup(__attribute__((unused))int check)
{
	write(1, "\n>> ", 4);
	return;
}

int	start_fork(char **arg, env_t *env)
{
	pid_t	ref;
	int	check = 0;
	char	*path = arg[0];

	if (exe(arg, env) != -1)
		return (0);
	if (check_file(path, env) != -1) {
		ref = fork();
		wait(&check);
		if (ref == 0) {
			exe_func(path, arg, env);
			kill(getpid(), 1);
		} else if (ref == -1)
			exit(1);
		return (check);
	}
	return (check);
}

void	start_sh(char **env, env_t *newenv)
{
	char	*str;
	char	**arg;
	int	check;

	newenv->noenv = start_env(env, newenv);
	while (1) {
		write(1, ">> ", 3);
		str = gnl(0);
		if (str != NULL && str[0] == '\0')
			continue;
		else if (str != NULL && check_semicolons(str) != 0) {
			semicolons(str, newenv);
			continue;
		}
		arg = char_charchar(str);
		if (arg == NULL) {
			my_putstr("exit\n");
			free_exit(newenv);
		} else {
			check = start_fork(arg, newenv);
			errors(check, newenv);
		}
	}
}

int	main(int ac, __attribute__((unused))char **av, char **env)
{
	env_t	newenv;

	if (ac > 1)
		return (EXIT_ERROR);
	newenv.ret = 0;
	signal(SIGINT, intrup);
	start_sh(env, &newenv);
	return (newenv.ret);
}
