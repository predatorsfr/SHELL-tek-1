/*
** EPITECH PROJECT, 2018
** check_file.c
** File description:
** check if file is valid
*/

#include <unistd.h>
#include "printf.h"
#include "shell.h"
#include "my.h"

int check_file(char *path, env_t *env)
{
	if (access(path, F_OK) == 0) {
		return (0);
	} else if (check_bin(path, env) != -1) {
		return (2);
	} else {
		my_printf("%s: Command not found.\n", path);
		return (-1);
	}
}
