##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## makefile exe
##

CC	=	gcc

CFLAGS	+=	-I./include -W -Wall -Wextra

CLFLAGS +=	-L./lib/my -L./lib/mpf -lmpf -lmy

SRC	=	src/main.c			\
		src/bin/setup_bin.c		\
		src/env/setup_env.c		\
		src/bin/check_bin.c		\
		src/exe/exe.c			\
		src/exe/check_file.c		\
		src/exe/cd.c			\
		src/env/unset.c			\
		src/env/setenv.c		\
		src/env/enverr.c		\
		src/semicolons.c		\
		src/parsing/str_to_tab.c	\
		src/parsing/parsing_semicolon.c	\
		src/free_exit.c			\

OBJ	=	$(SRC:.c=.o)

NAME	=	42sh

all:		$(NAME)

$(NAME):	$(OBJ)
		make -C ./lib/my re
		make -C ./lib/mpf re
		$(CC) $(OBJ) -o $(NAME) $(CLFLAGS) $(CFLAGS)

clean:
		make -C ./lib/my clean
		make -C ./lib/mpf clean
		rm -f $(OBJ)

fclean:		clean
		make -C ./lib/my fclean
		make -C ./lib/mpf fclean
		rm -f $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
