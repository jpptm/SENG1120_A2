//TowerHanoiDemo - Main Program
/******************************/
//Author: SENG1120 Staff
//Course: SENG1120
//Program Description: This program demonstrates the basic functionality of stacks. 

#include <iostream>
#include <cstdlib>
#include "TowerHanoi.h"

using namespace std;

int main()
{
	int numberOfDiscs = 0;
	int numberOfMoves = 0;
	int rodFrom, rodTo;
	bool validMove;
	bool gameEnded = false;

	// get the number of Discs the game will use - 1 is the minimum and 5 is the maximum
	do
	{
		cout << "Please input the number of discs (max 5):" << endl;
		cin >> numberOfDiscs;
	}
	while ((numberOfDiscs < 1) || (numberOfDiscs > 5));
	
	// instantiate game
	// we pass in the number of Discs to use for this game, then instantiate the LStacks!
	TowerHanoi game = TowerHanoi(numberOfDiscs);


	// ---- start of the game --------

	// print the current state of the game on the screen
	cout << game; 

	// this is the Game Loop
	while(!gameEnded)
	{
		// ask for the next move
		cout << "Please input the rod to remove from (1, 2 or 3): " << endl;	
		cin >> rodFrom;
		cout << "Please input the rod to place onto (1, 2 or 3): " << endl;	
		cin >> rodTo;

		// move should perform all the checks and only move a disc if the movement is allowed. 
		// If the movement is valid, return true; otherwise, return false.
		validMove = game.move(rodFrom, rodTo); 
		
		if (validMove)
		{
			numberOfMoves++;
		    cout << game; // print the current state of the game on the screen
		    gameEnded = game.checkWin(); // checks if the 3rd rod contains all the discs
		}
		else 
		{
			// does not make move, and prints message saying the move is not valid
			cout << "Move not valid." << endl;
		}
	}

	// ---- end of the game --------

	// print out a message and some stats.
	cout << "The game has ended." << endl; 
	cout << "You required " << numberOfMoves << " moves to win." << endl; 

	// done
	return 0;
}
