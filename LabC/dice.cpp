// Source File for Dice class

#include "dice.hpp"

/* Dice Default Constructor */

Dice::Dice()
{ 
	this->numSides = 6; 
	srand(time(NULL)); // random number generator
}

// Custom Dice or hard coded input, can be adjusted to suit the needs
// of the program.

Dice::Dice(int sides)
{
	this->numSides = sides;
	srand(time(NULL)); // random number generator
}

// Loaded Dice Default Constructor. 
// Derived from the Dice class.



int Dice::rollDice()
{
	return (rand() % numSides) + 1; // rolls the dice, ensures there is no 0.
}

// Roll the loaded dice with it configured to produce a favored result.

