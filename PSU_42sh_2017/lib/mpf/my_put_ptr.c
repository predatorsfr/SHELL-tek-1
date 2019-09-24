/*
** EPITECH PROJECT, 2017
** my_put_hex.c
** File description:
** disp hex of deci
*/

#include "printf.h"
#include "my.h"

void my_put_ptr(long long nb)
{
	if (nb == 0) {
		write(1, "(nil)", 5);
		return;
	}
	my_putstr("0x");
	my_put_hexmin(nb);
}
