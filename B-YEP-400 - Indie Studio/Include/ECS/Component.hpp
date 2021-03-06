/*
** EPITECH PROJECT, 2024
** Component.hpp
** File description:
** Created by Leo Fabre
*/
#ifndef COMPONENT_HPP
#define COMPONENT_HPP

#include "Ecs.hpp"
class AssetLoader;
class Component {
public:
    Entity *entity;
    virtual void init() {}
    virtual void update() {}
    virtual void draw() {}
    virtual ~Component() {}
};

ComponentID getNewComponentTypeID()
{
    static ComponentID lastID = 0;
    return lastID++;
}

#endif //COMPONENT_HPP