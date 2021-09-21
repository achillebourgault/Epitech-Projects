##
## EPITECH PROJECT, 2021
## B_OOP_400_LIL_4_1_arcade_achille_bourgault
## File description:
## Makefile
##

SRC	=	sdl2.cpp

OBJ	=	$(SRC:.cpp=.o)

CXXFLAGS =	-g -Wall -Wextra -std=c++17 -fpic -lSDL2 -lSDL2_ttf

NAME =	arcade_sdl2.so

all:	$(NAME)

$(NAME):	$(OBJ)
	g++ -o $(NAME) $(OBJ) $(CXXFLAGS) -shared
	cp arcade_sdl2.so ../../../lib/arcade_sdl2.so

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -f ../../../lib/arcade_sdl2.so

re: fclean all