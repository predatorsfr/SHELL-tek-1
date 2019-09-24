/*
** EPITECH PROJECT, 2017
** my_putstr.c
** File description:
** print string
*/

#include "my.h"
#include "printf.h"

int my_putstr(char const *str)
{
	if (str == NULL) {
		write(1, "(null)", 6);
		return (0);
	}
	if (*str == '\0')
		return (0);
	while (*str != '\0')
		my_putchar(*str++);
	return (0);
}
