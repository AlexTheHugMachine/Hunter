#include "Pathfinding.h"
#include <algorithm>
#include <iostream>

using namespace std;


Node::Node(Vec2 v, int d, Node* n)
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
        via = &n;
    }
}

/*Vec2* Dijkstra(Vec2 start, Vec2 end, int & size)
{
    cout << "Start (" << start.x << ", " << start.y << ")" << endl;
    cout << "End (" << end.x << ", " << end.y << ")" << endl;


    vector<Node> unvisited, 
                visited;    
    Node nStart = Node{start, 0, nullptr};
    Node cur, n;

    unvisited.push_back(nStart);

    Vec2 pos;
    // Initialize unvisited list
    for(int i = 0; i < dimX; ++i)
    {
        for(int j = 0; j < dimY; ++j)
        {
            pos = Vec2(i, j);
            if(pos == start) 
            {
                unvisited.push_back(nStart);
                
            }
            else 
            {
                //cout << pos.x << " " << pos.y << endl;
                unvisited.push_back(Node{pos, INF, nullptr});
            }
        }
    }

    cout << "Unvisited list initialized" << endl;

    
    while(!unvisited.empty())
    {
        vector<Node>::iterator it = min_element(unvisited.begin(), unvisited.end());
        int min_i = distance(unvisited.begin(), it);
        cur = unvisited[min_i];     // Visit node with minimum dist to start

        visited.push_back(cur);
        unvisited.erase(it);

//if(cur.via != nullptr)
        cout << "Visited (" << cur.coords.x << ", " << cur.coords.y << ") via " << cur.dist /*<< " " << cur.via->coords.y<< endl;
        
        if(cur.coords == end)   // If visit end point, over
        {
            
            break;
        }

        int size;
        Vec2* neighbors = getAdjacentPath(cur.coords, size);

        cout << "Neighb : " <<cur.coords.x << " " << cur.coords.y << endl;

        

        for(int i = 0; i < size; ++i) // For every neighbor
        {
            cout << neighbors[i].x << " " << neighbors[i].y << endl;
            n.coords = Vec2(-1, -1);
            for(unsigned int j = 0; j < unvisited.size(); j++) // Find node in unvisited
            {
                if(unvisited[j].coords == neighbors[i]) 
                {
                    n = unvisited[j];
                    //break;
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

    cout << "Exited (" << cur.coords.x << ", " << cur.coords.y << ") via " << cur.dist << endl;

    vector<Vec2>* path = new vector<Vec2>;
    n = visited.back();
    path->push_back(n.coords);
    visited.pop_back();

    while(!(visited.empty()))
    {

        //cout << visited.back().coords.x << " " << visited.back().coords.y << " " << visited.back().dist << endl;
        if(&visited.back() == n.via)
        {
            n = visited.back();
            path->push_back(n.coords);
        }
        visited.pop_back();

    }


    size = path->size();
    Vec2* res = new Vec2[size];
    for(int i = 0; i < size; ++i)
    {
        res[i] = path->back();
        //cout << res[i].x << " " << res[i].y << endl;
        path->pop_back();
    }
    return res;
    
}*/