/*
** EPITECH PROJECT, 2024
** EKeyboardInputModule.cpp
** File description:
** Created by Leo Fabre
*/
#include <raylib.h>
#include "raylib_encap/Input/EKeyboardInputModule.hpp"

EKeyboardInputModule::~EKeyboardInputModule()
{
}

EKeyboardInputModule::EKeyboardInputModule(PlayerNum num)
{
    switch (num) {
    case PlayerOne:
        SetP1Buttons();
        break;
    case PlayerTwo:
        SetP2Buttons();
        break;
    case PlayerThree:
        SetP3Buttons();
        break;
    case PlayerFour:
        SetP4Buttons();
        break;
    }
}

//region SetButtons

void EKeyboardInputModule::SetP1Buttons()
{
    KeyMap[Accept] = KEY_ENTER;
    KeyMap[Cancel] = KEY_ESCAPE;
    KeyMap[Left] = KEY_LEFT;
    KeyMap[Right] = KEY_RIGHT;
    KeyMap[Up] = KEY_UP;
    KeyMap[Down] = KEY_DOWN;
    KeyMap[DropBomb] = KEY_SPACE;
}

void EKeyboardInputModule::SetP2Buttons()
{
    KeyMap[Accept] = KEY_Q;
    KeyMap[Cancel] = KEY_Z;
    KeyMap[Left] = KEY_A;
    KeyMap[Right] = KEY_D;
    KeyMap[Up] = KEY_W;
    KeyMap[Down] = KEY_S;
    KeyMap[DropBomb] = KEY_E;
}

void EKeyboardInputModule::SetP3Buttons()
{
    KeyMap[Accept] = KEY_R;
    KeyMap[Cancel] = KEY_V;
    KeyMap[Left] = KEY_F;
    KeyMap[Right] = KEY_H;
    KeyMap[Up] = KEY_T;
    KeyMap[Down] = KEY_G;
    KeyMap[DropBomb] = KEY_Y;
}

void EKeyboardInputModule::SetP4Buttons()
{
    KeyMap[Accept] = KEY_U;
    KeyMap[Cancel] = KEY_COMMA;
    KeyMap[Left] = KEY_J;
    KeyMap[Right] = KEY_L;
    KeyMap[Up] = KEY_I;
    KeyMap[Down] = KEY_K;
    KeyMap[DropBomb] = KEY_O;
}
//endregion

bool EKeyboardInputModule::GetButtonDown(Button btn)
{
    return IsKeyDown(KeyMap[btn]);
}

bool EKeyboardInputModule::GetButtonUp(Button btn)
{
    return IsKeyUp(KeyMap[btn]);
}

bool EKeyboardInputModule::GetButtonPressed(Button btn)
{
    return IsKeyPressed(KeyMap[btn]);
}

bool EKeyboardInputModule::GetButtonReleased(Button btn)
{
    return IsKeyReleased(KeyMap[btn]);
}

void EKeyboardInputModule::update()
{
}

