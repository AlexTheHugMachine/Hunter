#include "Ennemy.h"

#include <iostream>
#include <cassert>

using namespace std;

Ennemy::Ennemy() {
    pos.x = 1.;
    pos.y = 1.;
}

Ennemy::~Ennemy()
{
}

Vec2 Ennemy::getPos() const {
    return pos;
}


void Ennemy::chasePlayer(const Terrain & T, const Player & P) 
{

}

void Ennemy::patrol(const Terrain & T) 
{

}

void Ennemy::update(const Terrain & T, const Player & P) 
{

}

void Ennemy::test() const
{
    Ennemy e;
    assert(e.pos.x == 1. && e.pos.y == 1.);
    cout << "The constructor works" << endl;

    Vec2 v = e.getPos();
    assert(v.x == e.pos.x && v.y == e.pos.y);
    cout << "The accessor works" << endl;

    cout << "TODO : The chasePlayer() function is not yet implemented !!!" << endl;

    cout << "TODO : The patrol() function is not yet implemented !!!" << endl;

    cout << "TODO : The update() function is not yet implemented !!!" << endl;


}
