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
#include <cmath>

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
** Function: CharacterType::getCharacterName()
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

/*********************************************************************  
** Function: void CharacterType::healCharacter()
** Description: Dice rolling function to determine how much character is healed.
** Parameters: N/A
** Pre-Conditions: Character wins a match and is being prepped to return to the queue.
** Post-Conditions: The amount of healed HP is given to the character. Announces if the character is fully 
**	recovered.
*********************************************************************/


void CharacterType::healCharacter()
{
	int healingRoll = ((rand() % 10) + 1);
	
	int maxSP = this->getMaxStrengthPoints();

	std::cout << "Healing Roll for " << this->getCharacterName() << ": " << healingRoll << std::endl; 

	if(healingRoll == 1)
	{
		this->currentStrengthPoints += ceil((this->getMaxStrengthPoints()) * .1);
		std::cout << getCharacterName() << " has had their wounds bandaged up." << std::endl;


		if(this->getStrengthPoints() >= maxSP)
		{
			this->currentStrengthPoints = maxSP;
			std::cout << getCharacterName() << " has made an astounding recovery!" << std::endl;
		}
	}

	else if(healingRoll == 2)
	{
		this->currentStrengthPoints += ceil((this->getMaxStrengthPoints()) * .2);
		std::cout << getCharacterName() << " has had their wounds bandaged up." << std::endl;

		if(this->getStrengthPoints() >= maxSP)
		{
			this->currentStrengthPoints = maxSP;
			std::cout << getCharacterName() << " has made an astounding recovery!" << std::endl;
		}
	}

	else if(healingRoll == 3)
	{
		this->currentStrengthPoints += ceil((this->getMaxStrengthPoints()) * .3);
		std::cout << getCharacterName() << " has had their wounds bandaged up." << std::endl;

		if(this->getStrengthPoints() >= maxSP)
		{
			std::cout << getCharacterName() << " has made an astounding recovery!" << std::endl;
			this->currentStrengthPoints = maxSP;
		}
	}

	else if(healingRoll == 4)
	{
		this->currentStrengthPoints += ceil((this->getMaxStrengthPoints()) * .4);
		std::cout << getCharacterName() << " has had their wounds bandaged up." << std::endl;

		if(this->getStrengthPoints() >= maxSP)
		{
			std::cout << getCharacterName() << " has made an astounding recovery!" << std::endl;
			this->currentStrengthPoints = maxSP;
		}
	}

	else if(healingRoll == 5)
	{
		this->currentStrengthPoints += ceil((this->getMaxStrengthPoints()) * .5);
		std::cout << getCharacterName() << " is looking pretty good." << std::endl;

		if(this->getStrengthPoints() >= maxSP)
		{
			std::cout << getCharacterName() << " has made an astounding recovery!" << std::endl;
			this->currentStrengthPoints = maxSP;
		}

	}

	else if(healingRoll == 6)
	{
		this->currentStrengthPoints += ceil((this->getMaxStrengthPoints()) * .6);
		std::cout << getCharacterName() << " Is looking pretty good." << std::endl;

		if(this->getStrengthPoints() >= maxSP)
		{
			std::cout << getCharacterName() << " has made an astounding recovery!" << std::endl;
			this->currentStrengthPoints = maxSP;
		}


	}

	else if(healingRoll == 7)
	{
		this->currentStrengthPoints += ceil((this->getMaxStrengthPoints()) * .7);
		std::cout << getCharacterName() << " seems to be looking okay." << std::endl;

		if(this->getStrengthPoints() >= maxSP)
		{
			std::cout << getCharacterName() << " has made an astounding recovery!" << std::endl;
			this->currentStrengthPoints = maxSP;
		}
	}

	else if(healingRoll == 8)
	{
		this->currentStrengthPoints += ceil((this->getMaxStrengthPoints()) * .8);
		std::cout << getCharacterName() << " looks no worse for wear!" << std::endl;

		if(this->getStrengthPoints() >= maxSP)
		{
			std::cout << getCharacterName() << " has made an astounding recovery!" << std::endl;
			this->currentStrengthPoints = maxSP;
		}
	}

	else if(healingRoll == 9)
	{
		this->currentStrengthPoints += ceil((this->getMaxStrengthPoints()) * .9);
		std::cout << getCharacterName() << " comes out of the infirmary looking fantastic!" << std::endl;

		if(this->getStrengthPoints() >= maxSP)
		{
			this->currentStrengthPoints = maxSP;
			std::cout << getCharacterName() << " has made an astounding recovery!" << std::endl;
		}
	}
	else
	{
		this->currentStrengthPoints = maxSP;
		std::cout << getCharacterName() << " has made an astounding recovery!" << std::endl;
	}

}

/*********************************************************************  
** Function: void CharacterType::addVictoryPoints(int _vPoints)
** Description: Adds the number of vPoints that a character wins in a round. A well performing character
**	can still 'win' the tournament, even if they are beaten. 
** Parameters: int _vPoints
** Pre-Conditions: Character meets a criteria, i.e. scores a critical hit, one hit kills, beats a vastly more powerful monster, etc.
** Post-Conditions: Number of vPoints character has is updated.
*********************************************************************/

void CharacterType::addVictoryPoints(int _vPoints)
{
	this->vPoints += _vPoints;
}

/*********************************************************************  
** Function: void CharacterType::addVictoryPoints(int _vPoints)
** Description: Adds the number of vPoints that a character wins in a round. A well performing character
**	can still 'win' the tournament, even if they are beaten. 
** Parameters: int _vPoints
** Pre-Conditions: Character meets a criteria, i.e. scores a critical hit, one hit kills, beats a vastly more powerful monster, etc.
** Post-Conditions: Number of vPoints character has is updated.
*********************************************************************/


int CharacterType::getVictoryPoints()
{
	return vPoints;
}