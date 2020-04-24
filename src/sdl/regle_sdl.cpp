#include "menu_sdl.h"
#include "regle_sdl.h"
#include<iostream>
#include <cstring>
using namespace std;


template<typename T>
constexpr T WIDTHSCREEN{ 800 };

template<typename T>
constexpr T HEIGHTSCREEN{ 600 };

template<typename T>
constexpr T TOTAL_POINTS{ 5000 };


regle_sdl::regle_sdl() {
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

   pWindow_regle= nullptr ;
 pRenderer_regle= nullptr ;

   if (SDL_CreateWindowAndRenderer(WIDTHSCREEN<unsigned int>, HEIGHTSCREEN<unsigned int>, SDL_WINDOW_SHOWN, &pWindow_regle, &pRenderer_regle) < 0)
  {
      SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "[DEBUG] > %s", SDL_GetError());
      SDL_Quit();
      SDL_Quit(); exit(1);
  }

  SDL_Event events;
  bool isOpen{ true };

  //attention !! les polices se trouvents dans des fichiers diiférents
  font_regle = TTF_OpenFont("data/minecraft_font.ttf", 50); // Crée un police avec la police "ariali.ttf" et de taille 18 pixels
  sous_titre_regle = TTF_OpenFont("data/minecraft_font.ttf", 25);

  if (font_regle == nullptr || sous_titre_regle==nullptr)
  {
      SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "[DEBUG] > %s", TTF_GetError());

  }
  string regle_du_jeu;
  regle_du_jeu="Bonjour et bienvenue dans Chasse Hunter. Vous etes Agent x";
  regle_du_jeu += " recruter par le LAC (une grande agence de securite a Lyon).\n";
  regle_du_jeu += "Votre but est d eliminer les ennemis sans se faire reperer.\n";
  regle_du_jeu+="Pour vous deplacer utilser les touches zqsd ( Avancer,Reculer";
  regle_du_jeu+=",se deplacer a gauche,se deplacer a droite ) .";
  char regle[regle_du_jeu.size()+1];
  strcpy(regle,regle_du_jeu.c_str());
  string luck;
  luck="Bonne \n Chance!";
  char good[luck.size()+1];
  strcpy(good,luck.c_str());
  //cout<< "Pour se déplacer appuyer sur les touches suivantes:""
  Titre_regle = TTF_RenderText_Blended(font_regle, "Regle du jeu", SDL_Color{ 255, 255, 255, 0 }); // Crée un surface qui contient le texte
  Txt_regle = TTF_RenderText_Blended_Wrapped(sous_titre_regle, regle, SDL_Color{ 255, 255, 255, 0 },WIDTHSCREEN<int>-100);
  good_luck = TTF_RenderText_Blended_Wrapped(sous_titre_regle,good,SDL_Color{255,255,255,0},250);

  if (Titre_regle == nullptr)
  {
      SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "[DEBUG] > %s", TTF_GetError());
  }

  //fond
  img_fond_charge_regle = SDL_LoadBMP("data/hunter.bmp");
  if (img_fond_charge_regle == NULL) // Car la doc nous dit qu'il y a un cas où cela peut être NULL
  {
      printf("Impossible de charger 'hunter.bmp' : %s\n",SDL_GetError()); // Affichage d'un message d'erreur et utilisation de SDL_GetError() pour avoir plus d'informations, comme le dit la doc
    exit(1);
  }

  img_fond_regle = SDL_CreateTextureFromSurface(pRenderer_regle, img_fond_charge_regle);

  SDL_Rect position_fond;

  SDL_QueryTexture(img_fond_regle, nullptr, nullptr, &position_fond.w, &position_fond.h);
  position_fond.x = 0;
  position_fond.y = 0;

  //image clavier
  img_keyboard = SDL_LoadBMP("data/keyboard.bmp");
  if (img_keyboard == NULL) // Car la doc nous dit qu'il y a un cas où cela peut être NULL
  {
      printf("Impossible de charger 'keyboard.bmp' : %s\n",SDL_GetError()); // Affichage d'un message d'erreur et utilisation de SDL_GetError() pour avoir plus d'informations, comme le dit la doc
    exit(1);
  }

  texture_img_keyboard = SDL_CreateTextureFromSurface(pRenderer_regle, img_keyboard);

  SDL_Rect position_keyboard;

  SDL_QueryTexture(texture_img_keyboard, nullptr, nullptr, &position_keyboard.w, &position_keyboard.h);
  position_keyboard.x = WIDTHSCREEN<int>/2-position_keyboard.w/2;
  position_keyboard.y = 350;


  //image left
  img_left = SDL_LoadBMP("data/fleche_gauche.bmp");
  if (img_keyboard == NULL) // Car la doc nous dit qu'il y a un cas où cela peut être NULL
  {
      printf("Impossible de charger 'fleche_gauche.bmp' : %s\n",SDL_GetError()); // Affichage d'un message d'erreur et utilisation de SDL_GetError() pour avoir plus d'informations, comme le dit la doc
    exit(1);
  }

  texture_img_left = SDL_CreateTextureFromSurface(pRenderer_regle, img_left);

  SDL_Rect position_left;

  SDL_QueryTexture(texture_img_left, nullptr, nullptr, &position_left.w, &position_left.h);
  position_left.x = 10;
  position_left.y = 10;

  /*SDL_Texture *texture = SDL_CreateTexture(pRenderer, SDL_PIXELFORMAT_RGBA8888,SDL_TEXTUREACCESS_TARGET,800,600);
  SDL_SetRenderDrawColor(pRenderer,12,50,0,255);
  SDL_SetRenderTarget(pRenderer, texture); //on modifie la texture
  SDL_RenderDrawLine(pRenderer,0,0,800,600);
  SDL_SetRenderTarget(pRenderer, NULL);// Dorénavent, on modifie à nouveau le renderer*/


  /*position.x = 600;
  position.y = 800;
  SDL_QueryTexture(texture, NULL, NULL, &position.w, &position.h);
  SDL_RenderCopy(pRenderer, texture, NULL, &position);
  SDL_RenderPresent(pRenderer);*/


  //titre
  texture_titre_regle = SDL_CreateTextureFromSurface(pRenderer_regle, Titre_regle); // Crée la texture qu'on va afficher a partir de la surface

  if (texture_titre_regle == nullptr)
  {
      SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "[DEBUG] > %s", TTF_GetError());
  }

  SDL_Rect position;

  SDL_QueryTexture(texture_titre_regle, nullptr, nullptr, &position.w, &position.h); // Récupere la dimension de la texture

  // Centre le titre
  position.x = WIDTHSCREEN<int> / 2 - position.w / 2;
  position.y = 10;

  //txt
   if (Txt_regle == nullptr)
  {
      SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "[DEBUG] > %s", TTF_GetError());
  }

  texture_sous_titre_regle = SDL_CreateTextureFromSurface(pRenderer_regle, Txt_regle); // Crée la texture qu'on va afficher a partir de la surface

  if (texture_sous_titre_regle == nullptr)
  {
      SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "[DEBUG] > %s", TTF_GetError());
  }

  SDL_Rect position_sous_titre;


  SDL_QueryTexture(texture_sous_titre_regle, nullptr, nullptr, &position_sous_titre.w, &position_sous_titre.h); // Récupere la dimension de la texture

  position_sous_titre.x = 50;
  position_sous_titre.y = 100;

//good_luck
  if (good_luck == nullptr)
 {
     SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "[DEBUG] > %s", TTF_GetError());
 }

 texture_good_luck = SDL_CreateTextureFromSurface(pRenderer_regle,good_luck); // Crée la texture qu'on va afficher a partir de la surface

 if (texture_good_luck == nullptr)
 {
     SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "[DEBUG] > %s", TTF_GetError());
 }

 SDL_Rect position_good_luck;


 SDL_QueryTexture(texture_good_luck, nullptr, nullptr, &position_good_luck.w, &position_good_luck.h); // Récupere la dimension de la texture

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
      SDL_SetRenderTarget(pRenderer_regle, texture_titre_regle);
      //SDL_SetRenderDrawColor(pRenderer, 255, 41, 0, 0);
      SDL_RenderClear(pRenderer_regle);

      SDL_RenderCopy(pRenderer_regle,img_fond_regle,nullptr,&position_fond);
      SDL_RenderCopy(pRenderer_regle,texture_img_keyboard,nullptr,&position_keyboard);
      SDL_RenderCopy(pRenderer_regle,texture_img_left,nullptr,&position_left);
      SDL_RenderCopy(pRenderer_regle, texture_titre_regle, nullptr, &position);
      SDL_RenderCopy(pRenderer_regle, texture_sous_titre_regle,nullptr, &position_sous_titre);
      SDL_RenderCopy(pRenderer_regle, texture_good_luck,nullptr, &position_good_luck);


      SDL_RenderPresent(pRenderer_regle);

      SDL_WaitEvent(&event);
        switch(event.type)
        {
            case SDL_MOUSEBUTTONUP:
                if (event.button.x>=position_left.x && event.button.x<=position_left.x+175 && event.button.y>=position_left.y && event.button.y<=position_left.y+74)
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

regle_sdl::~regle_sdl() {
  SDL_DestroyTexture(img_fond_regle);
  SDL_DestroyTexture(texture_img_keyboard);
  SDL_DestroyTexture(texture_img_left);
  SDL_DestroyTexture(texture_titre_regle);
  SDL_DestroyTexture(texture_sous_titre_regle);
  SDL_DestroyTexture(texture_good_luck);
  SDL_DestroyRenderer(pRenderer_regle);
  SDL_DestroyWindow(pWindow_regle);
  TTF_Quit();
  SDL_Quit();
}
