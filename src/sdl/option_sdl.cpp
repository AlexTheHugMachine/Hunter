#include "menu_sdl.h"
#include "option_sdl.h"
#include<iostream>
#include <cstring>
#include <cstdlib>
using namespace std;


template<typename T>
constexpr T WIDTHSCREEN{ 800 };

template<typename T>
constexpr T HEIGHTSCREEN{ 600 };

template<typename T>
constexpr T TOTAL_POINTS{ 5000 };


option_sdl::option_sdl() {
  if (SDL_Init(SDL_INIT_VIDEO) < 0)
  {
      SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "[DEBUG] > %s", SDL_GetError());
    SDL_Quit(); exit(1);
  }

  if (TTF_Init() < 0)
  {
      SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "[DEBUG] > %s", TTF_GetError());
      SDL_Quit(); exit(1);
  }

   pWindow_option= nullptr ;
   pRenderer_option= nullptr ;

   if (SDL_CreateWindowAndRenderer(WIDTHSCREEN<unsigned int>,
      HEIGHTSCREEN<unsigned int>, SDL_WINDOW_SHOWN, &pWindow_option,
      &pRenderer_option) < 0)
  {
      SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "[DEBUG] > %s", SDL_GetError());
      SDL_Quit();
      SDL_Quit(); exit(1);
  }

  SDL_Event events;
  bool isOpen{ true };

  font_option = TTF_OpenFont("data/minecraft_font.ttf", 50);
  subtitles_option = TTF_OpenFont("data/minecraft_font.ttf", 25);
  subtitles_option_underline=TTF_OpenFont("data/minecraft_font.ttf", 35);
  TTF_SetFontStyle(subtitles_option_underline,TTF_STYLE_UNDERLINE);

  if (font_option == nullptr || subtitles_option==nullptr ||
            subtitles_option_underline==nullptr)
  {
      SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "[DEBUG] > %s", TTF_GetError());

  }
  string option;
  option="This project is being developed as part of UE LIFAP4 ";
  option+="(Conception et Developpement d Application).\n Realized by par Celian";
  option+=" LOUIS-ITTY, Alexis Bonis and Lucas Rakotomalala; all second year ";
  option+="students in computer science license at Claude Bernard Lyon 1 ";
  option+=" university.\n Chasse Hunter is inspired by the Hunter Assasin games";
  option+=" availble on the phone.";
  char opt[option.size()+1];
  strcpy(opt,option.c_str());
  Title_option = TTF_RenderText_Blended(font_option, "Option",
                                        SDL_Color{ 255, 255, 255, 0 });
  Txt_option = TTF_RenderText_Blended_Wrapped(subtitles_option,opt,
                            SDL_Color{ 255, 255, 255, 0 },WIDTHSCREEN<int>-100);
  page_UE=TTF_RenderText_Blended(subtitles_option_underline,"Page UE"
                                                    ,SDL_Color{255,255,255,0});
  Gameplay=TTF_RenderText_Blended(subtitles_option_underline,
                              "Gameplay mobile games",SDL_Color{255,255,255,0});
  documentation=TTF_RenderText_Blended(subtitles_option_underline,
                                      "documentation",SDL_Color{255,255,255,0});

  if (Title_option == nullptr)
  {
      SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "[DEBUG] > %s", TTF_GetError());
  }

//background
  img_background_charge_option = SDL_LoadBMP("data/hunter.bmp");
  if (img_background_charge_option == NULL)
  {
    printf("Unable to load'hunter.bmp' : %s\n",SDL_GetError());
    exit(1);
  }

  img_background_option = SDL_CreateTextureFromSurface(pRenderer_option,
                                                  img_background_charge_option);

  SDL_Rect position_backgound;

  SDL_QueryTexture(img_background_option, nullptr, nullptr,&position_backgound.w,
                                                        &position_backgound.h);
  position_backgound.x = 0;
  position_backgound.y = 0;




//image left
  img_left_option = SDL_LoadBMP("data/fleche_gauche.bmp");
  if (img_left_option == NULL)
  {
    printf("Unable to load 'fleche_gauche.bmp' : %s\n",SDL_GetError());
    exit(1);
  }

  texture_img_left_option = SDL_CreateTextureFromSurface(pRenderer_option,
                                                          img_left_option);

  SDL_Rect position_left;

  SDL_QueryTexture(texture_img_left_option, nullptr, nullptr, &position_left.w, &position_left.h);
  position_left.x = 10;
  position_left.y = 10;


//title
  texture_title_option = SDL_CreateTextureFromSurface(pRenderer_option,
                                                      Title_option);

  if (texture_title_option == nullptr)
  {
      SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "[DEBUG] > %s", TTF_GetError());
  }

  SDL_Rect position;

  SDL_QueryTexture(texture_title_option, nullptr, nullptr, &position.w,
                                                            &position.h);


  position.x = WIDTHSCREEN<int> / 2 - position.w / 2;
  position.y = 10;

//txt
   if (Txt_option == nullptr)
  {
      SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "[DEBUG] > %s", TTF_GetError());
  }

  texture_subtitles_option = SDL_CreateTextureFromSurface(pRenderer_option,
                                                                    Txt_option);

  if (texture_subtitles_option == nullptr)
  {
      SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "[DEBUG] > %s", TTF_GetError());
  }

  SDL_Rect position_subtitles;


  SDL_QueryTexture(texture_subtitles_option, nullptr, nullptr,
                                            &position_subtitles.w,
                                             &position_subtitles.h);

  position_subtitles.x = 50;
  position_subtitles.y = 100;

//page_UE
   if (page_UE == nullptr)
  {
      SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "[DEBUG] > %s", TTF_GetError());
  }

  texture_page_UE = SDL_CreateTextureFromSurface(pRenderer_option,page_UE); // Crée la texture qu'on va afficher a partir de la surface

  if (texture_page_UE == nullptr)
  {
      SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "[DEBUG] > %s", TTF_GetError());
  }

  SDL_Rect position_page_UE;


  SDL_QueryTexture(texture_page_UE, nullptr, nullptr, &position_page_UE.w, &position_page_UE.h); // Récupere la dimension de la texture

  position_page_UE.x = 50;
  position_page_UE.y = 425;

//Gameplay
   if (Gameplay == nullptr)
  {
      SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "[DEBUG] > %s", TTF_GetError());
  }

  texture_Gameplay = SDL_CreateTextureFromSurface(pRenderer_option,Gameplay); // Crée la texture qu'on va afficher a partir de la surface

  if (texture_Gameplay == nullptr)
  {
      SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "[DEBUG] > %s", TTF_GetError());
  }

  SDL_Rect position_Gameplay;


  SDL_QueryTexture(texture_Gameplay, nullptr, nullptr, &position_Gameplay.w, &position_Gameplay.h); // Récupere la dimension de la texture

  position_Gameplay.x = 250;
  position_Gameplay.y = 425;

//documentation
     if (documentation == nullptr)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "[DEBUG] > %s", TTF_GetError());
    }

    texture_documentation= SDL_CreateTextureFromSurface(pRenderer_option,documentation); // Crée la texture qu'on va afficher a partir de la surface

    if (texture_documentation == nullptr)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "[DEBUG] > %s", TTF_GetError());
    }

    SDL_Rect position_documentation;


    SDL_QueryTexture(texture_documentation, nullptr, nullptr, &position_documentation.w, &position_documentation.h); // Récupere la dimension de la texture

    position_documentation.x = 50;
    position_documentation.y = 525;



    SDL_Event event;

  // Libération des resource de la police et de la surface qui contient le texte

   while (isOpen)
  {
       while (SDL_PollEvent(&events))
      {
          switch (events.type)
          {
          case SDL_QUIT:
              isOpen = false;
              break;
          }
      }
      SDL_SetRenderTarget(pRenderer_option, texture_title_option);
      //SDL_SetRenderDrawColor(pRenderer, 255, 41, 0, 0);
      SDL_RenderClear(pRenderer_option);

      SDL_RenderCopy(pRenderer_option,img_background_option,nullptr,
                                                          &position_backgound);
      SDL_RenderCopy(pRenderer_option,texture_img_left_option,nullptr,
                                                              &position_left);
      SDL_RenderCopy(pRenderer_option, texture_title_option, nullptr,&position);
      SDL_RenderCopy(pRenderer_option, texture_subtitles_option,nullptr,
                                                          &position_subtitles);
      SDL_RenderCopy(pRenderer_option, texture_page_UE,nullptr,
                                                            &position_page_UE);
      SDL_RenderCopy(pRenderer_option,texture_Gameplay,nullptr,
                                                            &position_Gameplay);
      SDL_RenderCopy(pRenderer_option, texture_documentation,nullptr,
                                                        &position_documentation);


      SDL_RenderPresent(pRenderer_option);

      SDL_WaitEvent(&event);
        switch(event.type)
        {
            case SDL_MOUSEBUTTONUP:
                if (event.button.x>=position_left.x &&
                    event.button.x<=position_left.x+175 &&
                    event.button.y>=position_left.y &&
                    event.button.y<=position_left.y+74)
                {
                  TTF_Quit();
                  SDL_Quit();
                  menu_sdl ms;
                }
                if (event.button.x>=position_page_UE.x &&
                    event.button.x<=position_page_UE.x+200 &&
                    event.button.y>=position_page_UE.y &&
                    event.button.y<=position_page_UE.y+100)
                {
                 system("xdg-open https://perso.liris.cnrs.fr/alexandre.meyer/public_html/www/doku.php?id=lifap4");
                }
                if (event.button.x>=position_Gameplay.x &&
                    event.button.x<=position_Gameplay.x+300 &&
                    event.button.y>=position_Gameplay.y &&
                    event.button.y<=position_Gameplay.y+100)
                {
                    system("xdg-open https://www.youtube.com/watch?v=ETm0Sg8TPlk");
                }
                if (event.button.x>=position_documentation.x &&
                    event.button.x<=position_documentation.x+300 &&
                    event.button.y>=position_documentation.y &&
                    event.button.y<=position_documentation.y+100)
                {
                    system("xdg-open ./doc/html/index.html");
                }
                break;
    }

}
  exit(1);
}

option_sdl::~option_sdl() {
  SDL_DestroyTexture(img_background_option);
  SDL_DestroyTexture(texture_img_left_option);
  SDL_DestroyTexture(texture_title_option);
  SDL_DestroyTexture(texture_subtitles_option);
  SDL_DestroyTexture(texture_page_UE);
  SDL_DestroyTexture(texture_Gameplay);
  SDL_DestroyTexture(texture_documentation);
  SDL_DestroyRenderer(pRenderer_option);
  SDL_DestroyWindow(pWindow_option);
  TTF_Quit();
  SDL_Quit();
}
