/*********************************************************************  
** Program Filename: fight.cpp
** Author: Andrew M. Calhoun
** Date: 7/17/2015
** Description: The header file for the Fight class. Cntains the basic statistic 
** variables, functions, and other data to conduct fights in a fantasy combat game.
** Input:  		N/A
** Output:  	N/A
*********************************************************************/

#include <iostream>
#include "fight.hpp"
#include "frontEnd.hpp"

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
							<< "Do you wish to choose one of the Goblins as your champion?\n" << std::endl;	

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
						  << "Do you wish to choose one of the Barbarians of Barad Cuothil as your champion?\n" << std::endl;
						  
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
						  << "Do you wish for one of the Lizardfolk of the Mistyfen Marshes to be your champion?\n" << std::endl;
						  
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
			 			  << "Do you wish for one of the Blue Men to be your champion?\n" << std::endl;
			 			
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
				std::cout << "The Shadow, servant of the Wraith Emperor, returns as reigning champion to the tournament this year.\n"
						  << "Feared across the realms, he is able to dance between light and darkness, seemingly at will.\n"
						  << "Though fragile in his appearance, he is deceptively strong and has brought many unprepared opponents\n"
						  << "to a quick and bitter end.\n"
						  << "Do you wish The Shadow to be your champion?\n" << std::endl;
						  
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
** Function: void fight::getOpponentList()
** Description: The character list -- lists all characters in the opponent
**				(NPC) vector.
** Parameters: N/A
** Pre-Conditions: Begins the fight sequence and is given a list of their enemies.
** Post-Conditions: N/A
*********************************************************************/

void Fight::getOpponentList()
{

	if(opponents.empty())
	{
		populateOpponents();
		getOpponentList();
	
	}

	else
	{
		for(unsigned int i = 0; i < opponents.size(); i++)
		{
			std::cout << "*----------------*\n";
			std::cout << "Name: " << opponents.at(i)->getCharacterName() << " the " << opponents.at(i)->getCharacterType() << std::endl;
			std::cout << "Strength Points: " << opponents.at(i)->getStrengthPoints() << " / " << opponents.at(i)->getMaxStrengthPoints() << std::endl;
			std::cout << "*----------------*\n\n";
		

		}
	}
}

/*********************************************************************  
** Function: void fight::populateOpponents()
** Description: Creates the opponents for the player's characters.
** Parameters: N/A
** Pre-Conditions: Determines whether there are any opponents or not.
** Post-Conditions: Creates opponents if none exist, otherwise lists opponents.
*********************************************************************/

void Fight::populateOpponents()
{
	
		Goblin* opGob = new Goblin();
		opponents.push_back(opGob);

		Barbarian* opBarb = new Barbarian();
		opponents.push_back(opBarb);

		ReptilePeople* opRP = new ReptilePeople();
		opponents.push_back(opRP);

		BlueMen* opBM = new BlueMen();
		opponents.push_back(opBM);

		TheShadow* BossMonster = new TheShadow();	// Boss Monster because I'm feeling cheeky.
		opponents.push_back(BossMonster);

	
	
}

/*********************************************************************  
** Function: void fight::killCharacter() -- Planned Feature
** Description: If a player's character has less than -1 Strength Points, they die.
** Parameters: N/A
** Pre-Conditions: If a player's character has less than -1 Strength Points.
** Post-Conditions: Perma-Deaths (deletes) the character.
*********************************************************************/

void Fight::killCharacter(std::string characterName)
{
	for (unsigned int i = 0; i < combatants.size(); i++)
	{
		if(combatants.at(i)->getCharacterName() == characterName)
		{
			combatants.erase(combatants.begin() + i);
		}
	}
}

/*********************************************************************  
** Function: void fight::killOpponent() -- Planned Feature
** Description: If a player's character has less than -1 Strength Points, they die.
** Parameters: N/A
** Pre-Conditions: If an opponent has less than -1 Strength Points.
** Post-Conditions: Perma-Deaths (deletes) the opponent.
*********************************************************************/

void Fight::killOpponent(std::string characterName)
{
	for (unsigned int i = 0; i < opponents.size(); i++)
	{
		if(opponents.at(i)->getCharacterName() == characterName)
		{
			opponents.erase(opponents.begin() + i);
		}
	}

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
** Function: CharacterType* fight::getOpponent(std::string characterName)
** Description: Opponent retrieval function.
** Parameters: std::string characterName
** Pre-Conditions: Player selects character for fight.
** Post-Conditions: Populates the combat2 object with the opponent
*********************************************************************/

CharacterType* Fight::getOpponent(std::string characterName)
{
	std::cout << "Character selected: " << characterName << std::endl;

	for (unsigned int i = 0; i < opponents.size(); i++)
	{
		if (opponents.at(i)->getCharacterName() == characterName)
		{
			return opponents.at(i);
		}
		
		
	}
		std::cout << "Character not found. Try again. >> ";
		return NULL;
}

/*********************************************************************  
** Function: void Fight::doBattle(CharacterType* combat1, CharacterType* combat2)
** Description: The fun part -- fighting
** Parameters: CharacterType* combat1, CharacterType* combat2
** Pre-Conditions: Character and opponent are selected.
** Post-Conditions: Critters do battle and the results are shown on the screen.
*********************************************************************/


void Fight::doBattle(CharacterType* combat1, CharacterType* combat2)
{

	bool combatOver = false;
	int attackValue,
		damageTaken;

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

			std::cout << combat1->getCharacterName() << " has hit " << combat2->getCharacterName() << " for " << damageTaken <<"!!!" << std::endl;

			combat2->setStrengthPoints(damageTaken);
			
			std::cout << combat2->getCharacterName() << " has: " << combat2->getStrengthPoints() << " SP left." << std::endl;
			
			if(combat2->getStrengthPoints() <= 1)
			{
				combatOver = true;
				std::cout << combat2->getCharacterName() << " has been defeated!" << std::endl << std::endl;

			}
			
			combat1Turn = false;
			combat2Turn = true;
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

			std::cout << combat2->getCharacterName() << " has hit " << combat1->getCharacterName() << " for " << damageTaken << "!!!" << std::endl;

			combat1->setStrengthPoints(damageTaken);
			std::cout << combat1->getCharacterName() << " has: " << combat1->getStrengthPoints() << " SP left." << std::endl;

			if(combat1->getStrengthPoints() <= 1)
			{
				combatOver = true;
				std::cout << combat1->getCharacterName() << " has been defeated!\n\n";
			}
			
			combat2Turn = false;
			combat1Turn = true;

		}
	}

	/* For Death of Characters in Later Version */

	/*if(combat1->getStrengthPoints() <= -1)
	{
		// isDead = true;
		std::cout << combat1->getCharacterName() << " the " << combat1->getCharacterType() << " has succumbed to their injuries and is now with the Gods." << std::endl;
		deadCharacter = combat1->getCharacterName();
		killCharacter(deadCharacter);
	}

	else if(combat2->getStrengthPoints() <= -1)
	{
		 // isDead = true;
		std::cout << combat1->getCharacterName() << " the " << combat2->getCharacterType() << " has succumbed to their injuries and is now with the Gods." << std::endl;
		deadCharacter = combat2->getCharacterName();
		killOpponent(deadCharacter);
	}
*/
}
/*	attackValue = combat1->characterAttack();

	
*/

/*********************************************************************  
** Function: void Fight::CombatSimulation
** Description: Testing Driver Function.
** Parameters: N/A
** Pre-Conditions: Start the program in testing mode (menus commented out or 9 is hit on the main menu)
** Post-Conditions: Critters do battle and the results are shown on the screen.
*********************************************************************/

void Fight::combatSimulation()
{
	Goblin* g1 = new Goblin("Goblin 1");
	Goblin* g2 = new Goblin("Goblin 2");
	Goblin* g3 = new Goblin("Goblin 3");
	Goblin* g4 = new Goblin("Goblin 4");
	Goblin* g5 = new Goblin("Goblin 5");
	Goblin* g6 = new Goblin("Goblin 6");
	Goblin* g7 = new Goblin("Goblin 7");
	Goblin* g8 = new Goblin("Goblin 8");
	Goblin* g9 = new Goblin("Goblin 9");
	Goblin* g10 = new Goblin("Goblin 10");
/*	Goblin* g11 = new Goblin("Goblin 11");
	Goblin* g12 = new Goblin("Goblin 12");
*/
	Barbarian* b1 = new Barbarian("Barbarian 1");
	Barbarian* b2 = new Barbarian("Barbarian 2");

	ReptilePeople* r1 = new ReptilePeople("Rep 1");
	ReptilePeople* r2 = new ReptilePeople("Rep 2");

	BlueMen* m1 = new BlueMen("Blue Man 1");
	BlueMen* m2 = new BlueMen("Blue Man 2");

	TheShadow *ts1 = new TheShadow("Shadow 1");
	TheShadow *ts2 = new TheShadow("Shadow 2"); 

	doBattle(g1, g2 );
	doBattle(g2, g3);
	doBattle(g3, b1);
	doBattle(g4, b2);
    doBattle(g5, r1);	
	doBattle(g6, r2);
	doBattle(g7, m1);
	doBattle(g8, m2);
	doBattle(g9, ts1);
	doBattle(g10, ts2);

	g1->resetStrengthPoints();
	g2->resetStrengthPoints();
	b1->resetStrengthPoints();
	b2->resetStrengthPoints();
	r1->resetStrengthPoints();
	r2->resetStrengthPoints();
	m1->resetStrengthPoints();
	m2->resetStrengthPoints();
	ts1->resetStrengthPoints();
	ts2->resetStrengthPoints();

	doBattle(g1, g2);
	doBattle(b1, b2);
	doBattle(r1, r2);
	doBattle(m1, m2);
	doBattle(ts1, ts2); 
	doBattle(g1, b1);
	doBattle(b2, r1);
	doBattle(r2, m1);
	doBattle(m2, ts1);
	doBattle(ts2, g2);



}


/*********************************************************************  
** Function: void healthCheck(CharacterType* character)
** Description: Planned Feature - checks the character's health and warns the player
				on whether or not combat is a good idea.
** Parameters: CharacterType* character
** Pre-Conditions: Character is selected to fight.
** Post-Conditions: Advises the player on whether or not fighting is wise.
*********************************************************************/

void healthCheck(CharacterType* character)
{
	float currentHealth = character->getStrengthPoints();
	float maxHealth = character->getMaxStrengthPoints();

	if(currentHealth <= (maxHealth / 2))
	{
		std::cout << character->getCharacterName() << " is wounded, it is not recommended that he fight." << std::endl;
	}
	else if(currentHealth <= (maxHealth / 4))
	{
		std::cout << character->getCharacterName() << " is gravely injured. They should not fight!" << std::endl;
	}

	else if(currentHealth <= 2)
	{
		std::cout << character->getCharacterName() << " is near death! They will surely perish if they fight!" << std::endl;
	}

	else 
	{
		std::cout << "The cunning men state that " << character->getCharacterName() << " is in fine shape! Send them into the arena!" << std::endl;
	}

}