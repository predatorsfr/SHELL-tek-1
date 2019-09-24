/*
** EPITECH PROJECT, 2017
** my_format.c
** File description:
** deals with basic format
*/

#include "printf.h"
#include "my.h"

int my_format(char c, va_list ap)
{
	if (c == 'o') {
		my_putchar('0');
		my_put_octal(va_arg(ap, unsigned int));
	} else if (c == 'x') {
		my_putstr("0x");
		my_put_hexmin(va_arg(ap, unsigned int));
	} else if (c == 'X') {
		my_putstr("0X");
		my_put_hex(va_arg(ap, unsigned int));
	}
	return (0);
}
