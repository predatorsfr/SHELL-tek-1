/*
** EPITECH PROJECT, 2017
** my.h
** File description:
** lib header
*/

#include <unistd.h>
#include <stdlib.h>

#ifndef HEADER_H_
#define HEADER_H_
#define EXIT_SUCCESS 0
#define EXIT_ERROR 84

char *gnl(int fd);
void my_putchar(char c);
char *my_revstr(char *str);
int puterr(char const *str);
int alphanum(char const *str);
int my_getnbr(char const *str);
int my_strlen(char const *str);
int my_putstr(char const *str);
char *my_strdup(char const *src);
int find_str(char *name, char **env);
char *my_strcat(char *dest, char const *src);
char *my_strcpy(char *dest, char const *src);
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, int n);

#endif
