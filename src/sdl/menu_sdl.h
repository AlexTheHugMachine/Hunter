#ifndef _MENUSDL_H
#define _MENUSDL_H

#include "regle_sdl.h"
#include <stdlib.h>
#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <cstdlib>
#include <iostream>
#include <string.h>

class menu_sdl {
    public :
        menu_sdl();
        ~menu_sdl();
  private:
    SDL_Window* pWindow;
    SDL_Renderer* pRenderer;
    SDL_Surface *img_fond_charge;

    TTF_Font * font;
    TTF_Font * sous_titre;

    SDL_Surface* Titre;
       SDL_Surface* Txt;
       SDL_Surface* Options;
       SDL_Surface* Regle_du_Jeu;
       SDL_Surface* Quitter;

       SDL_Texture *img_fond;
       SDL_Texture* texture_titre;
       SDL_Texture* texture_sous_titre;
       SDL_Texture* Options_texture;
       SDL_Texture* regle_texture;
       SDL_Texture* Quitter_texture;

};

#endif
