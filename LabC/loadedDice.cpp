/*************************************
* Name: Andrew M. Calhoun (calhouna)
* Email: calhouna@onid.oregonstate.edu
* Date: 7/5/2015
* Description: The source file for child class of the 
* dice class. Loaded dice to rig the dice
* to produce a better result.
***************************************/

#include "loadedDice.hpp"

LoadedDice::LoadedDice()
{
	this->numSides = 6;
	srand(time(NULL));
}

LoadedDice::LoadedDice(int sides)
{
	this->numSides = sides;
	srand(time(NULL));
}

int LoadedDice::rollDice()
{
	int riggedDice = rand() % 2;
	if(riggedDice == 1)
	{
		return numSides;
	}

	else {
		return (rand() % (numSides - 1)) + 1; 
	}
}

// Roll the dice.