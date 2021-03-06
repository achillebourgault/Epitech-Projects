/*
** EPITECH PROJECT, 2024
** bomberman
** File description:
** Created by Achille Bourgault
*/

#ifndef BOMBCOMP
#define BOMBCOMP

#include <3D/TransformComp.hpp>
#include <3D/BasicCubeComp.hpp>
#include "Component.hpp"
#include <ctime>
#include <3D/ModelComp.hpp>
#include <Character/PlayerComp.hpp>
#include "raylib_encap/ESound.hpp"

class BombComp : public Component {
public:
    BombComp(Colors color, PlayerComp *owner);
    void init() override;
    void update() override;
private:
    void explode();
    std::time_t spawnTime;
    TransformComp *_transform;
    ModelComp *model;
    Colors _color;
    std::vector<Entity *> particles;
    PlayerComp *_owner;
public:
    PlayerComp *getOwner() const;
private:
    ECube collider;
    enum Way {Left, Down, Up, Right};
private:
    void GenerateParticles(int definitive_spread);
    bool SpawnParticle(Vector3D &pos);
    bool particlesCleared;
    void checkPlayer(Vector3D pos);
    bool checkWall(Vector3D pos);
    bool checkObstacle(Vector3D pos);
    void spreadExplosion(Way way, int i);
public:
    int spread;
    bool hasExploded;
    const ECube &getCube() const;
    float _curParticleScale;
    float _baseParticleSize;
    clock_t _particleStartTime;
    clock_t _bombSpawnTime;
    void checkPowerup(Vector3D &pos);
    void checkBomb(Vector3D &pos);
    float timeAlive;
    PauseMenuComp *_pmc;
    void spawnRandomPowerup(Vector3D &pos);
};

#endif //BOMBERMAN_BOMBCOMP_HPP
