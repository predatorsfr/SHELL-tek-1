##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile bootstrap my_printf
##

SRC	=	my_putchar.c	\
		my_put_nbr.c	\
		my_strlen.c	\
		my_putstr.c	\
		my_printf.c	\
		my_put_bin.c	\
		my_put_hex.c	\
		my_put_hexmin.c	\
		my_put_octal.c	\
		my_revstr.c	\
		my_put_unbr.c	\
		my_putstroct.c	\
		my_put_ptr.c	\
		my_format.c

OBJ	=	$(SRC:.c=.o)

NAME	=	libmpf.a

CFLAGS	+=	-I ../../include/ -W -Wall -Wextra -Werror

all: 		$(NAME)

$(NAME):	$(OBJ)
		ar rc $(NAME) $(OBJ)
		ranlib $(NAME)

clean:
		rm -f $(OBJ)

fclean: 	clean
		rm -f $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
