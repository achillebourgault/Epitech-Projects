/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** IGameModule
*/

#ifndef IGAMEMODULE_HPP_
#define IGAMEMODULE_HPP_

#include <memory>
#include <functional>
#include "DisplayHandler.hpp"
#include "DisplayModule.hpp"

class IGameModule {
public:
    virtual void initGame() = 0;
    virtual void drawGame() = 0;
    virtual int gameLoop(char input, float time, int graphId) = 0;
    virtual int getScore() = 0;

    //set lambdas
    virtual void setDrawTextLambda(std::function<void(std::tuple<int, int> position, float scale,
                                                      std::string &text)>) = 0;
    virtual void setDrawSquareLambda(std::function<void(std::tuple<int, int> position, std::tuple<int, int> rectSize,
                                                        int color)>) = 0;
    virtual void setInitScreenLambda(std::function<void()>) = 0;
    virtual void setClearScreenLambda(std::function<void()>) = 0;
    virtual void setRefreshScreenLambda(std::function<void()>) = 0;
    virtual void setEndScreenLambda(std::function<void()>) = 0;
    virtual void setGetWinSizeLambda(std::function<std::tuple<int, int>()>) = 0;
    virtual void setGetNameLambda(std::function<std::string()> function) = 0;
    virtual void setSetNameLambda(std::function<void(std::string)> function) = 0;
    virtual void setLoadGameLambda(std::function<void(const std::string &)> function) = 0;
    virtual void setLoadGraphLibLambda(std::function<void(const std::string &)> function) = 0;
};

#endif /* !IGAMEMODULE_HPP_ */
