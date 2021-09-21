/*
** EPITECH PROJECT, 2024
** B_OOP_400_LIL_4_1_arcade_achille_bourgault
** File description:
** Created by Frederic Lawecki-Walkowiak
*/

#include "sdl2.hpp"
#include <iostream>
#include "../../interface/constants.hpp"

void sdl2::clearScreen()
{
    SDL_RenderClear(_renderer);
}

void sdl2::refreshScreen()
{
    SDL_Color white = sdl2::getSdlColor(WHITE);
    SDL_SetRenderDrawColor(_renderer, white.r, white.g, white.b, white.a);
    SDL_RenderPresent(_renderer);
}

void sdl2::endScreen()
{
    SDL_DestroyWindow(_window);
    SDL_Quit();
}

std::tuple<int, int> sdl2::getWindowSize()
{
    int top;
    int left;
    SDL_GetWindowSize(_window, &top, &left);
    return std::make_tuple(top, left);
}

void sdl2::initScreen()
{
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        std::cout << "Impossible to init SDL" << std::endl;
        exit(84);
    }
    _window = SDL_CreateWindow("Arcade", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1920, 1080, SDL_WINDOW_SHOWN);
    if (!_window) {
        std::cout << "Could not create_object window" << std::endl;
        SDL_Quit();
    }
    _renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED);
    TTF_Init();
    _font = TTF_OpenFont("src/font.ttf", 30);
    if (!_font){
        std::cout << "Could not load font" << std::endl;
        exit(84);
    }
}

void sdl2::drawSquare(std::tuple<float, float> position, std::tuple<int, int> rectSize, int color)
{
    SDL_Color squareColor = sdl2::getSdlColor(color);
    SDL_Rect square;
    square.x = (std::get<0>(position) * 10) + std::get<0>(getWindowSize()) / 2;
    square.y = (std::get<1>(position) * 10) + std::get<1>(getWindowSize()) / 2;
    square.w = std::get<0>(rectSize) * 15;
    square.h = std::get<1>(rectSize) * 15;
    SDL_SetRenderDrawColor(_renderer, squareColor.r, squareColor.g, squareColor.b, squareColor.a);
    SDL_RenderFillRect(_renderer, &square);
    SDL_RenderDrawRect(_renderer, &square);
    SDL_SetRenderDrawColor(_renderer, 0,0,0,255);
}

void sdl2::drawtext(std::tuple<int, int> position, float scale, std::string &text)
{
    (void) scale;
    int x = (std::get<0>(position) * 10) + std::get<0>(getWindowSize()) / 2;
    int y = (std::get<1>(position) * 10) + std::get<1>(getWindowSize()) / 2;
    SDL_Color textColor = getSdlColor(BLACK);
    SDL_Surface *textSurface = TTF_RenderText_Blended(_font, text.c_str(), textColor);
    SDL_Texture *textTexture = SDL_CreateTextureFromSurface(_renderer, textSurface);
    int text_width = strlen(text.c_str()) * 20;
    int text_height = 30;
    SDL_FreeSurface(textSurface);
    SDL_Rect renderQuad = { x, y, text_width, text_height };
    SDL_RenderCopy(_renderer, textTexture, NULL, &renderQuad);
}

char sdl2::getInput()
{
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.key.keysym.sym == SDLK_RETURN)
            return '\r';
        if (strlen(event.text.text) >= 1)
            return event.text.text[0];
    }
    return 0;
}

SDL_Color sdl2::getSdlColor(int color)
{
    SDL_Color black = {0,0,0, 255};
    SDL_Color white = {255,255,255, 255};
    SDL_Color red {255,0,0,255};
    SDL_Color green {9,255,0,255};
    SDL_Color blue {0,60,255,255};
    SDL_Color yellow {255,255,0,255};
    SDL_Color magenta {255,0,213,255};
    SDL_Color cyan {0,255,255,255};
    SDL_Color transparent {255,255,255, 0};
    SDL_Color grey {164,164,164,100};
    switch (color) {
        case BLACK:
            return black;
            break;
        case WHITE:
            return white;
            break;
        case RED:
            return red;
            break;
        case GREEN:
            return green;
            break;
        case BLUE:
            return blue;
            break;
        case YELLOW:
            return yellow;
            break;
        case MAGENTA:
            return magenta;
            break;
        case CYAN:
            return cyan;
            break;
        case TRANSPARENT:
            return transparent;
            break;
        case GREY:
            return grey;
            break;
        default:
            return black;
    }
}

sdl2::sdl2()
{
}

sdl2::~sdl2()
{
}

extern "C" IDisplayModule *create_object() {
    return new sdl2;
}

extern "C" void destroy_object(IDisplayModule *m) {
    delete m;
}
