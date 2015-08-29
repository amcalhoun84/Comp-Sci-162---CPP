/*********************************************************************  
** Program Filename: reptilePeople.cpp
** Author: Andrew M. Calhoun
** Date: 7/17/2015
** Description: The source file for the reptilePeople class. Inherits from characterType class.
** Input:  		N/A
** Output:  	N/A
*********************************************************************/

#include "characterType.hpp"
#include "reptilePeople.hpp"

/* Reptile Man Segment */

/*********************************************************************  
** Function: ReptilePeople::ReptilePeople()
** Description: Default constructor for ReptilePeople.
** Parameters: N/A
** Pre-Conditions: The program creates a default Reptile Man for testing.
** Post-Conditions: Reptile Man is created and ready to fight.
*********************************************************************/

ReptilePeople::ReptilePeople()
{
	this->creatureName = "Sleekswimmer";
	this->className = "Reptile Man";
	this->armor = 7;
	this->maxStrengthPoints = 18;
	this->currentStrengthPoints = 18;
	this->wins = 0;
	this->losses = 0;
	this->achHeel = false;

}

/*********************************************************************  
** Function: ReptilePeople::ReptilePeople()
** Description: Player created Reptile People constructor.
** Parameters: N/A
** Pre-Conditions: The program creates a reptile person who is named by the player.
** Post-Conditions: Reptile Person is created and ready to fight.
*********************************************************************/

ReptilePeople::ReptilePeople(std::string repPplName)
{
	this->creatureName = repPplName;
	this->className = "Reptile Person";
	this->armor = 7;
	this->maxStrengthPoints = 18;
	this->currentStrengthPoints = 18;
	this->wins = 0;
	this->losses = 0;
	this->achHeel = false;

}

/*********************************************************************  
** Function: int ReptilePeople::characterAttack()
** Description: The Reptile People's attack throw.
** Parameters: N/A
** Pre-Conditions: The program calls for an attack on the reptile peoples's turn.
** Post-Conditions: Damage is determined and returned to be compared against
**					the opponent's defense throw.
*********************************************************************/

int ReptilePeople::characterAttack()
{
	damage = rollDice(3, 6);
	return damage;

}


/*********************************************************************  
** Function: int ReptilePeople::characterDefense(int _characterAttack)
** Description: The Reptile People's defense throw.
** Parameters: int _characterAttack
** Pre-Conditions: The program calls for the character to defend and decrease damage
**					taken.
** Post-Conditions: The defense is compared against the damage, and the amount 
**					of damage taken is returned to the program.
*********************************************************************/

int ReptilePeople::characterDefense(int _characterAttack)
{
	defense = rollDice(1, 6);

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
