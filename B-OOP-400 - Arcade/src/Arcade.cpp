/*
** EPITECH PROJECT, 2024
** B_OOP_400_LIL_4_1_arcade_achille_bourgault
** File description:
** Created by Achille Bourgault
*/

#include <functional>
#include <fstream>
#include <dlfcn.h>
#include <cstring>
#include "games/nibbler/Nibbler.hpp"
#include "games/GameHandler.hpp"
#include "menu/MainMenu.hpp"
#include "interface/DisplayHandler.hpp"
#include "Arcade.hpp"
#include "menu/MenuLogin.hpp"
#include <chrono>

Arcade::Arcade(std::string lib)
{
    Player tmp = Player("default");
    _player = &tmp;
    openLib(lib);
    setup(lib);
    MainMenu menu(_player, &_currentDisplayHandler);
    _currentGameHandler.setGameModule(&menu);
    initGameLambdas();
    gameloop();
}

Arcade::~Arcade()
{
}

int Arcade::menuloop()
{
    bool exit = false;
    auto start = std::chrono::system_clock::now();
    auto end = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds = end-start;
    int res;
    while (!exit) {
        end = std::chrono::system_clock::now();
        elapsed_seconds = end-start;
        res = _currentGameHandler.getCurrentGame()->gameLoop(_currentDisplayHandler.getCurrentLib()->getInput(), elapsed_seconds.count(), _currentDisplayHandler.getId());
        switch (res)
        {
            case -300:
                nextGraphics();
                break;
            case -200:
                previousGraphics();
                break;
            case -100:
                start = std::chrono::system_clock::now();
                break;
            case 2:
                return 2;
            case 3:
                return 3;
            case 4:
                return 4;
            case 42:
                exit = true;
                return 42;
        }
    }
    return -100;
}

void Arcade::gameloop()
{
    bool exit = false;
    bool isGameChoosed = false;
    MenuLogin login(_player, &_currentDisplayHandler);
    _currentGameHandler.setGameModule(&login);
    initGameLambdas();
    _currentGameHandler.getCurrentGame()->initGame();
    int choosedGame = menuloop();
    MainMenu menu(login.getPlayer(), &_currentDisplayHandler);
    if (choosedGame == 42) {
        menu.setPlayer(login.getPlayer());
        _currentGameHandler.setGameModule(&menu);
        initGameLambdas();
        _currentGameHandler.getCurrentGame()->initGame();
        choosedGame = menuloop();
    }
    auto start = std::chrono::system_clock::now();
    auto end = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds = end-start;
    int res;

    while (!exit) {
        registerChangeLib(_currentDisplayHandler.getCurrentLib()->getInput());
        if (choosedGame >= 2 && !isGameChoosed) {
            if (choosedGame == 2) {
                changeGame("lib/arcade_nibbler.so");
            }
            if (choosedGame == 3) {
                changeGame("lib/arcade_pacman.so");
            }
            if (choosedGame == 4) {
                changeGame("lib/arcade_nibbler.so");
            }
            isGameChoosed = true;
        }
        end = std::chrono::system_clock::now();
        elapsed_seconds = end-start;
        res = _currentGameHandler.getCurrentGame()->gameLoop(_currentDisplayHandler.getCurrentLib()->getInput(), elapsed_seconds.count(), _currentDisplayHandler.getId());
        if ((res >= 0)) {
            break;
        }
        if (res == -100) {
            start = std::chrono::system_clock::now();
        }
    }
    if (res >= 0) {
        Player tmpPlayer = Player(menu.getPlayer()->getName());
        _player = &tmpPlayer;
        _currentGameHandler.setGameModule(&menu);
        initGameLambdas();
        gameloop();
    }
}

void Arcade::setup(std::string lib)
{
    _currentDisplayHandler = DisplayHandler(lib);
}

void Arcade::previousGraphics()
{
    if (_currentDisplayHandler.getId() == SFML) {
        if (openLib("lib/arcade_sdl2.so")) {
            _currentDisplayHandler.getCurrentLib()->endScreen();
            _currentDisplayHandler = DisplayHandler("lib/arcade_sdl2.so");
            _currentDisplayHandler.getCurrentLib()->initScreen();
        } else {
            std::cerr << "Cannot switch to sdl2, library file doesn't found." << std::endl;
        }
    }
    else if (_currentDisplayHandler.getId() == NCURSES) {
        if (openLib("lib/arcade_sfml.so")) {
            _currentDisplayHandler.getCurrentLib()->endScreen();
            _currentDisplayHandler = DisplayHandler("lib/arcade_sfml.so");
            _currentDisplayHandler.getCurrentLib()->initScreen();
        } else {
            std::cerr << "Cannot switch to sfml, library file doesn't found." << std::endl;
        }
    }
    else /* (_currentDisplayHandler.getId() == SDL2)*/ {
        if (openLib("lib/arcade_ncurses.so")) {
            _currentDisplayHandler.getCurrentLib()->endScreen();
            _currentDisplayHandler = DisplayHandler("lib/arcade_ncurses.so");
            _currentDisplayHandler.getCurrentLib()->initScreen();
        } else {
            std::cerr << "Cannot switch to sfml, library file doesn't found." << std::endl;
        }
    }
}

void Arcade::nextGraphics()
{
    if (_currentDisplayHandler.getId() == SFML) {
        if (openLib("lib/arcade_ncurses.so")) {
            _currentDisplayHandler.getCurrentLib()->endScreen();
            _currentDisplayHandler = DisplayHandler("lib/arcade_ncurses.so");
            _currentDisplayHandler.getCurrentLib()->initScreen();
        } else {
            std::cerr << "Cannot switch to ncurses, library file doesn't found." << std::endl;
        }
    }
    else if (_currentDisplayHandler.getId() == NCURSES) {
        if (openLib("lib/arcade_sdl2.so")) {
            _currentDisplayHandler.getCurrentLib()->endScreen();
            _currentDisplayHandler = DisplayHandler("lib/arcade_sdl2.so");
            _currentDisplayHandler.getCurrentLib()->initScreen();
        } else {
            std::cerr << "Cannot switch to sdl2, library file doesn't found." << std::endl;
        }
    }
    else /*(_currentDisplayHandler.getId() == SDL2)*/ {
        if (openLib("lib/arcade_sfml.so")) {
            _currentDisplayHandler.getCurrentLib()->endScreen();
            _currentDisplayHandler = DisplayHandler("lib/arcade_sfml.so");
            _currentDisplayHandler.getCurrentLib()->initScreen();
        } else {
            std::cerr << "Cannot switch to sfml, library file doesn't found." << std::endl;
        }
    }
}

void Arcade::previousGame()
{
    if (_currentGameHandler.getId() ==  GAME1ID) {
        _currentGameHandler = GameHandler("lib/arcade_centipede.so", &_currentDisplayHandler, _player, this);
        _currentGameHandler.getCurrentGame()->initGame();
        _currentGameHandler.getCurrentGame()->gameLoop(0, 0, 0);
    } else {
        _currentGameHandler = GameHandler("lib/arcade_nibbler.so", &_currentDisplayHandler, _player, this);
        _currentGameHandler.getCurrentGame()->initGame();
        _currentGameHandler.getCurrentGame()->gameLoop(0, 0, 0);
    }
}

void Arcade::changeGame(std::string path)
{
    _currentDisplayHandler.getCurrentLib()->endScreen();
    _currentGameHandler = GameHandler(path, &_currentDisplayHandler, _player, this);
    _currentGameHandler.setGameModule(_currentGameHandler.getCurrentGame());
    initGameLambdas();
    _currentGameHandler.getCurrentGame()->initGame();
}

void Arcade::changeGraphics(std::string path)
{
        if (openLib(path)) {
            _currentDisplayHandler.getCurrentLib()->endScreen();
            _currentDisplayHandler = DisplayHandler(path);
            _currentDisplayHandler.getCurrentLib()->initScreen();
        } else {
            std::cerr << "Cannot switch graphical library, library file doesn't found." << std::endl;
        }
}

void Arcade::nextGame()
{
    if (_currentGameHandler.getId() ==  GAME1ID) {
        _currentGameHandler = GameHandler("lib/arcade_centipede.so", &_currentDisplayHandler, _player, this);
        _currentGameHandler.getCurrentGame()->initGame();
        _currentGameHandler.getCurrentGame()->gameLoop(0, 0, 0);
    } else {
        _currentGameHandler = GameHandler("lib/arcade_nibbler.so", &_currentDisplayHandler, _player, this);
        _currentGameHandler.getCurrentGame()->initGame();
        _currentGameHandler.getCurrentGame()->gameLoop(0, 0, 0);
    }
}

void Arcade::restartGame()
{
}

void Arcade::backToMenu()
{
}

void Arcade::exit()
{
}

Player* Arcade::getPlayer()
{
    return _player;
}

void Arcade::connectPlayer(std::string player)
{
    Player tmp = Player(player);
    _player = &tmp;
}

bool Arcade::openLib(std::string lib)
{
    bool res = false;
    std::ifstream libfile(lib);

    if (libfile)
        res = true;
    return res;
}

char Arcade::getInput()
{
    return 0;
}

void Arcade::loadLibrairiesFunc(std::string lib)
{
    void *_currentLib;
    typedef std::function<bool(DisplayHandler&)> libsFunc_t;
    libsFunc_t libsFunc;

    _currentLib = dlopen(lib.c_str(), RTLD_LAZY);
    if (!_currentLib) {
        std::cerr << "Cannot open library: " << dlerror() << std::endl;
        std::exit(84);
    }
}

void Arcade::initGameLambdas()
{
    std::function<void(std::tuple<int, int>, float,
        std::string &)> _drawText = [this](std::tuple<int, int> position, float scale, std::string &text) {
        _currentDisplayHandler.getCurrentLib()->drawtext(position, scale, text);
    };
    _currentGameHandler.getCurrentGame()->setDrawTextLambda(_drawText);
    std::function<void(std::tuple<int, int>, std::tuple<int, int>, int)> _drawSquare = [this](std::tuple<float, float> position, std::tuple<int, int> rectSize, int color) {
        _currentDisplayHandler.getCurrentLib()->drawSquare(position, rectSize, color);
    };
    _currentGameHandler.getCurrentGame()->setDrawSquareLambda(_drawSquare);

    std::function<void()> _initScreen = [this]() {
        _currentDisplayHandler.getCurrentLib()->initScreen();
    };
    _currentGameHandler.getCurrentGame()->setInitScreenLambda(_initScreen);

    std::function<void()> _clearScreen = [this]() {
        _currentDisplayHandler.getCurrentLib()->clearScreen();
    };
    _currentGameHandler.getCurrentGame()->setClearScreenLambda(_clearScreen);

    std::function<void()> _refreshScreen = [this]() {
        _currentDisplayHandler.getCurrentLib()->refreshScreen();
    };
    _currentGameHandler.getCurrentGame()->setRefreshScreenLambda(_refreshScreen);

    std::function<void()> _endScreen = [this]() {
        _currentDisplayHandler.getCurrentLib()->endScreen();
    };
    _currentGameHandler.getCurrentGame()->setEndScreenLambda(_endScreen);

    std::function<std::tuple<int, int>()> _getWinSize = [this]() {
        return _currentDisplayHandler.getCurrentLib()->getWindowSize();
    };
    _currentGameHandler.getCurrentGame()->setGetWinSizeLambda(_getWinSize);

    std::function<void(std::string const &)> _loadGameLambda = [this] (std::string const &path) {
        changeGame(path);
    };
    _currentGameHandler.getCurrentGame()->setLoadGameLambda(_loadGameLambda);

    std::function<void(std::string const &)> _loadGraphLibLambda = [this] (std::string const &path) {
        changeGraphics(path);
    };
    _currentGameHandler.getCurrentGame()->setLoadGraphLibLambda(_loadGraphLibLambda);
}

void Arcade::registerChangeLib(char input) {
    if ((input == 'P') || (input == 'p'))
        nextGraphics();
    else if ((input == 'O') || (input == 'o'))
        previousGraphics();
}
