#ifndef PLAYER_H
#define PLAYER_H
#include "Vec2.h"
#include "Direction.h"
#include "Terrain.h"

/** Represent the player
 * 
 */
class Player {
    public :
        /** Default constructor : initializes at (0, 0)
         *  
         */
        Player();

        /**
         * @brief
         * Destructeur par défaut de la classe player
         */
        ~Player();

        /** 
         * @brief
         * Fonction renvoyant la position du joueur
         * @return
         * Renvoie le vecteur de la position du joueur
         */
        Vec2 getPos() const;

        /**
         * @brief
         * Fonction permettant le déplacement du joueur sur un terrain en fnction d'une direction
         * @param T Terrain
         * @param D Direction
         * @return Renvoie la position du joueur après modification des coordonnées
         */
        void move(Terrain T, Direction D);

        /**
         * @brief
         * Procédure permettant d'initialiser une position du joueur
         * @param V Prend en paramètre un vecteur V
         */
        void setPos(Vec2 V);

        /** Test the player class
         */
        void test() const;
    
    private :
        Vec2 pos; ///< Player position
};

#endif