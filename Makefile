##
## EPITECH PROJECT, 2019
## makefile
## File description:
## make to file
##

SRC     =	my_runner.c			\

OBJ	=	$(SRC:.c=.o)

NAME 	= 	my_runner

all:	$(NAME)

$(NAME):	$(OBJ)
	make -C lib/my
	gcc -g3 -Wall -W -Wextra -o $(NAME) $(OBJ) -lcsfml-graphics -lcsfml-window -lcsfml-audio -lcsfml-system -L./lib/my -lmy

clean:
	make clean -C lib/my
	rm -rf $(OBJ)

re:	fclean all

fclean: clean
	rm -rf $(NAME)

.PHONY: all clean fclean re
