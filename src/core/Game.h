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
     */
    void UpdateGame(Direction d);

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
     *  @return Pointer on array of Case
     *  @param dim [out] Vec2 comprised of the dimensions of the terrain
     *  @warning Don't forget to delete the array!
     */
    Case* getTerrain(Vec2& dim) const;

    Terrain t;  ///< Terrain
private:
    Player p;   ///< Player
    Ennemy* E;  ///< Array of Ennemies
    int NbE;    ///< Number of Ennemies


};

#endif
