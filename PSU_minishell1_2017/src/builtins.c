/*
** EPITECH PROJECT, 2018
** minishell1
** File description:
** raphael.dubois@epitech.eu
*/

#include "../include/my.h"

char* pwd(path_t *path)
{
	char *buf;
	int i = 4;
	int j = 0;
	int l = 0;

	while (path->home[i] != '\0') {
		buf[j] = path->home[i];
		if(path->home[i] == '/')
			l++;
		if (l == 3)
			break;
		j++;
		i++;
	}
	buf[j] = '\0';
	return (buf);
}

void my_cd(path_t *path)
{
	char buf[1024];
	char buf1[1024];


	if (path->line[0] == 'c' && path->line[1] == 'd' && my_strlen(path->line) == 2 || path->line[0] == 'c' && path->line[1] == 'd' && path->line[3] == '~' && my_strlen(path->line) == 4)
		chdir(pwd(path));
	if (path->line[0] == 'c' && path->line[1] == 'd' && path->line[3] == '-' && my_strlen(path->line) == 4) {
		if (path->rt == 1) {
			getcwd(buf1, sizeof(buf1));
			path->now = my_strdup(buf1);
		chdir(path->elder);
		path->rt++;
	} else if (path->rt == 2) {
		chdir(path->now);
		path->rt = 1;
	}
	}
	if (path->allarg[1] != NULL){
		getcwd(buf, sizeof(buf));
		path->elder = my_strdup(buf);
		chdir(path->allarg[1]);
	}
}

void choice(path_t *path)
{
	if (path->bin[1] == 'l' || path->bin[1] == 'p' || path->bin[1] == 'i' || path->bin[1] == 'c' && path->bin[2] == 'a')
		exec(path);
	else if (path->bin[1] == 'c' && path->bin[2] == 'd')
		my_cd(path);
    else {
    my_putstr(path->line);
		my_putstr(": Command not found.\n");
  }
}
