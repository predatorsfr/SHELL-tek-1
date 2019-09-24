/*
** EPITECH PROJECT, 2017
** my_printf.c
** File description:
** my_printf
*/

#include <stdarg.h>
#include "printf.h"
#include "my.h"

int check_var3(char c, va_list ap)
{
	switch (c) {
	case 'p':
		my_put_ptr(va_arg(ap, long));
		break;
	case '%':
		my_putchar('%');
		break;
	default:
		my_putchar('%');
		my_putchar(c);
	}
	return (EXIT_SUCCESS);
}

int check_var2(char c, va_list ap)
{
	switch (c) {
	case 's':
		my_putstr(va_arg(ap, char *));
		break;
	case 'S':
		my_putstroct(va_arg(ap, unsigned char *));
		break;
	case 'u':
		my_put_unbr(va_arg(ap, unsigned int));
		break;
	case 'x':
		my_put_hexmin(va_arg(ap, unsigned int));
		break;
	case 'X':
		my_put_hex(va_arg(ap, unsigned int));
		break;
	default:
		check_var3(c, ap);
	}
	return (EXIT_SUCCESS);

}

int check_var(char c, va_list ap)
{
	switch (c) {
	case 'b':
		my_put_bin(va_arg(ap, unsigned int));
		break;
	case 'c':
		my_putchar(va_arg(ap, int));
		break;
	case 'd':
	case 'i':
		my_put_nbr(va_arg(ap, int));
		break;
	case 'o':
		my_put_octal(va_arg(ap, unsigned int));
		break;
	default:
		check_var2(c, ap);
	}
	return (EXIT_SUCCESS);
}

int my_printf(char const *format, ...)
{
	va_list ap;
	int i = 0;

	va_start(ap, format);
	if (format == NULL)
		return (EXIT_ERROR);
	while (format[i] != '\0') {
		if (format[i] == '%') {
			if (format[i + 1] == '#') {
				my_format(format[i + 2], ap);
				i++;
			} else {
				check_var(format[i + 1], ap);
			}
			i++;
		} else
			my_putchar(format[i]);
		i++;
	}
	va_end(ap);
	return (EXIT_SUCCESS);
}
