#ifndef MENU_H
#define MENU_H
#include "ElementTD.h"

#include <string.h>
#include <iostream>

using namespace std;

class TableauDynamique{
public:
  unsigned int capacite;
   unsigned int taille_utilisee;
   ElementTD * ad;
  TableauDynamique ();
    ~TableauDynamique ();
    void afficher () const;
};



#endif
