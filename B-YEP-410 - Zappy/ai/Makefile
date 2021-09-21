##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## Created by Frédéric LAWECKI--WALKOWIAK
##

SRC	=	./src/commands/cmd_pnw.c		\
		./src/ai.c						\
		./src/client_loop.c				\
		./src/connect.c					\
		./src/main.c					\
		./src/parser.c					\
		./src/read_request.c			\
		./src/str_to_word_array.c		\
		./src/utils.c					\

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-I./include

NAME	=	../zappy_ai

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) $(CFLAGS)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all