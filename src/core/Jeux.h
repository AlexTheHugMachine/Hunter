#ifndef _JEU_H
#define _JEU_H

#include "Player.h"
#include "Terrain.h"
#include "Ennemy.h"

/**
@brief Un jeu (de pacman) = un terrain et un pacman
*/
class Jeu {

private :

	Terrain ter;
	Player play;
	Ennemy enn;

public :

    Jeu ();

    Terrain& getTerrain ();
    Ennemy& getEnnemy (); //ajouter

    const Terrain& getConstTerrain () const;
    const Player& getPos () const;
    const Fantome& getPos() const;
    int getNombreDeEnnemy() const;//A ajouter dans Ennemy
    bool actionClavier(const char touche);
    //ajouter padfinding;

};

#endif
