#ifndef ENNEMIES_H
#define ENNEMIES_H
#include "Vec2.h"
#include "player.h"
#include "direction.h"
//#include "Terrain.h"

class ennemies {
    private :
        Vec2 Pos;
        direction dir;
        enum etat { VivantRonde, VivantPoursuite, Mort };
        //Vec2 Ronde
    public :
        ennemies();
        ~ennemies();
        Vec2 GetPos() const;
        //void chasseJoueur(TableauDynamique2D T, player P);
        //void mouvementAuto(TableauDynamique2D T);
        //void update(TableauDynamique2D T, player P);
};

#endif