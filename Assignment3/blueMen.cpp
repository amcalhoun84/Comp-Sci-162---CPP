/*********************************************************************  
** Program Filename: blueMen.cpp
** Author: Andrew M. Calhoun
** Date: 7/17/2015
** Description: The source file for the BlueMen subclass. Inherits from characterType class.
** Input:  		N/A
** Output:  	N/A
*********************************************************************/

#include "characterType.hpp"
#include "blueMen.hpp"

/*********************************************************************  
** Function: BlueMen::BlueMen()
** Description: Default constructor for the Blue Men.
** Parameters: N/A
** Pre-Conditions: The program creates a default Blue Man for testing.
** Post-Conditions: Blue Man is created and ready to fight.
*********************************************************************/

BlueMen::BlueMen()
{
	this->creatureName = "Truebad";
	this->className = "Blue Man";
	this->armor = 3;
	this->maxStrengthPoints = 12;
	this->currentStrengthPoints = 12;
	this->wins = 0;
	this->losses = 0;
	this->achHeel = false;
}

/*********************************************************************  
** Function: BlueMen::BlueMen(std::string bMenName)
** Description: Player called constructor for the Blue Men.
** Parameters: std::string bMenName
** Pre-Conditions: The player creates a Blue Man character and names it.
** Post-Conditions: Blue Man is created and ready to fight.
*********************************************************************/

BlueMen::BlueMen(std::string bMenName)
{
	this->creatureName = bMenName;
	this->className = "Blue Man";
	this->armor = 3;
	this->maxStrengthPoints = 12;
	this->currentStrengthPoints = 12;
	this->wins = 0;
	this->losses = 0;
	this->achHeel = false;
}

/*********************************************************************  
** Function: int Barbarian::characterAttack()
** Description: The Blue Men's attack throw.
** Parameters: N/A
** Pre-Conditions: The program calls for an attack on the Blue Man's turn.
** Post-Conditions: Damage is determined and returned to be compared against
**					the opponent's defense throw.
*********************************************************************/


int BlueMen::characterAttack()
{
	damage = rollDice(2, 10);
	return damage;
}

/*********************************************************************  
** Function: int BlueMen::characterDefense(int _characterAttack)
** Description: The BlueMan's defense throw.
** Parameters: int _characterAttack
** Pre-Conditions: The program calls for the character to defend and decrease damage
**					taken.
** Post-Conditions: The defense is compared against the damage, and the amount 
**					of damage taken is returned to the program.
*********************************************************************/

int BlueMen::characterDefense(int _characterAttack)
{

	/* The little guys are tiny and hard to hit. */
	defense = rollDice(3, 6);	

	/* Debugging Purposes / Checking Algorithm */
	// std::cout << "Defense Roll: " << defense << std::endl;


	
	if(achHeel == true)
	{
		defense /= 2;		// If the achilles tendon is cut, divide defense by 2.
	}
	
	int result = (_characterAttack - defense) - armor;
	if(result <= 0)
	{
		return 0;
	}
	return result;

}