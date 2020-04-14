#include <SDL.h>
#include "Game.h"



class WinSdl
{
private:
    SDL_Window* window;
    SDL_Event events;
    bool over = false;
    SDL_Renderer* renderer;

    const int TileWidth = 50;
    Game g;
    Terrain t;
    int dimX;
    int dimY;


public:
    WinSdl();
    ~WinSdl();

    void display();
};