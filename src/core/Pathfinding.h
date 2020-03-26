#ifndef PATH_H
#define PATH_H

#include "Vec2.h"
#include <vector>
#include "Terrain.h"

using namespace std;

/** @brief Node class used by the pathfinding algorithm
 */
class Node
{
public:
    Vec2 coords; ///< Coordinates in the grid
    //int heur;    ///< Heuristic : distance to end Node
    //int cost;   ///< Total cost of the path to the node
    int dist;   ///< Distance to starting Node
    Node* via; ///< Current path via

public:

    Node() = default;
    Node(Vec2 v, int d, Node* n);

    void update(Node* n);

    bool operator< (const Node& rhs)
    {
        return dist < rhs.dist;
    }
};


class UnVisited
{
public:
    vector<Node> arr;
    Terrain* t;

public:
    UnVisited(Terrain* t, Vec2 start);

    bool empty();

    int getMinIndex();

    Node extractMin();

    void update(Vec2 coord, Node* n);

    bool exists(Vec2 coord);
    
};

class Visited
{
public:
    vector<Node> arr;
    Terrain* t;

public:
    Visited(Terrain* ter);

    Node* push(Node n);

    Node pop();

    bool empty();

    Vec2* getPath(int &s);
};


/** @brief Dijkstra pathfinding
     *  @param start Starting position
     *  @param end Ending position
     */
    Vec2* Dijkstra(Terrain* t, Vec2 start, Vec2 end, int& size);


#endif