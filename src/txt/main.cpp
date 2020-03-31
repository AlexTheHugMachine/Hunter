#include <iostream>
#include "Game.h"
#include "WinTxt.h"
#include <unistd.h>

using namespace std;


int main(void)
{ 
    termClear();
    Game g("data/Config.txt");
    //Game g;
    

    Vec2 p;
    Vec2* e;
    int nbE;
    Terrain ter  = g.getTerrain();
    char c;
    Direction dir = Direction::none;
    
    WinTXT win(ter.getDimX(), ter.getDimY());
    win.clear(' ');
    bool stop = false;
    bool won = false;
    while(!stop  && !won)
    {
        p = g.getPlayerPos();
        e = g.getEnnemiesPosition(nbE);
        //cout << "main : " << endl;

       // for(int i = 0; i < nbE)
        ter = g.getTerrain();
        
        win.clear();
        for(int j = 0; j < ter.getDimY(); ++j)
        {
            //cout << "|";
            for(int i = 0; i < ter.getDimX(); ++i)
            {
                if(Vec2(i, j).isInTab(e, nbE))
                {
                    win.print(i, j, 'E');
                    //cout << "E";
                }
                else if(Vec2(i, j) == p)
                {
                    win.print(i, j, 'P');
                    //cout << "P";
                }
                else if(ter.getCase(Vec2(i, j)) == Case::wall)
                {
                    win.print(i, j, '#');
                    cout << "#";
                }
                else win.print(i, j, ' '); //cout << " ";
            }
            //cout << "|" << endl;
        }
        win.draw();
        usleep(500000);
        //cin>>c;
        c = win.getCh();
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
                dir = Direction::none;
                break;
        }
        
        won = g.UpdateGame(dir);
        delete [] e;
    }

    if(won)
    {
        cout << "You win!!!" << endl << endl;
        win.pause();
    }
    termClear();
   
    return EXIT_SUCCESS;
    
}