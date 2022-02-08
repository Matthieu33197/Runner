##
## EPITECH PROJECT, 2019
## make
## File description:
## files
##

SRC	=	my.c				\
		move_draw_destroy.c		\
		move.c				\
		lose_win.c			\
		texture_sprite.c		\
		position.c			\
		text.c				\
		my_putstr_error.c		\
		desc_map.c

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)
clean:
		rm -rf *.o

fclean:		clean

