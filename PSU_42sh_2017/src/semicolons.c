/*
** EPITECH PROJECT, 2018
** semicolons.c
** File description:
** fill struct with multiple char**
*/

#include "my.h"
#include "shell.h"

int	check_semicolons(char const *str)
{
	int	i = 0;
	int	nb = 0;

	while (str[i] != '\0') {
		if (str[i] == ';')
			nb++;
		i++;
	}
	return (nb);
}

int	semicolons(char *str, env_t *newenv)
{
	int	len = check_semicolons(str);
	char	**final;
	int	check = 0;

	if (len == 0)
		return (0);
	for (int i = 0; i <= len; i++) {
		final = str_to_str(str);
		while (*str != ';' && *str != '\0')
			str++;
		if (*str == ';')
			str++;
		check = start_fork(final, newenv);
		errors(check, newenv);
	}
	return (0);
}
