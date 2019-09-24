/*
** EPITECH PROJECT, 2017
** my_put_nbr.c
** File description:
** display nb
*/

#include "printf.h"
#include "my.h"

int my_put_nbr(int nb)
{
	if (nb == -2147483648 || nb > 2147483647) {
		my_putstr("-2147483648");
		return (0);
	}
	if (nb < 0) {
		nb = nb * (-1);
		my_putchar('-');
	}
	if (nb > 9) {
		my_put_nbr(nb / 10);
	}
	my_putchar((nb % 10) + 48);
	return (0);
}
