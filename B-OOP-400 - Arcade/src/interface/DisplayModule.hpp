/*
** EPITECH PROJECT, 2024
** B_OOP_400_LIL_4_1_arcade_achille_bourgault
** File description:
** Created by Achille Bourgault
*/

#ifndef IDISPLAYMODULE_HPP_
#define IDISPLAYMODULE_HPP_

#include <string>
#include <vector>
#include "constants.hpp"

class IDisplayModule {
    public:
    virtual void initScreen() = 0;
    virtual char getInput() = 0;
    virtual void clearScreen() = 0;
    virtual void refreshScreen() = 0;
    virtual void endScreen() = 0;
    virtual std::tuple<int, int> getWindowSize() = 0;
    virtual void drawSquare(std::tuple<float, float> position, std::tuple<int, int> rectSize,
                            int color) = 0;
    virtual void drawtext(std::tuple<int, int> position, float scale,
        std::string &text) = 0;
    virtual ~IDisplayModule()
    {};
};

#endif /* !IDISPLAYMODULE_HPP_ */