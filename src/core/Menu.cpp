#include "ElementTD.h"
#include "Menu.h"

#include <iostream>
#include <stdlib.h>
using namespace std;

TableauDynamique::TableauDynamique () {
    ad = new ElementTD [5];
    capacite = 6;
    taille_utilisee = 5;
    ad[0]="Chasse Hunter";
    ad[1]="Affichage Console";
    ad[2]="Affichage Graphique";
    ad[3]="Options";
    ad[4]="Regle du jeu";
}


TableauDynamique::~TableauDynamique () {
  delete [] ad;
  ad = NULL;
  capacite = 0;
  taille_utilisee = 0;
}


void TableauDynamique::afficher () const {
  for (unsigned int i = 0; i < taille_utilisee; i++) {
        afficheElementTD(ad[i]);
        cout <<endl;
        cout<<endl;
  }
  cout << endl;
}
