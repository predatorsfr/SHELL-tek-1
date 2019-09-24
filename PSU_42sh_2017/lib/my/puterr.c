/*
** EPITECH PROJECT, 2018
** puterr.c
** File description:
** put error
*/

#include "my.h"
#include <unistd.h>

int puterr(char const *str)
{
	write(2, str, my_strlen(str));
	return (0);
}
