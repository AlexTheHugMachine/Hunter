#include "Vec2.h"

#include <iostream>
#include <math.h>
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

float Vec2::norm() const
{
    return sqrt(x*x + y*y);
}

bool Vec2::operator!=(const Vec2& rhs)
{
    return x != rhs.x ||
            y != rhs.y;
}

bool Vec2::operator==(const Vec2& rhs)
{
    return x == rhs.x &&
            y == rhs.y;
}

bool Vec2::isInTab(Vec2* t, int size) const
{
    for(int i = 0; i < size; ++i)
    {
        if(t[i] == *this)
        {
            return true;
        }
    }
    return false;
}

void Vec2::print() const
{
    cout << "x = " << x << ", y = " << y << endl;
}