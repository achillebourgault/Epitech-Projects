##
## EPITECH PROJECT, 2021
## B_OOP_400_LIL_4_1_arcade_achille_bourgault
## File description:
## Makefile
##

SRC	=	main.cpp    \
        Arcade.cpp  \
        games/GameHandler.cpp	\
        player/Player.cpp   \
        menu/MainMenu.cpp   \
        menu/MenuLogin.cpp   \
        interface/DisplayHandler.cpp    \
		interface/AGameModule.cpp

OBJ	=	$(SRC:.cpp=.o)

LDFLAGS	= -Wall -Wextra -std=c++17 -ldl -rdynamic -I./ -I./interface -I./games

NAME =	arcade

all:	$(NAME)

$(NAME):	$(OBJ)
	g++ -g -o $(NAME) $(OBJ) $(LDFLAGS)
	cp arcade ../arcade

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -f ../$(NAME)

re: fclean all