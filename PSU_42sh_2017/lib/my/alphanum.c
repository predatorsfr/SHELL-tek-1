/*
** EPITECH PROJECT, 2018
** alphanum
** File description:
** nb n letters
*/

#include "my.h"

int	alphanum(char const *str)
{
	int	i = 0;

	while (str[i] != '\0') {
		if ((str[i] < '0' || str[i] > '9') &&
				(str[i] < 'a' || str[i] > 'z') &&
				(str[i] < 'A' || str[i] > 'Z'))
			return (-1);
		i++;
	}
	return (0);
}
