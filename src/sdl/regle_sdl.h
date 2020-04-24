#ifndef _REGLESDL_H
#define _REGLESDL_H

#include <stdlib.h>
#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <cstdlib>
#include <iostream>
#include <string.h>

class regle_sdl {
    public :
        regle_sdl();
        ~regle_sdl();
  private:
    SDL_Window* pWindow_regle;
    SDL_Renderer* pRenderer_regle;

    TTF_Font * font_regle;
    TTF_Font * sous_titre_regle;

    SDL_Surface *img_fond_charge_regle;
    SDL_Surface* Titre_regle;
    SDL_Surface* Txt_regle;
    SDL_Surface* img_keyboard;
    SDL_Surface* img_left;
    SDL_Surface * good_luck;

    SDL_Texture *img_fond_regle;
    SDL_Texture *texture_img_keyboard;
    SDL_Texture *texture_img_left;
    SDL_Texture* texture_titre_regle;
    SDL_Texture* texture_sous_titre_regle;
    SDL_Texture * texture_good_luck;

};

#endif
