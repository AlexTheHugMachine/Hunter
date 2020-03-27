/** @file Game.h
 */
#ifndef _GAME_H
#define _GAME_H

#include "Player.h"
#include "Terrain.h"
#include "Ennemy.h"

/** @brief The game class stores the information related to the logic of the game
 *  @sa WinTxt
 */
class Game
{
public:
    /** @brief Initializes the game
     *  @param n [in] Number of Ennemies
     */
    Game(int n);

    ~Game();

    /** @brief Updates the game state
     *  @param d [in] Direction the player is moving in
     */
    void UpdateGame(Direction d);

private:
    Player p;   ///< Player
    Terrain t;  ///< Terrain
    Ennemy* E;  ///< Array of Ennemies
    int NbE;    ///< Number of Ennemies


};

#endif
