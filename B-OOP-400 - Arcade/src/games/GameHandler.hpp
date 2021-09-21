/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** Created by Achille Bourgault
*/

#ifndef ARCADE_GAMEHANDLER_HPP
#define ARCADE_GAMEHANDLER_HPP

#include <iostream>
#include "../interface/GameModule.hpp"
#include "../player/Player.hpp"
#include "../interface/AGameModule.hpp"

class GameHandler {
    public:
    GameHandler();
    GameHandler(std::string lib, DisplayHandler *currentlib, Player *player, void *core);
    ~GameHandler();
    AGameModule *getCurrentGame() const;
    int getId() const;
    void *getCore() const;

    private:
    DisplayHandler *_display_handler;
    Player *_player;
    AGameModule *_gameModule;
public:
    void setGameModule(AGameModule *gameModule);

private:
    void *_core;
    int _id;

};

typedef  AGameModule *create_game_t(DisplayHandler *currentlib, Player *player);
typedef  AGameModule *destroy_game_t(AGameModule*);

#endif //ARCADE_GAMEHANDLER_HPP
