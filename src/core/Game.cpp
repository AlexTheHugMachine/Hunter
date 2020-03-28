#include "Game.h"
#include <iostream>
using namespace std;

#define NB_E 2

Game::Game()
{
    p = Player();
    t = Terrain("data/test.txt");
    NbE = NB_E;
    E = new Ennemy[NbE];
    E[0] = Ennemy(&t, Vec2(9, 0), Vec2(0, 0));
     
   
    E[1] = Ennemy(&t, Vec2(9, 4), Vec2(0, 4));
   
    
}

Game::~Game()
{
   delete [] E;
}

bool Game::UpdateGame(Direction d)
{
    p.move(t, d);
    Vec2 PPos = p.getPos();

    bool over = false;
    int count = 0;
    for(int i = 0; i < NbE; ++i)
    {
        if(E[i].getState() != State::dead)
        {
            count++;
            E[i].update(t, p);
            Vec2 EPos = E[i].getPos();

            if(PPos == EPos)
            {
                E[i].setState(State::dead);
            }
            else
            {
                int s;
                Vec2* tiles = t.getAdjacentPath(EPos, s);
                for(int j = 0; j < s; ++j)
                {
                    if(PPos == tiles[j])
                    {
                        E[i].setState(State::pursuit);
                    }
                } 
                delete [] tiles;
            }
            
        }
    }
    if(count == 0)
        over = true;
    
    return over;
   
}

Vec2 Game::getPlayerPos() const
{
    return p.getPos();
}

Vec2* Game::getEnnemiesPosition(int& s) const
{
    Vec2* r = new Vec2[NbE];
    s = 0;
    for(int i = 0; i < NbE; ++i)
    {
        if(E[i].getState() != State::dead)
        {
            r[i] = E[i].getPos();
            s++;
        }
    }
    return r;
}

Terrain& Game::getTerrain()
{
    return t;
}