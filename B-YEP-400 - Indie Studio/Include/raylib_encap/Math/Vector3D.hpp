/*
** EPITECH PROJECT, 2024
** Vector3D.hpp
** File description:
** Created by Leo Fabre
*/
#ifndef VECTOR3D_HPP
#define VECTOR3D_HPP

#include <raylib.h>
#include <ostream>
#include "Vector2D.hpp"

class Vector3D : public Vector3 {
public:
    Vector3D(float x, float y, float z);
    Vector3D(const Vector2D &Vec);
    Vector3D();
    ~Vector3D();

    template<class Archive>
    void serialize(Archive &ar, const unsigned int version)
    {
        ar & x & y & z;
    }

    //region Static values
    static Vector3D Zero()
    {
        return Vector3D(0, 0, 0);
    }

    static Vector3D One()
    {
        return Vector3D(1, 1, 1);
    }

    static Vector3D Up()
    {
        return Vector3D(0, -1, 0);
    }

    static Vector3D Forward()
    {
        return Vector3D(0, -1, 0);
    }

    static Vector3D Right()
    {
        return Vector3D(1, 0, 0);
    }
    //endregion

    //region Operators

    Vector3D &Add(const Vector3D &vec);
    Vector3D &Subtract(const Vector3D &vec);
    Vector3D &Divide(const Vector3D &vec);
    Vector3D &Multiply(const Vector3D &vec);
    Vector3D &Clamp(float maxMagnitude);

    friend Vector3D &operator+(Vector3D &v1, const Vector3D &v2);
    friend Vector3D &operator-(Vector3D &v1, const Vector3D &v2);
    friend Vector3D &operator-(Vector3D &v1, const Vector3D &v2);
    friend Vector3D &operator/(Vector3D &v1, const Vector3D &v2);
    friend Vector3D &operator*(Vector3D &v1, const Vector3D &v2);

    Vector3D &operator+=(const Vector3D &vec);
    Vector3D &operator-=(const Vector3D &vec);
    Vector3D &operator/=(const Vector3D &vec);
    Vector3D &operator*=(const Vector3D &vec);
    Vector3D &operator*=(float factor);

    bool operator==(Vector3D other);
    bool operator!=(Vector3D other);

    friend std::ostream &operator<<(std::ostream &os, const Vector3D &d);
    //endregion
    Vector3D &Multiply(float factor);
    static Vector3D getNearestBlockPos(Vector3D pos);
};

#endif //VECTOR3D_HPP