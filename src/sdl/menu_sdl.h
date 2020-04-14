#ifndef _MENUSDL_H
#define _MENUSDL_H

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
        /**
         * @brief Constructeur par défaut de la classe menu_sdl
        */
        menu_sdl();

        /**
         * @brief Destructeur par défaut de la classe menu_sdl
         */
        ~menu_sdl();

        /**
         * @brief Fonction permettant l'affichage du menu
         */
        int main_menu_sdl();
};

#endif