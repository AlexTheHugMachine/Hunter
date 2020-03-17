#include "Vec2.h"

#include <iostream>
using namespace std;

Vec2::Vec2(float x, float y)
:
    x(x),
    y(y)
{
}

Vec2::Vec2()
:
    Vec2(0, 0)
{
}

Vec2::~Vec2()
{
}

Vec2 Vec2::operator+(Vec2 v)
{
    return Vec2(x + v.x, y + v.y);
}

Vec2 Vec2::operator+=(Vec2 v)
{
    x += v.x;
    y += v.y;
    return *this;
}

Vec2 Vec2::operator-(Vec2 v)
{
    return Vec2(x - v.x, y - v.y);
}

Vec2 Vec2::operator*(float a)
{
    return Vec2(x * a, y * a);
}