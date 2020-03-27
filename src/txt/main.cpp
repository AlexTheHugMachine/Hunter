#include <iostream>
#include "Terrain.h"
#include "Ennemy.h"

using namespace std;


int main(void)
{ 
    Terrain ter("data/test.txt");

    Vec2 start(0, 0);
    Vec2 end(9, 4);
    Ennemy e(&ter, start, end);
    
    while(1)
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
                else if(Vec2(i, j) == e.getPos()) cout << "0";
                else cout << " ";
            }
            cout << "|" << endl;
        }
        cout << endl;
        cin.get();

        e.update();
    }
    return EXIT_SUCCESS;
}

/* 
TODO : Ennemy and player movement
*/