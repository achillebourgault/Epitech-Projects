/*
** EPITECH PROJECT, 2024
** B_OOP_400_LIL_4_1_arcade_achille_bourgault
** File description:
** Created by Achille Bourgault
*/

#ifndef B_OOP_400_LIL_4_1_ARCADE_ACHILLE_BOURGAULT_MAINMENU_HPP
#define B_OOP_400_LIL_4_1_ARCADE_ACHILLE_BOURGAULT_MAINMENU_HPP

#include "../player/Player.hpp"
#include "../interface/GameModule.hpp"
#include "../games/GameHandler.hpp"
#include "../Arcade.hpp"
#include "../interface/AGameModule.hpp"

#define STATE_CATALOG 0
#define STATE_GAME_LAUNCHED 1

class MainMenu : public AGameModule {
    public:
    MainMenu(Player *p, DisplayHandler *handler);
    ~MainMenu();
    void drawGraphicsLibs();
    void drawScores();
    void drawInputName();
    void initGame() override;
    void drawGame() override;
    int gameLoop(char input, float time, int graphId) override;
    std::vector<std::string> getGameLibsAvailible();
    std::vector<std::string> getGraphicsLibsAvailible();
    int getScore() override;
    int getId() const;

    private:
    DisplayHandler *_display;

    void setup();
    std::string _name;
    Player *_player;
public:
    void setPlayer(Player *player);

public:
    Player *getPlayer() const;

private:
    bool _isConnected;
    int _xPos;
    int _yPos;
    int _id;

    void registerInputsName(char input);
    void connectPlayer();
    GameHandler _currentGameHandler;
    int registerInputsMenu(char input);
    void drawMenu();
};

#endif //B_OOP_400_LIL_4_1_ARCADE_ACHILLE_BOURGAULT_MAINMENU_HPP
