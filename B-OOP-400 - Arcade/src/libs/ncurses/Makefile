##
## EPITECH PROJECT, 2021
## B_OOP_400_LIL_4_1_arcade_achille_bourgault
## File description:
## Makefile
##

SRC	=	ncurses.cpp

OBJ	=	$(SRC:.cpp=.o)

CXXFLAGS =	-Wall -Wextra -std=c++17 -fpic -lncurses

NAME =	arcade_ncurses.so

all:	$(NAME)

$(NAME):	$(OBJ)
	g++ -o $(NAME) $(OBJ) $(CXXFLAGS) -shared
	cp arcade_ncurses.so ../../../lib/arcade_ncurses.so

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -f ../../../lib/arcade_ncurses.so

re: fclean all