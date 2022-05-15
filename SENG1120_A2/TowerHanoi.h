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
    bool move(int rodFrom, int rodTo);

    // Check the game's state, if the value is true then the game will end
    bool checkWin();

    // Make helper function to make string as ostream& output
    ostream &printGame(ostream &finalState);

private:
    // Initialise each rod as a stack of discs
    LStack<Disc> rods[3];
};

// overload << operator to output the "UI" of the current game state
ostream &operator<<(ostream &out, TowerHanoi &game);

#endif // TOWER_HANOI_H