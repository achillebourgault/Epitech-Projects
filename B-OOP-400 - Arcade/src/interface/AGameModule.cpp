#include <functional>

/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** Created by Achille Bourgault
*/

#include "AGameModule.hpp"
#include "GameModule.hpp"

void AGameModule::setDrawTextLambda(
    std::function<void(std::tuple < int, int > , float,
        std::string & )> function)
{
    _drawText = function;
}

void AGameModule::setDrawSquareLambda(
    std::function<void(std::tuple < int, int > , std::tuple < int, int > ,
        int)> function)
{
    _drawSquare = function;
}

void AGameModule::setInitScreenLambda(std::function<void()> function)
{
    _initScreen = function;
}

void AGameModule::setClearScreenLambda(std::function<void()> function)
{
    _clearScreen = function;
}

void AGameModule::setRefreshScreenLambda(std::function<void()> function)
{
    _refreshScreen = function;
}

void AGameModule::setEndScreenLambda(std::function<void()> function)
{
    _endScreen = function;
}

void AGameModule::setGetWinSizeLambda(
    std::function<std::tuple<int, int>()> function)
{
    _getWinSize = function;
}

void AGameModule::setGetNameLambda(std::function<std::string()> function)
{
    _getNameLambda = function;
}

void AGameModule::setSetNameLambda(std::function<void(std::string)> function)
{
    _setNameLambda = function;
}

void AGameModule::setLoadGameLambda(std::function < void(std::string const &)> function){
    _loadGameLambda = function;
}

void AGameModule::setLoadGraphLibLambda(std::function < void(std::string

const &)> function){
    _loadGraphLibLambda = function;
}

AGameModule::~AGameModule()
{
}
