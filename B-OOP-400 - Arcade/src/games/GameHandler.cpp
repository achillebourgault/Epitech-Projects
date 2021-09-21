/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** Created by Achille Bourgault
*/

#include <functional>
#include <dlfcn.h>
#include <cstring>
#include "GameHandler.hpp"

GameHandler::GameHandler(std::string libpath, DisplayHandler *currentlib, Player *player, void *core)
{
    _display_handler = currentlib;
    _player = player;
    void* libGame = dlopen(libpath.c_str(), RTLD_LAZY);
    if (!libGame) {
        std::cerr << "Cannot open game library: " << dlerror() << std::endl;
        std::exit(84);
    }
    dlerror();
    create_game_t *create_handler = (create_game_t*) dlsym(libGame, "create_object");
    const char* dlsym_error = dlerror();
    if (dlsym_error) {
        std::cerr << "Cannot load symbol create_object: " << dlsym_error << '\n';
        std::exit(84);
    }
    destroy_t *destroy_lib = (destroy_t*) dlsym(libGame, "destroy_object");
    dlsym_error = dlerror();
    if (dlsym_error) {
        std::cerr << "Cannot load symbol destroy_object: " << dlsym_error << '\n';
        std::exit(84);
    }
    _gameModule = create_handler(_display_handler, player);
    _core = core;
    if (strstr(libpath.c_str(), "lib/arcade_nibbler")) {
        _id = GAME1ID;
    } else if (strstr(libpath.c_str(), "lib/arcade_centipede")) {
        _id = GAME2ID;
    } else {
        _id = GAME1ID;
    }
}

GameHandler::~GameHandler()
{
}

AGameModule *GameHandler::getCurrentGame() const
{
    return _gameModule;
}

int GameHandler::getId() const
{
    return _id;
}

void *GameHandler::getCore() const
{
    return _core;
}

GameHandler::GameHandler()
{
}

void GameHandler::setGameModule(AGameModule *gameModule) {
    _gameModule = gameModule;
}
