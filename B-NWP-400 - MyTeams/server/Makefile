##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Generic Makefile
##

SRC	=	src/uuid.c \
        src/types/message.c \
        src/types/private_discussion.c \
        src/types/subscriber.c \
        src/types/register.c \
        src/types/channel.c \
        src/types/user.c \
        src/types/team.c \
        src/types/threads.c \
        src/commands/list.c \
        src/commands/use.c \
        src/commands/connexion.c \
        src/commands/commands.c \
        src/commands/send.c \
        src/commands/info.c \
        src/commands/help.c \
        src/commands/users.c \
        src/commands/subscribe.c \
        src/commands/create.c \
        src/commands/messages.c \
        src/server.c \
        src/server_init.c \
        src/main.c \
        src/utils/str_to_word_array.c \
        src/utils/data.c \
        src/utils/files.c \
        src/utils/utils.c \
        src/utils/time.c


OBJ	=	$(SRC:.c=.o)

CFLAGS =	-I./include/ -I../libs/myteams -luuid -L../libs/myteams -lmyteams -Wl,-R$(LD_LIBRARY_PATH)

NAME =	../myteams_server

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) $(CFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
