#ifndef PATH_H
#define PATH_H

#include "Vec2.h"
#include <vector>

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

    void update(Node n);

    bool operator< (const Node& rhs)
    {
        return dist < rhs.dist;
    }
};


class UnVisited
{
public:
    vector<Node> arr;

};


/** @brief Dijkstra pathfinding
     *  @param start Starting position
     *  @param end Ending position
     */
    Vec2* Dijkstra(Vec2 start, Vec2 end, int& size);


#endif