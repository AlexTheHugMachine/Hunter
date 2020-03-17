#ifndef ENNEMIES_H
#define ENNEMIES_H
#include "Vec2.h"
#include "player.h"
#include "direction.h"
//#include "Terrain.h"

/**
 * Classe représentant les ennemis du joueur qu'il doit éliminer
 */
class ennemies {
    private :
        Vec2 Pos;
        direction dir;
        enum etat { VivantRonde, VivantPoursuite, Mort };
        //Vec2 Ronde
    public :
        /**
         * @brief
         * Constructeur par défaut de la classe ennemies
         */
        ennemies();
        /**
         * @brief
         * Destructeur par défaut de la classe ennemies
         */
        ~ennemies();
        /**
         * @brief
         * Fonction renvoyant la position de l'ennemi
         * @return
         * Renvoie le vecteur position de l'ennemi
         */
        Vec2 GetPos() const;
        //void chasseJoueur(TableauDynamique2D T, player P);
        //void mouvementAuto(TableauDynamique2D T);
        //void update(TableauDynamique2D T, player P);
};

#endif