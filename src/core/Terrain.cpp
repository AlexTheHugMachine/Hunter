//#include "Case.h"
#include "Terrain.h"

#include <iostream>
#include <stdlib.h>
using namespace std;

TableauDynamique2D::TableauDynamique2D () {
    /*ad = new ElementTD [1];
    capacite = 1;
    taille_utilisee = 0;*/
    int **tableau2D = new int*[15];
      for (int i = 0; i < 21; i++)
         tableau2D[i] = new int[21];
}

TableauDynamique2D::~TableauDynamique2D () {
  delete [] tableau2D;
  tableau2D = NULL;
  for (int i = 0; i < 21; i++){
    delete [] tableau2D[i];
    tableau2D[i]=NULL;
}
delete [] tableau2D;
}

void TableauDynamique2D::TableauDynamique2D (const **TableauDynamique2D ) {
  for (unsigned int i=0;i<=15;i++){
    for (unsigned int j=0;j<=21;j++){
      if(i==0 || j==0 || j==15|| i==15 ){
        TableauDynamique[i][j]='/'
      }
    }
  }
}

void TableauDynamique2D::afficher(const **TableauDynamique2D){
  for (unsigned int i=0;i<=15;i++){
    for (unsigned int j=0;j<=21;j++){
      std::cout <<TableauDynamique2D[i][j];
      }
      cout<<endl;
    }
  }
}


int main () {
  TableauDynamique2D *tab=new TableauDynamique2D();
  tab->afficher();
  //t.afficher();
  return 0;
}
