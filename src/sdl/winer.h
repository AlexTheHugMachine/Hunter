#ifndef _WINER_H
#define _WINER_H

#include "menu_sdl.h"
#include <stdlib.h>
#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <cstdlib>
#include <iostream>
#include <string.h>

class winer
{
    public:
        /**
         * @brief Constructeur par défaut de la classe winer
         * @return Renvoie une fenêtre affichant le texte "YOU WIN ! CONGRATULATION" lorsque le joueur gagne
         */
        winer();
        /**
         * @brief Destructeur par défaut de la classe winer
         */
        ~winer();
    private:
        SDL_Window* pWindow;
        SDL_Renderer* pRenderer;
        SDL_Surface *img_background_charge;

        TTF_Font * font;

        SDL_Surface* Title;
        SDL_Texture* title_texture;
};


#endif