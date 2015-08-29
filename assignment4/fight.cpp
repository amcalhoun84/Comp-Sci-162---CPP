/*********************************************************************  
** Program Filename: fight.cpp
** Author: Andrew M. Calhoun
** Date: 7/17/2015
** Description: The header file for the Fight class. Contains the basic statistic 
** variables, functions, and other data to conduct fights in a fantasy combat game.
** Input:  		N/A
** Output:  	N/A
*********************************************************************/

#include <iostream>
#include "fight.hpp"
#include "frontEnd.hpp"
#include "queue.hpp"
#include "stack.hpp"

/*********************************************************************  
** Function: void fight::CreateCharacter()
** Description: The character creation utility.
** Parameters: N/A
** Pre-Conditions: Player wants to create a character.
** Post-Conditions: Character is created and added to the player controlled
**					character list.
*********************************************************************/

void Fight::createCharacter()
{

	int input;

	char yesNo;		// For Y/N interface.
	bool unique;	// Make sure there is a unique character.
	
	FrontEnd fe;	// Create the front end environment as necessary.
	Fight f;		// Needed for fighting


	CharacterType* combat; 	// Needed to create a critter.
	
	do {

	std::cout << "Character Creation Menu:\n"
			  << "1. Goblin\n"
			  << "2. Barbarian\n"
			  << "3. Reptile People\n"
			  << "4. The Blue Men\n"
			  << "5. The Shadow\n" 
			  << "6. Return to Main Menu" << std::endl;
		
		std::cout << "Choice >> ";
		std::cin >> input;
		std::cin.clear();
		std::cin.ignore(64, '\n');

		switch(input)
		{
			case 1:
			{
				std::cout << "Goblins are an often misunderstood small, nimble people\n"
							<< "from the the Spired Mountains of Kibram. \n"
							<< "They are cunning and fight dirty, favoring weakening their\n"
							<< "opponents. They're a numerous people, owing as an adaptation\n"
							<< "to their frailty.\n" 
							<< "Do you wish to choose one of the Goblins as an entrant?\n" << std::endl;	

							std::cout << "Y/N? >> ";

							while(yesNo != 'Y' && yesNo != 'y' && yesNo != 'N' && yesNo != 'n')							
							{
								
								std::cin.get(yesNo);
								std::cin.ignore(64, '\n');
								std::cin.clear();
						
								if(yesNo == 'Y' || yesNo == 'y')					
								{

									while(unique == false)
									{	
										std::cout << "What would you like to name your character? >> ";
										std::getline(std::cin, newName);	
										unique = checkUnique(newName);
									}

									combat = new Goblin(newName);
									combatants.push_back(combat);

									std::cout << "Character has been created." << std::endl;
									unique = false;

									return;
								}		
								else if (yesNo == 'N' || yesNo == 'n')
								{
									break;
								}

								else { std::cout << "Bad entry. Try again. (Y/N) >> "; }
							}

			}
			
			case 2:
			{
				std::cout << "The Barbarians of Barad Cuothil, the Bastion of Steel of the Great Hinterlands\n"
						  << "have sent their finest warriors to the tournament. The Barbarians are a tenacious,"
						  << "martial people, seeing glory in battle as the road to honor and fame.\n"
						  << "Do you wish to choose one of the Barbarians of Barad Cuothil to be an entrant?\n" << std::endl;
						  
						  std::cout << "Y/N? >> ";	

						  while(yesNo != 'Y' && yesNo != 'y' && yesNo != 'N' && yesNo != 'n')	
						  {					
						 
								std::cin.get(yesNo);
								std::cin.ignore(64, '\n');
								std::cin.clear();
						
								

								if(yesNo == 'Y' || yesNo == 'y')					
								{
									
									while(unique == false)
									{	
										std::cout << "What would you like to name your character? >> ";
										std::getline(std::cin, newName);	
										unique = checkUnique(newName);
									}	
										combat = new Barbarian(newName);
										combatants.push_back(combat);

									std::cout << "Character has been created." << std::endl;
									unique = false;

									return;
								}
								else if (yesNo == 'N' || yesNo == 'n')
								{
									break;
								}

								else { std::cout << "Bad entry. Try again. (Y/N) >> "; }
							}
			}

			case 3:
			{
				std::cout << "The Reptile Men, commonly known as Lizardfolk, of the Mistyfen Marshes wish to prove\n"
						  << "themselves as the world's greatest and most stalwart warriors.\n"
						  << "Persecuted and hated by most other cultures, this has led them to become a suspicious\n"
						  << "and insular people. The harsh conditions of the swamp have led them to become incredibly\n"
						  << "tough. Their skin is hard as stone, and they can take a considerable deal of punishment.\n"
						  << "Do you wish for one of the Lizardfolk of the Mistyfen Marshes to be one of your entrants?\n" << std::endl;
						  
						  std::cout << "Y/N? >> ";		

						  while(yesNo != 'Y' && yesNo != 'y' && yesNo != 'N' && yesNo != 'n')	
						  {				

			
							std::cin.get(yesNo);
							std::cin.ignore(64, '\n');
							std::cin.clear();
						
				
							if(yesNo == 'Y' || yesNo == 'y')					
							{
								while(unique == false)
								{	
									std::cout << "What would you like to name your character? >> ";
									std::getline(std::cin, newName);	
									unique = checkUnique(newName);
								}

								combat = new ReptilePeople(newName);
								combatants.push_back(combat);									
								std::cout << "Character has been created." << std::endl;
								unique = false;

								return;
							}		
							else if (yesNo == 'N' || yesNo == 'n')
							{
								break;
							}

							else { std::cout << "Bad entry. Try again. (Y/N) >> "; }
						}
			}

			case 4:
			{
				std::cout << "The Blue Men of the Harvashi Vale have proven to be a tricksy and cunning people.\n"
			 			  << "Their diminutive size has given them incredible advantages in combat, as they are difficult to hit,\n"
			 			  << "favor swarm tactics, and are trained from birth to brave the toils and tribulations of a world that\n"
			 			  << "is much too big for them. This has lent them a preternatural toughness and brutal efficiency in the\n"
			 			  << "arenas of war and combat. Even proud nations with powerful armies know to fear the Blue Men.\n"
			 			  << "Do you wish for one of the Blue Men to fight in the tournament?\n" << std::endl;
			 			
			 				std::cout << "Y/N? >> ";		

			 			  while(yesNo != 'Y' && yesNo != 'y' && yesNo != 'N' && yesNo != 'n')	
						  {						

							std::cin.get(yesNo);
							std::cin.ignore(64, '\n');
							std::cin.clear();
						
						
							if(yesNo == 'Y' || yesNo == 'y')					
							{
								while(unique == false)
								{	
									std::cout << "What would you like to name your character? >> ";
									std::getline(std::cin, newName);	
									unique = checkUnique(newName);
								}
						
								combat = new BlueMen(newName);
								combatants.push_back(combat);
								std::cout << "Character has been created." << std::endl;
								unique = false;
								return;
							}		
							else if (yesNo == 'N' || yesNo == 'n')
							{
								break;
							}

							else { std::cout << "Bad entry. Try again. (Y/N)"; }
						}
			}

			case 5:
			{
				std::cout << "The Shadows, servants of the Wraith Emperor are feared across the realms,\n"
						  << "as they are able to dance between light and darkness, seemingly at will.\n"
						  << "Though fragile in their appearance, they is deceptively strong and have brought many unprepared opponents\n"
						  << "to a quick and bitter end.\n"
						  << "Do you wish for one of the Shadows to be your champion?\n" << std::endl;
						  
						  	std::cout << "Y/N? >> ";		

						  while(yesNo != 'Y' && yesNo != 'y' && yesNo != 'N' && yesNo != 'n')	
						  {						
						
							std::cin.get(yesNo);
							std::cin.ignore(64, '\n');
							std::cin.clear();
									

							if(yesNo == 'Y' || yesNo == 'y')					
							{
								while(unique == false)
								{	
									std::cout << "What would you like to name your character? >> ";
									std::getline(std::cin, newName);	
									unique = checkUnique(newName);
								}

								combat = new TheShadow(newName);
								combatants.push_back(combat);

								std::cout << "Character has been created." << std::endl;
								unique = false;
								return;
							}		
							else if (yesNo == 'N' || yesNo == 'n')
							{
								break;
							}

							else { std::cout << "Bad entry. Try again. (Y/N)"; }
						}
			}

			case 6: 
			{
				std::cout << "Are you sure you want to quit? (Y/N) >> " << std::endl; // obligatory are you sure message for now.

				while(yesNo != 'Y' && yesNo != 'y' && yesNo != 'N' && yesNo != 'n')							
						
						std::cin.get(yesNo);
						std::cin.ignore(64, '\n');
						std::cin.clear();

						if(yesNo == 'Y' || yesNo == 'y')
						{
						std::cout << std::endl;
						return;
						}

						else
						{
							break;
						}

			}

			default:
			{
				std::cout << "Invalid input. Please try again." << std::endl;
			}

		} 
	} 
	while (input != 6);
}


/*********************************************************************  
** Function: void fight::getCharacterList()
** Description: Checks to see if character name is unique.
** Parameters: std::string characterName
** Pre-Conditions: Player inputs name.
** Post-Conditions: Returns true or false, and if false, asks the player to
**					think of another name.
*********************************************************************/

bool Fight::checkUnique(std::string characterName)
{
		if(combatants.empty())
		{
		return true;
		}

		for(unsigned int i = 0; i < combatants.size(); i++)
		{
			if(combatants.at(i)->getCharacterName() == characterName)
			{
				std::cout << "Name already taken, please choose another." << std::endl;
				return false;
			}
		}
	
	return true;
}

bool Fight::checkFree(std::string characterName)
{
		if(results1.empty() && results2.empty())
		{
		return true;
		}

		for(unsigned int i = 0; i < results1.size(); i++)
		{
			if(results1.at(i)->getCharacterName() == characterName)
			{
				std::cout << "Character is already on Team 1, please choose another." << std::endl;
				return false;
			}
		}

		for(unsigned int i = 0; i < results2.size(); i++)
		{
			if(combatants.at(i)->getCharacterName() == characterName)
			{
				std::cout << "Character is already on Team 2, please choose another." << std::endl;
				return false;
			}
		}
	
	return true;
}

int Fight::getRosterSize()
{
	return combatants.size();
}


/*********************************************************************  
** Function: void fight::getCharacterList()
** Description: The character list -- lists all characters in the combatant
**				vector.
** Parameters: N/A
** Pre-Conditions: Player wants to see a character list.
** Post-Conditions: N/A
*********************************************************************/

bool Fight::getCharacterList()
{

	if(combatants.empty())
	{
		std::cout << "No combatants found." << std::endl;
		return true;
	}

	else
	{
		for(unsigned int i = 0; i < combatants.size(); i++)
		{
			std::cout << "*----------------*\n";
			std::cout << "Name: " << combatants.at(i)->getCharacterName() << " the " << combatants.at(i)->getCharacterType() << std::endl;
			std::cout << "Strength Points: " << combatants.at(i)->getStrengthPoints() << " / " << combatants.at(i)->getMaxStrengthPoints() << std::endl;
			std::cout << "*----------------*\n\n";

		}
	}
	return false;
}


/*********************************************************************  
** Function: void fight::deleteCharacter(std::string characterName)
** Description: Character deletion utility.
** Parameters: std::string characterName()
** Pre-Conditions: Player wants to delete character.
** Post-Conditions: Removes the character from the vector and deletes them.
*********************************************************************/

void Fight::deleteCharacter(std::string characterName)
{
	char input;

	for (unsigned int i = 0; i < combatants.size(); i++)
	{
		if(combatants.at(i)->getCharacterName() == characterName)
		{

			std::cout << "Are you sure you want to delete " << characterName  << "? (Y/N) >> ";
			
			do
			{ 
				std::cin.get(input);
			
				if(input == 'Y' || input == 'y')
				{
					std::cout << characterName + " has been sent to meet their Gods." << std::endl;
					combatants.erase(combatants.begin() + i);
					return;
				}
				else if(input == 'N' || input == 'n')
				{
					std::cout << "They are spared... for now." << std::endl;
					return;
				}
				else
				{
					std::cout << "Invalid input. Please put in Y/N." << std::endl;
				}
			} 
			while(input != 'Y' && input != 'y' && input != 'N' && input != 'n');
		}
				
	}
	std::cout << "Character not found." << std::endl;

}

/*********************************************************************  
** Function: CharacterType* fight::getCharacter(std::string characterName)
** Description: Character retrieval function.
** Parameters: std::string characterName
** Pre-Conditions: Player selects character for fight.
** Post-Conditions: Populates Combat1 object with the character.
*********************************************************************/


CharacterType* Fight::getCharacter(std::string characterName)
{
	
	std::cout << "Character selected: " << characterName << std::endl;

	for (unsigned int i = 0; i < combatants.size(); i++)
	{
		if(combatants.at(i)->getCharacterName() == characterName)
		{
			return combatants.at(i);
		}
	
	}

	std::cout << "Character not found. Try again. >> ";
	return NULL;

}

/*********************************************************************  
** Function: void Fight::doBattle()
** Description: The fun part -- fighting. Removed the combat character and
**  queue parameters as they did not matter in this version.
** Parameters: N/A
** Pre-Conditions: Character and opponent are selected.
** Post-Conditions: Critters do battle and the results are shown on the screen.
*********************************************************************/


void Fight::doBattle()
{


	bool combatOver;
	int attackValue,
		damageTaken;

	

	std::cout << "Let the tournament commence! The two teams enter the blood-stained, dusty arena and prepare to battle." << std::endl;

	do 
	{

		turnCounter = 1;
		initiative = rand() % 2;

		if(initiative == 0)	// combat1 goes first
		{
			combat1Turn = true;
			combat2Turn = false;
		}

		else	// combat2 goes first
		{
			combat1Turn = false;
			combat2Turn = true;
		}

		combatOver = false;

		combat1 = queue1.getFront();
		combat2 = queue2.getFront();

		queue2.removeFront();
		queue1.removeFront();

		std::cout << "Presenting the two challengers! " << combat1->getCharacterName() << " the " << combat1->getCharacterType() << " and their opponent " << combat2->getCharacterName() << " the " << combat2->getCharacterType() << "! Let the battle commence!" << std::endl;
	
		while(!combatOver)
			{
				if(combat1Turn)
				{
					attackValue = combat1->characterAttack();

					if (combat1->getCharacterType() == "Goblin" && attackValue == 12 && combat2->getCharacterType() != "Goblin")
					{
						combat2->setAchilles(true);	// If the Goblin is able to cut the achilles tendon, set it to true for the opposing combatant as long as they are not a goblin.
					}
								
					damageTaken = combat2->characterDefense(attackValue);
					if(damageTaken > 0)
					{
						std::cout << combat1->getCharacterName() << " has hit " << combat2->getCharacterName() << " for " << damageTaken <<"!!!" << std::endl;
					}
					else
					{
						std::cout << combat2->getCharacterName() << " deflects " << combat1->getCharacterName() << "'s attack." << std::endl;
					}


					combat2->setStrengthPoints(damageTaken);
					std::cout << combat2->getCharacterName() << " has: " << combat2->getStrengthPoints() << " SP left." << std::endl;
				

					
					if(combat2->getStrengthPoints() <= 1)
					{
						if (turnCounter == 1)
						{

						combatOver = true;
						combat1->addVictoryPoints(2);
						if((combat2->getCharacterType() == "Shadow" || combat2->getCharacterType() == "Blue Man") && combat1->getCharacterType() == "Goblin")
						{
							combat1->addVictoryPoints(1);
						}
						losersStack.push(combat2);
						std::cout << combat2->getCharacterName() << " has fallen in battle. A group of cunning men run out to help them leave the arena." << std::endl;		
						combat1->healCharacter();
						queue1.addBack(combat1);
							
						}
						else
						{
						
						combatOver = true;
						combat1->addVictoryPoints(1);
						if((combat2->getCharacterType() == "Shadow" || combat2->getCharacterType() == "Blue Man") && combat1->getCharacterName() == "Goblin")
						{
							combat1->addVictoryPoints(1);
						}

						losersStack.push(combat2);
						std::cout << combat2->getCharacterName() << " has fallen in battle. A group of cunning men run out to help them leave the arena." << std::endl;		
						combat1->healCharacter();
						queue1.addBack(combat1);
						}

					}
					
					combat1Turn = false;
					combat2Turn = true;
					turnCounter++;
				}

				else
				{
					attackValue = combat2->characterAttack();

					std::cout << attackValue << std::endl;

					if (combat2->getCharacterType() == "Goblin" && attackValue == 12 && combat1->getCharacterType() != "Goblin")
					{
						combat1->setAchilles(true); // If the Goblin is able to cut the achilles tendon, set it to true for the opposing combatant as long as they are not a goblin.
					}

					damageTaken = combat1->characterDefense(attackValue);

					if(damageTaken > 0)
					{
						std::cout << combat2->getCharacterName() << " has hit " << combat1->getCharacterName() << " for " << damageTaken <<"!!!" << std::endl;
					}
					else
					{
						std::cout << combat1->getCharacterName() << " deflects " << combat2->getCharacterName() << "'s attack." << std::endl;
					}

					combat1->setStrengthPoints(damageTaken);
					std::cout << combat1->getCharacterName() << " has: " << combat1->getStrengthPoints() << " SP left." << std::endl;

					if(combat1->getStrengthPoints() <= 1)
					{
						if (turnCounter == 1)
						{

						combatOver = true;
						combat2->addVictoryPoints(2);
						if((combat1->getCharacterType() == "Shadow" || combat1->getCharacterType() == "Blue Man") && combat2->getCharacterType() == "Goblin")
						{
							combat2->addVictoryPoints(1);
						}
						losersStack.push(combat1);
						std::cout << combat1->getCharacterName() << " has fallen in battle. A group of cunning men run out to help them leave the arena." << std::endl;		
						combat2->healCharacter();
						queue2.addBack(combat2);
							
						}
						else
						{
						
						combatOver = true;
						combat2->addVictoryPoints(1);
						if((combat1->getCharacterType() == "Shadow" || combat1->getCharacterType() == "Blue Man") && combat2->getCharacterName() == "Goblin")
						{
							combat2->addVictoryPoints(1);
						}

						losersStack.push(combat1);
						std::cout << combat1->getCharacterName() << " has fallen in battle. A group of cunning men run out to help them leave the arena." << std::endl;		
						combat2->healCharacter();
						queue2.addBack(combat2);
						}
					}
					
					combat2Turn = false;
					combat1Turn = true;
					turnCounter++;

				}
			

			} 

		if(queue1.isEmpty())
		{
			std::cout << "Team 1 has been totally defeated!\n We will now tally the points.\n\n";
		

		}

		if(queue2.isEmpty())
		{
			std::cout << "Team 2 has been totally defeated!\n We will now tally the points.\n\n";
			
		}

		

		
	}while(!queue1.isEmpty() && !queue2.isEmpty());

	while(!queue2.isEmpty())
	{
		queue2.removeFront();
	}

	while(!queue1.isEmpty())
	{
		queue1.removeFront();
	}


	while(!losersStack.isEmpty())
	{
		losersStack.pop();
	}

	tournamentResults();
		

}

/*********************************************************************  
** Function: void Fight::teamPlacement()
** Description: Team placement 
** Parameters: N/A
** Pre-Conditions: Characters are selected and placed on teams.
** Post-Conditions: Team Lineup Queues are created.
*********************************************************************/

void Fight::teamPlacement()
{
	CharacterType* c;
	unsigned int size = 0;
	unsigned int roster = getRosterSize();
	int counter = 0;

	std::string newTeamMate;

	getCharacterList();

	
	if(roster < 6)
	{
		std::cout << "You need at least FOUR (3 per team) contestants to enter the tournament." << std::endl;
		return;
	}

	do
	{

		std::cout << "How large do you want both teams to be? (3-6) >> " << std::endl;
		std::cin >> size; 

		if((size * 2) > roster)
		{
			counter = ((size * 2) - roster);
			std::cout << "You need more contestants to fill the roster! You need " << counter << " more characters." << std::endl;
			return;
		}

		if(size < 3)
		{
			std::cout << "Urist is annoyed! He said this is a tournament, sure, The Servant of the Wraith Emperor won single-handedly last year, but it caused complaints. So we switched to a team format." << std::endl;
	
		}

		else if(size > 6)
		{
			std::cout << "Even though this is a bloody tournament, safety regulations require no more than 6 contestants be on each team." << std::endl;
		
		}

		

	} while (size < 3 || size > 6);

	counter = size;
	std::cin.ignore();
	std::cin.clear();

	for(unsigned int i = 0; i < size; i++)
	{
		while(!freeAgent)		
			{	
				std::cout << "Team 1 needs " << counter << " more contestants." << std::endl;
				std::getline(std::cin, newTeamMate);
				freeAgent = checkFree(newTeamMate);

				if(freeAgent)
				{
					c = getCharacter(newTeamMate);
					results1.push_back(c);
					queue1.addBack(c);
				}
				else
				{
					std::cout << newTeamMate << " is on a team already!" << std::endl;
				}
			}
			counter--;
			freeAgent = false;
	}
	
	std::cout << "Team 1 Created." << std::endl;

	counter = size; 

	for(unsigned int i = 0; i < size; i++)
	{
		while(!freeAgent && getCharacter(newTeamMate) != NULL)
		{
			std::cout << "Team 2 needs " << counter << " more contestants." << std::endl;
			std::getline(std::cin, newTeamMate);
			freeAgent = checkFree(newTeamMate);

			if(freeAgent)
			{
				c = getCharacter(newTeamMate);
				results2.push_back(c);
				queue2.addBack(c);
			}
			else
			{
				std::cout << newTeamMate << " is on a team already!" << std::endl;
			}

		}

		counter--;
		freeAgent = false;
	}

	for(unsigned int i = 0; i < size; i++)
	{
		if(results1.at(i) == NULL)
		{
			std::cout << "Team 1 has invalid members. Please try again." << std::endl; 
			results1.clear();
			results2.clear();
			return;
		}
		else if(results2.at(i) == NULL)
		{
			std::cout << "Team 2 has invalid members. Please try again." << std::endl; 
			results1.clear();
			results2.clear();
			return;
		}
	}
	
	
	std::cout << "Team 2 Created." << std::endl;

	doBattle();

	return;
}

/*********************************************************************  
** Function: void Fight::CombatSimulation
** Description: Testing Driver Function.
** Parameters: N/A
** Pre-Conditions: Start the program in testing mode (menus commented out or 9 is hit on the main menu)
** Post-Conditions: Critters do battle and the results are shown on the screen.
*********************************************************************/

void Fight::combatSimulation()
{
	std::cout << "Debugging Mode On. Test Combat Simulation!" << std::endl;

	combat1 = new Goblin("Schmidty");
	queue1.addBack(combat1);
	results1.push_back(combat1);	

	std::cout << combat1->getCharacterName() << " is added to the back." << std::endl;

	combat1 = new Barbarian("Conan");
	queue1.addBack(combat1);
	results1.push_back(combat1);	

	std::cout << combat1->getCharacterName() << " is added to the back." << std::endl;

	combat1 = new ReptilePeople("Sleekswim");
	queue1.addBack(combat1);
	results1.push_back(combat1);	

	std::cout << combat1->getCharacterName() << " is added to the back." << std::endl;

	combat2 = new BlueMen("MurderHobbit");
	queue2.addBack(combat2);
	results2.push_back(combat2);	

	std::cout << combat2->getCharacterName() << " is added to the back." << std::endl;

	combat2 = new TheShadow("Pazuzu");
	queue2.addBack(combat2);
	results2.push_back(combat2);	

	std::cout << combat2->getCharacterName() << " is added to the back." << std::endl;

	combat2 = new Goblin("Happy");
	queue2.addBack(combat2);
	results2.push_back(combat2);	

	std::cout << combat2->getCharacterName() << " is added to the back." << std::endl;

	doBattle();
//	doBattle(queue1, queue2);
//	doBattle(queue1, queue2);


}

/*********************************************************************  
** Function: void Fight::tournamentResults()
** Description: Determines the winning team and top 3 characters.
** Parameters: N/A
** Pre-Conditions: Characters fought, and a team lineup was beaten.
** Post-Conditions: Displays the results of the tournament, cleans up the 
**	queues, vectors, and stack, and gives the player an opportunity to start fresh.
*********************************************************************/


void Fight::tournamentResults()
{
	team1Total = 0;
	team2Total = 0;

	CharacterType* winner1;
	CharacterType* winner2;
	CharacterType* winner3;
	CharacterType* placeHolder;


	for(unsigned int i = 0; i < results1.size(); i++)
	{
		std::cout << results1.at(i)->getCharacterName() << " has " << results1.at(i)->getVictoryPoints() << " victory points.\n";
		team1Total += results1.at(i)->getVictoryPoints();
		champions.push_back(results1.at(i));
	}


	for(unsigned int i = 0; i < results2.size(); i++)
	{
		std::cout << results2.at(i)->getCharacterName() << " has " << results2.at(i)->getVictoryPoints() << " victory points.\n";
		team2Total += results2.at(i)->getVictoryPoints();
		champions.push_back(results2.at(i));
	}

	std::cout << "Team 1 Total: " << team1Total << std::endl;
	std::cout << "Team 2 Total: " << team2Total << std::endl;

	if(team1Total > team2Total)
	{
		std::cout << "Team 1 is the VICTOR!" << std::endl;
	}

	else if(team1Total < team2Total)
	{
		std::cout << "Team 2 is the VICTOR!" << std::endl;
	}

	else
	{
		std::cout << "Both teams have shown amazing prowess, they have tied!" << std::endl;
	}

	for(unsigned int i = 0; i < champions.size()-1; i++)
	{	
		for(unsigned int j = 0; j < champions.size()-1; j++)
		{

			if(champions.at(j)->getVictoryPoints() > champions.at(j+1)->getVictoryPoints())
			{
				placeHolder = champions.at(j);
				champions.at(j) = champions.at(j+1);
				champions.at(j+1) = placeHolder;
			}
		}
	}

	winner1 = champions.at(champions.size()-1);
	winner2 = champions.at(champions.size()-2);
	winner3 = champions.at(champions.size()-3);

	std::cout << "The individual winners of the Boatmurdered Tourney for their displays of skill, cunning, and prowess are: \n\n"
			   << "First Place: " << winner1->getCharacterName() << " with " << winner1->getVictoryPoints() << " points.\n"
			   << "Second Place: " << winner2->getCharacterName() << " with " << winner2->getVictoryPoints() << " points.\n"
			   << "Third Place: "	<< winner3->getCharacterName() << " with " << winner3->getVictoryPoints() << " points.\n";

	std::cout << "We hope you enjoyed the show! Come again soon." << std::endl;

	results1.clear();
	results2.clear();
	champions.clear();

	for(unsigned int i = 0; i<champions.size(); i++)
	{
		placeHolder = champions.at(i);
		delete placeHolder;
	}

	delete winner1;
	delete winner2;
	delete winner3;


	return; 	// Exit the program
}