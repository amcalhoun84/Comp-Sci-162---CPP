/*********************************************************************  
** Program Filename: fight.hpp
** Author: Andrew M. Calhoun
** Date: 7/17/2015
** Description: The header file for the Fight class. Cntains the basic statistic 
** variables, functions, and other data to conduct fights in a fantasy combat game.
** Input:  		N/A
** Output:  	N/A
*********************************************************************/

#ifndef FIGHT_HPP
#define FIGHT_HPP


#include <vector>
#include "queue.hpp"
#include "stack.hpp"
#include "node.hpp"
#include "characterType.hpp"
#include "goblin.hpp"
#include "barbarian.hpp"
#include "reptilePeople.hpp"
#include "blueMen.hpp"
#include "theShadow.hpp"

class Fight { 

private:


	CharacterType* combat1;
	CharacterType* combat2;
	CharacterType* preGen;
	Stack losersStack;
	Queue queue1;
	Queue queue2;
	Queue resultsLineUp;

	unsigned int initiative, 
				 turnCounter,
				 teamNumber,
				 teamSize,
				 teamCount,
				 team1Total,
				 team2Total;



	bool  freeAgent,
		  combat1Turn, 
		  combat2Turn,
		  combatOver;
		 
	std::string deadCharacter,
				newName,
				teamName1,
				teamName2;


	std::vector<CharacterType*> combatants;	
	std::vector<CharacterType*> results1;
	std::vector<CharacterType*> results2;
	std::vector<CharacterType*> champions;
	// std::vector<CharacterType*> opponents;	Edited out of this edition, given we just have combatants.



public:

	void combatSimulation();
	void populateOpponents();
	void getOpponentList();
	void createCharacter();
	void deleteCharacter(std::string characterName);
	void killCharacter(std::string characterName);
	void killOpponent(std::string characterName);
	void doBattle();
	void healthCheck(CharacterType* character);
	bool getCharacterList();
	bool checkUnique(std::string characterName);
	bool checkFree(std::string characterName);
	void teamPlacement();
	CharacterType* getCharacter(std::string characterName);
	CharacterType* getOpponent(std::string characterName);
	void tournamentResults();
	int getRosterSize();


/*********************************************************************  
** Function: void preGenerated()
** Description: Pre-Generated Characters, given the character creation
				worked last time.
** Parameters: N/A
** Pre-Conditions: Program Started.
** Post-Conditions: Critters created.
*********************************************************************/

	void preGenerated()
	{
		preGen = new Goblin("Schmidty");
		combatants.push_back(preGen);
		preGen = new Goblin("Angry");
		combatants.push_back(preGen);
		preGen = new Barbarian("Gors");
		combatants.push_back(preGen);
		preGen = new Barbarian("Gotha");
		combatants.push_back(preGen);
	
		preGen = new ReptilePeople("Zalu");
		combatants.push_back(preGen);
		preGen = new ReptilePeople("Mook");
		combatants.push_back(preGen);
	
		preGen = new BlueMen("Bilbo");
		combatants.push_back(preGen);
		preGen = new BlueMen("Frodo");
		combatants.push_back(preGen);
	
		preGen = new TheShadow("Pazuzu");
		combatants.push_back(preGen);
		preGen = new TheShadow("Almech");
		combatants.push_back(preGen);


	}

};


#endif