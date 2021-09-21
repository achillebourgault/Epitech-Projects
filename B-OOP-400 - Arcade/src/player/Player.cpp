/*
** EPITECH PROJECT, 2024
** B_OOP_400_LIL_4_1_arcade_achille_bourgault
** File description:
** Created by Achille Bourgault
*/

#include <iostream>
#include <cstring>
#include <fstream>
#include <ftw.h>
#include "Player.hpp"
#include "../Arcade.hpp"

Player::Player(std::string name) : _name(name)
{
    if (!strstr(name.c_str(), "default")) {
        _isConnected = true;
        loadScore();
    } else {
        _isConnected = false;
        loadScore();
	}
}

Player::~Player()
{
}

void Player::setName(std::string name)
{
    _name = name;
}

std::string Player::getName()
{
    return _name;
}

int Player::getHighScore(std::string game)
{
    int res = 0;

    for (auto const& it : _high_scores) {
        if (strncmp(it.first.c_str(), game.c_str(), strlen(game.c_str())) == 0) {
            res = it.second;
            break;
        }
    }
    return res;
}

void Player::setHighScore(std::string game, int score)
{
    std::string scorepath(".scores/");
    scorepath.append(getName());
    scorepath.append(".save");
    std::ofstream newfile(scorepath);
    int scoreA = getHighScore(GAME1);
    int scoreB = getHighScore(GAME2);
    int scoreC = getHighScore(GAME3);

    if (strncmp(game.c_str(), GAME1, strlen(GAME1)) == 0)
        scoreA = score;
    else if (strncmp(game.c_str(), GAME2, strlen(GAME2)) == 0)
        scoreB = score;
    else if (strncmp(game.c_str(), GAME3, strlen(GAME3)) == 0)
        scoreC = score;
    newfile << GAME1 << "=" << scoreA << "\n" << GAME2 << "=" << scoreB << "\n" << GAME3
        << "=" << scoreC << std::endl;
    newfile.close();
    loadScore();
}

void Player::loadScore()
{
    std::string tmpScore;
    std::pair<std::string, int> game1;
    std::pair<std::string, int> game2;
    std::pair<std::string, int> game3;
    std::ifstream scoredir(".scores");

    if (!scoredir)
        mkdir(".scores", 0777);
    std::string scorepath = ".scores/";
    std::string line;
    scorepath.append(getName());
    scorepath.append(".save");
    std::ifstream file(scorepath);
    if (!file) {
        std::ofstream newfile(scorepath);
        newfile << GAME1 << "=0" << "\n" << GAME2 << "=0" << "\n" << GAME3
            << "=0" << std::endl;
        game1 = std::make_pair(GAME1, 0);
        game2 = std::make_pair(GAME2, 0);
        game3 = std::make_pair(GAME3, 0);
        newfile.close();
    } else {
        while (getline(file, line)) {
            if (strncmp(line.c_str(), GAME1, strlen(GAME1)) == 0) {
                tmpScore = line.substr(strlen(GAME1) + 1);
                game1 = std::make_pair(GAME1, atoi(tmpScore.c_str()));
            } else if (strncmp(line.c_str(), GAME2, strlen(GAME2)) == 0) {
                tmpScore = line.substr(strlen(GAME2) + 1);
                game2 = std::make_pair(GAME2, atoi(tmpScore.c_str()));
            } else if (strncmp(line.c_str(), GAME3, strlen(GAME3)) == 0) {
                tmpScore = line.substr(strlen(GAME3) + 1);
                game3 = std::make_pair(GAME3, atoi(tmpScore.c_str()));
            }
        }
        file.close();
    }
    _high_scores.clear();
    _high_scores.push_back(game1);
    _high_scores.push_back(game2);
    _high_scores.push_back(game3);
}

bool Player::isConnected() const {
    return _isConnected;
}

void Player::setIsConnected(bool isConnected) {
    _isConnected = isConnected;
}
