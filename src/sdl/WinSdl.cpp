#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "WinSdl.h"

#include <iostream>

using namespace std;

#define TILE_WIDTH 64
#define TILE_HEIGHT 64

void WinSdl::run()
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

    const int FPS = 60;
    const int frameDelay = 1000 / FPS;
    Uint32 frameStart;
    int frameTime;

    // SDL-related variables
    SDL_Window *window;
    SDL_Event events;
    bool over = false;
    SDL_Renderer *renderer;
    SDL_Texture *texture_empty, *texture_wall, *texture_player, *texture_ennemy;
    SDL_Rect rect;
    SDL_Surface *surface;

    if (SDL_Init(SDL_INIT_VIDEO) < 0) // initialisation de la SDL
    {
        cout << "Erreur d'initialisation de la SDL : " << SDL_GetError() << endl; //on affiche l'erreur
    }

    // Création de la fenêtre
    window = SDL_CreateWindow("Hunter",
                              SDL_WINDOWPOS_CENTERED,
                              SDL_WINDOWPOS_CENTERED, TOTAL_WIDTH * TILE_WIDTH, TOTAL_HEIGHT * TILE_HEIGHT, 0); // Création de la fenêtre

    if (window == NULL) //gestion des erreurs
    {
        cout << "Erreur lors de la creation d'une fenetre : " << SDL_GetError() << endl;
    }

    // Création du renderer
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    if (renderer == NULL) //gestion des erreurs
    {
        cout << "Erreur lors de la creation d'un renderer : " << SDL_GetError() << endl;
    }

    texture_empty = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, TILE_WIDTH, TILE_HEIGHT);
    texture_wall = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, TILE_WIDTH, TILE_HEIGHT);
    texture_player = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, TILE_WIDTH, TILE_HEIGHT);

    if (texture_wall == nullptr || texture_empty == nullptr || texture_player == nullptr)
    {
        cout << "Erreur lors de la création des textures : " << SDL_GetError() << endl;
    }

    rect.w = TILE_WIDTH;
    rect.h = TILE_HEIGHT;
    rect.x = 0;
    rect.y = 0;


    surface = IMG_Load("data/textures/wood_planks_small.jpg");
    if (surface)
    {
        texture_empty = SDL_CreateTextureFromSurface(renderer, surface);
        SDL_FreeSurface(surface);
    }

    surface = IMG_Load("data/textures/Player/player_down.png");
    if (surface)
    {
        texture_player = SDL_CreateTextureFromSurface(renderer, surface);
        SDL_FreeSurface(surface);
    }

    surface = IMG_Load("data/textures/wall_top1.jpg");
    if (surface)
    {
        texture_wall = SDL_CreateTextureFromSurface(renderer, surface);
        SDL_FreeSurface(surface);
    }

    surface = IMG_Load("data/textures/Ennemies/e1.png");
    if (surface)
    {
        texture_ennemy = SDL_CreateTextureFromSurface(renderer, surface);
        SDL_FreeSurface(surface);
    }


    // Boucle : tant qu'on ferme pas la fenêtre
    while (!over && !won)
    {
        dir = Direction::none;
        frameStart = SDL_GetTicks();
        p = g.getPlayerPos();
        e = g.getEnnemiesPosition(nbE);

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
                else if(Vec2(i, j).isInTab(e, nbE))
                    SDL_RenderCopy(renderer, texture_ennemy, nullptr, &rect);
            }
        }
        SDL_RenderPresent(renderer);

        SDL_Delay(200);

        bool moved = false;

        const Uint8 *keystate = SDL_GetKeyboardState(NULL);

        //continuous-response keys
        if (keystate[SDL_SCANCODE_A])
        {
            dir = Direction::left;
            // cout << "Q" << endl;
            surface = IMG_Load("data/textures/Player/player_left.png");
            if (surface)
            {
                texture_player = SDL_CreateTextureFromSurface(renderer, surface);
                SDL_FreeSurface(surface);
            }
        }
        if (keystate[SDL_SCANCODE_D])
        {
            dir = Direction::right;
            // cout << "D" << endl;
            surface = IMG_Load("data/textures/Player/player_right.png");
            if (surface)
            {
                texture_player = SDL_CreateTextureFromSurface(renderer, surface);
                SDL_FreeSurface(surface);
            }
            
        }
        if (keystate[SDL_SCANCODE_W])
        {
            dir = Direction::up;
            // cout << "Z" << endl;
            surface = IMG_Load("data/textures/Player/player_up.png");
            if (surface)
            {
                texture_player = SDL_CreateTextureFromSurface(renderer, surface);
                SDL_FreeSurface(surface);
            }
        }
        if (keystate[SDL_SCANCODE_S])
        {
            dir = Direction::down;
            // cout << "S" << endl;
            surface = IMG_Load("data/textures/Player/player_down.png");
            if (surface)
            {
                texture_player = SDL_CreateTextureFromSurface(renderer, surface);
                SDL_FreeSurface(surface);
            }
        }

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

            default:
                break;

                // case SDL_KEYDOWN:
                //     switch (events.key.keysym.sym)
                //     {
                //     case SDLK_z:
                //         //if (!moved)
                //         dir = Direction::up;
                //         moved = true;
                //         break;

                //     case SDLK_s:
                //         //if (!moved)
                //         dir = Direction::down;
                //         moved = true;
                //         break;

                //     case SDLK_q:
                //         //if (!moved)
                //         dir = Direction::left;
                //         moved = true;
                //         break;

                //     case SDLK_d:
                //         //if (!moved)
                //         dir = Direction::right;
                //         moved = true;
                //         break;

                //     default:
                //         dir = Direction::none;
                //         break;
                //     }
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

}