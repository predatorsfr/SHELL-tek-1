/*
** EPITECH PROJECT, 2017
** clean.c
** File description:
** clean a string
*/

#include "../include/my.h"

void clear(char *str, path_t *path)
{
	path->bin = malloc(sizeof(char) * my_strlen(str));
	path->arg = malloc(sizeof(char) * my_strlen(str));
	int j = 1;
	int l = 0;
	int k = 0;

	path->bin[0] = '/';
	for (int i = 0 ;str[i] != '\0' ; i++) {
		if (str[0] == ' ')
			i = 1;
		if (str[i] == ' ' && k == 0) {
			k = 1;
			i++;
		}
		if (k == 0)
			path->bin[j++] = str[i];
		if (k == 1)
			path->arg[l++] = str[i];
	}
}

void clean(char *str, path_t *path)
{
	char *blank = malloc(sizeof(str));
	int c = 0;
	int d = 0;
	int temp;

	while (str[c] != '\0') {
		if (str[c] == ' ') {
			temp = c + 1;
			if (str[temp] != '\0') {
				while (str[temp] == ' ' && str[temp] != '\0') {
					if (str[temp] == ' ')
						c++;
					temp++;
				}
			}
		}
		blank[d++] = str[c++];
	}
	blank[d] = '\0';
	clear(blank, path);
}
