/** @file Terrain.h
 */
#ifndef TERRAIN
#define TERRAIN

#include "Case.h"
#include "Vec2.h"
#include <string>

/** Terrain
 */
class Terrain{
public:

    /** Initializes a new terrain
     * @param x [in] dimension
     * @param y [in] dimension
     */
    Terrain(int x, int y);

    /** Load terrain from file
     * @param filename [in] file location
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
     * @param v [in] Coordinates
     * @return Case value
     */
    Case getCase(Vec2 v) const;

    /** Case mutator
     * @param v [in] Coordinates
     * @param c [in] Case value
     */
    void setCase(Vec2 v, Case c);
    
    /** Case mutator
     * @param x [in] Coordinate
     * @param y [in] Coordinate
     * @param c [in] Case value
     */
    void setCase(int x, int y, Case c);

    /** Tests if a position is in the Terrrain
     *  @param v [in] Vec2 to test
     */
    bool isInTerrain(Vec2 v) const;

    /** Tests if a position is in the Terrrain and a path
     *  @param v [in] Vec2 to test
     */
    bool isTerrainPath(Vec2 v) const;

    /** @brief [DEBUG] displays the terrain
     *  @warning DEBUG ONLY!!
     */
    void draw(); // DEBUG ONLY!!!!!!

    /** @brief Test the Ennemy class
     * 
     * This is a regression test
     */
    void test() const;

    /** @brief returns adjacent tiles where characters can walk
     *  @param pos [in] current tile
     *  @param size [out] size of array returned
     *  @warning Don't forget to disallocate the returned array ! 
     */
    Vec2* getAdjacentPath(Vec2 pos, int& size) const;



private:
    Case* arr; ///< Array of tiles
    int dimX; ///< width
    int dimY; ///< height

private:
    /** @brief returns adjacent tiles
     *  @param pos [in] current tile
     *  @param size [out] size of array returned
     *  @return pointer on array of Vec2
     *  @warning Don't forget to disallocate the returned array ! 
     */
    Vec2* getAdjacent(Vec2 pos, int& size) const;

};

#endif
