/*********************************************************************  
** Program Filename: barbarian.hpp
** Author: Andrew M. Calhoun
** Date: 7/17/2015
** Description: The header file for the Barbarian class. Inherits from characterType class.
** Input:  		N/A
** Output:  	N/A
*********************************************************************/

#ifndef BARBARIAN_HPP
#define BARBARIAN_HPP

#include "characterType.hpp"

class Barbarian : public CharacterType
{

public: 
	
	Barbarian();
	Barbarian(std::string barbieName);
	int characterAttack();
	int	characterDefense(int _characterAttack);
	

};

#endif