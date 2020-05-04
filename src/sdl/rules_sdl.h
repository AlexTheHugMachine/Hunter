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

class rules_sdl {
    public :
        /**
         * @brief Constructeur par défaut de la classe rules_sdl
         * @return Renvoie une fenêtre avec les règles du jeu
         */
        rules_sdl();
        /**
         * @brief Destructeur par défaut de la classe rules_sdl
         */
        ~rules_sdl();
  private:
    SDL_Window* pWindow_rules;
    SDL_Renderer* pRenderer_rules;

    TTF_Font * font_rule;
    TTF_Font * subtitles_rules;

    SDL_Surface*img_background_charge_rules;
    SDL_Surface* Title_rules;
    SDL_Surface* Txt_rules;
    SDL_Surface* img_keyboard;
    SDL_Surface* img_left;
    SDL_Surface* good_luck;

    SDL_Texture* img_background_rules;
    SDL_Texture* texture_img_keyboard;
    SDL_Texture* texture_img_left;
    SDL_Texture* texture_title_rules;
    SDL_Texture* texture_subtitles_rules;
    SDL_Texture* texture_good_luck;

};

#endif
