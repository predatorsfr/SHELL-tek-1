/*
** EPITECH PROJECT, 2018
** free_exit.c
** File description:
** free maximum of allocated memory
*/

#include <stdlib.h>
#include <stdio.h>
#include "shell.h"

void	free_exit(env_t *env)
{
	for (int i = 0; env->env[i] != NULL; i++)
		free(env->env[i]);
	for (int i = 0; env->paths[i] != NULL; i++)
		free(env->paths[i]);
	free(env->env);
	free(env->paths);
	exit(env->ret);
}
