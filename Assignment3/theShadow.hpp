/*********************************************************************  
** Program Filename: thwShadow.hpp
** Author: Andrew M. Calhoun
** Date: 7/17/2015
** Description: The header file for the TheShadow class. Inherits from characterType class.
** Input:  		N/A
** Output:  	N/A
*********************************************************************/

#ifndef THESHADOW_HPP
#define THESHADOW_HPP

#include "characterType.hpp"

class TheShadow : public CharacterType {

public: 
	
	TheShadow();
	TheShadow(std::string tSName);
	int characterAttack();
	int	characterDefense(int _characterAttack);
	
private:

	int shadowTF;


};

#endif