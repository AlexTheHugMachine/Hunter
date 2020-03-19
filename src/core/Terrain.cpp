#include "Terrain.h"

Terrain::Terrain(int x, int y)
{
    arr = new Case[x * y];
    dimX = x;
    dimY = y; 
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
    arr[dimX * (int) v.y + (int) v.x] = c;
}