##
## EPITECH PROJECT, 2021
## B_OOP_400_LIL_4_1_arcade_achille_bourgault
## File description:
## Makefile
##

SRC	=	Pacman.cpp

OBJ	=	$(SRC:.cpp=.o)

CXXFLAGS =	-Wall -Wextra -std=c++17 -fpic

NAME =	arcade_pacman.so

all:	$(NAME)

$(NAME):	$(OBJ)
	g++ -o $(NAME) $(OBJ) $(CXXFLAGS) -shared
	cp arcade_pacman.so ../../../lib/arcade_pacman.so

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -f ../../../lib/arcade_pacman.so

re: fclean all