##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## Created by Frédéric LAWECKI--WALKOWIAK
##

SRC	=	./src/world/tiles_utils.c \
        ./src/world/get_items.c \
        ./src/world/world.c \
        ./src/world/generator.c \
        ./src/world/tiles.c \
        ./src/init_network.c \
        ./src/types/elevation.c \
        ./src/types/player.c \
        ./src/types/vision/directions.c \
        ./src/types/vision/vision.c \
        ./src/types/inventory/inventory.c \
        ./src/types/movements/movements.c \
        ./src/types/sounds/sounds.c \
        ./src/types/team.c \
        ./src/parser.c \
        ./src/commands/inventory.c \
        ./src/commands/mct.c \
        ./src/commands/sbp.c \
        ./src/commands/seg.c \
        ./src/commands/bct.c \
        ./src/commands/edi.c \
        ./src/commands/pic.c \
        ./src/commands/forward.c \
        ./src/commands/right.c \
        ./src/commands/eject.c \
        ./src/commands/pgt.c \
        ./src/commands/take_object.c \
        ./src/commands/left.c \
        ./src/commands/pdi.c \
        ./src/commands/smg.c \
        ./src/commands/ppo.c \
        ./src/commands/tna.c \
        ./src/commands/pbc.c \
        ./src/commands/sgt.c \
        ./src/commands/set_object.c \
        ./src/commands/pfk.c \
        ./src/commands/plv.c \
        ./src/commands/eht.c \
        ./src/commands/vzr_lgn.c \
        ./src/commands/fork.c \
        ./src/commands/ebo.c \
        ./src/commands/incantation.c \
        ./src/commands/pdr.c \
        ./src/commands/connect_nbr.c \
        ./src/commands/unknown.c \
        ./src/commands/vzr_plrs.c \
        ./src/commands/pie.c \
        ./src/commands/pin.c \
        ./src/commands/pex.c \
        ./src/commands/enw.c \
        ./src/commands/broadcast_text.c \
        ./src/commands/msz.c \
        ./src/commands/pnw.c \
        ./src/commands/sst.c \
        ./src/commands/suc.c \
        ./src/commands/look.c \
        ./src/server.c \
        ./src/main.c \
        ./src/server_loop.c \
        ./src/get_parameter.c \
        ./src/utils/str_to_word_array.c \
        ./src/utils/utils2.c \
        ./src/utils/utils.c \
        ./src/utils/tile_utils.c \
        ./src/utils/player_utils.c \
        ./src/utils/error_manager.c \


OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-I./include -I./include/types

NAME	=	../zappy_server

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) $(CFLAGS)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all