/*
** EPITECH PROJECT, 2017
** my_strncmp.c
** File description:
** same as strcmp but u choose how many char to compare
*/

#include "my.h"

int my_strncmp(char const *s1, char const *s2, int n)
{
	int i = 0;

	n = n - 1;
	while ((s1[i] != '\0' || s2[i] != '\0')) {
		if (s1[i] != s2[i] && i == n) {
			return (s1[i] - s2[i]);
		}
		i++;
	}
	return (0);
}
