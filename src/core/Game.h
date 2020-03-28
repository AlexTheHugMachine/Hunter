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
     */
    Game();

    ~Game();

    /** @brief Updates the game state
     *  @param d [in] Direction the player is moving in
     *  @return true if the player wins (no more ennemies)
     */
    bool UpdateGame(Direction d);

    /** @brief Access the player class
     *  @return Vec2
     */
    Vec2 getPlayerPos() const;

    /** @brief Get the position of all the living Ennemies
     *  @return Pointer on array of Vec2
     *  @param s [out] size of the array
     *  @warning Don't forget to delete the array!
     */
    Vec2* getEnnemiesPosition(int& s) const;

    /** @brief Access the terrain
     *  @return Reference to the terrain
     *  @warning Don't change the terrain !
     */
    Terrain& getTerrain();

private:
    Terrain t;  ///< Terrain
    Player p;   ///< Player
    Ennemy* E;  ///< Array of Ennemies
    int NbE;    ///< Number of Ennemies


};

#endif
