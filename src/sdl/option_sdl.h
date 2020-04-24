#ifndef _OPTIONSDL_H
#define _OPTIONSDL_H

#include <stdlib.h>
#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <cstdlib>
#include <iostream>
#include <string.h>

class option_sdl {
    public :
        option_sdl();
        ~option_sdl();
  private:
    SDL_Window* pWindow_option;
    SDL_Renderer* pRenderer_option;

    TTF_Font * font_option;
    TTF_Font * sous_titre_option;
    TTF_Font * sous_titre_option_underline;

    SDL_Surface *img_fond_charge_option;
    SDL_Surface* Titre_option;
    SDL_Surface* Txt_option;
    SDL_Surface* img_left_option;
    SDL_Surface* page_UE;
    SDL_Surface* Gameplay;
    SDL_Surface * documentation;

    SDL_Texture *img_fond_option;
    SDL_Texture *texture_img_left_option;
    SDL_Texture* texture_titre_option;
    SDL_Texture* texture_sous_titre_option;
    SDL_Texture* texture_page_UE;
    SDL_Texture* texture_Gameplay;
    SDL_Texture * texture_documentation;

};

#endif
