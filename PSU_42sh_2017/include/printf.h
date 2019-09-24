/*
** EPITECH PROJECT, 2017
** printf.h
** File description:
** printf
*/

#ifndef PRINTF_H_
#define PRINTF_H_

#include <stdarg.h>

void my_put_bin(unsigned int nb);
int my_put_nbr(int nb);
int my_put_octal(unsigned int nb);
int my_put_unbr(unsigned int nb);
void my_put_hexmin(long long nb);
int my_put_hex(unsigned int nb);
int my_putstroct(const unsigned char *str);
int check_var(char c, va_list ap);
int my_printf(char const *format, ...);
void my_put_ptr(long long nb);
int my_format(char c, va_list ap);

#endif
