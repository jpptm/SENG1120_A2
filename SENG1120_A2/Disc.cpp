//Course: SENG1120
//Coded by: Alex Mendes 

#include "Disc.h"
#include <cstdlib>

// Constructors
Disc::Disc()
{
	value = "";
	diameter = 0;
}

Disc::Disc(const string valueString_, const int valueDiam_)
{
	value = valueString_;
	diameter = valueDiam_;
}

// empty destructor
Disc::~Disc(){}

// Mutator methods (setters)
void Disc::set_value(const string valueString_, const int valueDiam_) 
{value = valueString_; diameter = valueDiam_}

// Accessor methods (getters)
string Disc::get_value() const {return value;}
int Disc::get_diam() const {return diameter;}

// overloaded ostream operator
ostream& operator <<(ostream& out, const Disc& p)
{
	out << p.get_value();
    return out;
}

// overloaded < operator
bool operator < (const Disc& d1, const Disc& d2)
{
    if (d1.get_diam() < d2.get_diam())
		return true;
	else
		return false;
}
