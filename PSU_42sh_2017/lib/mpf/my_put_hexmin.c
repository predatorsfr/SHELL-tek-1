/*
** EPITECH PROJECT, 2017
** my_put_hex.c
** File description:
** disp hex of deci
*/

#include "printf.h"
#include "my.h"

void my_put_hexmin(long long nb)
{
	char base[16] = "0123456789abcdef";

	if (nb != 0) {
		my_put_hexmin(nb / 16);
		my_putchar(base[nb % 16]);
	}
}
