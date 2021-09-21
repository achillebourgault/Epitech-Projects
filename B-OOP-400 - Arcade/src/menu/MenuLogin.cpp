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
#include "MenuLogin.hpp"
#include <chrono>


MenuLogin::MenuLogin(Player *p, DisplayHandler *handler)
{
    _display = handler;
    _player = p;
    _xPos = std::get<0>(_display->getCurrentLib()->getWindowSize()) / 2;
    _yPos = std::get<1>(_display->getCurrentLib()->getWindowSize()) / 2;
}

int MenuLogin::gameLoop(char input, float time, int graphId) {
    _id = graphId;
    _xPos = std::get<0>(_display->getCurrentLib()->getWindowSize()) / 2;
    _yPos = std::get<1>(_display->getCurrentLib()->getWindowSize()) / 2;
        registerInputsName(input);
        if (_player->isConnected()) {
            return 42;
        }
        if (time > 0.12) {
            _clearScreen();
            drawInputName();
            _refreshScreen();
            return -100;
        }
        return 0;
}

MenuLogin::~MenuLogin()
{
}

void MenuLogin::drawInputName()
{
    std::tuple<int, int> size = std::make_tuple(15, 3);
    std::tuple<int, int> pos = std::make_tuple(-12, -11);
    std::tuple<int, int> posFieldName = std::make_tuple(-10, -10);
    std::tuple<int, int> txtPos = std::make_tuple( -12, -15);
    std::tuple<int, int> enterPos = std::make_tuple( -25, 15);

    std::string test("Connectez-vous:");
    std::string enter("Entree pour valider, espace pour corriger");
    _drawSquare(pos, size, BLUE);
    _drawText(txtPos, 50, test);
    _drawText(enterPos, 50, enter);
    _drawText(posFieldName, 38, _name);
}

void MenuLogin::initGame() {
    _display->getCurrentLib()->initScreen();
}

void MenuLogin::drawGame() {

}

void MenuLogin::setup() {
    initGame();
}

void MenuLogin::registerInputsName(char input)
{
    if (input == 'x' || input == 'X') {
        _display->getCurrentLib()->endScreen();
        exit(0);
    }
    else if ((input >= 'a' && input <= 'z') || (input >= 'A' && input <= 'Z')) {
        _name += input;
    }
    else if (input == ' ') {
        _name = _name.substr(0, _name.size() - 1);
    }
    else if (((input == '\r') || (input == '\n')) && _name.size() > 0) {
        connectPlayer();
    }
}

void MenuLogin::connectPlayer()
{
    _player->setIsConnected(true);
    _player->setName(_name);
    _player->loadScore();
}

int MenuLogin::getScore() {
    return 0;
}

int MenuLogin::getId() const {
    return _id;
}

Player *MenuLogin::getPlayer() const {
    return _player;
}

void MenuLogin::setPlayer(Player *player) {
    _player = player;
}
