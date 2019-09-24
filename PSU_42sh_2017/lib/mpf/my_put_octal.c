/*
** EPITECH PROJECT, 2017
** my_put_octal.c
** File description:
** take unsigned int to octal
*/

#include "printf.h"
#include "my.h"

int my_put_octal(unsigned int nb)
{
	if (nb != 0) {
		my_put_octal(nb / 8);
		my_putchar((nb % 8) + '0');
	}
	return (0);
}
