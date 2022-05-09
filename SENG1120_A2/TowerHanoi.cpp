// Implement the functions of TowerHanoi.h within this class
#include "TowerHanoi.h"

// Author: Johanne Montano
// Course: SENG1120
// Student Number: c3336019

// Constructors
TowerHanoi::TowerHanoi()
{
    // Initialise all member variables within this default constructor
    rod1 = LStack<Disc>();
    rod2 = LStack<Disc>();
    rod3 = LStack<Disc>();
}

TowerHanoi::TowerHanoi(const int numberOfDiscs)
{
    // Initialise rod 2 and rod 3 to be empty and fill rod 1 with the number of discs the user has chosen
    rod2 = LStack<Disc>();
    rod3 = LStack<Disc>();

    // rod1 = .....
}

// Empty destructor
TowerHanoi::~TowerHanoi() {}

// Move rods if the chosen move is valid else skip - use overloaded < operator from disc
bool TowerHanoi::move(const int rodFrom, const int rodTo)
{
    // Init
    return true;
}

// Check game state every turn - if the first 2 rods are empty and rod 3 has all the discs properly sorted
// the game must finish since the player has successfully moved all discs to the final rod
bool TowerHanoi::checkWin() const
{
    // Init
    return true;
}