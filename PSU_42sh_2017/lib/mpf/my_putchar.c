/*
** EPITECH PROJECT, 2017
** my_putchar.c
** File description:
** display a char
*/

#include "my.h"

void my_putchar(char c)
{
	write(1, &c, 1);
}
