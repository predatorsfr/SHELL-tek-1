/*
** EPITECH PROJECT, 2018
** str_to_str.c
** File description:
** cut string into strings seperated by ;
*/

#include "my.h"
#include "shell.h"

int	len(char const *str)
{
	int	i = 0;

	while (str[i] != ';' && str[i] != '\0')
		i++;
	return (i);
}

int	count_str(char const *str)
{
	int	nb = 0;

	for (int i = 0; str[i] != '\0'; i++)
		if (str[i] == ';')
			nb++;
	return (nb);
}

void	fill_str(char *str, char const *ref)
{
	int	i = 0;

	while (ref[i] != ';' && ref[i] != '\0') {
		str[i] = ref[i];
		i++;
	}
	str[i] = '\0';
}

char	**str_to_str(char const *str)
{
	char	*final;

	if (str == NULL)
		return (NULL);
	final = malloc(sizeof(char) * (len(str) + 1));
	if (final == NULL)
		return (NULL);
	fill_str(final, str);
	return (char_charchar(final));
}
