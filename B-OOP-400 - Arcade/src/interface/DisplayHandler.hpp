/*
** EPITECH PROJECT, 2024
** B_OOP_400_LIL_4_1_arcade_achille_bourgault
** File description:
** Created by Achille Bourgault
*/

#ifndef B_OOP_400_LIL_4_1_ARCADE_ACHILLE_BOURGAULT_DISPLAYHANDLER_HPP
#define B_OOP_400_LIL_4_1_ARCADE_ACHILLE_BOURGAULT_DISPLAYHANDLER_HPP

#include <iostream>
#include <string>
#include "DisplayModule.hpp"
#include "../libs/sfml/sfml.hpp"
#include "../libs/sdl2/sdl2.hpp"
#include "../libs/ncurses/ncurses.hpp"

class DisplayHandler {
    public:
    DisplayHandler(std::string libpath);
    DisplayHandler();
    ~DisplayHandler();
    IDisplayModule *getCurrentLib() const;
    private:
    IDisplayModule *_currentLib;
    int _id;
public:
    int getId() const;
};

typedef IDisplayModule* create_t();
typedef void destroy_t(IDisplayModule*);

#endif