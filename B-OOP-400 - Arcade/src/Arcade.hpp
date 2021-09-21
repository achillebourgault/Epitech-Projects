/*
** EPITECH PROJECT, 2024
** B_OOP_400_LIL_4_1_arcade_achille_bourgault
** File description:
** Created by Achille Bourgault
*/

#ifndef B_OOP_400_LIL_4_1_ARCADE_ACHILLE_BOURGAULT_ARCADE_HPP
#define B_OOP_400_LIL_4_1_ARCADE_ACHILLE_BOURGAULT_ARCADE_HPP

#include <iostream>
#include <vector>
#include <cstring>
#include <functional>
#include "games/GameHandler.hpp"
#include "interface/constants.hpp"
#include "player/Player.hpp"
#include "interface/DisplayHandler.hpp"
#include "menu/MainMenu.hpp"

typedef void (*clearScreen_t)();
typedef void (*refreshScreen_t)();
typedef void (*endScreen_t)();
typedef std::tuple<int, int>(*getWindowSize_t)();
typedef void (*initScreen_t)();
typedef void (*drawSquare_t)(std::tuple<int, int> position,
    std::tuple<int, int> rectSize, int color);
typedef void (*drawText_t)(std::tuple<int, int> position,
    float scale, std::string const &text);
typedef char (*getInput_t)();

class Arcade {
    public:
    Arcade(std::string libpath);
    ~Arcade();
    void setup(std::string lib);

    //ARCADE KEYS
    void previousGraphics();
    void nextGraphics();
    void previousGame();
    void nextGame();
    void restartGame();
    void backToMenu();
    void exit();

    //LIBS FUNC
    char getInput();

    void loadLibrairiesFunc(std::string lib);

    //PLAYER
    void connectPlayer(std::string player);
    Player * getPlayer();

    protected:
    GameHandler _currentGameHandler;
    DisplayHandler _currentDisplayHandler;
    std::vector<void*> _libs;
    Player *_player;

    bool openLib(std::string lib);
    void initGameLambdas();
    void gameloop();

    void changeGame(std::string path);

    void changeGraphics(std::string path);

    int menuloop();

    void registerChangeLib(char input);
};

#endif //B_OOP_400_LIL_4_1_ARCADE_ACHILLE_BOURGAULT_ARCADE_HPP
