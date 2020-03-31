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
    state = State::patrol;
}

Ennemy::~Ennemy()
{
    delete [] patrolPath;
}

Ennemy& Ennemy::operator=(const Ennemy& rhs)
{
    pos = rhs.pos;
    patrolPos = rhs.patrolPos;
    patrolInc = rhs.patrolInc;
    state = rhs.state;
    length = rhs.length;
    patrolPath = new Vec2[length];

    for(int i = 0; i < length; i++)
    {
        patrolPath[i] = rhs.patrolPath[i];
    }
    return *this;
}

Vec2 Ennemy::getPos() const {
    return pos;
}

int Ennemy::getX() const
{
    return pos.x;
}

int Ennemy::getY() const
{
    return pos.y;
}

void Ennemy::chasePlayer(const Terrain & T, const Player & P) 
{
    int s;
    Vec2* t = Dijkstra(&T, pos, P.getPos(), s);

    if(s > 1)
        pos = t[1];

    delete [] t;
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

void Ennemy::update(const Terrain & T, const Player & P) 
{
    if(state == State::patrol)
        patrol();
    else if(state == State::pursuit)
        chasePlayer(T, P);
    //cout << "pos " << pos.x << " " << pos.y << " " << state << endl;
}

void Ennemy::setState(State s)
{
    state = s;
}

State Ennemy::getState() const
{
    return state;
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
