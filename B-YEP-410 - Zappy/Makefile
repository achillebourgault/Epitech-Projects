##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Generic Makefile
##

SERVER	=		server/
VISUALIZER = 	visualizer/
AI =			ai/

all:
	make -C $(SERVER) -s
	make -C $(VISUALIZER) -s
	make -C $(AI) -s

zappy_server:
	make -C $(SERVER) -s

zappy_ai:
	make -C $(AI) -s

zappy_gui:
	make -C $(VISUALIZER) -s

clean:
	make clean -C $(SERVER) -s
	make clean -C $(VISUALIZER) -s
	make clean -C $(AI) -s

fclean:
	make fclean -C $(SERVER) -s
	make fclean -C $(VISUALIZER) -s
	make fclean -C $(AI) -s

re:
	make re -C $(SERVER) -s
	make re -C $(VISUALIZER) -s
	make re -C $(AI) -s

.PHONY: all clean fclean re