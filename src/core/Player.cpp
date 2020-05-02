#include "Player.h"
#include "Vec2.h"

#include <assert.h>
#include <iostream>
using namespace std;

Player::Player()
{
    pos = Vec2(0, 0);
}

Player::Player(Vec2 p)
{
    pos = p;
}

Player::~Player()
{

}

Vec2 Player::getPos() const
{
    return pos;
}

int Player::getX() const
{
    return pos.x;
}

int Player::getY() const
{
    return pos.y;
}

void Player::move(const Terrain& t, Direction D)
{
    switch (D)
    {
    case Direction::left:
        if(t.isTerrainPath(pos - Vec2(1, 0))) pos = pos - Vec2(1, 0);
        break;

    case Direction::right:
        if(t.isTerrainPath(pos + Vec2(1, 0))) pos = pos + Vec2(1, 0);
        break;

    case Direction::up:
        if(t.isTerrainPath(pos - Vec2(0, 1))) pos = pos - Vec2(0, 1);
        break;

    case Direction::down:
        if(t.isTerrainPath(pos + Vec2(0, 1))) pos = pos + Vec2(0, 1);
        break;
    
    default:
        break;
    }
}

void Player::setPos(Vec2 p)
{
    pos = p;
}

void Player::test() const
{
    Player p;
    assert(p.pos == Vec2(0, 0));
    cout << "Constructor works" << endl;

    assert(p.getPos() == p.pos);
    cout << "The accessor works" << endl;

    Vec2 v(5, 5);
    p.setPos(v);
    assert(p.pos == v);
    cout << "The mutator works" << endl;
}