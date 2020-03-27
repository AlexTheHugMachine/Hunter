#include "Game.h"

#define NB_E 2

Game::Game()
{
    p = Player();
    t = Terrain("data/test.txt");
    NbE = NB_E;
    E = new Ennemy[NbE];
    E[0] = Ennemy(&t, Vec2(9, 0), Vec2(0, 0));
    E[0] = Ennemy(&t, Vec2(9, 1), Vec2(0, 1));
}

Game::~Game()
{
    delete [] E;
}

void Game::UpdateGame(Direction d)
{
    p.move(t, d);
    Vec2 PPos = p.getPos();

    for(int i = 0; i < NbE; ++i)
    {
        if(E[i].getState() != State::dead)
        {
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
            }
            
        }
    }
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
        //if(E[i].getState() != State::dead)
        {
            r[i] = E[i].getPos();
            s++;
        }
    }
    return r;
}

Case* Game::getTerrain(Vec2& dim) const
{
    return t.getTerrain(dim);
}