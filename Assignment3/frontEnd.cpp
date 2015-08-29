/*********************************************************************  
** Program Filename: frontend.cpp
** Author: Andrew M. Calhoun
** Date: 7/17/2015
** Description: The main menu for the fantasy combat game.
** Input:  Player input to navigate around the various functionality.
** Output: Fun! Lots and lots of fun -- including combat results, wins/losses (planned)
**			descriptions of the monsters, and more!
*********************************************************************/

#include "frontEnd.hpp"
#include "characterType.hpp"
#include "fight.hpp"


/*********************************************************************  
** Function: void FrontEnd::displayGreeting()
** Description: The Title Screen / Greeting of the Game
** Parameters: N/A
** Pre-Conditions: Player starts the program.
** Post-Conditions: N/A
*********************************************************************/

void FrontEnd::displayGreeting()
{

	std::cout << "Welcome to the Fantasy Combat Torunament at Boatmurdered!\n"
			  <<  "Two contestants enter, and only one leaves.\n" << std::endl;
	
}

/*********************************************************************  
** Function: void FrontEnd::playGame()
** Description: The game option menu.
** Parameters: N/A
** Pre-Conditions: Player hits the play game command.
** Post-Conditions: Player can create, delete, list, and fight characters.
*********************************************************************/

/* Included in this portion is a special option 9 for straight testing of the 
combat algorithm and "pregenerated" characters. */

void FrontEnd::playGame()
{
	Fight f;
	int choice;

	do { 
	std::cout << "Game Options: \n"
			<< "1. Create Character \n"
			<< "2. Delete Character \n"
			<< "3. List Characters \n"
			<< "4. Fight \n"
			<< "5. Return to Main Menu\n" << std::endl;

	std::cout << "Input Choice >> ";
	std::cin >> choice;
	std::cin.clear();

		switch (choice)
		{
			case 1:
			{
				std::cin.ignore();
				f.createCharacter();
				break;
			}


			case 2:
			{
				std::cin.ignore();
				std::cin.clear();

				std::cout << "What is the name of the character you wish to delete?" << std::endl;
				
				std::string deleteCharacter;
				
				std::getline(std::cin, deleteCharacter);

				f.deleteCharacter(deleteCharacter);

				break;
			}
			case 3 :
			{
				std::cin.ignore();
				f.getCharacterList();
				break;
			}

			case 4:
			{
				std::cin.ignore();
					CharacterType* combat1;
					CharacterType* combat2;
					
				std::string getCharacterInput;


				emptyList = f.getCharacterList();

				if(emptyList == true)
				{
					std::cout << "You cannot fight without a character, create one first.\n\n" << std::endl;
					break;
				}

				std::cout << "Select your combatant.\n\n";
				std::cout << "Who shall be your champion? >> ";
				std::getline(std::cin, getCharacterInput);
		
				combat1 = f.getCharacter(getCharacterInput);
				
				f.getOpponentList();

				std::cout << "\n\nWho shall be their opponent? >> ";
				std::getline(std::cin, getCharacterInput);
				combat2 = f.getOpponent(getCharacterInput);
								
				
				if(combat1 == NULL || combat2 == NULL) // Last chance 
				{
					std::cout << "Invalid character/creature detected! Please try again." << std::endl;
					break;
				}


				f.doBattle(combat1, combat2);

			//	delete combat1;
			//	delete combat2;

				break;

			}

			case 5:
			{
				//delete combat1;
				//delete combat2;
				return;
			}

			case 9:		// Secret Tester Demo - runs the original algorithm tests
			{
					f.combatSimulation();
					break;				
			}


			default:
			{
				std::cout << "Bad choice. Try again." << std::endl;
				std::cin.ignore(1024, '\n');
				std::cin.clear();
				break;
			}
		}
	} while(choice != 5);

}

/*********************************************************************  
** Function: void FrontEnd::displayMenu()
** Description: The Main Menu
** Parameters: N/A
** Pre-Conditions: Player starts the program.
** Post-Conditions: N/A
*********************************************************************/

void FrontEnd::displayMenu()
{

	int input;

	do 
	{
		std::cout << "1. How to Play\n"
				  << "2. Play\n" 
				  << "3. Credits\n"
				  << "4. Quit the Game\n" << std::endl;


		std::cout << "Input Choice >> "; 
		std::cin >> input;
		std::cin.clear();

		switch (input)
		{
			case 1:
			{
			std::cout << "Welcome to the annual Boatmurdered Tournament. The great\n"
						<< "dwarven fortress of Boatmurdered welcomes you and your\n"
						<< "champions. The rules are very simple. Two creatures enter\n"
						<< "the arena and only one leaves. Can you defeat the greatest\n"
						<< "warriors the land has ever known?!\n\n"
						<< "Playing the game is very simple -- simply press 2 to play and\n"
						<< "create your character from the five types provided. Once you are\n"
						<< "ready to fight, you can enter your champion into the competition.\n"
						<< "\n\nMay the Gods Be On Your Side." << std::endl << std::endl;

			break;
			}

			case 2:
			{
				playGame();
				break;
			}

			case 3:
			{
				displayCredits();
				break;
			}

			case 4:
			{
				std::cout << "\nFare thee well!\n" << std::endl;
				return;
			}


			default:
			{
				std::cout << "Bad Choice. Please try again." << std::endl;
				std::cin.ignore(1024, '\n');
				std::cin.clear();
				break;
			}
		}

	}	while(input != 5);

}

/*********************************************************************  
** Function: void FrontEnd::displayCredits()
** Description: Displays game credits
** Parameters: N/A
** Pre-Conditions: Player wants to see the credits.
** Post-Conditions: N/A
*********************************************************************/

void FrontEnd::displayCredits()
{
	std::cout << "\nGameplay and Project Idea by: Professor Terry Rooker\n"
			  << "\nProgramming by: Andrew M. Calhoun\n"
			  << "\nNaming Ideas based on the naming algorithm from Dwarf Fortress - http://www.bay12games.com/dwarves/\n"
			  << "and donjon.com." << std::endl;

			  return;
}



