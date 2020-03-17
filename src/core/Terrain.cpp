#include "Terrain.h"

Terrain::Terrain(int x, int y)
{
    arr = new Case[x * y];
    DimX = x;
    DimY = y; 
}

Terrain::~Terrain()
{
    delete arr;
    DimX = 0;
    DimY = 0;
}

int Terrain::GetDimX() const
{
   return DimX;
}

int Terrain::GetDimY() const
{
    return DimY;
}

Vec2 Terrain::GetDim() const
{
    return Vec2(DimX, DimY);
}

Case Terrain::GetCase(int x, int y) const
{
    return arr[DimX * y + x];
}

void Terrain::SetCase(int x, int y, Case c)
{
    arr[DimX * y + x] = c;
}