#include <iostream>
#include "Game.h"

using namespace std;


int main(void)
{ 
    
    Game g;

    Vec2 p;
    Vec2* e;
    int nbE;
    Terrain t;
    char c;
    Direction dir = Direction::none;
    
    bool stop = false;
    bool won = false;
    while(!stop  && !won)
    {
        p = g.getPlayerPos();
        e = g.getEnnemiesPosition(nbE);
        t = g.getTerrain();

        for(int j = 0; j < t.getDimY(); ++j)
        {
            cout << "|";
            for(int i = 0; i < t.getDimX(); ++i)
            {
                if(Vec2(i, j).isInTab(e, nbE))
                {
                    cout << "E";
                }
                else if(Vec2(i, j) == p)
                {
                    cout << "P";
                }
                else if(t.getCase(Vec2(i, j)) == Case::wall)
                {
                    cout << "#";
                }
                else cout << " ";
            }
            cout << "|" << endl;
        }

        cin>>c;

        switch(c)
        {
            case 'z':
                dir = Direction::up;
                break;
            case 's': 
                dir = Direction::down;
                break;
            case 'q':
                dir = Direction::left;
                break;
            case 'd':
                dir = Direction::right;
                break;
            case 'x':
                stop = true;
                break;
            default:
                break;
        }
        
        won = g.UpdateGame(dir);
    }
    delete [] e;

    if(won)
    {
        cout << "You win!!!" << endl;
    }
   
    return EXIT_SUCCESS;
    
}