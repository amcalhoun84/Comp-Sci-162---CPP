/*********************************************************************  
** Program Filename: characterType.hpp
** Author: Andrew M. Calhoun
** Date: 7/17/2015
** Description: The header file for the CharacterType class and subclasses.
** 				contains the basic statistic variables, functions, and 
**				other data about the various classes in a fantasy combat arena
				game.
** Input:  		N/A
** Output:  	N/A
*********************************************************************/

#ifndef CHARACTERTYPE_HPP
#define CHARACTERTYPE_HPP

#include <string>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <iostream>

class CharacterType
{
protected:
	

		int armor,
		maxStrengthPoints,
		strengthPoints,
		currentStrengthPoints,
		damage,
		defense,
		numOfSides,
		numOfDice,
		diceRoll,
		vPoints;		// Victory Points
		std::string className,
			creatureName,
			teamName;


	bool achHeel,
		 isDead;			// If they're killed, gets a special message.

//	std::string rNames[];
//	std::vector<std::string> randomNames(rNames, rNames + 130);

	/* Creature Specials - use to test on all classes as well. */
	bool won;



public:
	CharacterType();
	virtual ~CharacterType(); 	// It's time to get in the habit of using destructors, especially for games and more dynamic programs.
	
	std::string getCharacterName();
	std::string getCharacterType();
	
	virtual int characterAttack() = 0;
	virtual int	characterDefense(int _characterAttack) = 0 ;
	
	void setStrengthPoints(int damage);
	void resetCharacterPoints() { this->currentStrengthPoints = maxStrengthPoints;
								 this->achHeel = false;
								 this->vPoints = 0; }

	void healCharacter();

	int getStrengthPoints();
	int getMaxStrengthPoints();


	// Point Tally Functions
	void addVictoryPoints(int _vPoints);
	int getVictoryPoints();

	void setAchilles(bool achHeel);
//	virtual void characterReset(){}

	/* For Stats */

	/* For Fun */

	std::string randomNameGenerator();

// Dice Rolling Algorithm

	int rollDice(int numOfDice, int numOfSides);


};


#endif