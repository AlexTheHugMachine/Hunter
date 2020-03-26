#ifndef PATH_H
#define PATH_H

#include "Vec2.h"
#include <vector>
#include "Terrain.h"

using namespace std;

/** @brief Node class used by the pathfinding algorithm
 *  @sa UnVisited
 *  @sa Visited
 */
class Node
{
public:
    Vec2 coords; ///< Coordinates in the grid
    int dist;   ///< Distance to starting Node
    Vec2 via; ///< Coordinatess of the previos node

public:
    /** @brief Default constructor
     */
    Node() = default;

    /** @brief Constructor
     *  @param v Coordintates in the terrain
     *  @param d Distance to starting node
     *  @param n Coordinates of the previous node in the path
     */
    Node(Vec2 v, int d, Vec2 n);

    /** @brief Update the current node passing through another node
     *  @param n node of passage
     */
    void update(Node n);

    /** @brief inequality test
     *  @param rhs right hand side term
     */
    bool operator< (const Node& rhs)
    {
        return dist < rhs.dist;
    }
};

/** @brief Unvisited Node array
 *  @sa Node
 *  @sa UnVisited
 */
class UnVisited
{
public:
    vector<Node> arr; ///< array of nodes

public:
    /** @brief Constructor
     *  @param t Pointer on terrain
     *  @param start starting coordinates for pathfinding
     */
    UnVisited(Terrain* t, Vec2 start);

    /** @brief tests if the array is empty
     *  @return bool : true if the array is empty
     */
    bool empty();

    /** @brief Deletes the node with the shortest path to the starting point
     *  @return Copy of the deleted Node
     */
    Node extractMin();

    /** @brief updates the node with certain coordinates
     *  @param coord Coordinates of the node to update
     *  @param n Node of passage for the update
     */
    void update(Vec2 coord, Node n);

    /** @brief Tests if a node with certain coordinates exists
     *  @param coord Coordinates of the node to test the existence in the array
     */
    bool exists(Vec2 coord);
    
private:
    /** @brief Returns the index of the node with the shortest distance to the start
     *  @return Index of the array
     */
    int getMinIndex();
};

/** @brief Array of visited nodes
 *  @sa Node
 *  @sa UnVisited
 */
class Visited
{
public:
    vector<Node> arr; ///< Stack of nodes

public:
    /** @brief Default constructor
     */
    Visited() = default;

    /** @brief Push a node at the top of the Stack
     *  @param n Node to push
     */
    void push(Node n);

    /** @brief Transforms the stack into an array containing the (shortest) path from start to end
     *  @return Pointer on first value of a dynamically allocated array of Vec2
     *  @param s [out] size of the returned array
     */
    Vec2* getPath(int &s);

private:
    /** @brief pop the node at the top of the stack
     *  @return Copy of the deleted node
     */
    Node pop();

    /** @brief Tests if the stack is empty
     *  @return bool : true if the stack is empty
     */
    bool empty();
};


/** @brief Dijkstra pathfinding
 *  @param t Pointer on terrain
 *  @param start Starting position
 *  @param end Ending position
 *  @return Pointer on the first value of a dynamically allocated array
 *  @param size [out] size of the returned array
 */
Vec2* Dijkstra(Terrain* t, Vec2 start, Vec2 end, int& size);


#endif