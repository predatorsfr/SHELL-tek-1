/*
** EPITECH PROJECT, 2018
** minishell1
** File description:
** raphael.dubois@epitech.eu
*/

#include "include/gnl.h"
#include "include/my.h"

void catprompt(char *str)
{
	my_strcat(str,">");
	my_putstr(str);
}

void finishpath(path_t *path)
{
	for (int i = 0; path->allpath[i] != 0; i++)
		my_strcat(path->allpath[i],path->bin);
}

void pathcat(path_t *path)
{
	path->allpath = malloc(sizeof(char *) * my_strlen(path->path) + 1);
	int i = 0;
	int j = 0;
	int k = 0;

	path->allpath[0] = malloc(sizeof(char *) * my_strlen(path->path) + 1);
	while(path->path[k] != '\0') {
		if(path->path[k] == ':') {
			i++;
			k++;
			j = 0;
			path->allpath[i] = malloc(sizeof(char *) * my_strlen(path->path) + 1);
		}
		path->allpath[i][j] = path->path[k];
		j++;
		k++;
	}
	finishpath(path);
}
