##
## EPITECH PROJECT, 2021
## B_OOP_400_LIL_4_1_arcade_achille_bourgault
## File description:
## Makefile
##

SRC	=	sfml.cpp

OBJ	=	$(SRC:.cpp=.o)

CXXFLAGS =	-Wall -Wextra -std=c++17 -lsfml-system -lsfml-graphics -lsfml-audio -lsfml-window -fpic

NAME =	arcade_sfml.so

all:	$(NAME)

$(NAME):	$(OBJ)
	g++ -o $(NAME) $(OBJ) $(CXXFLAGS) -shared
	cp arcade_sfml.so ../../../lib/arcade_sfml.so

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -f ../../../lib/arcade_sfml.so

re: fclean all