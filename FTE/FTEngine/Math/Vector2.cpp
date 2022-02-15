#include "Vector2.h"

vector2::vector2(float x, float y)
:x(x),y(y) {}

vector2::vector2(const vector2 &v2)
:x(v2.x), y(v2.y) {}

float vector2::magnitude()
{
    return sqrt(pow(x,2) + pow(y,2));
}

float vector2::dot(const vector2 &v2) const
{
    return (x * v2.x)+(y * v2.y);
}

void vector2::Normalize()
{
    float length = magnitude();
    this->x /= length;
    this->y /= length;
}

vector2 vector2::zero()
{
    return vector2(0,0);
}

vector2 vector2::one()
{
    return vector2(1,1);
}

vector2 vector2::forward()
{
    return vector2(1,0);
}

vector2 vector2::right()
{
    return vector2(0,1);
}

vector2 vector2::operator-(const vector2 &v2)
{
    float rx = x - v2.x;
    float ry = y - v2.y;
    return vector2(rx,ry);
}

vector2 vector2::operator+(const vector2 &v2)
{
    float rx = x + v2.x;
    float ry = y + v2.y;
    return vector2(rx,ry);
}

std::string vector2::ToString()
{
    std::string str = "vector2(" + std::to_string(x) + ", {" + std::to_string(y) + "})";
    return str;
}
