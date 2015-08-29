// Dice.hpp
#ifndef DICE_HPP
#define DICE_HPP

#include <cstdlib>
#include <iostream>
#include <ctime>

// Dice Class

class Dice
{
public:
	Dice(); // Default Constructor
	Dice(int);	// Constructor
	int rollDice(); // rolling function
	
protected:
	int numSides;	// Number of Sides to the dice

};

// Derived Class - Loaded Dice, to rig it for specific rolls / results.


#endif
