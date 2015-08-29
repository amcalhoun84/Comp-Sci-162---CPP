/*********************************************************************  
** Program Filename: characterType.cpp
** Author: Andrew M. Calhoun
** Date: 7/17/2015
** Description: The source file for the CharacterType class and subclasses.
** 				contains the basic functionality and execution of the 
				character types, including constructors and modifiers.
** Input:  		N/A
** Output:  	N/A
*********************************************************************/

#include "characterType.hpp"
#include <cstdlib>
#include <string>
#include <ctime>
#include <vector>

/************************************************ *********************  
** Function: CharacterType::CharacterType()
** Description: The base default constructor of character creation.
** Parameters: N/A
** Pre-Conditions: Run the program and create a critter. 
** Post-Conditions: N/A - or instantiaate a default Character Type. Also
**					sets the seed for the random number generator.
*********************************************************************/

CharacterType::CharacterType()
{
	srand(time(0));
//	this->creatureName = "Default Critter";
//	this->className = "Default Class";
//	this->armor = 0;
//	this->maxStrengthPoints = 0;
//	this->currentStrengthPoints = 0;


}

/*********************************************************************  
** Function: CharacterType::~CharacterType()
** Description: The base default destructor of character creation.
** Parameters: N/A
** Pre-Conditions: Program requests to remove the character type. 
** Post-Conditions: N/A - destroys character type. 
*********************************************************************/

CharacterType::~CharacterType()
{
	// Delete Character
	
}

/*********************************************************************  
** Function: CharacterType::getCharactername()
** Description: A simple command to get the character's name.
** Parameters: N/A
** Pre-Conditions: Program requests the character's name. 
** Post-Conditions: Returns the character's name.
*********************************************************************/


std::string CharacterType::getCharacterName()
{
	return creatureName;

}
/*
std::string CharacterType::randomNameGenerator()
{
	const char *rNames[] = { "Jeerd", "Chort", "Boolebolg", "Parolor", "Feheeld", "Frag", "Brak"}

	int randomNameGrab = rand() % randomNames.size();

	return randomNames[index];

}
*/

/*********************************************************************  
** Function: CharacterType::getCharacterType()
** Description: A simple command to get the character's class/creature type.
** Parameters: N/A
** Pre-Conditions: Program requests the character's class/creature type. 
** Post-Conditions: Returns the character's class/creature type.
*********************************************************************/

std::string CharacterType::getCharacterType()
{
	return className;
}

/*********************************************************************  
** Function: CharacterType::setStrengthPoints(int damage)
** Description: Calculates the damage and sets the character's strength
**				points.
** Parameters: int damage
** Pre-Conditions: Character is in combat, and takes damage. 
** Post-Conditions: Sets the character's SP based on damage.
*********************************************************************/

void CharacterType::setStrengthPoints(int damage)
{
	currentStrengthPoints = currentStrengthPoints - damage;
}

/*********************************************************************  
** Function: CharacterType::getStrengthPoints()
** Description: Tells the player how many strength points something has
**				left.
** Parameters: N/A
** Pre-Conditions: Program requests the strength points of a critter. 
** Post-Conditions: Returns the current strength points of the creature.
*********************************************************************/


int CharacterType::getStrengthPoints()
{
	return currentStrengthPoints;
}

/*********************************************************************  
** Function: CharacterType::getMaxStrengthPoints()
** Description: Tells the player their character's max strenght points.
** Parameters: N/A
** Pre-Conditions: Program requests the max strength points of a critter. 
** Post-Conditions: Returns the max strength points of the creature.
*********************************************************************/

int CharacterType::getMaxStrengthPoints()
{
	return maxStrengthPoints;
}

/*********************************************************************  
** Function: CharacterType::setAchilles()
** Description: Setter for the achilles tendon special attack condition.
** Parameters: N/A
** Pre-Conditions: Combat occurs and a goblin rolls a 12 on an attack.
** Post-Conditions: Sets the character as having it's Achilles Tendon
**					slashed. Reduces defense.
*********************************************************************/

void CharacterType::setAchilles(bool achHeel)
{
	this->achHeel = achHeel;
}


/*********************************************************************  
** Function: int CharacterType::rollDice(int numOfDice, int numOfSides)
** Description: Dice rolling function for the random number generator.
** Parameters: int numOfDice, int numOfSides
** Pre-Conditions: The attack and defend functions of the various characters 
**					is called.
** Post-Conditions: Determines how much damage is inflicted and what the defense 
**					is and returns the roll to be put into further calculations.
*********************************************************************/

int CharacterType::rollDice(int numOfDice, int numOfSides) 
{
		
	int roll = 0;
	for(int i = 0; i < numOfDice; i++)
	{
		roll += (rand() % numOfSides) + 1;
		// for debugging - std::cout << "Has rolled " << roll << std::endl;
	}
	
	return roll;
}