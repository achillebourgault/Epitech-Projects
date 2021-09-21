/*
** EPITECH PROJECT, 2024
** B_OOP_400_LIL_4_1_arcade_achille_bourgault
** File description:
** Created by Frederic Lawecki-Walkowiak
*/

#include "ncurses.hpp"
#include <iostream>

ncurses::ncurses()
{

}

ncurses::~ncurses() {

}

void ncurses::clearScreen()
{
    clear();
}

void ncurses::refreshScreen()
{
    std::tuple<int, int> size = getWindowSize();
    std::string error = "Please augment the size of your terminal";
    if ((std::get<0>(size) <= 130) || (std::get<1>(size) <= 35)) {
        clear();
        drawtext(std::make_tuple(6, 6), 1, error);
    }
    refresh();
}

void ncurses::endScreen()
{
    clrtoeol();
    refresh();
    endwin();
}

std::tuple<int, int> ncurses::getWindowSize()
{
    std::tuple<int, int> size = std::make_tuple(COLS, LINES);
    return size;
}

void ncurses::initScreen()
{
    initscr();
    start_color();
    curs_set(0);
    noecho();
    cbreak();
    keypad(stdscr, TRUE);
    nodelay(stdscr, TRUE);
    _startx = 0;
    _starty = 0;
    win = stdscr;

    resize_term(LINES, COLS);
    if(has_colors() == FALSE)
    {	endwin();
        printf("Your terminal does not support color\n");
        exit(1);
    }
    init_color(COLOR_WHITE, std::get<0>(getNcursesColor(WHITE)), std::get<1>(getNcursesColor(WHITE)), std::get<2>(getNcursesColor(WHITE)));
    init_color(COLOR_BLACK, std::get<0>(getNcursesColor(BLACK)), std::get<1>(getNcursesColor(BLACK)), std::get<2>(getNcursesColor(BLACK)));
    init_color(COLOR_RED, std::get<0>(getNcursesColor(RED)), std::get<1>(getNcursesColor(RED)), std::get<2>(getNcursesColor(RED)));
    init_color(COLOR_GREEN, std::get<0>(getNcursesColor(GREEN)), std::get<1>(getNcursesColor(GREEN)), std::get<2>(getNcursesColor(GREEN)));
    init_color(COLOR_BLUE, std::get<0>(getNcursesColor(BLUE)), std::get<1>(getNcursesColor(BLUE)), std::get<2>(getNcursesColor(BLUE)));
    init_color(COLOR_YELLOW, std::get<0>(getNcursesColor(YELLOW)), std::get<1>(getNcursesColor(YELLOW)), std::get<2>(getNcursesColor(YELLOW)));
    init_color(COLOR_MAGENTA, std::get<0>(getNcursesColor(MAGENTA)), std::get<1>(getNcursesColor(MAGENTA)), std::get<2>(getNcursesColor(MAGENTA)));
    init_color(COLOR_CYAN, std::get<0>(getNcursesColor(CYAN)), std::get<1>(getNcursesColor(CYAN)), std::get<2>(getNcursesColor(CYAN)));
    init_pair(0, COLOR_WHITE, COLOR_BLACK);
    init_pair(1, COLOR_BLACK, COLOR_WHITE);
    init_pair(2, COLOR_WHITE, COLOR_RED);
    init_pair(3, COLOR_WHITE, COLOR_GREEN);
    init_pair(4, COLOR_WHITE, COLOR_BLUE);
    init_pair(5, COLOR_WHITE, COLOR_YELLOW);
    init_pair(6, COLOR_WHITE, COLOR_MAGENTA);
    init_pair(7, COLOR_WHITE, COLOR_CYAN);
    wbkgd(stdscr, COLOR_PAIR(WHITE));
}

void ncurses::drawSquare(std::tuple<float, float> position, std::tuple<int, int> rectSize, int color)
{
    int x = std::get<0>(position) + std::get<0>(getWindowSize()) / 2;
    int y = std::get<1>(position) + std::get<1>(getWindowSize()) / 2;
    int width = std::get<0>(rectSize);
    int height = std::get<1>(rectSize);

    attron(COLOR_PAIR(color));
    for (int ytmp = y; ytmp < height + y; ytmp++) {
        for (int xtmp = x; xtmp < width + x; xtmp++) {
            mvaddch(ytmp, xtmp, ' ');
        }
    }
    attroff(COLOR_PAIR(color));
}

void ncurses::drawtext(std::tuple<int, int> position, float scale, std::string &text)
{
    (void) scale;
    int x = std::get<0>(position) + std::get<0>(getWindowSize()) / 2;
    int y = std::get<1>(position) + std::get<1>(getWindowSize()) / 2;
    mvprintw(y, x, text.c_str());
}

char ncurses::getInput()
{
    int ch = getch();
    if (ch == KEY_ENTER || ch == '\n' || ch == '\r')
        ch = '\r';
    return ch;
}

std::tuple<int, int, int> ncurses::getNcursesColor(int color)
{
    switch (color) {
        case BLACK:
            return std::make_tuple(0,0,0);
        case WHITE:
            return std::make_tuple(255,255,255);
        case RED:
            return std::make_tuple(255,0,0);
        case GREEN:
            return std::make_tuple(9,255,0);
        case BLUE:
            return std::make_tuple(0,60,255);
        case YELLOW:
            return std::make_tuple(255,255,0);
        case MAGENTA:
            return std::make_tuple(255,0,213);
        case CYAN:
            return std::make_tuple(0,255,255);
        case TRANSPARENT:
            return std::make_tuple(255,255,255);
        case GREY:
            return std::make_tuple(164,164,164);
        default:
            return std::make_tuple(0,0,0);
    }
}

extern "C" IDisplayModule *create_object() {
    return new ncurses;
}

extern "C" void destroy_object(IDisplayModule *m) {
    delete m;
}