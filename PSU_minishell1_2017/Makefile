##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## makefile exe
##

CC	=	gcc -g

CFLAGS	+=	-L./src -lgnl -I./include

SRC	=	main.c \
		src/builtins.c\
		src/bin.c \
		src/my_exec.c \
		src/clean.c \
		src/my_putstr.c \
		src/my_strcmp.c \
		src/my_strcpy.c \
		src/my_strdup.c \
		src/my_strlen.c \
		src/my_strcat.c \
		src/my_getnbr.c \
		src/my_putchar.c \
		src/my_revstr.c \

OBJ	=	$(SRC:.c=.o)

NAME	=	mysh

all:		$(NAME)

$(NAME):	$(OBJ)
		$(CC) $(OBJ) -o $(NAME) $(CFLAGS)

clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME)
		rm -f *~
		rm -f src/*~
		rm -f include/*~

re:		fclean all

.PHONY :	all clean fclean re
