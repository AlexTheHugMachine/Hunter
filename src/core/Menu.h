#ifndef MENU_H
#define MENU_H
#include "ElementTD.h"
#include "Game.h"
#include "txtGame.h"
#include "WinTxt.h"

#include <string.h>
#include <iostream>

using namespace std;

class Menu{
public:
  unsigned int capacite;
   unsigned int taille_utilisee;
   ElementTD * ad;
  Menu ();
    ~Menu ();
    void afficher () const;
    void action(unsigned int &m) const;
};



#endif
