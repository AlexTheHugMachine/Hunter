#include "ElementTD.h"
#include "Menu.h"
#include <cstdlib>

#include <iostream>
#include <stdlib.h>
using namespace std;

Menu::Menu () {
    ad = new ElementTD [5];
    capacite = 6;
    taille_utilisee = 5;
    ad[0]="Chasse Hunter";
    ad[1]="1.Jouer";
    ad[2]="2.Regle du jeu";
    ad[3]="3.Options";
    ad[4]="4.Quitter";
}


Menu::~Menu () {
  delete [] ad;
  ad = NULL;
  capacite = 0;
  taille_utilisee = 0;
}


void Menu::afficher () const {
  for (unsigned int i = 0; i < taille_utilisee; i++) {
        cout<<"                     ";
        afficheElementTD(ad[i]);
        cout <<endl;
        cout<<endl;
  }
  cout << endl;
}

void afficher_regle(){
  system("clear");
  cout<<"                     ";
  cout << "Regle du jeu" << endl <<endl;
  cout << "Bonjour et bienvenue dans Chasse Hunter. Vous êtes Agent x "
  <<"recruter par le LAC (une grande agence de sécurité à Lyon). Votre but est d éliminer les ennemis sans se faire"
  <<"d éliminer les ennemis sans se faire repérer."<<endl;
  cout<< "Pour se déplacer appuyer sur les touches suivantes:" << endl;
  cout<<"-z pour avancer."<<endl;
  cout<<"-s pour reculer."<<endl;
  cout<<"-q pour se déplacer à gauche." << endl;
  cout<<"-d pour se déplacer à droite." << endl;
  cout<<"On compte sur vous bonne chanse."<<endl<<endl;
  cout<<"Voulez-vous commencer à jouer? Entrer le chiffre correspondant"<<endl;
  cout<<"1.Oui      2. Non"<<endl;
  unsigned int i;
  cin >> i;
  while ( cin.fail( ) || i < 1 || i> 2) {

    cout << "Erreur veuillez choisir entre 1 et 2" << std::endl;
    cin.clear();
    cin.ignore(256,'\n');
    cin >> i;
  }
  if(i==1){
    txtGame txt;
    txt.txtmain();
  }
  else{
    system("clear");
    Menu mn;
    mn.afficher();
    unsigned int m;
    cout << "Que voulez vous faire? indiquer le chiffre correspondant" << endl;
    cin >> m;
    mn.action(m);
  }
}

void afficher_option(){
  system("clear");
  cout<<"                     ";
  cout<<"Option"<<endl<<endl;
  cout<<"Ce projet est élaboré dans le cadre de l'UE LIFAP4"
  <<"(Conception et Developpement d'Application). "<<endl
  <<"Realiser par Celian LOUIS-ITTY, Alexis Bonis et Lucas Rakotomalala; "<<endl
  <<"tous étudiants en deuxième année en licence informatique au sein de "
  << "l université Claude Bernard"<<endl << "Lyon 1."<<endl;
  cout<<"Chasse Hunter s'inspire du jeux Hunter Assassin disponible sur telephone"
  <<endl;
  cout<< "Vous pouvez consulter la documention en indiquant le chiffre"<<endl;
  cout << "1.Page de l'UE LIFAP4    " <<"2.Gameplay jeux mobiles    "
  <<"3.documention   "<<"4.Retour au menu"<<endl;
  unsigned int i;
  cin>>i;
  while ( cin.fail( ) || i < 1 || i> 4) {

    cout << "Erreur veuillez choisir entre 1 et 4" << std::endl;
    cin.clear();
    cin.ignore(256,'\n');
    cin >> i;
  }
  //il faudra fermer le navigateur pour pouvoir continuer le programme
  if(i==1){
    system("xdg-open https://perso.liris.cnrs.fr/alexandre.meyer/public_html/www/doku.php?id=lifap4");
    system("clear");
    afficher_option();
  }
  if(i==2){
    system("xdg-open https://www.youtube.com/watch?v=ETm0Sg8TPlk");
    system("clear");
    afficher_option();
  }
  if(i==3){
    system("xdg-open ./doc/html/index.html");
    system("clear");
    afficher_option();
  }
  if(i==4){
    system("clear");
    Menu mn;
    mn.afficher();
    unsigned int m;
    cout << "Que voulez vous faire? indiquer le chiffre correspondant" << endl;
    cin >> m;
    mn.action(m);
  }
}

void Menu::action(unsigned int &m) const {
  while ( cin.fail( ) || m < 1 || m> 4) {

    cout << "Erreur veuillez choisir entre 1 et 4" << std::endl;
    cin.clear();
    cin.ignore(256,'\n');
    cin >> m;
  }
  if(m==1){
    system("clear");
    txtGame txt;
    txt.txtmain();
  }
  if(m==2){
    afficher_regle();
  }
  if(m==3){
    afficher_option();
  }
  if(m==4){
    cout<<"Merci d'avoir visité notre application"<<endl;
  }
}
