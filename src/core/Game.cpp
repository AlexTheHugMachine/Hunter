#include "Game.h"

Game::Game(int n)
{
    p = Player();
    t = Terrain("data/test.txt");
    NbE = n;
    E = new Ennemy[n];
    for(int i = 0; i < NbE; ++i)
    {
        E[i] = Ennemy(&t, Vec2(9, i), Vec2(0, i)); //Careful, not more than 5 ennemies with this initialization
    }
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