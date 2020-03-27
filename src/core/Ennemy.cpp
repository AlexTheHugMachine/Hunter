#include "Ennemy.h"

#include <iostream>
#include <cassert>
#include "Pathfinding.h"

using namespace std;

Ennemy::Ennemy(const Terrain *t, Vec2 start, Vec2 end) {
    pos = start;
    patrolPath = Dijkstra(t, start, end, length);
    patrolPos = 0;
    patrolInc = 1;
}

Ennemy::~Ennemy()
{
    delete [] patrolPath;
}

Vec2 Ennemy::getPos() const {
    return pos;
}


void Ennemy::chasePlayer(const Terrain & T, const Player & P) 
{

}

void Ennemy::patrol() 
{
    assert(pos.isInTab(patrolPath, length));
    patrolPos += patrolInc;
    if(patrolPos == length)
    {
        patrolPos -= 2;
        patrolInc *= -1;
    }
    else if(patrolPos < 0)
    {
        patrolPos = 1;
        patrolInc *= -1;
    }
    pos = patrolPath[patrolPos];
}

void Ennemy::update(/*const Terrain & T, const Player & P*/) 
{
    patrol();
}

void Ennemy::test(const Terrain *t) const
{
    Vec2 start(0, 0);
    Vec2 end(9, 4);
    Ennemy e(t, start, end);
    assert(e.pos == start);
    cout << "The constructor works" << endl;

    Vec2 v = e.getPos();
    assert(v == e.pos);
    cout << "The accessor works" << endl;

    cout << "TODO : The chasePlayer() function is not yet implemented !!!" << endl;

    cout << "TODO : The patrol() function is not yet implemented !!!" << endl;

    cout << "TODO : The update() function is not yet implemented !!!" << endl;


}
