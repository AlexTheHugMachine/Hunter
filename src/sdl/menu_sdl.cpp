#include "menu_sdl.h"
#include "rules_sdl.h"
#include "option_sdl.h"
#include "WinSdl.h"
using namespace std;

template<typename T>
constexpr T WIDTHSCREEN{ 800 };

template<typename T>
constexpr T HEIGHTSCREEN{ 600 };

template<typename T>
constexpr T TOTAL_POINTS{ 5000 };


menu_sdl::menu_sdl() {
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

   pWindow= nullptr ;
 pRenderer= nullptr ;

   if (SDL_CreateWindowAndRenderer(WIDTHSCREEN<unsigned int>,
        HEIGHTSCREEN<unsigned int>, SDL_WINDOW_SHOWN, &pWindow, &pRenderer) < 0)
  {
      SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "[DEBUG] > %s", SDL_GetError());
      SDL_Quit();
      SDL_Quit(); exit(1);
  }

  SDL_Event events;
  bool isOpen{ true };

  font = TTF_OpenFont("data/minecraft_font.ttf", 50);
  subtitles = TTF_OpenFont("data/minecraft_font.ttf", 40);

  if (font == nullptr|| subtitles==nullptr)
  {
    SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "[DEBUG] > %s", TTF_GetError());
  }
  // Create surface
  Title = TTF_RenderText_Blended(font, "HUNTER", SDL_Color{ 255, 255, 255, 0 });
  Txt = TTF_RenderText_Blended(subtitles, "Play",
                                                SDL_Color{ 255, 255, 255, 0 });
  Options = TTF_RenderText_Blended(subtitles, "Options",
                                              SDL_Color{ 255, 255, 255, 0 });
  Rules= TTF_RenderText_Blended(subtitles,"Rules",
                                                SDL_Color{ 255, 255, 255, 0 });
  Exit = TTF_RenderText_Blended(subtitles, "Exit",
                                                SDL_Color{ 255, 255, 255, 0 });

  if (Title == nullptr)
  {
      SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "[DEBUG] > %s", TTF_GetError());
  }

  //background
  img_background_charge = SDL_LoadBMP("data/hunter.bmp");
  if (img_background_charge == NULL)
  {
    // Affichage d'un message d'erreur et utilisation de SDL_GetError()
    printf("Unable to load 'hunter.bmp' : %s\n",SDL_GetError());
    exit(1);
  }

  img_background = SDL_CreateTextureFromSurface(pRenderer,img_background_charge);

  SDL_Rect position_background;

  SDL_QueryTexture(img_background, nullptr, nullptr, &position_background.w,
                                                    &position_background.h);
  position_background.x = 0;
  position_background.y = 0;



//Title
  // Create texture
  title_texture = SDL_CreateTextureFromSurface(pRenderer, Title);

  if (title_texture == nullptr)
  {
      SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "[DEBUG] > %s", TTF_GetError());
  }

  SDL_Rect position;

  //Retrieve the dimension of the texture
  SDL_QueryTexture(title_texture, nullptr, nullptr, &position.w, &position.h);

  // Center title
  position.x = WIDTHSCREEN<int> / 2 - position.w / 2;
  position.y = 10;

//txt
   if (Txt == nullptr)
  {
    SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "[DEBUG] > %s", TTF_GetError());
  }

  subtitles_texture = SDL_CreateTextureFromSurface(pRenderer, Txt);

  if (subtitles_texture == nullptr)
  {
    SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "[DEBUG] > %s", TTF_GetError());
  }

  SDL_Rect position_subtitles;


  SDL_QueryTexture(subtitles_texture, nullptr, nullptr, &position_subtitles.w,
                                                        &position_subtitles.h);

  position_subtitles.x = WIDTHSCREEN<int> / 2 - position_subtitles.w / 2;
  position_subtitles.y = 100;


  //options
 Options_texture = SDL_CreateTextureFromSurface(pRenderer, Options);

  SDL_Rect position_Options;

  SDL_QueryTexture(Options_texture, nullptr, nullptr, &position_Options.w,
                                                      &position_Options.h);

  position_Options.x = WIDTHSCREEN<int> / 2 - position_Options.w / 2;
  position_Options.y = 300;

//Rules
  rules_texture = SDL_CreateTextureFromSurface(pRenderer, Rules);

  SDL_Rect position_rules;

  SDL_QueryTexture(Options_texture, nullptr, nullptr, &position_rules.w,
                                                     &position_rules.h);

  position_rules.x = WIDTHSCREEN<int> / 2 - position_rules.w / 2;
  position_rules.y = 200;

//exit
  exit_texture = SDL_CreateTextureFromSurface(pRenderer, Exit);

  SDL_Rect position_exit;

  SDL_QueryTexture(exit_texture, nullptr, nullptr, &position_exit.w,
                                                  &position_exit.h);

    position_exit.x = WIDTHSCREEN<int> / 2 - position_exit.w / 2;
    position_exit.y = 400;


  /*SDL_QueryTexture(Options_texture, nullptr, nullptr, &position_quitter.w, &position_quitter.h); // Récupere la dimension de la texture
    
    position_quitter.x = WIDTHSCREEN<int> / 2 - position_quitter.w / 2;
    position_quitter.y = 400;*/

    SDL_Event event;


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
      SDL_SetRenderTarget(pRenderer,title_texture);
      //SDL_SetRenderDrawColor(pRenderer, 255, 41, 0, 0);
      SDL_RenderClear(pRenderer);

      SDL_RenderCopy(pRenderer,img_background,nullptr,&position_background);
      SDL_RenderCopy(pRenderer, title_texture, nullptr, &position);
      SDL_RenderCopy(pRenderer, subtitles_texture, nullptr,&position_subtitles);
      SDL_RenderCopy(pRenderer,Options_texture,nullptr,&position_Options);
      SDL_RenderCopy(pRenderer,rules_texture,nullptr,&position_rules);
      SDL_RenderCopy(pRenderer,exit_texture,nullptr,&position_exit);

      SDL_RenderPresent(pRenderer);

      SDL_WaitEvent(&event);
        switch(event.type)
        {
            case SDL_MOUSEBUTTONUP:
                if (event.button.x>=position.x &&
                    event.button.x<=position_subtitles.x+150 &&
                    event.button.y>=position_subtitles.y &&
                    event.button.y<=position_subtitles.y+50)
                {
                  WinSdl game;
                  game.run();
                  TTF_Quit();
                  SDL_Quit();
                }
                if (event.button.x>=position_Options.x &&
                    event.button.x<=position_Options.x+180 &&
                    event.button.y>=position_Options.y &&
                    event.button.y<=position_Options.y+50)
                {
                    TTF_Quit();
                    SDL_Quit();
                    option_sdl op;

                }
                if (event.button.x>=position_rules.x &&
                    event.button.x<=position_rules.x+180 &&
                    event.button.y>=position_rules.y &&
                    event.button.y<=position_rules.y+50)
                {
                    TTF_Quit();
                    SDL_Quit();
                    rules_sdl rules;

                }
                if (event.button.x>=position_exit.x &&
                    event.button.x<=position_exit.x+180 &&
                    event.button.y>=position_exit.y &&
                    event.button.y<=position_exit.y+50)
                {
                    cout<<"Thank you for using our app"<<endl;
                    TTF_Quit();
                    SDL_Quit();
                    exit(1);

                }
                break;
        }
    }



  exit(1);
}

menu_sdl::~menu_sdl() {
  SDL_DestroyTexture(img_background);
  SDL_DestroyTexture(title_texture);
  SDL_DestroyTexture(subtitles_texture);
  SDL_DestroyRenderer(pRenderer);
  SDL_DestroyWindow(pWindow);
  TTF_Quit();
  SDL_Quit();
}
