/*
** EPITECH PROJECT, 2017
** my_revstr.c
** File description:
** rev str
*/

#include "printf.h"
#include "my.h"

char *my_revstr(char *str)
{
	int i = 0;
	int ii = 0;

	while (str[i] != '\0')
		i++;
	char my_str[i];

	for (int i = 0; str[i] != '\0'; i++)
		my_str[i] = str[i];
	i -= 1;
	while (my_str[ii] != '\0') {
		str[ii] = my_str[i];
		ii++;
		i--;
	}
	return (str);
}
