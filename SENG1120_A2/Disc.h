//Course: SENG1120
//Coded by: Alex Mendes 

#ifndef DISC_H
#define DISC_H
#include <string>
#include <cstdlib>
#include <iostream>
using namespace std;

class Disc 
{
public:
	
	// Constructors
	Disc();
	Disc(const string, const int); // the piece will be initialized either as "X" or "XXX" or "XXXXX", etc...

	// Destructor
    ~Disc();

	// Setters
    void set_value(const string, const int);

	// Getters
	string get_value() const;
	int get_diam() const;

//Private member variables
private:
	string value; // "   X   " or "  XXX  " or " XXXXX ", etc...
	int diameter; // 1, 3, 5, ...
};

ostream& operator <<(ostream&, const Disc&);

bool operator < (const Disc&, const Disc&);

#endif