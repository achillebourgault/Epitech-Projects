/*
** EPITECH PROJECT, 2024
** AssetLoader.hpp
** File description:
** Created by Leo Fabre
*/
#ifndef ASSETLOADER_HPP
#define ASSETLOADER_HPP

#include <raylib_encap/EModel.hpp>
#include <raylib_encap/EAnimatedModel.hpp>
#include <Component.hpp>
#include <raylib_encap/ESound.hpp>
#include <raylib_encap/EMusic.hpp>
#include "../../Source/Components/EFramesModel.hpp"

class AssetLoader : public Component {
public:
    void init() override;
    AssetLoader();
    ~AssetLoader();
    EModel PlayerModel;
    EModel StoneCubeModel;
    EModel BombModel;
    EModel ObstacleModel;
    EModel ExplosionModel;
    EAnimatedModel ExplosionAnim;
    EModel FloorModel;
    //Powerups
    EModel FullFireModel;
    EModel BombUpModel;
    EModel SkateModel;
    EModel SoftBlockPassModel;
    EModel FireUpModel;
    //Sound
    ESound ExplosionSound;
    EMusic WalkingSound;
    ESound PowerupPickUp;
    ESound PowerupGenerated;
    ESound PlayerHurt;
    float Volume;
    ESound PlayerDead;
    ESound ButtonClick;
    ESound addScore;
    //Textures
    ESprite FullFireSprite;
    ESprite BombUpSprite;
    ESprite SkateSprite;
    ESprite SoftBlockPassSprite;
    ESprite FireUpSprite;
    ESprite MainLogo;

    //Menu
    ESprite MenuASprite;
    ESprite MenuBSprite;
    ESprite MenuCSprite;
    ESprite MenuDSprite;
    ESprite MenuESprite;
    bool loadGame;

    EFramesModel playerWalking;
};

#endif //ASSETLOADER_HPP