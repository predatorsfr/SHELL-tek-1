/*
** EPITECH PROJECT, 2017
** my.h
** File description:
** lib header
*/

#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

#ifndef HEADER_H_
#define HEADER_H_

#define EXIT_SUCCESS 0
#define EXIT_ERROR 84

typedef struct path_t {
  char *line;
  char *bin;
  char *arg;
  char *path;
  char **allpath;
  char **allarg;
  char **env;
  char *elder;
  char *now;
  char *home;
  int rt;
} path_t;

typedef struct rt_t {
  int rt;
} rt_t;

void choice(path_t *path);
int exec(path_t *path);
void catprompt(char *str);
void pathcat(path_t *path);
void clean(char *str, path_t *path);
void	my_putchar(char c);
char	*my_revstr(char *str);
int	my_getnbr(char const *str);
int	my_strlen(char const *str);
int	my_putstr(char const *str);
char	*my_strdup(char const *src);
char	*my_strcat(char *dest, char *src);
char	*my_strcpy(char *dest, char const *src);
int	my_strcmp(char const *s1, char const *s2);

#endif
