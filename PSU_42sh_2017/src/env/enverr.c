/*
** EPITECH PROJECT, 2018
** enverr.c
** File description:
** err
*/

#include "shell.h"
#include "my.h"

void	setenv_err(void)
{
	puterr("setenv: Variable name must contain ");
	puterr("alphanumeric characters.\n");
}
