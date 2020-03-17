#ifndef PLAYER_H
#define PLAYER_H
#include "Vec2.h"
#include "direction.h"
#include "Terrain.h"

/** Represent the player
 * 
 */
class player {
    private :
        Vec2 Pos;
    public :
        /**
         * @brief
         * Fonction renvoyant la position du joueur
         * @return
         * Renvoie le vecteur de la position du joueur
         */
        Vec2 GetPos() const;
        /**
         * @brief
         * Fonction permettant le déplacement du joueur sur un terrain en fnction d'une direction
         * @param T Terrain
         * @param D Direction
         * @return Renvoie la position du joueur après modification des coordonnées
         */
        Vec2 Move(Terrain T, direction D);
        /**
         * @brief
         * Procédure permettant d'initialiser une position du joueur
         * @param V Prend en paramètre un vecteur V
         */
        void SetPos(Vec2 V);
        /**
         * @brief
         * Constructeur par défaut de la classe player
         */
        player();
        /**
         * @brief
         * Destructeur par défaut de la classe player
         */
        ~player();
};

#endif