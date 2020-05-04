#ifndef _MENUSDL_H
#define _MENUSDL_H

#include "rules_sdl.h"
#include <stdlib.h>
#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <cstdlib>
#include <iostream>
#include <string.h>

/**
 * @brief classe permettant d'afficher le menu dans la version sdl
 */
class menu_sdl {
    public :
        /**
         * @brief Constructeur par défaut de la classe menu_sdl
         * @return Renvoie une fenêtre permettant de séléctionner ce que l'utilisateur veut faire
         */
        menu_sdl();
        /**
         * @brief Destructeur par défaut de la classe menu_sdl
         */
        ~menu_sdl();
  private:
    SDL_Window* pWindow;
    SDL_Renderer* pRenderer;
    SDL_Surface *img_background_charge;

    TTF_Font * font;
    TTF_Font * subtitles;

    SDL_Surface* Title;
       SDL_Surface* Txt;
       SDL_Surface* Options;
       SDL_Surface* Rules;
       SDL_Surface* Exit;

       SDL_Texture* img_background;
       SDL_Texture* title_texture;
       SDL_Texture* subtitles_texture;
       SDL_Texture* Options_texture;
       SDL_Texture* rules_texture;
       SDL_Texture* exit_texture;
};

#endif
