/*
** EPITECH PROJECT, 2024
** B_OOP_400_LIL_4_1_arcade_achille_bourgault
** File description:
** Created by Frederic Lawecki-Walkowiak
*/

#ifndef ARCADE_SDL2_HPP
#define ARCADE_SDL2_HPP

#include "../../interface/DisplayModule.hpp"
#include <tuple>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

class sdl2 : public IDisplayModule {
public :
    sdl2();
    ~sdl2();
    void clearScreen() override;
    void refreshScreen() override;
    void endScreen() override;
    std::tuple<int, int> getWindowSize() override;
    void initScreen() override;
    void drawSquare(std::tuple<float, float> position, std::tuple<int, int> rectSize, int color) override;
    void drawtext(std::tuple<int, int> position, float scale, std::string &text) override;
    char getInput() override;
    SDL_Color getSdlColor(int color);
private :
    SDL_Window *_window;
    SDL_Renderer *_renderer;
    TTF_Font *_font;
};


#endif //ARCADE_SDL2_HPP
