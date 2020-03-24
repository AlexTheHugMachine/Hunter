#ifndef TERRAIN
#define TERRAIN

#include "Case.h"
#include "Vec2.h"
#include <string>

/** Terrain
 */
class Terrain{
public:

    /** New terrain
     * Initializes a new terrain
     * @param x dimension
     * @param y dimension
     */
    Terrain(int x, int y);

    /** Load terrain from file
     * @param filename file location
     */
    Terrain(std::string filename);

    /** Deletes terrain
     */
    ~Terrain();

    /** DimX accessor
     * @return DimY
     */
    int getDimX() const;

    /** DimY accessor
     * @return DimY
     */
    int getDimY() const;

    /** Dimensions accessor
     * @return Vec2 with dimensions in X and Y axes
     */
    Vec2 getDim() const;

    /** Case accessor
     * @param v Coordinates
     * @return Case value
     */
    Case getCase(Vec2 v) const;

    /** Case mutator
     * @param v Coordinates
     * @param c Case value
     */
    void setCase(Vec2 v, Case c);
    
    /** Case mutator
     * @param x Coordinate
     * @param y Coordinate
     * @param c Case value
     */
    void setCase(int x, int y, Case c);

    /** @brief [DEBUG] displays the terrain
     * @warning DEBUG ONLY!!
     */
    void draw() const; // DEBUG ONLY!!!!!!

    /** @brief Dijkstra pathfinding
     *  @param start Starting position
     *  @param end Ending position
     */
    Vec2* Dijkstra(Vec2 start, Vec2 end, int& size) const;

    /** @brief Test the Ennemy class
     */
    void test() const;

private:

    /** @brief returns adjacent tiles
     *  @param pos [in] current tile
     *  @param size [out] size of array returned
     *  @return pointer on array of Vec2
     */
    Vec2* getAdjacent(Vec2 pos, int& size) const;

    /** @brief returns adjacent tiles where characters can walk
     *  @param pos [in] current tile
     *  @param size [out] size of array returned
     *  @return pointer on array of Vec2
     */
    Vec2* getAdjacentPath(Vec2 pos, int& size) const;

    

    /** @brief Checks if coords inside of the Terrain boundaries
     *  @param pos coord of tile to check
     */
    bool isInTerrain(Vec2 pos) const;

private:
    Case* arr = nullptr;
    int dimX;
    int dimY;

};

#endif
