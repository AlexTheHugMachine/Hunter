/** @file Ennemy.h
 */
#ifndef ENNEMIES_H
#define ENNEMIES_H
#include "Vec2.h"
#include "Player.h"
#include "Direction.h"
#include "Terrain.h"

/** @enum State
 *  @brief Descibes the action the Ennemy is performing
 *  @sa Ennemy
 */
enum State { 
    patrol, ///< The ennemy is patrolling along a fixed path
    pursuit, ///< The ennemy is pursuing the player
    dead    ///< The ennemy is dead
};

/** @brief Classe représentant les ennemis du joueur qu'il doit éliminer
 *  @sa Player
 *  @sa Terrain
 */
class Ennemy {
    public :
        /**
         * @brief Initializes the Ennemy
         * @param t [in] Pointer on terrain
         * @param start [in] Staring position of the patrol
         * @param end [in] End position of the patrol path
         */
        Ennemy(const Terrain *t, Vec2 start, Vec2 end);

        /**
         * @brief Destructeur par défaut de la classe ennemies
         */
        ~Ennemy();

        /**
         * @brief Fonction renvoyant la position de l'ennemi
         * @return Renvoie le vecteur position de l'ennemi
         */
        Vec2 getPos() const;

        /** @brief Moves according to its state
         */
         /* @param T [in] Terrain
         *  @param P [in] Player */
        void update(/*const Terrain & T, const Player & P*/);

        /** @brief Test the Ennemy class
         * 
         *  This is a regressino test
         */
        void test(const Terrain *t) const;
        
    private :
        Vec2 pos;       ///< Position
        Direction dir;  ///< Direction
        State state;    ///< State
        Vec2* patrolPath;   ///< Patrol path
        int length;     ///< Patrol path length
        int patrolPos;  ///< Position on the patrol path
        int patrolInc;  ///< Increment to move along the patrol path

    private:
        /** @brief Moves towards the Player
         *  @param T [in] Terrain
         *  @param P [in] Player
         */
        void chasePlayer(const Terrain & T, const Player & P);

        /** @brief Moves along the predefined patrol path
         */
        void patrol();
};

#endif