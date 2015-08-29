/*********************************************************************  
** Program Filename: barbarian.cpp
** Author: Andrew M. Calhoun
** Date: 7/17/2015
** Description: The source file for the Barbarian class. Inherits from characterType class.
** Input:  		N/A
** Output:  	N/A
*********************************************************************/

#include "characterType.hpp"
#include "barbarian.hpp"


/*********************************************************************  
** Function: Barbarian::Barbarian()
** Description: Default constructor for Barbarians.
** Parameters: N/A
** Pre-Conditions: The program creates a default Barbarian for testing.
** Post-Conditions: Barbarian is created and ready to fight.
*********************************************************************/

Barbarian::Barbarian()
{
	this->creatureName = "Urist";
	this->className = "Barbarian";
	this->armor = 0;
	this->maxStrengthPoints = 12;
	this->currentStrengthPoints = 12;
	this->vPoints = 0;
	this->achHeel = false;

	
}

/*********************************************************************  
** Function: Barbarian::Barbarian(std::string barbieName)
** Description: Player generated constructor for the Barbarian
** Parameters: N/A
** Pre-Conditions: The player creates and names a Barbarian.
** Post-Conditions: Barbarian is created and ready to fight.
*********************************************************************/

Barbarian::Barbarian(std::string barbieName)
{
	this->creatureName = barbieName;
	this->className = "Barbarian";
	this->armor = 0;
	this->maxStrengthPoints = 12;
	this->currentStrengthPoints = 12;
	this->achHeel = false;

	
}

/*********************************************************************  
** Function: int Barbarian::characterAttack()
** Description: The Barbarian's attack throw.
** Parameters: N/A
** Pre-Conditions: The program calls for an attack on the barbarian's turn.
** Post-Conditions: Damage is determined and returned to be compared against
**					the opponent's defense throw.
*********************************************************************/

int Barbarian::characterAttack()
{
	damage = rollDice(4, 4);	// upped damage, as Barbarians should hit HARD.
	if(damage >= 9)
	{
		std::cout << this->creatureName << " has landed a stunning blow! The crowd goes wild!" << std::endl;
		this->vPoints++;
		return damage;
	}
	else
	{
		return damage;
	}
}

/*********************************************************************  
** Function: int Barbarian::characterDefense()
** Description: The Barbarians's defense throw.
** Parameters: int _characterAttack
** Pre-Conditions: The program calls for the Barbarian to defend and decrease damage
**					taken.
** Post-Conditions: The defense is compared against the damage, and the amount 
**					of damage taken is returned to the program.
*********************************************************************/

int Barbarian::characterDefense(int _characterAttack)
{
	defense = rollDice(2, 6);
	
	/* Debugging Purposes / Checking Algorithm */
	// std::cout << "Defense Roll: " << defense << std::endl;

	if(achHeel == true)
	{
		defense /= 2;		// If the achilles tendon is cut, divide defense by 2.
	}
	
	int result = (_characterAttack - defense);

	if(result <= 0)
	{
		return 0;
	}

	return result;

}
