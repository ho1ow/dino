#ifndef VECTOR_H    
#define VECTOR_H

#include <cmath>
#include <iostream>
struct Vector
{
    int x, y;

    inline Vector(int x, int y)
    {
        this->x = x;
        this->y = y;
    };

    inline Vector() : Vector(0, 0)
    {
    }

    Vector operator+(const Vector &other) const
    {
        return {this->x + other.x, this->y + other.y};
    }

    Vector operator-(const Vector &other) const
    {
        return {this->x - other.x, this->y - other.y};
    }

    Vector operator*(float number) const
    {
        return {static_cast<int>(this->x * number),
                static_cast<int>(this->y * number)};
    }
    static float distance(const Vector &v1, const Vector &v2)
    {
        return sqrt(pow(v2.x - v1.x, 2) + pow(v2.y - v1.y, 2));
    }
};

#endif
