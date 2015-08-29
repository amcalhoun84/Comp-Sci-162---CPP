/*************************************
* Name: Andrew M. Calhoun (calhouna)
* Email: calhouna@onid.oregonstate.edu
* Date: 7/5/2015
* Description: The header for child class of the 
* dice class. Loaded dice to rig the dice
* to produce a better result.
***************************************/

#include <cstdlib>
#include <iostream>
#include <ctime>
#include "dice.hpp"

class LoadedDice : public Dice
{

private:
	int numSides;

public:
    LoadedDice();	// Default Constructor
    LoadedDice(int); // Constructor
    int rollDice();  // roll loaded Dice
};	 // inherits protected members from parent Class, no need to rewrite them, otherwise redundancies will occur.
