/*
** EPITECH PROJECT, 2024
** B_OOP_400_LIL_4_1_arcade_achille_bourgault
** File description:
** Created by Frederic Lawecki-Walkowiak
*/

#ifndef ARCADE_NCURSES_H
#define ARCADE_NCURSES_H

#include "../../interface/DisplayModule.hpp"
#include <tuple>
#include <ncurses.h>

class ncurses : public IDisplayModule {
public :
    ncurses();
    ~ncurses();
    void clearScreen() override;
    void refreshScreen() override;
    void endScreen() override;
    std::tuple<int, int> getWindowSize() override;
    void initScreen() override;
    void drawSquare(std::tuple<float, float> position, std::tuple<int, int> rectSize, int color) override;
    void drawtext(std::tuple<int, int> position, float scale, std::string &text) override;
    char getInput() override;
    std::tuple<int, int, int> getNcursesColor(int color);

protected:
    WINDOW *win;
    int _startx;
    int _starty;
};


#endif //ARCADE_NCURSES_H