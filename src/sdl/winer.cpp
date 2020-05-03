#include "winer.h"

using namespace std;

template<typename T>
constexpr T WIDTHSCREEN{ 800 };

template<typename T>
constexpr T HEIGHTSCREEN{ 600 };

template<typename T>
constexpr T TOTAL_POINTS{ 5000 };

winer::winer() {
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

  if (font == nullptr)
  {
    SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "[DEBUG] > %s", TTF_GetError());
  }
  // Create surface
  Title = TTF_RenderText_Blended(font, "YOU WIN CONGRATULATION!", SDL_Color{ 255, 255, 255, 0 });

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
  position.y = HEIGHTSCREEN<int> /2;

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
      SDL_RenderClear(pRenderer);
      SDL_RenderCopy(pRenderer, title_texture, nullptr, &position);
      SDL_RenderPresent(pRenderer);
      SDL_WaitEvent(&event);
      switch(event.type)
        {
            case SDL_MOUSEBUTTONUP:
                if (event.button.x>=0 && event.button.y>=0)
                {
                  menu_sdl mn;
                  TTF_Quit();
                  SDL_Quit();
                }
        }
  }

  exit(1);
}

winer::~winer() {
  SDL_DestroyTexture(title_texture);
  SDL_DestroyRenderer(pRenderer);
  SDL_DestroyWindow(pWindow);
  TTF_Quit();
  SDL_Quit();
}
