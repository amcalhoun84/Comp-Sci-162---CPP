/*********************************************************************  
** Program Filename: goblin.cpp
** Author: Andrew M. Calhoun
** Date: 7/17/2015
** Description: The source file for the Goblin class. Inherits from characterType class.
** Input:  		N/A
** Output:  	N/A
*********************************************************************/

#include "characterType.hpp"
#include "goblin.hpp"

Goblin::Goblin()
{
	this->creatureName = "Happy"; 	// Because Goblins are happy.
	this->className = "Goblin";
	this->armor = 5;
	this->maxStrengthPoints = 8;
	this->currentStrengthPoints = 8;
	this->vPoints = 0;
	this->achHeel = false;

}

/*********************************************************************  
** Function: CharacterType::CharacterType(std::string gobName)
** Description: The base default constructor of character creation.
** Parameters: std::string gobName.
** Pre-Conditions: Player creates a goblin character and names it.
** Post-Conditions: Goblin is created with custom name.
*********************************************************************/

Goblin::Goblin(std::string gobName)
{
	this->creatureName = gobName;	
	this->className = "Goblin";
	this->armor = 5;	// upping Goblin armor from 3, Goblins would wear more armor given they're frail.
	this->maxStrengthPoints = 8;
	this->currentStrengthPoints = 8;
	this->vPoints = 0;
	this->achHeel = false;

}

/*********************************************************************  
** Function: int Goblin::characterAttack()
** Description: The Goblin's attack throw.
** Parameters: N/A
** Pre-Conditions: The program calls for an attack on the goblin's turn.
** Post-Conditions: Damage is determined to be compared against defense
**					and whether or not the goblin successfully cut its
**					opponents Achilles Tendon.
*********************************************************************/

int Goblin::characterAttack()
{
	damage = rollDice(2, 6); // Roll two sided dice.

	if(damage >= 9 && damage <= 11)
	{
		std::cout << this->creatureName << " has landed a stunning blow! The crowd goes wild!" << std::endl;
		this->vPoints++;
	}

	else if(damage == 12)	// If the goblin does 12 damage on the base, it cuts it's opponent achilles tendon.
	{
		std::cout << this->creatureName << " has landed a stunning blow, cutting their opponent's achilles tendon!" << std::endl;
		this->vPoints += 2;
		return damage;
	}

	return damage;
}

/*********************************************************************  
** Function: int Goblin::characterDefense()
** Description: The Goblin's defense throw.
** Parameters: int _characterAttack
** Pre-Conditions: The program calls for the goblin to defend and decrease damage
**					taken.
** Post-Conditions: The defense is compared against the damage, and the amount 
**					of damage taken is returned to the program.
*********************************************************************/


int Goblin::characterDefense(int _characterAttack)
{
	defense = rollDice(2, 4);		// upped goblin defense given their diminutive size.

	/* Debugging Purposes / Checking Algorithm */
	// std::cout << "Defense Roll: " << defense << std::endl;


	int result = (_characterAttack - defense) - armor;

	if(result <= 0)
	{
		return 0;
	}

	return result;
}

