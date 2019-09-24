/*
** EPITECH PROJECT, 2017
** my_put_octal.c
** File description:
** take unsigned int to octal
*/

#include "my.h"
#include "printf.h"

void my_put_bin(unsigned int nb)
{
	if (nb != 0) {
		my_put_bin(nb / 2);
		my_putchar((nb % 2) + '0');
	}
}
