/** @file Case.h
 */
#ifndef CASE
#define CASE

/** @enum Case
 *  @brief Describes what is on a particular tile
 */
enum Case{
    empty, ///< The tile is free, characters can walk on it
    wall,  ///< There is a wall on the tile
    test,   ///< For testing purposes
    start,  ///< The starting point for the player
    end,    ///< The goal of the player
};


#endif