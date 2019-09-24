/*
** EPITECH PROJECT, 2017
** my_put_hex.c
** File description:
** disp hex of deci
*/

#include "printf.h"
#include "my.h"

int my_put_hex(unsigned int nb)
{
	char base[16] = "0123456789ABCDEF";

	if (nb != 0) {
		my_put_hex(nb / 16);
		my_putchar(base[nb % 16]);
	}
	return (0);
}
