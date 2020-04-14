#include <SDL2/SDL.h>
#include <iostream>
#include "menu_sdl.h"
#include "WinSdl.h"
using namespace std;

int main(void)
{
    //menu_sdl ms;
    //ms.main_menu_sdl();

    WinSdl sdl;
    sdl.display();

    /*SDL_Window* window;
    SDL_Event events;
    bool over = false;
    SDL_Renderer* renderer;

    if(SDL_Init(SDL_INIT_VIDEO) < 0) // initialisation de la SDL
    {
      cout << "Erreur d'initialisation de la SDL : " << SDL_GetError() << endl;//on affiche l'erreur
       return EXIT_FAILURE;//on sort du programme pour éviter de plus gros problèmes
    }
    
// Création de la fenêtre
    window = SDL_CreateWindow("Hunter",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED, 600, 600, SDL_WINDOW_RESIZABLE);  // Création de la fenêtre

    if (window == NULL)  //gestion des erreurs
    {
        cout << "Erreur lors de la creation d'une fenetre : " << SDL_GetError() << endl;
        return EXIT_FAILURE;
    }

// Création du renderer
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    if (renderer == NULL)  //gestion des erreurs
    {
        cout << "Erreur lors de la creation d'un renderer : " << SDL_GetError() << endl;
        return EXIT_FAILURE;
    }

// Boucle : tant qu'on ferme pas la fenêtre
    while(!over)
    {
        SDL_WaitEvent(&events);

        if(events.window.event == SDL_WINDOWEVENT_CLOSE)
            over = true;
    }
    
    SDL_DestroyWindow(window);
    SDL_Quit();//on quitte la SDL

    return 0;*/

}

