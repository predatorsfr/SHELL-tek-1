/*
** EPITECH PROJECT, 2017
** my_putstrhex.c
** File description:
** disp str. non printable char are written in oct
*/

#include "printf.h"
#include "my.h"

int my_putstroct(const unsigned char *str)
{
	int i = 0;

	while (str[i] != '\0') {
		if (str[i] < 32 || str[i] >= 127) {
			my_putchar('\\');
			if (str[i] < 8)
				my_putstr("00");
			else if (str[i] >= 8 && str[i] <= 63)
				my_putstr("0");
			my_put_octal((unsigned char)str[i]);
			i++;
		} else {
			my_putchar(str[i]);
			i++;
		}
	}
	return (0);
}
