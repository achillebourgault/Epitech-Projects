/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** Created by Achille Bourgault
*/

#ifndef ARCADE_AGAMEMODULE_HPP
#define ARCADE_AGAMEMODULE_HPP

#include "GameModule.hpp"

class AGameModule : public IGameModule {
    public:
    virtual ~AGameModule();
    void setDrawTextLambda(std::function<void(std::tuple<int, int>, float,
        std::string &)> function) override;
    void setDrawSquareLambda(
        std::function<void(std::tuple<int, int>, std::tuple<int, int>,
            int)> function) override;
    void setInitScreenLambda(std::function<void()> function) override;
    void setClearScreenLambda(std::function<void()> function) override;
    void setRefreshScreenLambda(std::function<void()> function) override;
    void setEndScreenLambda(std::function<void()> function) override;
    void setGetWinSizeLambda(
        std::function<std::tuple<int, int>()> function) override;
    void setGetNameLambda(std::function<std::string()> function) override;
    void setSetNameLambda(std::function<void(std::string)> function) override;
    void setLoadGameLambda(
        std::function<void(std::string const &)> function) override;
    void setLoadGraphLibLambda(
        std::function<void(std::string const &)> function) override;


    protected:
    std::function<void(std::tuple<int, int>, float,
        std::string &)> _drawText;
    std::function<void(std::tuple<int, int>, std::tuple<int, int>,
            int)> _drawSquare;
    std::function<void()> _initScreen;
    std::function<void()> _clearScreen;
    std::function<void()> _refreshScreen;
    std::function<void()> _endScreen;
    std::function<std::tuple<int, int>()> _getWinSize;
    std::function<std::string()> _getNameLambda;
    std::function<void(std::string)> _setNameLambda;
    std::function<void(std::string const &)> _loadGameLambda;
    std::function<void(std::string const &)> _loadGraphLibLambda;
};

#endif //ARCADE_AGAMEMODULE_HPP
