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

	unsigned int initiative;
	bool combat1Turn, 
		 combat2Turn,
		 combatOver;

	std::string deadCharacter;
	std::string newName;

	std::vector<CharacterType*> combatants;	
	std::vector<CharacterType*> opponents;	



public:

	void combatSimulation();
	void populateOpponents();
	void getOpponentList();
	void createCharacter();
	void deleteCharacter(std::string characterName);
	void killCharacter(std::string characterName);
	void killOpponent(std::string characterName);
	void doBattle(CharacterType* combat1, CharacterType* combat2);
	void healthCheck(CharacterType* character);
	bool getCharacterList();
	bool checkUnique(std::string characterName);
	CharacterType* getCharacter(std::string characterName);
	CharacterType* getOpponent(std::string characterName);

};


#endif