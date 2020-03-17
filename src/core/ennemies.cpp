#include "ennemies.h"

ennemies::ennemies() {
    Pos.x = 1;
    Pos.y = 1;
}

Vec2 ennemies::GetPos() const {
    return Pos;
}

/*
void ennemies::chasseJoueur(TableauDynamique 2D, player P) {

}

void ennemies::mouvementAuto(TableauDynamique2D T) {

}

void ennemies::update(TableauDynamique2D T, player P) {

}
*/