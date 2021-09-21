##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## Created by Frédéric LAWECKI--WALKOWIAK
##

SRC	=	./src/requests/login.c	\
		./src/requests/read_requests.c	\
		./src/connect.c	\
		./src/draw_player.c	\
		./src/draw_resources.c	\
		./src/drawer.c	\
		./src/gameloop.c	\
		./src/gui.c	\
		./src/main.c	\
		./src/parser.c	\
		./src/player.c	\
		./src/ressource.c	\
		./src/str_to_word_array.c	\
		./src/tiles.c	\
		./src/update_data.c	\
		./src/utils.c	\

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-I./include -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio

NAME	=	../zappy_gui

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) $(CFLAGS)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all