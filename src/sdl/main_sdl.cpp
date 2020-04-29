#include <SDL2/SDL.h>
#include "Game.h"
#include <iostream>
#include "menu_sdl.h"
#include "WinSdl.h"

using namespace std;

#define TILE_WIDTH 64
#define TILE_HEIGHT 64

int main(void)
{
    WinSdl game;
    game.run();
    
    return 0;
}
