/*********************************************************************  
** Program Filename: theShadow.cpp
** Author: Andrew M. Calhoun
** Date: 7/17/2015
** Description: The source file for the TheShadow class. Inherits from characterType class.
** Input:  		N/A
** Output:  	N/A
*********************************************************************/

#include "characterType.hpp"
#include "theShadow.hpp"

/*********************************************************************  
** Function: TheShadow::TheShadow()
** Description: Default constructor for the Shadow.
** Parameters: N/A
** Pre-Conditions: The program creates a default Shadow for testing.
** Post-Conditions: The Shadow is created and ready to fight.
*********************************************************************/

TheShadow::TheShadow()
{
	this->creatureName = "Uhammnit";
	this->className = "Shadow";
	this->armor = 0;
	this->maxStrengthPoints = 12;
	this->currentStrengthPoints = 12;
	this->wins = 0;
	this->losses = 0;
	this->achHeel = false;
}


/*********************************************************************  
** Function: TheShadow()::TheShadow(std::string tsName)
** Description: Default constructor for Goblins.
** Parameters: std::string tsName
** Pre-Conditions: The player wants to create a Shadow Character.
** Post-Conditions: The Shadow is named and created and ready to fight.
*********************************************************************/

TheShadow::TheShadow(std::string tsName)
{
	this->creatureName = tsName;
	this->className = "Shadow";
	this->armor = 0;
	this->maxStrengthPoints = 12;
	this->currentStrengthPoints = 12;
	this->wins = 0;
	this->losses = 0;
	this->achHeel = false;
}

/*********************************************************************  
** Function: int TheShadow::characterAttack()
** Description: The Shadow's attack throw.
** Parameters: N/A
** Pre-Conditions: The program calls for an attack on the Shadow's turn.
** Post-Conditions: Damage is determined and returned to be compared against
**					the opponent's defense throw.
*********************************************************************/


int TheShadow::characterAttack() 
{
	damage = rollDice(2, 10);
	return damage;
}


/*********************************************************************  
** Function: int TheShadow::characterDefense(int _characterAttack)
** Description: The BlueMan's defense throw.
** Parameters: int _characterAttack
** Pre-Conditions: The program calls for the Shadow to defend and decrease damage
**					taken.
** Post-Conditions: The defense is compared against the damage, and the amount 
**					of damage taken is returned to the program. If the shadow
**					activates it's special move, it takes no damage.
*********************************************************************/

int TheShadow::characterDefense(int _characterAttack)
{
	
	defense = rollDice(1, 6);

	/* Debugging Purposes / Checking Algorithm */
	// std::cout << "Defense Roll: " << defense << std::endl;

	if(achHeel == true)
	{
		defense /= 2;		// If the achilles tendon is cut, divide defense by 2.
	}

	int result = (_characterAttack - defense) - armor;

	shadowTF = (rand() % 2);	// Random 0 or 1. If hits certain parameter, the shadow has no damage done to it.

	if(shadowTF == 0)
	{
		std::cout << "The shadow deftly dodges the attack!" << std::endl;
		return 0;
	}

	else if(result <= 0)
	{
		return 0;
	}

	else
	{
		return result;
	}

}