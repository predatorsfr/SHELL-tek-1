/*
** EPITECH PROJECT, 2018
** minishell1
** File description:
** raphael.dubois@epitech.eu
*/

#include "../include/my.h"

int exec(path_t *path)
{
	pid_t pid;
	int i = 0;
  int j = 0;

	pid = fork();
	if (pid == 0) {
		while((execve(path->allpath[i],path->allarg,path->env)) == -1) {
			i++;
      j++;
    }
	} else
		wait(0);
	return (0);
}
