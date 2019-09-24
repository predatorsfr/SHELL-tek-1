/*
** EPITECH PROJECT, 2018
** minishell1
** File description:
** raphael.dubois@epitech.eu
*/

#include "include/gnl.h"
#include "include/my.h"

void my_str_to_word_tab(path_t *path)
{
	path->allarg = malloc(sizeof(char *) * my_strlen(path->line));
	int i = 0;
	int j = 0;
	int k = 0;

	while (path->line[j] != '\0') {
		path->allarg[i] = malloc(sizeof(char) * my_strlen(path->line) + 1);
		k = 0;
		while (path->line[j] == ' ' && path->line[j] != '\0')
		j++;
		while (path->line[j] != ' ' && path->line[j] != '\0') {
			path->allarg[i][k] = path->line[j];
			k++;
			j++;
	}
	path->allarg[i][k] = '\0';
	i++;
	}
	path->allarg[i + 1] == NULL;
}

void my_getenv(char **env, path_t *path)
{
	path->env = malloc(sizeof(char *) * 100);
	path->path = malloc(sizeof(char) * 150);
	path->home = malloc(sizeof(char) * 100);
	int i = 0;
	int j = 5;
	int k = 0;
	int l = 0;
	for (;env[i] != NULL; i++) {
		path->env[i] = malloc(sizeof(char) * 100);
		path->env[i] = my_strdup(env[i]);
	}
	path->env[i + 1] = NULL;

	i = 0;

	while(env[i][j] != '\0') {
		if (env[i][0] == 'P' && env[i][3] == '=') {
			path->home = my_strdup(env[i]);
		}
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

void catch_sigint(int sig)
{
	rt_t *rt;
	char buf[1024];
	if (sig == 2) {
		my_putchar('\n');
		getcwd(buf, sizeof(buf));
		catprompt(buf);
	}
}
int main (int ac, char **av, char **env)
{
	path_t *path = malloc(sizeof(path));
	rt_t *rt;
	char buf[1024];
	int i = 0;
	int j = 0;
	path->line = NULL;
	path->rt = 1;

my_getenv(env,path);
	while(1) {
		signal(SIGINT,catch_sigint);
		getcwd(buf, sizeof(buf));
		catprompt(buf);
		if ((path->line = get_next_line(0)) == NULL)
			return (0);
		clean(path->line, path);
		my_str_to_word_tab(path);
		pathcat(path);
		choice(path);
	}
	return (0);
}
