#ifndef _LOSER_H
#define _LOSER_H

#include "menu_sdl.h"
#include <stdlib.h>
#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <cstdlib>
#include <iostream>
#include <string.h>


/**
 * @brief Classe permettant d'afficher une fenetre avec un texte prédéfini lorsque le joueur perd
 */
class loser
{
    public:
        /**
         * @brief Constructeur par défaut de la classe loser
         * @return Renvoie l'affichage d'une fenêtre avec un texte "YOU LOSE" si le joueur perd
         **/
        loser();
        /**
         * @brief Destructeur par défaut de la classe loser
         */
        ~loser();
    private:
        SDL_Window* pWindow;
        SDL_Renderer* pRenderer;
        SDL_Surface *img_background_charge;

        TTF_Font * font;

        SDL_Surface* Title;
        SDL_Texture* title_texture;
};

#endif