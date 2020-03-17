#ifndef TERRAIN
#define TERRAIN

#include "Case.h"
#include "Vec2.h"

class Terrain{
private:
    Case* arr;
    int DimX;
    int DimY;

private:

public:

    /** New terrain
     * Initializes a new terrain
     * @param x dimension
     * @param y dimension
     */
    Terrain(int x, int y);

    /** Deletes terrain
     */
    ~Terrain();

    /** DimX accessor
     * @return DimY
     */
    int GetDimX() const;

    /** DimY accessor
     * @return DimY
     */
    int GetDimY() const;

    /** Dimensions accessor
     * @return Vec2 with dimensions in X and Y axes
     */
    Vec2 GetDim() const;

    /** Case accessor
     * @param x coordinate
     * @param y coordinate
     * @return Case value
     */
    Case GetCase(int x, int y) const;

    /** Case mutator
     * @param x coordinate
     * @param y coordinate
     * @param c Case value
     */
    void SetCase(int x, int y, Case c);

};

#endif
