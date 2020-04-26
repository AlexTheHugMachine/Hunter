#include <SDL2/SDL.h>
#include "Game.h"
#include <iostream>
#include "menu_sdl.h"
// #include "WinSdl.h"

using namespace std;

#define TILE_WIDTH 64
#define TILE_HEIGHT 64

int main(void)
{
    // Game-related variables
    Game g;

    Vec2 p;
    Vec2 *e;
    int nbE;
    Terrain t = g.getTerrain();
    Direction dir = Direction::none;
    bool won = false;

    const int TOTAL_WIDTH = t.getDimX();
    const int TOTAL_HEIGHT = t.getDimY();

    const int FPS = 144;
    const int frameDelay = 1000 / FPS;
    Uint32 frameStart;
    int frameTime;

    // SDL-related variables
    SDL_Window *window;
    SDL_Event events;
    bool over = false;
    SDL_Renderer *renderer;
    SDL_Texture *texture_empty, *texture_wall, *texture_player;
    SDL_Rect rect;
    SDL_Surface *surface;

    if (SDL_Init(SDL_INIT_VIDEO) < 0) // initialisation de la SDL
    {
        cout << "Erreur d'initialisation de la SDL : " << SDL_GetError() << endl; //on affiche l'erreur
        return EXIT_FAILURE;                                                      //on sort du programme pour éviter de plus gros problèmes
    }

    // Création de la fenêtre
    window = SDL_CreateWindow("Hunter",
                              SDL_WINDOWPOS_CENTERED,
                              SDL_WINDOWPOS_CENTERED, TOTAL_WIDTH * TILE_WIDTH, TOTAL_HEIGHT * TILE_HEIGHT, 0); // Création de la fenêtre

    if (window == NULL) //gestion des erreurs
    {
        cout << "Erreur lors de la creation d'une fenetre : " << SDL_GetError() << endl;
        return EXIT_FAILURE;
    }

    // Création du renderer
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    if (renderer == NULL) //gestion des erreurs
    {
        cout << "Erreur lors de la creation d'un renderer : " << SDL_GetError() << endl;
        return EXIT_FAILURE;
    }

    texture_empty = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, TILE_WIDTH, TILE_HEIGHT);
    texture_wall = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, TILE_WIDTH, TILE_HEIGHT);
    texture_player = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, TILE_WIDTH, TILE_HEIGHT);

    if (texture_wall == nullptr || texture_empty == nullptr || texture_player == nullptr)
    {
        cout << "Erreur lors de la création des textures : " << SDL_GetError() << endl;
        return EXIT_FAILURE;
    }

    rect.w = TILE_WIDTH;
    rect.h = TILE_HEIGHT;
    rect.x = 0;
    rect.y = 0;

    // SDL_SetRenderTarget(renderer, texture_empty);
    // SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    // SDL_RenderFillRect(renderer, &rect);

    surface = IMG_Load("data/textures/wood_planks_small.jpg");
    if (surface)
    {
        texture_empty = SDL_CreateTextureFromSurface(renderer, surface);
        SDL_FreeSurface(surface);
    }

    surface = IMG_Load("data/textures/player.png");
    if (surface)
    {
        texture_player = SDL_CreateTextureFromSurface(renderer, surface);
        SDL_FreeSurface(surface);
    }

    // SDL_SetRenderTarget(renderer, texture_wall);
    // SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    // SDL_RenderFillRect(renderer, &rect);

    SDL_SetRenderTarget(renderer, nullptr);

    surface = IMG_Load("data/textures/wall_top1.jpg");
    if (surface)
    {
        texture_wall = SDL_CreateTextureFromSurface(renderer, surface);
        SDL_FreeSurface(surface);
    }

    // SDL_EnableKeyRepeat(int SDL_DEFAULT_REPEAT_DELAY, int SDL_DEFAULT_REPEAT_INTERVAL);
    // Boucle : tant qu'on ferme pas la fenêtre
    while (!over && !won)
    {
        dir = Direction::none;
        frameStart = SDL_GetTicks();
        p = g.getPlayerPos();
        // Escape from while loop if click on the "cross"

        int i, j;

        for (int i = 0; i < TOTAL_WIDTH; i++)
        {
            for (int j = 0; j < TOTAL_HEIGHT; j++)
            {
                rect.x = i * TILE_WIDTH;
                rect.y = j * TILE_HEIGHT;
                rect.w = TILE_WIDTH;
                rect.h = TILE_HEIGHT;
                if (t.getCase(Vec2(i, j)) == Case::wall)
                    SDL_RenderCopy(renderer, texture_wall, nullptr, &rect);
                else
                    SDL_RenderCopy(renderer, texture_empty, nullptr, &rect);
                if (Vec2(i, j) == p)
                    SDL_RenderCopy(renderer, texture_player, nullptr, &rect);
            }
        }
        SDL_RenderPresent(renderer);

        SDL_Delay(100);
        // SDL_WaitEvent(&events);
        // if (events.window.event == SDL_WINDOWEVENT_CLOSE)
        //     over = true;
        bool moved = false;

        // const Uint8 *keystate = SDL_GetKeyboardState(NULL);

        // //continuous-response keys
        // if (keystate[SDL_SCANCODE_Q])
        // {
        //     dir = Direction::left;
        // }
        // if (keystate[SDL_SCANCODE_D])
        // {
        //     dir = Direction::right;
        // }
        // if (keystate[SDL_SCANCODE_Z])
        // {
        //     dir = Direction::up;
        // }
        // if (keystate[SDL_SCANCODE_S])
        // {
        //     dir = Direction::down;
        // }

        while (SDL_PollEvent(&events))
        {
            switch (events.type)
            {
            case SDL_WINDOWEVENT:
                if (events.window.event == SDL_WINDOWEVENT_CLOSE)
                {
                    over = true;
                }
                break;

            case SDL_KEYDOWN:
                switch (events.key.keysym.sym)
                {
                case SDLK_z:
                    //if (!moved)
                    dir = Direction::up;
                    moved = true;
                    break;

                case SDLK_s:
                    //if (!moved)
                    dir = Direction::down;
                    moved = true;
                    break;

                case SDLK_q:
                    //if (!moved)
                    dir = Direction::left;
                    moved = true;
                    break;

                case SDLK_d:
                    //if (!moved)
                    dir = Direction::right;
                    moved = true;
                    break;

                default:
                    dir = Direction::none;
                    break;
                }
            }
        }
        g.UpdateGame(dir);
        won = false;
        delete[] e;

        frameTime = SDL_GetTicks() - frameStart;
        if (frameDelay > frameTime)
        {
            SDL_Delay(frameDelay - frameTime);
        }
    }
    SDL_DestroyTexture(texture_empty);
    SDL_DestroyTexture(texture_wall);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit(); //on quitte la SDL
    return 0;
}
