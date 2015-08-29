/*********************************************************************  
** Program Filename: main.cpp
** Author: Andrew M. Calhoun
** Date: 7/17/2015
** Description: The main function source file.
**
** Input:  		Player plays game.
** Output:  	Player has fun with game. :)
*********************************************************************/

#include "frontEnd.hpp"
#include "fight.hpp"
#include "characterType.hpp"

/*********************************************************************  
** Function: void FrontEnd::displayGreeting()
** Description: The Title Screen / Greeting of the Game
** Parameters: N/A
** Pre-Conditions: Player starts the program.
** Post-Conditions: N/A
*********************************************************************/

int main()
{

	FrontEnd fe;
	Fight f;

	// f.combatSimulation();  -- testing module.

	/* For interactive program, right now we just need a combat simulation to make 
	// sure everything works. */
	
	f.populateOpponents();
	fe.displayGreeting();
	fe.displayMenu();

	return 0;
}
