#include "Pathfinding.h"
#include <algorithm>
#include <iostream>

using namespace std;

#define INF 999999


Node::Node(Vec2 v, int d, Vec2 n)
{
    coords = v;
    dist = d;
    via = n;
}

void Node::update(Node n)
{
    int new_dist = 1 + n.dist;
    if(new_dist < dist)
    {
        dist = new_dist;
        via = n.coords;
    }
}

UnVisited::UnVisited(Terrain* t, Vec2 start)
{
    int dimX = t->getDimX();
    int dimY = t->getDimY();

    for(int x = 0; x < dimX; ++x)
    {
        for(int y = 0; y < dimY; ++y)
        {
            if(Vec2(x, y) == start)
            {
                arr.push_back(Node(start, 0, Vec2(-1, -1)));
            }
            else
            {
                arr.push_back(Node(Vec2(x, y), INF, Vec2(-1, -1)));
            }
            
        }
    }
}

bool UnVisited::empty()
{
    return arr.empty();
}

int UnVisited::getMinIndex()
{
    int min = arr.front().dist;
    int imin = 0;

    for(unsigned int i = 0; i < arr.size(); ++i)
    {
        if(arr[i].dist < min)
        {
            min = arr[i].dist;
            imin = i;
        }
    }

    return imin;

}

Node UnVisited::extractMin()
{
    int i = getMinIndex();
    Node n = arr[i];
    arr.erase(arr.begin() + i);
    return n;
}

void UnVisited::update(Vec2 coord, Node n)
{
    for(unsigned int i = 0; i < arr.size(); ++i)
    {
        if(arr[i].coords == coord)
        {
            arr[i].update(n);
        }
    }
}

bool UnVisited::exists(Vec2 coord)
{
    bool res = false;
    for(unsigned int i = 0; i < arr.size(); ++i)
    {
        if(arr[i].coords == coord)
        {
            res = true;
            break;
        }
    }
    return res;
}


Visited::Visited(Terrain* ter)
{
    t = ter;
}

void Visited::push(Node n)
{
    arr.push_back(n);
}

Node Visited::pop()
{
    Node n = arr.back();
    arr.pop_back();
    return n;
}

bool Visited::empty()
{
    return arr.empty();
}

Vec2* Visited::getPath(int &s)
{
    /*cout << "Visited coords : " << endl << endl;
    for(int i = 0; i < arr.size(); i++)
    {
        cout << &arr[i] << " " << arr[i].coords.x << " " << arr[i].coords.y << endl;
    }
    cout << endl;*/

    Vec2* a = new Vec2[arr.size()];
    Node node = pop();
    
    // node.coords == end if everything works
    

    a[0] = node.coords;
    s = 1;
    while(!empty())
    {
        Node next = pop();
        if(next.coords == node.via)
        {
            node = next;
            a[s] = node.coords;
            s++;
        }
    }
    
    int i = s - 1;

    Vec2* res = new Vec2[s];

    int count = 0;
    for(; i>=0; --i)
    {
        res[count] = a[i];
        count ++;
    }

    delete [] a;
    a = nullptr;
    return res;

    
}
/* bug : no following path described by "via" => pointers are null?
*/
Vec2* Dijkstra(Terrain* t, Vec2 start, Vec2 end, int& size)
{
    UnVisited UV(t, start);
    Visited V(t);

    bool success = false;
    while(! UV.empty())
    {
        Node N = UV.extractMin();
        V.push(N);

        if(N.coords == end)
        {
            success = true;
            break;
        }

        int s;
        Vec2* tab;
        tab = t->getAdjacentPath(N.coords, s);

        for(int i = 0; i < s; ++i)
        {
            if(UV.exists(tab[i]))
            {
                UV.update(tab[i], N);
            }
        }
    }

    if(success)
    {
        return V.getPath(size);
    }
    cout << "NOPE" << endl;
    return nullptr;
    
}