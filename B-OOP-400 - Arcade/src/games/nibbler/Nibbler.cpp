/*
** EPITECH PROJECT, 2024
** B_OOP_400_LIL_4_1_arcade_achille_bourgault
** File description:
** Created by Achille Bourgault
*/

#include <chrono>
#include <thread>
#include "Nibbler.hpp"

Nibbler::Nibbler()
{
    _inGame = false;
    _isEnd = false;
    _direction = DIRECTION_UP;
    _state = STATE_MENU;

    _snakeParts = new std::vector<std::tuple<int, int>>;
    _snakeParts->insert(_snakeParts->cend(), std::make_tuple((MAP_SIZE / 2),
        (MAP_SIZE / 2) - 2));
    _snakeParts->insert(_snakeParts->cend(), std::make_tuple((MAP_SIZE / 2),
        (MAP_SIZE / 2) - 1));
    _snakeParts->insert(_snakeParts->cend(), std::make_tuple((MAP_SIZE / 2),
        (MAP_SIZE / 2)));
    _snakeParts->insert(_snakeParts->cend(), std::make_tuple((MAP_SIZE / 2),
        (MAP_SIZE / 2) + 1));
    generateMap();
}

Nibbler::~Nibbler()
{
}

int Nibbler::gameLoop(char input, float time, int graphId)
{
    _id = graphId;
    if (_state != STATE_QUIT_GAME) {
        registerInputs(input);
        if (_isEnd) {
            return _currentScore;
        }
        if (time > 0.12) {
            _clearScreen();
            if (_state == STATE_MENU) {
                drawMenu();
            } else if (_state == STATE_GAME) {
                drawGame();
                move("current_direction");
                drawOverlay();
            } else if (_state == STATE_END_LOOSE) {
                drawGame();
                drawEnd();
            }
            _refreshScreen();
            return -100;
        }
        return -1;
    }
}

void Nibbler::reloadGame()
{
    _clearScreen();
    _refreshScreen();
    _inGame = true;
    _direction = DIRECTION_UP;
    _currentScore = 0;
    _snakeParts = new std::vector<std::tuple<int, int>>;
    _snakeParts->push_back(std::make_tuple((MAP_SIZE / 2),
        (MAP_SIZE / 2) - 2));
    _snakeParts->push_back(std::make_tuple((MAP_SIZE / 2),
        (MAP_SIZE / 2) - 1));
    _snakeParts->push_back(std::make_tuple((MAP_SIZE / 2),
        (MAP_SIZE / 2)));
    _snakeParts->push_back(std::make_tuple((MAP_SIZE / 2),
        (MAP_SIZE / 2) + 1));
    generateMap();
    _state = STATE_GAME;
}

void Nibbler::initGame()
{
    _initScreen();
    _currentScore = 0;
    _direction = DIRECTION_UP;
}

void Nibbler::drawMenu()
{
    std::tuple<int, int> size = std::make_tuple(30, 15);
    std::tuple<int, int> pos = std::make_tuple(-5, - 10);
    std::tuple<int, int> posTextPressEnter = std::make_tuple(- 12, - 6);
    std::tuple<int, int> posA = std::make_tuple(- 18, - 13);
    _drawSquare(posA, size, GREY);
    std::string title("Nibbler");
    std::string description("PRESS SPACE TO PLAY");
    _drawText(pos, 55, title);
    _drawText(posTextPressEnter, 42, description);
}

void Nibbler::drawEnd()
{
    std::tuple<int, int> posTitle = std::make_tuple(- 3, 0);
    std::tuple<int, int> posDescription = std::make_tuple(- 2, 2);
    std::tuple<int, int> posRetry = std::make_tuple(- 20, 5);
    std::string title("YOU DIED");
    std::string description("Score: ");
    std::string retry("You can retry with SPACE or quit with X");

    for (auto & c: description) c = toupper(c);
    description.append("   ");
    description.append(std::to_string(_currentScore));
    _drawText(posTitle, 55, title);
    _drawText(posDescription, 42, description);
    _drawText(posRetry, 32, retry);
}

void Nibbler::drawGame()
{
    std::tuple<int, int> posTitle = std::make_tuple(- 4, - 17);
    std::string title("Nibbler");
    std::tuple<int, int> size = std::make_tuple(MAP_SIZE * 2, MAP_SIZE);
    std::tuple<int, int> posA = std::make_tuple(- (std::get<0>(size) / 2), - 15);

    _drawSquare(posA, size, BLUE);
    _drawText(posTitle, 55, title);

    drawMap();
    drawSnake();
}

void Nibbler::drawOverlay()
{
    std::tuple<int, int> posScore = std::make_tuple(- 5, 6);
    std::string score("Score: ");
    int scale = getId() == SFML ? 50 : 1;

    score.append(std::to_string(_currentScore));
    _drawText(posScore, scale, score);
}

void Nibbler::drawSnake()
{
    for (auto parts : *_snakeParts) {
        int y = 1;
        std::tuple<int, int> size = std::make_tuple(2, y);
        int posX = std::get<0>(parts);
        int posY = std::get<1>(parts);
        std::tuple<int, int> pos = std::make_tuple( - (MAP_SIZE) + (posX * 2), - 15 + posY);
        _drawSquare(pos, size, YELLOW);
    }
}

void Nibbler::drawMap()
{
    std::tuple<int, int> size = std::make_tuple(2, 1);
    for (int y = 0; y < MAP_SIZE; y++) {
        for (int x = 0 ;x < MAP_SIZE; x++) {
            if (_map[y][x] == '*') {
                std::tuple<int, int> pos = std::make_tuple(- (MAP_SIZE) + (x * 2), - 15 + y);
                _drawSquare(pos, size, RED);
            }
        }
    }
}

void Nibbler::registerInputsInMenu(char input)
{
    if (input == 'x' || input == 'X') {
        _isEnd = true;
    } else if (input == ' ') {
        setState(STATE_GAME);
        _clearScreen();
    }
}

void Nibbler::registerInputsInGame(char in)
{
    if (in == 'x' || in == 'X') {
        _isEnd = true;
    } else if (in == 'm' || in == 'M') {
        setState(STATE_MENU);
    }
    if (in == 'q' || in == 'd') {
        if (!_inGame)
            _inGame = true;
        void *exec = in == 'q' ? move("left") : move("right");
    }
}

void Nibbler::registerInputsInEnd(char input)
{
    if (input == 'x' || input == 'X') {
        _isEnd = true;
    } else if (input == ' ') {
        reloadGame();
    }
}

int Nibbler::handleLoose(int posX, int posY)
{
    int tmpscore = _currentScore;

    for (auto parts : *_snakeParts) {
        int IposX = std::get<0>(parts);
        int IposY = std::get<1>(parts);

        if (IposX == posX && IposY == posY && _inGame) {
            _clearScreen();
            _refreshScreen();
            setState(STATE_END_LOOSE);
            return tmpscore;
        }
    }
    if (posX < 0 || posX > (MAP_SIZE - 1) || posY < 0 || posY > (MAP_SIZE - 1)) {
        _clearScreen();
        _snakeParts->pop_back();
        _snakeParts->insert(_snakeParts->cbegin(), std::make_tuple(posX, posY));
        _refreshScreen();
        std::this_thread::sleep_for(std::chrono::milliseconds(300));
        setState(STATE_END_LOOSE);
        return tmpscore;
    }
}

void *Nibbler::move(std::string dir)
{
    if (strstr(dir.c_str(), "current_direction")) {
        std::tuple<int, int> head = _snakeParts->front();
        int posX = std::get<0>(head);
        int posY = std::get<1>(head);

        if (_direction == DIRECTION_DOWN)
            posY += 1;
        else if (_direction == DIRECTION_UP)
            posY -= 1;
        else if (_direction == DIRECTION_LEFT)
            posX -= 1;
        else if (_direction == DIRECTION_RIGHT)
            posX += 1;

        handleLoose(posX, posY);
        if (_map[posY][posX] == '*') {
            _currentScore += 100;
            _snakeParts->insert(_snakeParts->cbegin(), std::make_tuple(posX, posY));
            _map[posY][posX] = ' ';
            if (getTotalFoods() < 3) {
                generateRandomFoods();
            }
        }

        _snakeParts->pop_back();
        _snakeParts->insert(_snakeParts->cbegin(), std::make_tuple(posX, posY));
    }
    else if (strstr(dir.c_str(), "left")) {
        if (_direction == DIRECTION_UP) {
            _direction = DIRECTION_LEFT;
        } else if (_direction == DIRECTION_DOWN) {
            _direction = DIRECTION_RIGHT;
        } else if (_direction == DIRECTION_LEFT) {
            _direction = DIRECTION_DOWN;
        } else if (_direction == DIRECTION_RIGHT) {
            _direction = DIRECTION_UP;
        }
    } else if (strstr(dir.c_str(), "right")) {
        if (_direction == DIRECTION_UP) {
            _direction = DIRECTION_RIGHT;
        } else if (_direction == DIRECTION_DOWN) {
            _direction = DIRECTION_LEFT;
        } else if (_direction == DIRECTION_LEFT) {
            _direction = DIRECTION_UP;
        } else if (_direction == DIRECTION_RIGHT) {
            _direction = DIRECTION_DOWN;
        }
    } else
        fprintf(stderr, "ERROR: MOVEMENT (USE left/right) -> Got [%s]\n", dir.c_str());
}

void Nibbler::setState(int state)
{
    _state = state;
    _clearScreen();
    _refreshScreen();
}

void Nibbler::generateMap()
{
    int y = 0;

    for (;y < MAP_SIZE; y++) {
        int foodPos = rand()%(MAP_SIZE-0 + 1) + 0;
        bool isFoodLine = foodPos % 2 != 0;
        for (int x = 0 ;x < MAP_SIZE; x++) {
            if (x == foodPos && isFoodLine)
                _map[y][x] = '*';
            else
                _map[y][x] = ' ';
        }
    }
}

int Nibbler::getTotalFoods()
{
    int res = 0;

    for (int y = 0; y < MAP_SIZE; y++) {
        for (int x = 0 ;x < MAP_SIZE; x++) {
            if (_map[y][x] == '*')
                res++;
        }
    }
    return res;
}

void Nibbler::generateRandomFoods()
{
    bool obstruct = true;
    int foodAmount = rand()%(5-2 + 1) + 2;

    for (int i = 0; i < foodAmount; i++) {
        int foodPosX = rand()%(MAP_SIZE-0 + 1) + 0;
        int foodPosY = rand()%(MAP_SIZE-0 + 1) + 0;
        while (obstruct) {
            obstruct = false;
            for (auto parts : *_snakeParts) {
                int posX = std::get<0>(parts);
                int posY = std::get<1>(parts);

                if (foodPosX == posX && foodPosY == posY) {
                    obstruct = true;
                    foodPosX = rand()%(MAP_SIZE-0 + 1) + 0;
                    foodPosY = rand()%(MAP_SIZE-0 + 1) + 0;
                    break;
                }
            }
        }
        _map[foodPosY][foodPosX] = '*';
    }
}

void Nibbler::registerInputs(char input)
{
    if (_state == STATE_MENU) {
        registerInputsInMenu(input);
    } else if (_state == STATE_GAME) {
        registerInputsInGame(input);
    } else if (_state == STATE_END_LOOSE) {
        registerInputsInEnd(input);
    }
}

int Nibbler::getScore() {
    return _currentScore;
}

int Nibbler::getId() const {
    return _id;
}

extern "C" IGameModule *create_object() {
    return new Nibbler();
}

extern "C" void destroy_object(AGameModule *m) {
    delete m;
}

