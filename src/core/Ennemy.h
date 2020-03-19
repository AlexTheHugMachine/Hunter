#ifndef ENNEMIES_H
#define ENNEMIES_H
#include "Vec2.h"
#include "Player.h"
#include "Direction.h"
#include "Terrain.h"

enum State { 
    patrol, 
    pursuit, 
    dead 
};

/**
 * Classe représentant les ennemis du joueur qu'il doit éliminer
 */
class Ennemy {
    public :
        /**
         * @brief
         * Constructeur par défaut de la classe ennemies
         */
        Ennemy();

        /**
         * @brief
         * Destructeur par défaut de la classe ennemies
         */
        ~Ennemy();

        /**
         * @brief
         * Fonction renvoyant la position de l'ennemi
         * @return
         * Renvoie le vecteur position de l'ennemi
         */
        Vec2 getPos() const;

        /** @brief Moves according to its state
         */
        void update(const Terrain & T, const Player & P);

        /** @brief Test the Ennemy class
         */
        void test() const;
        
    private :
        Vec2 pos;       ///< Position
        Direction dir;  ///< Direction
        State state;    ///< State
        //Vec2 Ronde

    private:
        /** @brief Moves towards the Player
         *  @param T [in] Terrain
         *  @param P [in] Player
         */
        void chasePlayer(const Terrain & T, const Player & P);

        /** @brief Moves along a predefined path
         *  @param [in] Terrain
         */
        void patrol(const Terrain & T);
};

#endif