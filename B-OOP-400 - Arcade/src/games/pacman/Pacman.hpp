/*

** EPITECH PROJECT, 2024
** B_OOP_400_LIL_4_1_arcade_achille_bourgault
** File description:
** Created by Achille Bourgault
*/

#ifndef B_OOP_400_LIL_4_1_ARCADE_ACHILLE_BOURGAULT_Pacman_HPP
#define B_OOP_400_LIL_4_1_ARCADE_ACHILLE_BOURGAULT_Pacman_HPP

#include <string>
#include <iostream>
#include <cstring>
#include "../../player/Player.hpp"
#include "../../interface/GameModule.hpp"
#include "../../interface/AGameModule.hpp"

#define MAP_SIZE 29

#define DIRECTION_UP 0
#define DIRECTION_DOWN 1
#define DIRECTION_LEFT 2
#define DIRECTION_RIGHT 3

#define STATE_MENU 0
#define STATE_GAME 1
#define STATE_END_LOOSE 2
#define STATE_END_WIN 3
#define STATE_QUIT_GAME 4

class Pacman : public AGameModule {
    public:
    Pacman();
    void initGame() override;
    void drawGame() override;
    int gameLoop(char input, float time, int graphId) override;
    int getScore() override;
    int getId() const;
    ~Pacman();

    protected:
    bool _inGame;
    int _direction;
    int _state;
    int _currentScore;
    int _id;
    bool _isEnd;

protected:
    char _map[MAP_SIZE][MAP_SIZE];
    std::vector<std::tuple<int, int>> *_playerParts;

    private:
    void registerInputsInGame(char input);
    void *move(std::string dir);
    void registerInputsInMenu(char input);
    void setState(int state);
    void drawMenu();
    void generateMap();
    void drawMap();
    void drawPlayer();
    int handleLoose(int x, int y);
    void drawEnd();
    void drawOverlay();
    void registerInputsInEnd(char input);
    void reloadGame();
    void registerInputs(char input);
};

#endif //B_OOP_400_LIL_4_1_ARCADE_ACHILLE_BOURGAULT_Pacman_HPP
