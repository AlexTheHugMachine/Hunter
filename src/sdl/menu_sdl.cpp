#include "menu_sdl.h"

template<typename T>
constexpr T WIDTHSCREEN{ 800 };

template<typename T>
constexpr T HEIGHTSCREEN{ 600 };

template<typename T>
constexpr T TOTAL_POINTS{ 5000 };

int menu_sdl::main_menu_sdl() {
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "[DEBUG] > %s", SDL_GetError());
        return EXIT_FAILURE;
    }

    if (TTF_Init() < 0)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "[DEBUG] > %s", TTF_GetError());
        return EXIT_FAILURE;
    }

    SDL_Window* pWindow{ nullptr };
    SDL_Renderer* pRenderer{ nullptr };

     if (SDL_CreateWindowAndRenderer(WIDTHSCREEN<unsigned int>, HEIGHTSCREEN<unsigned int>, SDL_WINDOW_SHOWN, &pWindow, &pRenderer) < 0)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "[DEBUG] > %s", SDL_GetError());
        SDL_Quit();
        return EXIT_FAILURE;
    }

    SDL_Event events;
    bool isOpen{ true };

    //attention !! les polices se trouvents dans des fichiers diiférents
    TTF_Font* font = TTF_OpenFont("/usr/share/fonts/truetype/Sarai/Sarai.ttf", 50); // Crée un police avec la police "ariali.ttf" et de taille 18 pixels
    TTF_Font* sous_titre = TTF_OpenFont("/usr/share/fonts/truetype/Sarai/Sarai.ttf", 40);

    if (font == nullptr)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "[DEBUG] > %s", TTF_GetError());

    }

    SDL_Surface* Titre = TTF_RenderText_Blended(font, "HUNTER", SDL_Color{ 255, 255, 255, 0 }); // Crée un surface qui contient le texte
    SDL_Surface* Txt = TTF_RenderText_Blended(sous_titre, "Affichage texte", SDL_Color{ 255, 255, 255, 0 });
    SDL_Surface* Graphique = TTF_RenderText_Blended(sous_titre, "Affichage graphique", SDL_Color{ 255, 255, 255, 0 });
    SDL_Surface* Options = TTF_RenderText_Blended(sous_titre, "Options", SDL_Color{ 50, 50, 255, 0 });
    SDL_Surface* Regle_du_Jeu = TTF_RenderText_Blended(sous_titre, "Regle du jeu", SDL_Color{ 50, 50, 255, 0 });
    SDL_Surface* Quitter = TTF_RenderText_Blended(sous_titre, "Quitter", SDL_Color{ 255, 255, 255, 0 });

    if (Titre == nullptr)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "[DEBUG] > %s", TTF_GetError());
    }

    //fond
    SDL_Surface *img_fond_charge = SDL_LoadBMP("data/testimage.bmp");
    if (img_fond_charge == NULL) // Car la doc nous dit qu'il y a un cas où cela peut être NULL
    {
        printf("Impossible de charger 'testimage.bmp' : %s\n",SDL_GetError()); // Affichage d'un message d'erreur et utilisation de SDL_GetError() pour avoir plus d'informations, comme le dit la doc
        return -1;
    }

    SDL_Texture *img_fond = SDL_CreateTextureFromSurface(pRenderer, img_fond_charge);

    SDL_Rect position_fond;

    SDL_QueryTexture(img_fond, nullptr, nullptr, &position_fond.w, &position_fond.h);
    position_fond.x = 0;
    position_fond.y = 0;


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
    SDL_Texture* texture_titre = SDL_CreateTextureFromSurface(pRenderer, Titre); // Crée la texture qu'on va afficher a partir de la surface

    if (texture_titre == nullptr)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "[DEBUG] > %s", TTF_GetError());
    }

    SDL_Rect position;

    SDL_QueryTexture(texture_titre, nullptr, nullptr, &position.w, &position.h); // Récupere la dimension de la texture

    // Centre le titre
    position.x = WIDTHSCREEN<int> / 2 - position.w / 2;
    position.y = 10;

    //txt
     if (Txt == nullptr)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "[DEBUG] > %s", TTF_GetError());
    }

    SDL_Texture* texture_sous_titre = SDL_CreateTextureFromSurface(pRenderer, Txt); // Crée la texture qu'on va afficher a partir de la surface

    if (texture_sous_titre == nullptr)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "[DEBUG] > %s", TTF_GetError());
    }

    SDL_Rect position_sous_titre;

    SDL_QueryTexture(texture_sous_titre, nullptr, nullptr, &position_sous_titre.w, &position_sous_titre.h); // Récupere la dimension de la texture

    position_sous_titre.x = WIDTHSCREEN<int> / 2 - position_sous_titre.w / 2;
    position_sous_titre.y = 100;

    //graphique
    SDL_Texture* Graphique_texture = SDL_CreateTextureFromSurface(pRenderer, Graphique); // Crée la texture qu'on va afficher a partir de la surface

    if (Graphique_texture == nullptr)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "[DEBUG] > %s", TTF_GetError());
    }

    SDL_Rect position_graphique;

    SDL_QueryTexture(Graphique_texture, nullptr, nullptr, &position_graphique.w, &position_graphique.h); // Récupere la dimension de la texture

    // Centre le titre
    position_graphique.x = WIDTHSCREEN<int> / 2 - position_graphique.w / 2;
    position_graphique.y = 200;

    //options
    SDL_Texture* Options_texture = SDL_CreateTextureFromSurface(pRenderer, Options); // Crée la texture qu'on va afficher a partir de la surface

    SDL_Rect position_Options;

    SDL_QueryTexture(Options_texture, nullptr, nullptr, &position_Options.w, &position_Options.h); // Récupere la dimension de la texture

    position_Options.x = WIDTHSCREEN<int> / 2 - position_Options.w / 2;
    position_Options.y = 300;

    //regle du jeu
    SDL_Texture* regle_texture = SDL_CreateTextureFromSurface(pRenderer, Regle_du_Jeu); // Crée la texture qu'on va afficher a partir de la surface

    SDL_Rect position_regle;

    SDL_QueryTexture(Options_texture, nullptr, nullptr, &position_regle.w, &position_regle.h); // Récupere la dimension de la texture

    position_regle.x = WIDTHSCREEN<int> / 2 - position_regle.w / 2;
    position_regle.y = 400;

    //quitter
    SDL_Texture* Quitter_texture = SDL_CreateTextureFromSurface(pRenderer, Quitter); // Crée la texture qu'on va afficher a partir de la surface

    SDL_Rect position_quitter;

    SDL_QueryTexture(Options_texture, nullptr, nullptr, &position_quitter.w, &position_quitter.h); // Récupere la dimension de la texture

    position_quitter.x = WIDTHSCREEN<int> / 2 - position_quitter.w / 2;
    position_quitter.y = 500;



    // Libération des resource de la police et de la surface qui contient le texte
    SDL_FreeSurface(Titre);
    TTF_CloseFont(font);
    SDL_FreeSurface(Txt);
    SDL_FreeSurface(Graphique);
    SDL_FreeSurface(Options);
    SDL_FreeSurface(Regle_du_Jeu);
    SDL_FreeSurface(Quitter);
    TTF_CloseFont(sous_titre);
    SDL_FreeSurface(img_fond_charge);


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
        SDL_SetRenderTarget(pRenderer, texture_titre);
        //SDL_SetRenderDrawColor(pRenderer, 255, 41, 0, 0);
        SDL_RenderClear(pRenderer);

        SDL_RenderCopy(pRenderer,img_fond,nullptr,&position_fond);
        SDL_RenderCopy(pRenderer, texture_titre, nullptr, &position);
        SDL_RenderCopy(pRenderer, texture_sous_titre, nullptr, &position_sous_titre);
        SDL_RenderCopy(pRenderer,Graphique_texture,nullptr,&position_graphique);
        SDL_RenderCopy(pRenderer,Options_texture,nullptr,&position_Options);
        SDL_RenderCopy(pRenderer,regle_texture,nullptr,&position_regle);
        SDL_RenderCopy(pRenderer,Quitter_texture,nullptr,&position_quitter);

        SDL_RenderPresent(pRenderer);
    }

    SDL_DestroyTexture(img_fond);
    SDL_DestroyTexture(texture_titre);
    SDL_DestroyTexture(texture_sous_titre);
    SDL_DestroyRenderer(pRenderer);
    SDL_DestroyWindow(pWindow);
    TTF_Quit();
    SDL_Quit();

    return EXIT_SUCCESS;
}

menu_sdl::menu_sdl() {

}

menu_sdl::~menu_sdl() {

}