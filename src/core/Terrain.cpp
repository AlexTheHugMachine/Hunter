#include "Terrain.h"
#include <cassert>
#include <iostream>
#include <fstream>

using namespace std;

Terrain::Terrain(int x, int y)
{
    arr = new Case[x * y];
    dimX = x;
    dimY = y; 
    for(int i = 0; i < dimX; ++i)
    {
        for(int j = 0; j < dimY; ++j)
        {
            arr[dimX * j + i] = Case::empty;
        }
    }
}

Terrain::Terrain(std::string filename)
{
    ifstream file(filename);
    if(file.is_open()){

    cout << "Fichier ouvert" << endl;
    }
    else cout << "Nope" << endl; 
    file >> dimX;
    file >> dimY;

    cout << "dimX " << dimX;
    cout << " dimY " << dimY << endl;

    arr = new Case[dimX * dimY];
    char c;
    int i = 0;
    
    while(!file.eof())
    {
        file.read(&c, 1);
        if(c != '|' && c != '\n'){
            switch (c)
            {
            case '#':
                arr[i] = Case::wall;
                break;
            case ' ':
                arr[i] = Case::empty;
            default:
                break;
            }
            i++;
        }
    }

    file.close();
    draw();
}

Terrain::~Terrain()
{
    delete arr;
    dimX = 0;
    dimY = 0;
}

int Terrain::getDimX() const
{
   return dimX;
}

int Terrain::getDimY() const
{
    return dimY;
}

Vec2 Terrain::getDim() const
{
    return Vec2(dimX, dimY);
}

Case Terrain::getCase(Vec2 v) const
{
    return arr[dimX * (int) v.y + (int) v.x];
}

void Terrain::setCase(Vec2 v, Case c)
{
    assert(v.x >= 0 && v.x < dimX);
    assert(v.y >= 0 && v.y < dimY);
    arr[dimX * (int) v.y + (int) v.x] = c;
}

void Terrain::setCase(int x, int y, Case c)
{
    setCase(Vec2(x, y), c);
}

void Terrain::draw() const
{
    for(int j = 0; j < dimY; ++j)
    {
        cout << "|";
        for(int i = 0; i < dimX; ++i)
        {
            if(arr[dimX * j + i] == Case::wall)
            {
                cout << "#";
            }
            else cout << " ";
        }
        cout << "|" << endl;
    }
}

void Terrain::test() const
{
    Terrain t(2, 2);
    assert(t.getDimX() == t.dimX);
    cout << "getDimX() works" << endl;

    assert(t.getDimY() == t.dimY);
    cout << "getDimY() works" << endl;

    Vec2 dim = t.getDim();
    assert(dim.x == t.dimX && dim.y == t.dimY);
    cout << "getDim() works" << endl;

    assert(t.getCase(Vec2(0, 0)) == arr[6 * dimX + 3]);
    cout << "getCase() works" << endl;

    t.setCase(Vec2(1, 0), Case::wall);
    assert(t.arr[0 * t.dimX + 1] == Case::wall);
    cout << "setCase() works" << endl;

}