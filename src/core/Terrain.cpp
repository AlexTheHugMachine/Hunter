#include "Terrain.h"
#include <cassert>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

#define INF 999999

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
    Vec2 pos(0, 2);
    Vec2* t;
    int s;
    //############ DEBUG ONLY!!! ############
    t = getAdjacentPath(pos, s);
    for(int j = 0; j < dimY; ++j)
    {
        cout << "|";
        for(int i = 0; i < dimX; ++i)
        {

            if(arr[dimX * j + i] == Case::wall)
            {
                cout << "#";
            }
            else if(Vec2(i, j).isInTab(t, s)) cout << "0";
            else cout << " ";
        }
        cout << "|" << endl;
    }
    //############ DEBUG ONLY!!! ############
}

/*vector<Vec2>* Terrain::Dijkstra(Vec2 start, Vec2 end)
{
    vector<Node> unvisited, 
                visited;    
    Node nStart = Node{start, 0, nullptr};
    unvisited.push_back(nStart);

    Vec2 pos;
    // Initialize unvisited list
    for(int i = 0; i < dimX; ++i)
    {
        for(int j = 0; j < dimY; ++j)
        {
            pos = Vec2(i, j);
            if(pos == start) unvisited.push_back(nStart);
            else unvisited.push_back(Node{pos, INF, nullptr});
        }
    }

    bool success = false;
    Node cur, n;
    while(!unvisited.empty())
    {
        vector<Node>::iterator it = min_element(unvisited.begin(), unvisited.end());
        int min_i = distance(unvisited.begin(), it);
        cur = unvisited[min_i];     // Visit node with minimum dist to start

        visited.push_back(cur);
        if(cur.coords == end)   // If visit end point, over
        {
            success = true;
            break;
        }

        int size;
        Vec2* neighbors = getAdjacentPath(cur.coords, size);

        

        for(int i = 0; i < size; ++i) // For every neighbor
        {
            n.coords = Vec2(-1, -1);
            for(int j = 0; j < unvisited.size(); j++) // Find node in 
            {
                if(unvisited[j].coords == neighbors[i]) 
                {
                    n = unvisited[i];
                    break;
                }
            }
            if(n.coords != Vec2(-1, -1)) // If neighbor is in unvisited
            {
                int new_d = 1 + cur.dist;
                if(new_d < n.dist) // If found shorter path for neighbor, then update neighbor
                {
                    n.dist = new_d;
                    n.via = &cur;
                }
            }
        }
    }

    vector<Vec2>* path = new vector<Vec2>;
    n = visited.back();
    path->insert(path->begin(), n.coords);
    visited.pop_back();

    while(!visited.empty())
    {
        if(&visited.back() == n.via)
        {
            n = visited.back();
            path->insert(path->begin(), n.coords);
        }
        visited.pop_back();

    }

    return path;




    
}*/
vector<Vec2> Terrain::funtion(int i)
{
    vector<Vec2> v(i);
    return v;
}

Vec2* Terrain::getAdjacent(Vec2 pos, int& size) const
{
    Vec2* arr = new Vec2[8];
    size = 0;
    Vec2 cur;
    for(int i = pos.x - 1; i <= pos.x + 1; ++i)
    {
        for(int j = pos.y - 1; j <= pos.y + 1; ++j)
        {
            cur = Vec2(i, j);
            if(cur != pos && isInTerrain(cur))
            {
                arr[size] = cur;
                size++;
            }
        }
    }
    return arr;
}

Vec2* Terrain::getAdjacentPath(Vec2 pos, int& size) const
{
    int s = size;
    size = 0;
    Vec2* res = getAdjacent(pos, s);
    Vec2* arr = new Vec2[8];
    
    for(int i = 0; i < s; ++i)
    {
        if(getCase(res[i]) == Case::empty)
        {
            arr[size] = res[i];
            size++;
        }
    }
    delete [] res;
    return arr;
}

bool Terrain::isInTerrain(Vec2 pos) const
{
    return pos.x >= 0 &&
            pos.y >= 0 &&
            pos.x < dimX &&
            pos.y < dimY;
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