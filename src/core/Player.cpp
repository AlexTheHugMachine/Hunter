#include "Player.h"

#include <iostream>
#include <assert.h>
using namespace std;

Player::Player() {
    pos.x = 0;
    pos.y = 0;
}

Player::~Player()
{
}

Vec2 Player::getPos() const {
    return pos;
}

void Player::move(Terrain T, Direction D) {

}

void Player::setPos(Vec2 V) {
    pos.x = V.x;
    pos.y = V.y;
}

void Player::test() const
{
    Player p;
    assert(p.pos.x == 0 && p.pos.y == 0);
    cout << "The constructor works" << endl;

    Vec2 v = p.getPos();
    assert(v.x == p.pos.x && v.y == p.pos.y);
    cout << "The getPos() accessor works" << endl;

    v = Vec2(5., 9.);
    p.setPos(v);
    assert(p.pos.x == v.x && p.pos.y == v.y);
    cout << "The setPos() mutator works" << endl;

    cout << "The move() function is not implemented yet!!" << endl;
    
}