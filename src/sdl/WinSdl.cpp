#include "WinSdl.h"

#include <iostream>

using namespace std;

WinSdl::WinSdl()
{
    t = g.getTerrain();
    dimX = t.getDimX();
    dimY = t.getDimY();

    if (SDL_Init(SDL_INIT_VIDEO) < 0) // initialisation de la SDL
    {
        cout << "Erreur d'initialisation de la SDL : " << SDL_GetError() << endl; //on affiche l'erreur
        //return EXIT_FAILURE;//on sort du programme pour éviter de plus gros problèmes
    }

    // Création de la fenêtre
    window = SDL_CreateWindow("Hunter",
                              SDL_WINDOWPOS_CENTERED,
                              SDL_WINDOWPOS_CENTERED, dimX * TileWidth, dimY * TileWidth, SDL_WINDOW_RESIZABLE); // Création de la fenêtre

    if (window == NULL) //gestion des erreurs
    {
        cout << "Erreur lors de la creation d'une fenetre : " << SDL_GetError() << endl;
        //return EXIT_FAILURE;
    }

    // Création du renderer
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    if (renderer == NULL) //gestion des erreurs
    {
        cout << "Erreur lors de la creation d'un renderer : " << SDL_GetError() << endl;
        //return EXIT_FAILURE;
    }
}

WinSdl::~WinSdl()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    cout<< "coucou" << endl;
}

void WinSdl::display()
{
    

    while(!over)
    {
        SDL_WaitEvent(&events);

        if(events.window.event == SDL_WINDOWEVENT_CLOSE)
            over = true;
    }
}