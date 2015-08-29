/*********************************************************************  
** Program Filename: goblin.hpp
** Author: Andrew M. Calhoun
** Date: 7/17/2015
** Description: The header file for the Goblin class. Inherits from characterType class.
** Input:  		N/A
** Output:  	N/A
*********************************************************************/

#ifndef GOBLIN_HPP
#define GOBLIN_HPP

#include "characterType.hpp"

class Goblin : public CharacterType
{

public: 
	
	Goblin();
	Goblin(std::string gobName);
	int characterAttack();
	int	characterDefense(int _characterAttack);

};

#endif