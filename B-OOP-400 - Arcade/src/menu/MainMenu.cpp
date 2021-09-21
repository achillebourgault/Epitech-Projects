/*
** EPITECH PROJECT, 2024
** B_OOP_400_LIL_4_1_arcade_achille_bourgault
** File description:
** Created by Achille Bourgault
*/

#include <dirent.h>
#include <string>
#include <vector>
#include <cstring>
#include <tuple>
#include "../games/nibbler/Nibbler.hpp"
#include "MainMenu.hpp"
#include <chrono>


MainMenu::MainMenu(Player *p, DisplayHandler *handler)
{
    _display = handler;
    _player = p;
    _xPos = std::get<0>(_display->getCurrentLib()->getWindowSize()) / 2;
    _yPos = std::get<1>(_display->getCurrentLib()->getWindowSize()) / 2;
}

int MainMenu::gameLoop(char input, float time, int graphId) {
    _id = graphId;
    _xPos = std::get<0>(_display->getCurrentLib()->getWindowSize()) / 2;
    _yPos = std::get<1>(_display->getCurrentLib()->getWindowSize()) / 2;

    if (_player->isConnected()) {
        int res = registerInputsMenu(input);
        if ((input == 'A') || (input == 'a'))
            return 2;
        if ((input == 'B') || (input == 'b'))
            return 3;
        if ((input == 'C') || (input == 'c'))
            return 4;
        if (input == 'O' || input == 'o') {
            return -200;
        }
        if (input == 'P' || input == 'p') {
            return -300;
        }
        if (res < 0)
            return res;
        if (time > 0.12) {
            _clearScreen();
            drawMenu();
            _refreshScreen();
            return -100;
        }

        return 1;
    }
    return -1;
}

MainMenu::~MainMenu()
{
}

void MainMenu::drawGraphicsLibs()
{
    std::vector<std::string> graphicsLibs = getGraphicsLibsAvailible();

    if (graphicsLibs.empty())
        return;
}

void MainMenu::drawScores()
{
}

void MainMenu::drawMenu()
{
    std::tuple<int, int> size = std::make_tuple(20, 20);
    std::tuple<int, int> posA = std::make_tuple(- 40, - 10);
    std::tuple<int, int> posB = std::make_tuple(-10, - 10);
    std::tuple<int, int> posC = std::make_tuple(20, - 10);

    std::tuple<int, int> posAd = std::make_tuple(- 30, - 6);
    std::tuple<int, int> posBd = std::make_tuple(-5, - 6);
    std::tuple<int, int> posCd = std::make_tuple(30, - 6);

    std::tuple<int, int> posAh = std::make_tuple(- 25, - 2);
    std::tuple<int, int> posBh = std::make_tuple(5,  - 2);
    std::tuple<int, int> posCh = std::make_tuple(35, - 2);

    std::tuple<int, int> posHSA = std::make_tuple(-33, 10);
    std::tuple<int, int> posHSB = std::make_tuple(-5, 10);
    std::tuple<int, int> posHSC = std::make_tuple(25, 10);

    std::tuple<int, int> posTitle = std::make_tuple(0, - 15);
    std::tuple<int, int> posDescription = std::make_tuple(-45, 25);
    std::string title("ARCADE");
    std::string description("Press A, B or C to launch a game, X to quit, O or P to switch library");
    std::string gameA(GAME1);
    std::string gameB(GAME2);
    std::string gameC(GAME3);
    std::string placeholderA("A");
    std::string placeholderB("B");
    std::string placeholderC("C");

    std::string highscoreA = _player->getHighScore(GAME1) > 0 ? "HighScore: " : "HighScore: n/a";
    std::string highscoreB = _player->getHighScore(GAME2) > 0 ? "HighScore: " : "HighScore: n/a";
    std::string highscoreC = _player->getHighScore(GAME3) > 0 ? "HighScore: " : "HighScore: n/a";
    highscoreA += _player->getHighScore(GAME1) > 0 ? std::to_string(_player->getHighScore(GAME1)) : "";
    highscoreB += _player->getHighScore(GAME2) > 0 ? std::to_string(_player->getHighScore(GAME2)) : "";
    highscoreC += _player->getHighScore(GAME3) > 0 ? std::to_string(_player->getHighScore(GAME3)) : "";

    _drawSquare(posA, size, BLUE);
    _drawSquare(posB, size, GREEN);
    _drawSquare(posC, size, RED);
    _drawText(posTitle, 75, title);
    _drawText(posDescription, 60, description);
    _drawText(posAd, 35, gameA);
    _drawText(posBd, 35, gameB);
    _drawText(posCd, 35, gameC);
    _drawText(posAh, 55, placeholderA);
    _drawText(posBh, 55, placeholderB);
    _drawText(posCh, 55, placeholderC);
    _drawText(posHSA, 20, highscoreA);
    _drawText(posHSB, 20, highscoreB);
    _drawText(posHSC, 20, highscoreC);
}

std::vector<std::string> MainMenu::getGameLibsAvailible()
{
    struct dirent *entry;
    DIR *dir = opendir("libs/");
    std::vector<std::string> availibles;

    if (!dir) {
        availibles.push_back("");
        availibles.clear();
        return availibles;
    }
    while ((entry = readdir(dir)) != nullptr) {
        if (strstr(entry->d_name, ".so") && (strstr(entry->d_name, "nibbler") ||
                                             strstr(entry->d_name, "pacman") || strstr(entry->d_name, "qix") ||
                                             strstr(entry->d_name, "centipede") ||
                                             strstr(entry->d_name, "solarfox"))) {
            availibles.push_back(entry->d_name);
        }
    }
    closedir(dir);
    return availibles;
}

std::vector<std::string> MainMenu::getGraphicsLibsAvailible()
{
    struct dirent *entry;
    DIR *dir = opendir("libs/");
    std::vector<std::string> availibles;

    if (!dir) {
        availibles.push_back("");
        availibles.clear();
        return availibles;
    }
    while ((entry = readdir(dir)) != nullptr) {
        if (strstr(entry->d_name, ".so") &&
            (!strstr(entry->d_name, "nibbler") &&
             !strstr(entry->d_name, "pacman") &&
             !strstr(entry->d_name, "qix") &&
             !strstr(entry->d_name, "centipede") &&
             !strstr(entry->d_name, "solarfox") &&
             strcmp(entry->d_name, ".") != 0 &&
             strcmp(entry->d_name, ".."))) {
            availibles.push_back(entry->d_name);
        }
    }
    closedir(dir);
    return std::vector<std::string>();
}

void MainMenu::initGame() {
    _display->getCurrentLib()->initScreen();
}

void MainMenu::drawGame() {

}

void MainMenu::setup() {
    initGame();
}

int MainMenu::registerInputsMenu(char input)
{
    if (input == 'x' || input == 'X') {
        _display->getCurrentLib()->endScreen();
        exit(0);
    }
    if (input == 'O' || input == 'o') {
        return -200;
    }
    if (input == 'P' || input == 'p') {
        return -300;
    }
    return 0;
}

int MainMenu::getScore() {
    return 0;
}

int MainMenu::getId() const {
    return _id;
}

Player *MainMenu::getPlayer() const {
    return _player;
}

void MainMenu::setPlayer(Player *player) {
    _player = player;
}
