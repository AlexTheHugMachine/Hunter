#include "Game.h"
#include <iostream>
#include <fstream>
using namespace std;

#define NB_E 2

Game::Game()
: t("data/test.txt")
{
    p = Player(t.start);
    // cout<< "coucou" << endl; 
    // t = Terrain("data/test.txt");
    NbE = NB_E;
    E = new Ennemy[NbE];
    E[0] = Ennemy(&t, Vec2(9, 0), Vec2(0, 0));
     
   
    E[1] = Ennemy(&t, Vec2(9, 4), Vec2(0, 4));
   
    
}

Game::Game(std::string filename)
{
    ifstream file(filename);

    string terrain;
    Vec2 start, end;

    if(file.is_open())
    {
        file >> terrain;
        t = Terrain(terrain);
        p = Player();
        file >> NbE;
        E = new Ennemy[NbE];
        for(int i = 0; i < NbE; i++)
        {
            file >> start.x;
            file >> start.y;
            file >> end.x;
            file >> end.y;
            E[i] = Ennemy(&t, start, end);
        }
    }
}

Game::~Game()
{
   delete [] E;
   E = nullptr;
   // cout << "Game destructor" << endl;
}

GameState Game::UpdateGame(Direction d)
{
    p.move(t, d);
    Vec2 PPos = p.getPos();

    GameState state = GameState::running;

    //int count = 0;
    //cout << "UpdateGame : " << endl;
    for(int i = 0; i < NbE; ++i)
    {
        //cout << i << " : " << E[i].pos.x << " " << E[i].pos.y << endl;
    //   if(E[i].getState() != State::dead)
      //  {
            //cout << i << " : " << E[i].pos.x << " " << E[i].pos.y << endl;
           // count++;
            E[i].update(t, p);
            Vec2 EPos = E[i].getPos();

            if(PPos == EPos)
            {
                //E[i].setState(State::dead);
                state = GameState::lose;
                break;
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
            
        //}
    }
    if(t.getCase(PPos) == Case::end)
        state = GameState::win;
        
    return state;
   
}

Vec2 Game::getPlayerPos() const
{
    return p.getPos();
}

Vec2* Game::getEnnemiesPosition(int& s) const
{
    //cout << "GetEnPos" << endl;
    Vec2* r = new Vec2[NbE];
    s = 0;
    for(int i = 0; i < NbE; ++i)
    {
        if(E[i].getState() != State::dead)
        {
            r[s] = E[i].getPos();
            //cout << i << " : " << r[s].x << " " << r[s].y << endl;
            s++;
        }
    }
    return r;
}

const Terrain& Game::getTerrain()
{
    return t;
}