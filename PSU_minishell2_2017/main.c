/*
** EPITECH PROJECT, 2018
** minishell1
** File description:
** raphael.dubois@epitech.eu
*/

#include "include/gnl.h"
#include "include/my.h"

void my_getenv(char **env, path_t *path)
{
	path->path = malloc(sizeof(char) * 150);
	int i = 0;
	int j = 5;
	int k = 0;

	while(env[i][j] != '\0') {
		if (env[i][0] == 'P' && env[i][4] == '=') {
			while (env[i][j] != '\0') {
			path->path[k] = env[i][j];
			j++;
			k++;
			}
			break;
		}
	i++;
	}
	path->path[j] = '\0';
}

int main (int ac, char **av, char **env)
{
	path_t *path = malloc(sizeof(path));
	char buf[1024];

	while(1) {
		getcwd(buf, sizeof(buf));
		catprompt(buf);
		path->line = get_next_line(0);
		clean(path->line, path); //chope l'input
		my_getenv(env, path); //prend la ligne du path
		pathcat(path); //cat le bin a chaque path
		if (path->bin[1] == 'l')
		exec(path);
	}
	//free(path);
	return (0);
}
