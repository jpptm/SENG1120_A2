// Declare the functions needed for TowerHanoi within this file

// Author: Johanne Montano
// Course: SENG1120
// Student Number: c3336019

// Will use camel case within this class because presupplied files cannot be altered

// Implement Macroguard
#ifndef TOWER_HANOI_H
#define TOWER_HANOI_H

#include "LStack.h"
#include "Disc.h"

// Try challenge later
// #include <list>

class TowerHanoi
{
public:
    // Initialise constructors for the game
    TowerHanoi();
    TowerHanoi(const int numberOfDiscs);

    // Initialise empty destructor
    ~TowerHanoi();

    // Check if the user's chosen move is valid or not - also will alter the state of the stacks
    // If the move is valid then execute and if not, skip
    bool move(const int rodFrom, const int rodTo);

    // Check the game's state, if the value is true then the game will end
    bool checkWin() const;

private:
    // Declare how many total discs the player wants to play with and the rods we need using stacks
    LStack<Disc> rod1, rod2, rod3;

    // Push diameter to stack
    // --------- Disc disc; ---------
};

// overload << operetor to output the "UI" of the current game state
ostream &operator<<(ostream &out, const TowerHanoi &game);

#endif // TOWER_HANOI_H