/*
** EPITECH PROJECT, 2024
** B_OOP_400_LIL_4_1_arcade_achille_bourgault
** File description:
** Created by Frederic Lawecki-Walkowiak
*/

#include "sfml.hpp"
#include <iostream>
#include <SFML/Graphics/Text.hpp>
#include "../../interface/constants.hpp"

void sfml::clearScreen()
{
    _window.clear(getSfmlColor(WHITE));
}

void sfml::refreshScreen()
{
    _window.display();
}

void sfml::endScreen()
{
    _window.close();
}

std::tuple<int, int> sfml::getWindowSize()
{
    int x = _window.getSize().x;
    int y = _window.getSize().y;
    return (std::tuple<int, int>(x, y));
}

void sfml::initScreen()
{
    _window.create(sf::VideoMode(1920, 1080, 32), "Arcade");
    _window.clear(getSfmlColor(WHITE));
    _window.setFramerateLimit(60);
    _font.loadFromFile("src/font.otf");
    if (!_font.loadFromFile("src/font.otf")) {
        _window.close();
        std::cerr << "Error: failed to load font" << std::endl;
        exit(84);
    }
}

void sfml::drawSquare(std::tuple<float, float> position, std::tuple<int, int> rectSize, int color)
{
    sf::Vector2f _rectangleSize;
    sf::Vector2f _rectanglePosition;
    _rectangleSize.x = std::get<0>(rectSize) * 15;
    _rectangleSize.y = std::get<1>(rectSize) * 15;
    _rectanglePosition.x = (std::get<0>(position) * 10) + std::get<0>(getWindowSize()) / 2;
    _rectanglePosition.y = (std::get<1>(position) * 10) + std::get<1>(getWindowSize()) / 2;
    sf::RectangleShape _shape(_rectangleSize);
    _shape.setPosition(_rectanglePosition);
    _shape.setFillColor(sfml::getSfmlColor(color));
    _window.draw(_shape);
}

void sfml::drawtext(std::tuple<int, int> position, float scale, std::string &text)
{
    sf::Vector2f _textPosition;
    scale = 30;
    sf::Text _text;
    _text.setString(text);
    _text.setFont(_font);
    _text.setCharacterSize(scale);
    _text.setFillColor(sfml::getSfmlColor(BLACK));
    _textPosition.x = (std::get<0>(position) * 10) + std::get<0>(getWindowSize()) / 2;
    _textPosition.y = (std::get<1>(position) * 10) + std::get<1>(getWindowSize()) / 2;
    _text.setPosition(_textPosition);
    _window.draw(_text);
}

char sfml::getInput()
{
    std::string res("");
    while (_window.pollEvent(_event)) {
        if (_event.type == sf::Event::TextEntered) {
            res += (char)_event.text.unicode;
            break;
        }
    }
    return res.empty() ? 0 : res[0];
}

sf::Color sfml::getSfmlColor(int color)
{
    switch (color) {
        case BLACK:
            return sf::Color(0,0,0);
            break;
        case WHITE:
            return sf::Color(255,255,255);
            break;
        case RED:
            return sf::Color(255,0,0);
            break;
        case GREEN:
            return sf::Color(9,255,0);
            break;
        case BLUE:
            return sf::Color(0,60,255);
            break;
        case YELLOW:
            return sf::Color(255,255,0);
            break;
        case MAGENTA:
            return sf::Color(255,0,213);
            break;
        case CYAN:
            return sf::Color(0,255,255);
            break;
        case TRANSPARENT:
            return sf::Color(255,255,255, 0);
            break;
        case GREY:
            return sf::Color(164,164,164);
            break;
        default:
            return sf::Color(0,0,0);
    }
}

sfml::sfml()
{
}

sfml::~sfml()
{
}

extern "C" IDisplayModule *create_object() {
    return new sfml;
}

extern "C" void destroy_object(IDisplayModule *m) {
    delete m;
}