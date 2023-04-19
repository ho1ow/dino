#ifndef VECTOR2_H
#define VECTOR2_H
#include "../commonVar.h"
struct Vector2
{
    int x, y;

    inline Vector2(int x, int y)
    {
        this->x = x;
        this->y = y;
    };

    inline Vector2() : Vector2(0, 0)
    {
    }

    Vector2 operator+(const Vector2 &other) const
    {
        return {this->x + other.x, this->y + other.y};
    }

    Vector2 operator-(const Vector2 &other) const
    {
        return {this->x - other.x, this->y - other.y};
    }

    Vector2 operator*(float number) const
    {
        return {static_cast<int>(this->x * number),
                static_cast<int>(this->y * number)};
    }
    static float distance(const Vector2 &v1, const Vector2 &v2)
    {
        return sqrt(pow(v2.x - v1.x, 2) + pow(v2.y - v1.y, 2));
    }
};

#endif
