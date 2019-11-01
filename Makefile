##
## EPITECH PROJECT, 2017
## runner
## File description:
## make
##

SRC	=	main.c		\
		src.c		\
		first.c		\
		second.c	\
		last.c		\
		error.c

OBJ	=	$(SRC:.c=.o)

NAME	=	my_runner

all:	$(OBJ)
	gcc $(SRC) -o $(NAME)  -lcsfml-system -lcsfml-audio -lcsfml-graphics -lcsfml-window #-lc_graph_prog

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
