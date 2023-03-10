#include <iostream>
#include "Game.h"
#include "WinTxt.h"
#include <unistd.h>
#include "txtGame.h"

using namespace std;

void txtGame::txtmain()
{
    termClear();
    Game g;

    Vec2 p;
    Vec2 *e;
    int nbE;
    Terrain t = g.getTerrain();
    char c;
    Direction dir = Direction::none;

    WinTXT win(t.getDimX(), t.getDimY());
    win.clear(' ');
    bool stop = false;
    bool won = false;
    bool lose = false;

    t = g.getTerrain();
    while (!stop)
    {
        p = g.getPlayerPos();
        e = g.getEnnemiesPosition(nbE);
        //cout << "main : " << endl;

        // for(int i = 0; i < nbE)

        win.clear();
        for (int j = 0; j < t.getDimY(); ++j)
        {
            //cout << "|";
            for (int i = 0; i < t.getDimX(); ++i)
            {
                if (Vec2(i, j).isInTab(e, nbE))
                {
                    win.print(i, j, 'E');
                    //cout << "E";
                }
                else if (Vec2(i, j) == p)
                {
                    win.print(i, j, 'P');
                    //cout << "P";
                }
                else if (t.getCase(Vec2(i, j)) == Case::wall)
                {
                    win.print(i, j, '#');
                    //cout << "#";
                }
                else if (t.getCase(Vec2(i, j)) == Case::end)
                {
                    win.print(i, j, 'O');
                }
                else
                    win.print(i, j, ' '); //cout << " ";
            }
            //cout << "|" << endl;
        }
        win.draw();
        usleep(200000);
        //cin>>c;
        c = win.getCh();
        switch (c)
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
        GameState state = g.UpdateGame(dir);
        if(state == GameState::win) {
            won = true;
            break;
        };

        if(state == GameState::lose) {
            lose = true;
            break;
        }

        delete[] e;
    }

    if (won)
    {
        //win.clear();
        //win.print(2, 2, "You Win!");
        cout << "You win!!!" << endl;
        win.pause();
    }
    if (lose)
    {
        //win.clear();
        //win.print(2, 2, "You Win!");
        cout << "You lose :-(" << endl;
        win.pause();
    }
    //termClear();
}
