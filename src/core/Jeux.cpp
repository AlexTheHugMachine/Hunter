#include "Jeux.h"

Jeu::Jeu () : ter(), play(), enn() {
	//ter.mangePastille(pac.getX(),pac.getY());
}

Terrain& Jeu::getTerrain () { return ter; }

Player& Jeu::getPos() {	return pac; }

const Terrain& Jeu::getConstTerrain () const { return ter; }

const Player& Jeu::getPos () const { return play; }

const Ennemy& Jeu::getConstPos() const { return Enn; }

int Jeu::getNombreDeEnnemy() const { return 1; }


bool Jeu::actionClavier (const char touche) {
	switch(touche) {
		case 'g' :
				pac.gauche(ter);
				break;
		case 'd' :
				pac.droite(ter);
				break;
		case 'h' :
				pac.haut(ter);
				break;
		case 'b' :
				pac.bas(ter);
				break;
	}
	if (ter.getXY(pac.getX(),pac.getY())=='.') {
	    ter.mangePastille(pac.getX(),pac.getY());
        return true;
	}
	return false;
}

//void Jeu::actionsAutomatiques () {
    //fan.versPacman(ter,pac);
    fan.bougeAuto(ter);
}
