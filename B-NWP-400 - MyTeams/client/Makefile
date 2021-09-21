##
## EPITECH PROJECT, 2024
## B_NWP_400_LIL_4_1_myteams_achille_bourgault
## File description:
## Created by Frédéric LAWECKI--WALKOWIAK
##

SRC	=	src/read_command.c \
        src/command_splitter.c \
        src/str_to_word_array.c \
        src/get_request.c \
        src/connect_to_server.c \
        src/send_request.c \
        src/handle_command.c \
        src/commands/cmd_exit.c \
        src/commands/cmd_create.c \
        src/commands/cmd_user.c \
        src/commands/cmd_subscribe.c \
        src/commands/cmd_info.c \
        src/commands/cmd_list.c \
        src/commands/cmd_unknown.c \
        src/commands/cmd_login.c \
        src/commands/cmd_subscribed.c \
        src/commands/cmd_unsubscribe.c \
        src/commands/cmd_help.c \
        src/commands/cmd_send.c \
        src/commands/cmd_users.c \
        src/commands/cmd_use.c \
        src/commands/cmd_messages.c \
        src/commands/cmd_logout.c \
        src/client_loop.c \
        src/main.c \
        src/events/event_private_msg.c \
        src/events/event_login.c \
        src/events/event_logout.c \
        src/events/event_unknown.c

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-I./include -I../libs/myteams -L../libs/myteams -lmyteams -Wl,-R$(LD_LIBRARY_PATH)

NAME	=	../myteams_cli

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) $(CFLAGS)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all