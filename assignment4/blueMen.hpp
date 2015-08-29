/*********************************************************************  
** Program Filename: blueMen.hpp
** Author: Andrew M. Calhoun
** Date: 7/17/2015
** Description: The header file for the BlueMen class. Inherits from characterType class.
** Input:  		N/A
** Output:  	N/A
*********************************************************************/

#ifndef BLUEMEN_HPP
#define BLUEMEN_HPP


#include "characterType.hpp"

class BlueMen : public CharacterType
{

public: 
	
	BlueMen();
	BlueMen(std::string bMenName);
	int characterAttack();
	int	characterDefense(int _characterAttack);



};

#endif