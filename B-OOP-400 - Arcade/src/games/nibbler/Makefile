##
## EPITECH PROJECT, 2021
## B_OOP_400_LIL_4_1_arcade_achille_bourgault
## File description:
## Makefile
##

SRC	=	Nibbler.cpp

OBJ	=	$(SRC:.cpp=.o)

CXXFLAGS =	-Wall -Wextra -std=c++17 -fpic

NAME =	arcade_nibbler.so

all:	$(NAME)

$(NAME):	$(OBJ)
	g++ -o $(NAME) $(OBJ) $(CXXFLAGS) -shared
	cp arcade_nibbler.so ../../../lib/arcade_nibbler.so

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -f ../../../lib/arcade_nibbler.so

re: fclean all