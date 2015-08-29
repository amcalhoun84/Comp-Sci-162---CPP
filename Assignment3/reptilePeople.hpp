/*********************************************************************  
** Program Filename: reptilePeople.hpp
** Author: Andrew M. Calhoun
** Date: 7/17/2015
** Description: The header file for the reptilePeople class. Inherits from characterType class.
** Input:  		N/A
** Output:  	N/A
*********************************************************************/

#ifndef REPTILEPEOPLE_HPP
#define REPTILEPEOPLE_HPP

#include "characterType.hpp"

class ReptilePeople : public CharacterType
{

public: 
	
	ReptilePeople();
	ReptilePeople(std::string repPplName);
	int characterAttack();
	int	characterDefense(int _characterAttack);
	

};

#endif