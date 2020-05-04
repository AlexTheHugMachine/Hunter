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
  unsigned int capacity;
   unsigned int size_used;
   ElementTD * ad;
  Menu ();
    /**
     * @brief Constructeur par défaut de la classe Menu
     * @return Renvoie un menu vide
     */
    ~Menu ();
    /**
     * @brief Procédure qui affiche le contenu du menu dans une fenêtre de terminal
     */
    void display () const;
    /**
     * @brief Procédure qui permet de définir les différentes actions que peut faire l'utilisateur dans le menu en fonction de la touche pressée
     * @param m Touche pressée par l'utilisateur
     */
    void action(unsigned int &m) const;
};



#endif
