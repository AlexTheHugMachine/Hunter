#include "menu_sdl.h"
#include "rules_sdl.h"
#include<iostream>
#include <cstring>
using namespace std;


template<typename T>
constexpr T WIDTHSCREEN{ 800 };

template<typename T>
constexpr T HEIGHTSCREEN{ 600 };

template<typename T>
constexpr T TOTAL_POINTS{ 5000 };


rules_sdl::rules_sdl() {
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

   pWindow_rules= nullptr ;
   pRenderer_rules= nullptr ;

   if (SDL_CreateWindowAndRenderer(WIDTHSCREEN<unsigned int>,
      HEIGHTSCREEN<unsigned int>, SDL_WINDOW_SHOWN, &pWindow_rules,
                                                          &pRenderer_rules) < 0)
  {
      SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "[DEBUG] > %s", SDL_GetError());
      SDL_Quit();
      SDL_Quit(); exit(1);
  }

  SDL_Event events;
  bool isOpen{ true };

  font_rule = TTF_OpenFont("data/minecraft_font.ttf", 50);
  subtitles_rules = TTF_OpenFont("data/minecraft_font.ttf", 25);

  if (font_rule == nullptr || subtitles_rules==nullptr)
  {
      SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "[DEBUG] > %s", TTF_GetError());

  }
  string rules;
  rules= "Hello and welcome to Chasse Hunter. You are Agent x";
  rules += " recruit by the LAC (a large security agency in Lyon).\n";
  rules += "Your goal is eliminate enemies without being done.\n";
  rules +="Pour vous deplacer utilser les touches zqsd ( Avancer,Reculer";
  rules +=",se deplacer a gauche,se deplacer a droite ) .";
  char rul[rules.size()+1];
  strcpy(rul,rules.c_str());
  string luck;
  luck="Bonne \n Chance!";
  char good[luck.size()+1];
  strcpy(good,luck.c_str());
  //cout<< "Pour se déplacer appuyer sur les touches suivantes:""
  Title_rules = TTF_RenderText_Blended(font_rule, "Rules",
                                                SDL_Color{ 255, 255, 255, 0 });
  Txt_rules = TTF_RenderText_Blended_Wrapped(subtitles_rules, rul,
                            SDL_Color{ 255, 255, 255, 0 },WIDTHSCREEN<int>-100);
  good_luck = TTF_RenderText_Blended_Wrapped(subtitles_rules,good,
                                                  SDL_Color{255,255,255,0},250);

  if (Title_rules == nullptr)
  {
      SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "[DEBUG] > %s", TTF_GetError());
  }

//background
  img_background_charge_rules = SDL_LoadBMP("data/hunter.bmp");
  if (img_background_charge_rules == NULL)
  {
      printf("Unable to load 'hunter.bmp' : %s\n",SDL_GetError());
    exit(1);
  }

  img_background_rules = SDL_CreateTextureFromSurface(pRenderer_rules,
                                                  img_background_charge_rules);

  SDL_Rect position_backgound;

  SDL_QueryTexture(img_background_rules, nullptr, nullptr,&position_backgound.w,
                                                         &position_backgound.h);
  position_backgound.x = 0;
  position_backgound.y = 0;

//image keyboard
  img_keyboard = SDL_LoadBMP("data/keyboard.bmp");
  if (img_keyboard == NULL)
  {
    printf("Unable to load 'keyboard.bmp' : %s\n",SDL_GetError());
  }

  texture_img_keyboard = SDL_CreateTextureFromSurface(pRenderer_rules, img_keyboard);

  SDL_Rect position_keyboard;

  SDL_QueryTexture(texture_img_keyboard, nullptr, nullptr, &position_keyboard.w, &position_keyboard.h);
  position_keyboard.x = WIDTHSCREEN<int>/2-position_keyboard.w/2;
  position_keyboard.y = 350;


  //image left
  img_left = SDL_LoadBMP("data/fleche_gauche.bmp");
  if (img_keyboard == NULL)
  {
      printf("Unable to load 'fleche_gauche.bmp' : %s\n",SDL_GetError());
  }

  texture_img_left = SDL_CreateTextureFromSurface(pRenderer_rules, img_left);

  SDL_Rect position_left;

  SDL_QueryTexture(texture_img_left, nullptr, nullptr, &position_left.w, &position_left.h);
  position_left.x = 10;
  position_left.y = 10;




//title
  texture_title_rules= SDL_CreateTextureFromSurface(pRenderer_rules,
                                                                  Title_rules);

  if (texture_title_rules == nullptr)
  {
      SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "[DEBUG] > %s", TTF_GetError());
  }

  SDL_Rect position;

  SDL_QueryTexture(texture_title_rules, nullptr, nullptr, &position.w,
                                                                    &position.h);

  position.x = WIDTHSCREEN<int> / 2 - position.w / 2;
  position.y = 10;

//txt
   if (Txt_rules == nullptr)
  {
      SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "[DEBUG] > %s", TTF_GetError());
  }

  texture_subtitles_rules = SDL_CreateTextureFromSurface(pRenderer_rules,
                                                                    Txt_rules);

  if (texture_subtitles_rules == nullptr)
  {
      SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "[DEBUG] > %s", TTF_GetError());
  }

  SDL_Rect position_subtitles;


  SDL_QueryTexture(texture_subtitles_rules, nullptr, nullptr,
                                                          &position_subtitles.w,
                                                          &position_subtitles.h);

  position_subtitles.x = 50;
  position_subtitles.y = 100;

//good_luck
  if (good_luck == nullptr)
 {
     SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "[DEBUG] > %s", TTF_GetError());
 }

 texture_good_luck = SDL_CreateTextureFromSurface(pRenderer_rules,good_luck);

 if (texture_good_luck == nullptr)
 {
     SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "[DEBUG] > %s", TTF_GetError());
 }

 SDL_Rect position_good_luck;


 SDL_QueryTexture(texture_good_luck, nullptr, nullptr, &position_good_luck.w,
                                                        &position_good_luck.h);

 position_good_luck.x = 90;
 position_good_luck.y =480;




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
      SDL_SetRenderTarget(pRenderer_rules, texture_title_rules);
      //SDL_SetRenderDrawColor(pRenderer, 255, 41, 0, 0);
      SDL_RenderClear(pRenderer_rules);

      SDL_RenderCopy(pRenderer_rules,img_background_rules,nullptr,
                                                          &position_backgound);
      SDL_RenderCopy(pRenderer_rules,texture_img_keyboard,nullptr,
                                                            &position_keyboard);
      SDL_RenderCopy(pRenderer_rules,texture_img_left,nullptr,&position_left);
      SDL_RenderCopy(pRenderer_rules, texture_title_rules, nullptr, &position);
      SDL_RenderCopy(pRenderer_rules, texture_subtitles_rules,nullptr,
                                                        &position_subtitles);
      SDL_RenderCopy(pRenderer_rules,texture_good_luck,nullptr,
                                                          &position_good_luck);


      SDL_RenderPresent(pRenderer_rules);

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
                break;
    }

}
  exit(1);
}

rules_sdl::~rules_sdl() {
  SDL_DestroyTexture(img_background_rules);
  SDL_DestroyTexture(texture_img_keyboard);
  SDL_DestroyTexture(texture_img_left);
  SDL_DestroyTexture(texture_title_rules);
  SDL_DestroyTexture(texture_subtitles_rules);
  SDL_DestroyTexture(texture_good_luck);
  SDL_DestroyRenderer(pRenderer_rules);
  SDL_DestroyWindow(pWindow_rules);
  TTF_Quit();
  SDL_Quit();
}
