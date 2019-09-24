/*
** EPITECH PROJECT, 2018
** minishell1
** File description:
** raphael.dubois@epitech.eu
*/

#include "../include/my.h"
#include "../include/gnl.h"

int exec(path_t *path)
{
  pid_t pid;
  char *new_argv[] = { "ls", NULL };

  pid = fork();
  if (pid == 0) {
    if ((execve("/bin/ls",new_argv,NULL)) == -1);
    return (-1);
  } else
    wait(0);
    return (0);
}
