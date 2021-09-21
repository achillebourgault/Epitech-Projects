/*
** EPITECH PROJECT, 2024
** B_OOP_400_LIL_4_1_arcade_achille_bourgault
** File description:
** Created by Achille Bourgault
*/

#include <chrono>
#include <thread>
#include "Pacman.hpp"

Pacman::Pacman()
{
    _inGame = false;
    _isEnd = false;
    _direction = DIRECTION_UP;
    _state = STATE_MENU;

    _playerParts = new std::vector<std::tuple<int, int>>;
    _playerParts->insert(_playerParts->cend(), std::make_tuple((MAP_SIZE / 2),
        (MAP_SIZE / 2) - 2));
    _playerParts->insert(_playerParts->cend(), std::make_tuple((MAP_SIZE / 2),
        (MAP_SIZE / 2) - 1));
    _playerParts->insert(_playerParts->cend(), std::make_tuple((MAP_SIZE / 2),
        (MAP_SIZE / 2)));
    _playerParts->insert(_playerParts->cend(), std::make_tuple((MAP_SIZE / 2),
        (MAP_SIZE / 2) + 1));
    generateMap();
}

Pacman::~Pacman()
{
}

int Pacman::gameLoop(char input, float time, int graphId)
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

void Pacman::reloadGame()
{
    _clearScreen();
    _refreshScreen();
    _inGame = true;
    _direction = DIRECTION_UP;
    _currentScore = 0;
    _playerParts = new std::vector<std::tuple<int, int>>;
    _playerParts->push_back(std::make_tuple((MAP_SIZE / 2),
        (MAP_SIZE / 2) - 2));
    generateMap();
    _state = STATE_GAME;
}

void Pacman::initGame()
{
    _initScreen();
    _currentScore = 0;
    _direction = DIRECTION_UP;
}

void Pacman::drawMenu()
{
    std::tuple<int, int> size = std::make_tuple(50, 15);
    std::tuple<int, int> pos = std::make_tuple(3, - 10);

    std::tuple<int, int> posTextPressEnter = std::make_tuple(- 2, - 6);

    std::tuple<int, int> posA = std::make_tuple(- 18, - 13);

    _drawSquare(posA, size, GREY);
    std::string title("Pacman");
    std::string description("PRESS SPACE TO PLAY");
    _drawText(pos, 55, title);
    _drawText(posTextPressEnter, 42, description);
}

void Pacman::drawEnd()
{
    std::tuple<int, int> size = std::make_tuple(60,35);
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

void Pacman::drawGame()
{
    std::tuple<int, int> posTitle = std::make_tuple(- 4, - 17);
    std::string title("Pacman");
    std::tuple<int, int> size = std::make_tuple(MAP_SIZE * 2, MAP_SIZE);
    std::tuple<int, int> posA = std::make_tuple(- (std::get<0>(size) / 2),  - 15);

    _drawSquare(posA, size, GREY);
    _drawText(posTitle, 55, title);

    drawMap();
    drawPlayer();
}

void Pacman::drawOverlay()
{
    std::tuple<int, int> posScore = std::make_tuple(- 5, + 6);
    std::string score("Score: ");
    int scale = getId() == SFML ? 50 : 1;

    score.append(std::to_string(_currentScore));
    _drawText(posScore, scale, score);
}

void Pacman::drawPlayer()
{
    for (auto parts : *_playerParts) {
        int y = 1;
        std::tuple<int, int> size = std::make_tuple(2, y);
        int posX = std::get<0>(parts);
        int posY = std::get<1>(parts);
        std::tuple<int, int> pos = std::make_tuple(- (MAP_SIZE) + (posX * 2), - 15 + posY);
        _drawSquare(pos, size, YELLOW);
    }
}

void Pacman::drawMap()
{
    std::tuple<int, int> size = std::make_tuple(2, 1);
    for (int y = 0; y < MAP_SIZE; y++) {
        for (int x = 0 ;x < MAP_SIZE; x++) {
            std::tuple<int, int> pos = std::make_tuple(- (MAP_SIZE) + (x * 2), - 15 + y);
            if (_map[y][x] == '#') {
                _drawSquare(pos, size, BLUE);
            } else if (_map[y][x] == 'O') {
                _drawSquare(pos, size, CYAN);
            } else if (_map[y][x] == '.') {
                _drawSquare(pos, size, WHITE);
            }
        }
    }
}

void Pacman::registerInputsInMenu(char input)
{
    if (input == 'x' || input == 'X') {
        _isEnd = true;
    } else if (input == ' ') {
        setState(STATE_GAME);
        _clearScreen();
    }
}

void Pacman::registerInputsInGame(char in)
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

void Pacman::registerInputsInEnd(char input)
{
    if (input == 'x' || input == 'X') {
        _isEnd = true;
    } else if (input == ' ') {
        reloadGame();
    }
}

int Pacman::handleLoose(int posX, int posY)
{
    int tmpscore = _currentScore;

    for (auto parts : *_playerParts) {
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
        _playerParts->pop_back();
        _playerParts->insert(_playerParts->cbegin(), std::make_tuple(posX, posY));
        _refreshScreen();
        std::this_thread::sleep_for(std::chrono::milliseconds(300));
        setState(STATE_END_LOOSE);
        return tmpscore;
    }
}

void *Pacman::move(std::string dir)
{
    if (strstr(dir.c_str(), "current_direction")) {
        std::tuple<int, int> head = _playerParts->front();
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
        if (_map[posY][posX] == '.') {
            _currentScore += 100;
            _map[posY][posX] = ' ';
        }

        _playerParts->pop_back();
        _playerParts->insert(_playerParts->cbegin(), std::make_tuple(posX, posY));
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

void Pacman::setState(int state)
{
    _state = state;
    _clearScreen();
    _refreshScreen();
}

void Pacman::generateMap()
{
    int cpt = 0;

    std::string map("############## ##############\n"
                    "#O...........  ............O#\n"
                    "#.############ ############.#\n"
                    "#.#..........  ...........#.#\n"
                    "#.#.########## ##########.#.#\n"
                    "#.#.#                   #.#.#\n"
                    "#.#.#                   #.#.#\n"
                    "# #.#                   #.#.#\n"
                    "#.#.#                   #.#.#\n"
                    "#.#.#                   #.#.#\n"
                    "#                           #\n"
                    "#                           #\n"
                    "#        ##       ##        #\n"
                    "#        #         #        #\n"
                    "#                           #\n"
                    "                             \n"
                    "#                           #\n"
                    "#                           #\n"
                    "#                           #\n"
                    "#        #         #        #\n"
                    "#.#.#    ##       ##    #.#.#\n"
                    "#.#.#                   #.#.#\n"
                    "#.#.#                   #.#.#\n"
                    "#.#.#                   #.#.#\n"
                    "#.#.#                   #.#.#\n"
                    "#.#.########## ##########.#.#\n"
                    "#.#..........  ...........#.#\n"
                    "#.############ ############.#\n"
                    "#O...........  ............O#\n"
                    "############## ##############\n");

    int y = 0;
    int x = 0;
    for (; cpt < map.length(); cpt++) {
        if (map[cpt] == '\n') {
            _map[y][x] = '\0';
            y++;
        } else {
            _map[y][x] = map[cpt];
        }
    }
    
}

void Pacman::registerInputs(char input)
{
    if (_state == STATE_MENU) {
        registerInputsInMenu(input);
    } else if (_state == STATE_GAME) {
        registerInputsInGame(input);
    } else if (_state == STATE_END_LOOSE) {
        registerInputsInEnd(input);
    }
}

int Pacman::getScore() {
    return _currentScore;
}

int Pacman::getId() const {
    return _id;
}

extern "C" IGameModule *create_object() {
    return new Pacman();
}

extern "C" void destroy_object(AGameModule *m) {
    delete m;
}

