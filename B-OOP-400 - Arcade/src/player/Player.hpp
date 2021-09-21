/*
** EPITECH PROJECT, 2024
** B_OOP_400_LIL_4_1_arcade_achille_bourgault
** File description:
** Created by Achille Bourgault
*/

#ifndef B_OOP_400_LIL_4_1_ARCADE_ACHILLE_BOURGAULT_PLAYER_HPP
#define B_OOP_400_LIL_4_1_ARCADE_ACHILLE_BOURGAULT_PLAYER_HPP

#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include <list>

class Player {
    public:
    Player(std::string name);
    ~Player();
    void setName(std::string name);
    std::string getName();
    void loadScore();
    int getHighScore(std::string game);
    void setHighScore(std::string game, int score);
    bool isConnected() const;
    void setIsConnected(bool isConnected);
    protected:
    std::string _name;
    bool _isConnected;
    std::list<std::pair<std::string, int> > _high_scores;
};

#endif //B_OOP_400_LIL_4_1_ARCADE_ACHILLE_BOURGAULT_PLAYER_HPP
