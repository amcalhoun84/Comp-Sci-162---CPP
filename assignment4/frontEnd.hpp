/*********************************************************************  
** Program Filename: frontEnd.hpp
** Author: Andrew M. Calhoun
** Date: 7/17/2015
** Description: The header file for the FrontEnd subclass.
**				The design decision was made as the fight class was growing
**				too bloated with the visual features. Given that it does access
**				a lot of members of the fight class, it was an easy way to ensure
**				continuity of program without overly complicated use of pointers.
** Input:  		N/A
** Output:  	N/A
*********************************************************************/


#ifndef FRONTEND_HPP
#define FRONTEND_HPP

#include "queue.hpp"
#include "node.hpp"
#include "stack.hpp"
#include "characterType.hpp"
#include "fight.hpp"
#include <iostream>

class FrontEnd {		// Demoted Class to child of the Fight, given that it is the interface.

private:
	int teamCount, 
		rosterSize;
	bool emptyList;


public:

FrontEnd(){}
void displayMenu();
void displayGreeting();
void playGame();
void displayCharacterList();
void displayStatistics();
void displayCredits();


};

#endif