##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Generic Makefile
##

SRC	=	src/main.c    				\
		src/server.c    			\
		src/client.c    			\
		src/files.c    				\
		src/commands.c    			\
		src/commands/cmd_login.c   	\
		src/commands/cmd_stor.c   	\
		src/commands/cmd_workdir.c  \
		src/commands/cmd_files.c  	\
		src/commands/cmd_utils.c  	\
		src/utils.c    				\
		src/socket.c

OBJ	=	$(SRC:.c=.o)

CFLAGS =	-I./include/ -g

NAME =	myftp

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) $(CFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
