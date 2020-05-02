#include "ElementTD.h"
#include "Menu.h"
#include <cstdlib>

#include <iostream>
#include <stdlib.h>
using namespace std;

Menu::Menu () {
    ad = new ElementTD [5];
    capacity = 6;
    size_used= 5;
    ad[0]="Chasse Hunter";
    ad[1]="1.Play";
    ad[2]="2.Rules";
    ad[3]="3.Options";
    ad[4]="4.Exit";
}


Menu::~Menu () {
  delete [] ad;
  ad = NULL;
  capacity = 0;
  size_used = 0;
}


void Menu::display () const {
  for (unsigned int i = 0; i < size_used; i++) {
        cout<<"                     ";
        displayElementTD(ad[i]);
        cout <<endl;
        cout<<endl;
  }
  cout << endl;
}

void display_rules(){
  system("clear");
  cout<<"                     ";
  cout << "Rules" << endl <<endl;
  cout << "Hello and welcome to Chasse Hunter. You are Agent x  "
  <<"recruit by the LAC (a large security agency in Lyon).  Your goal is "
  <<" eliminate enemies without being done."<<endl;
  cout<< "To move press the following keys (azerty keyboard):" << endl;
  cout<<"-z to advance."<<endl;
  cout<<"-s to move back."<<endl;
  cout<<"-q to move left." << endl;
  cout<<"-d to move right." << endl;
  cout<<"We count on you good luck."<<endl<<endl;
  cout<<"Do you want to start playing? Enter the corresponding number"<<endl;
  cout<<"1.Yes     2. No"<<endl;
  unsigned int i;
  cin >> i;
  while ( cin.fail( ) || i < 1 || i> 2) {

    cout << "Error please choose between 1 and 2" << std::endl;
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
    mn.display();
    unsigned int m;
    cout << "What do you want to do? indicate the corresponding figure"<< endl;
    cin >> m;
    mn.action(m);
  }
}

void display_options(){
  system("clear");
  cout<<"                     ";
  cout<<"Options"<<endl<<endl;
  cout<<"This project is being developed as part of UE LIFAP4"
  <<"(Conception et Developpement d'Application). "<<endl
  <<"Realized by Celian LOUIS-ITTY, Alexis Bonis and Lucas Rakotomalala;"<<endl
  <<"all second year students in computer science license at Claude Bernard"
  << "Lyon 1 university."<<endl;
  cout<<"Chasse Hunter is inspired by the Hunter Assasin games availble on"
  <<"the phone."<<endl;
  cout<< "You can consult the documention by indicating the number"<<endl;
  cout << "1.Page of UE LIFAP4    " <<"2.Gameplay mobile games    "
  <<"3.documention   "<<"4.Back to menu"<<endl;
  unsigned int i;
  cin>>i;
  while ( cin.fail( ) || i < 1 || i> 4) {

    cout << "Error please choose between 1 and 4" << std::endl;
    cin.clear();
    cin.ignore(256,'\n');
    cin >> i;
  }
  if(i==1){
    system("xdg-open https://perso.liris.cnrs.fr/alexandre.meyer/public_html/www/doku.php?id=lifap4");
    system("clear");
    display_options();
  }
  if(i==2){
    system("xdg-open https://www.youtube.com/watch?v=ETm0Sg8TPlk");
    system("clear");
    display_options();
  }
  if(i==3){
    system("xdg-open ./doc/html/index.html");
    system("clear");
    display_options();
  }
  if(i==4){
    system("clear");
    Menu mn;
    mn.display();
    unsigned int m;
    cout << "What do you want to do? indicate the corresponding figure" << endl;
    cin >> m;
    mn.action(m);
  }
}

void Menu::action(unsigned int &m) const {
  while ( cin.fail( ) || m < 1 || m> 4) {

    cout << "Error please choose between 1 and 4" << std::endl;
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
    display_rules();
  }
  if(m==3){
    display_options();
  }
  if(m==4){
    cout<<"Thank you for using our app"<<endl;
  }
}
