/*
** EPITECH PROJECT, 2024
** B_OOP_400_LIL_4_1_arcade_achille_bourgault
** File description:
** Created by Frederic Lawecki-Walkowiak
*/

#ifndef ARCADE_SFML_HPP
#define ARCADE_SFML_HPP

#include "../../interface/DisplayModule.hpp"
#include <SFML/Graphics.hpp>


class sfml : public IDisplayModule {
public :
    sfml();
    ~sfml();
    void clearScreen() override;
    void refreshScreen() override;
    void endScreen() override;
    std::tuple<int, int> getWindowSize() override;
    void initScreen() override;
    void drawSquare(std::tuple<float, float> position, std::tuple<int, int> rectSize, int color) override;
    void drawtext(std::tuple<int, int> position, float scale, std::string &text) override;
    char getInput() override;
    static sf::Color getSfmlColor(int color);
private :
    sf::RenderWindow _window;
    sf::Event _event;
    sf::Font _font;
};


#endif //ARCADE_SFML_HPP
