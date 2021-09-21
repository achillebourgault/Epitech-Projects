/*
** EPITECH PROJECT, 2024
** B_OOP_400_LIL_4_1_arcade_achille_bourgault
** File description:
** Created by Achille Bourgault
*/

#ifndef B_OOP_400_LIL_4_1_ARCADE_ACHILLE_BOURGAULT_MenuLogin_HPP
#define B_OOP_400_LIL_4_1_ARCADE_ACHILLE_BOURGAULT_MenuLogin_HPP

#include "../player/Player.hpp"
#include "../interface/GameModule.hpp"
#include "../games/GameHandler.hpp"
#include "../Arcade.hpp"
#include "../interface/AGameModule.hpp"

class MenuLogin : public AGameModule {
    public:
    MenuLogin(Player *p, DisplayHandler *handler);
    ~MenuLogin();
    void drawInputName();
    void initGame() override;
    void drawGame() override;
    int gameLoop(char input, float time, int graphId) override;
    int getScore() override;
    int getId() const;
    void setPlayer(Player *player);
    Player *getPlayer() const;

    private:
    DisplayHandler *_display;
    void setup();
    std::string _name;
    Player *_player;
    int _xPos;
    int _yPos;
    int _id;
    void registerInputsName(char input);
    void connectPlayer();
    GameHandler _currentGameHandler;
};

#endif //B_OOP_400_LIL_4_1_ARCADE_ACHILLE_BOURGAULT_MenuLogin_HPP
