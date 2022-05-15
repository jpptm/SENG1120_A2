// Implement the functions of TowerHanoi.h within this class
#include "TowerHanoi.h"
#include <string>
#include <cstring>

// Author: Johanne Montano
// Course: SENG1120
// Student Number: c3336019

// Constructors - default one is empty because we don't want to reinstantiate everything
TowerHanoi::TowerHanoi()
{
}

TowerHanoi::TowerHanoi(const int numberOfDiscs)
{
    // Use backwards for loop to initialise rod 1 - rods 2 and 3 are now empty at this point so we just have to fill rod 1 in
    for (int i = numberOfDiscs; i > 0; i--)
    {
        // Use temp var to set each disc's ui and diameter
        string DiscUI = "";
        int x_count = 2 * i - 1;

        for (int j = 0; j < x_count; j++)
        {
            DiscUI = DiscUI + "X";
        }

        // Make the disc object after the string is made and then push it to rod 1
        Disc hanoiDisc = Disc(DiscUI, x_count);
        rods[0].push(hanoiDisc);
    }
}

// Empty destructor
TowerHanoi::~TowerHanoi() {}

// Move rods if the chosen move is valid else skip - use overloaded < operator from disc
bool TowerHanoi::move(int rodFrom, int rodTo)
{
    // Return invalid right away if rodFrom and rodTo are the same
    if (rodFrom == rodTo)
    {
        return false;
    }

    // If our rodTo and rodFrom are out of range just return false right away
    if ((rodFrom > 5 || rodFrom < 1) || (rodTo > 5 || rodTo < 1))
    {
        return false;
    }

    // Make copy, alter copy and then set rod to copy's new state and assume move is initially invalid
    LStack<Disc> &target1 = rods[rodFrom - 1];
    LStack<Disc> &target2 = rods[rodTo - 1];

    // ALWAYS CHECK LIST LENGTH IF SOMETHING HAS TO BE POPPED OR PEEKED

    if (target1.is_empty())
    {
        return false;
    }

    if (!target2.is_empty())
    {
        if (target2.peek() < target1.peek())
        {
            return false;
        }
    }
    Disc disct = target1.pop();
    target2.push(disct);

    return true;
}

// If the first 2 rods are empty and rod 3 has all the discs properly sorted
// the game must finish since the player has successfully moved all discs to the final rod
bool TowerHanoi::checkWin()
{
    if (rods[0].is_empty() && rods[1].is_empty())
    {
        return true;
    }
    return false;
}

// Helper function to pass to ostream to get current game state
ostream &TowerHanoi::printGame(ostream &finalState)
{
    // This function will be using a 2d matrix to print the current game state

    // These consts are catered to comply to the spec but can be extended to n discs and n rods as well
    int maxSpace = 6;
    int maxDiscs = 5;

    // We have 3 rods and initially 5 discs in one rod with the largest disc
    // being 2n-1 in diameter then we add our max space offset for formatting - 33 + offset of 6
    int maxWidth = ((2 * maxDiscs) - 1) * 3 + 2 * maxSpace;

    // Our max disc diam for the spec
    // Since the max discs are 5 then the max diam is 2 * 5 - 1
    int maxDiscDiam = 9;

    // Initialise a 2d char matrix of 7 rows and maxWidth columns
    // Here we also account for the constant base that goes ------- with 1 2 3 under it
    char gameState[maxDiscs + 2][maxWidth];

    // Initially populate with char spaces
    for (int i = 0; i < (maxDiscs + 2) * maxWidth; i++)
    {
        ((char *)gameState)[i] = ' ';
    }

    // Instantiate the dashes (----------) in the 2nd bottom row
    for (int i = 0; i < maxWidth; i++)
    {
        gameState[maxDiscs][i] = '-';
    }

    // Derive each rod's state and write that state to our gameState matrix
    for (int i = 0; i < 3; i++)
    {
        // Use ASCII to write the 1 2 3 below --------
        gameState[maxDiscs + 1][(i * (maxDiscDiam + maxSpace)) + maxDiscDiam / 2] = i + 49;

        // Initialise a temporary size (serves an accessor for tempStack) and a temporary disc array (tempStack)
        int tempSize = 0;
        Disc tempStack[rods[i].length()];

        // Pop the rods, store them in the tempStack, read and write the elements and push them to the original rod
        while (!rods[i].is_empty())
        {
            tempStack[tempSize++] = rods[i].pop();
        }

        // Read through tempStack and read the data to the matrix
        // Get each disc and each string value for each disc using this loop
        for (int j = 0; j < tempSize; j++)
        {
            Disc disc = tempStack[j];
            string str = disc.get_value();
            // Get our offsets to space our output properly
            int widthLeeway = (i * (maxDiscDiam + maxSpace)) + (maxDiscDiam - disc.get_diam()) / 2;
            int heightLeeway = maxDiscs - tempSize;

            // We use memory copy here because the initial plan was to copy the rod, pop, read write then push back
            // But that gets rid of the original rods because pointers and data is copied along so when you delete one
            // you effectively delete everything then you get segfaults everywhere
            // To rectify that we use memcpy to copy our data to the matrix without prematurely destroying the original rods
            // and just copy the number of bytes wherever the block of memory for our target is
            memcpy((char *)gameState[j + heightLeeway] + widthLeeway, str.data(), strlen(str.data()));
        }

        // At this point the matrix is completely written, we just have to use a backwards for loop to write our
        // discs back to the stack to retain order
        for (int k = tempSize; k > 0; k--)
        {
            rods[i].push(tempStack[k - 1]);
        }
    }

    // Now we write what we have in the matrix to the ostream and then return that value
    for (int a = 0; a < maxDiscs + 2; a++)
    {
        for (int b = 0; b < maxWidth; b++)
        {
            finalState << gameState[a][b];
        }
        // Add new line every time we finish writing a row so it doesn't become one long char series
        finalState << endl;
    }

    return finalState;
}

// Overload << operator so we can show current game state using the helper function printGame()
ostream &operator<<(ostream &out, TowerHanoi &game)
{
    game.printGame(out);
    return out;
}