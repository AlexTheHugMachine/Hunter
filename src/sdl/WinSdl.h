#include <SDL.h>




class WinSdl
{
private:
    SDL_Window* window;
    SDL_Event events;
    bool over = false;
    SDL_Renderer* renderer;
public:
    WinSdl();
    ~WinSdl();

    void display();
};