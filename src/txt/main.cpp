#include <iostream>
#include "Terrain.h"
#include "Game.h"

using namespace std;


int main(void)
{ 

    Game g(2);
    
    /*
    Terrain ter("data/test.txt");

    Vec2 start(0, 1);
    Vec2 end(9, 4);
    Ennemy e(&ter, start, end);
    Player p;
    
    bool stop = false;
    while(!stop)
    {
        for(int j = 0; j < ter.getDimY(); ++j)
        {
            cout << "|";
            for(int i = 0; i < ter.getDimX(); ++i)
            {

                if(ter.getCase(Vec2(i, j)) == Case::wall)
                {
                    cout << "#";
                }
                else if(Vec2(i, j) == e.getPos()) cout << "E";
                else if(Vec2(i, j) == p.getPos()) cout << "P";
                else cout << " ";
            }
            cout << "|" << endl;
        }
        cout << endl;
        char c;
        cin>>c;

        Direction dir;
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
            case 'x':
                dir = Direction::none;
                stop = true;
                break;
            default:
                dir = Direction::none;
        }
        p.move(ter, dir);

        e.update(ter, p);
    }
    
    */

    return EXIT_SUCCESS;
}

/* 
TODO : Ennemy and player movement
*/