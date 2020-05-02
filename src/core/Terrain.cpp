#include "Terrain.h"
#include <cassert>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <Pathfinding.h>

using namespace std;


Terrain::Terrain(int x, int y)
{
    dimX = x;
    dimY = y; 
    arr = new Case[x * y];
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

    //cout << "Fichier ouvert" << endl;
    }
    else cout << "Nope" << endl; 
    file >> dimX;
    file >> dimY;

    //cout << "dimX " << dimX;
    //cout << " dimY " << dimY << endl << endl;

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
                break;
            case 'S':
                arr[i] = Case::start;
                start = Vec2(i % dimX, i / dimX);
                break;
            case 'E':
                arr[i] = Case::end;
                break;
            default:
                break;
            }
            i++;
        }
    }

    file.close();
}

Terrain::~Terrain()
{
    // cout<< "Destroy terrain" << endl;
    delete [] arr;
    arr = nullptr;
    dimX = 0;
    dimY = 0;
    // cout<< "Destroyed terrain" << endl;
}

Terrain Terrain::operator=(const Terrain& rhs)
{
    Terrain t;
    t.dimX = rhs.dimX;
    t.dimY = rhs.dimY;
    t.arr = new Case[dimX * dimY];
    for(int i = 0; i < dimX * dimY; i++)
    {
        t.arr[i] = rhs.arr[i]; 
    }

    return t;
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

Vec2 Terrain::getDim(int x, int y) const 
{
    return Vec2(x, y);
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

Case* Terrain::getTerrain(Vec2& dim) const
{
    dim = getDim();
    return arr;
}

bool Terrain::isInTerrain(Vec2 v) const
{
    return v.x >= 0 && v.y >= 0 &&
            v.x < dimX && v.y < dimY;
}

bool Terrain::isTerrainPath(Vec2 v) const
{
    return isInTerrain(v) && getCase(v) == Case::empty;
    
}

void Terrain::draw() 
{
    //############ DEBUG ONLY!!! ############
    /*Vec2 start(0, 0);
    Vec2 end(9, 4);
    int s;
    Vec2* p = Dijkstra(this, start, end, s);*/

    for(int j = 0; j < dimY; ++j)
    {
        cout << "|";
        for(int i = 0; i < dimX; ++i)
        {

            if(arr[dimX * j + i] == Case::wall)
            {
                cout << "#";
            }
            //else if(Vec2(i, j).isInTab(p, s)) cout << "0";
            else cout << " ";
        }
        cout << "|" << endl;
    }
    //############ DEBUG ONLY!!! ############
    //delete [] p;
}

Vec2* Terrain::getAdjacent(Vec2 pos, int& size) const
{
    Vec2* A = new Vec2[4]; //Set to 8 to show diagonal tiles
    size = 0;
    Vec2 cur;

    cur = pos - Vec2(1, 0);
    if(isInTerrain(cur)) 
    {
        A[size] = cur;
        size++;
    }

    cur = pos + Vec2(1, 0);
    if(isInTerrain(cur)) 
    {
        A[size] = cur;
        size++;
    }
    
    cur = pos - Vec2(0, 1);
    if(isInTerrain(cur)) 
    {
        A[size] = cur;
        size++;
    }
    
    cur = pos + Vec2(0, 1);
    if(isInTerrain(cur)) 
    {
        A[size] = cur;
        size++;
    }
    
/*
     //To show diagonal tiles
    for(int i = pos.x - 1; i <= pos.x + 1; ++i)
    {
        for(int j = pos.y - 1; j <= pos.y + 1; ++j)
        {
            cur = Vec2(i, j);
            if(cur != pos && isInTerrain(cur))
            {
                A[size] = cur;
                size++;
            }
        }
    }*/

    return A;
}

Vec2* Terrain::getAdjacentPath(Vec2 pos, int& size) const
{
    int s = size;
    size = 0;
    Vec2* res = getAdjacent(pos, s);
    Vec2* A = new Vec2[8];
    
    for(int i = 0; i < s; ++i)
    {
        if(getCase(res[i]) == Case::empty)
        {
            A[size] = res[i];
            size++;
        }
    }
    delete [] res;
    return A;
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