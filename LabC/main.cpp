#include <iostream>
#include <fstream>
#include "dice.hpp"
#include "loadedDice.hpp"

int main() {

	int numberSides, tests;		 // input variables
	std::ofstream myFile;		 // setup an output stream
	myFile.open ("results.csv"); // create/open a file to export results.

	Dice standardDie;
//	Dice tenSided(10); // Used in a testing phase, decided to go for custom sided dice to examine results.
	

	LoadedDice standardLoaded;
//	LoadedDice loadedTen(10);	Used in a testing phase, decided to go for custom sided dice to examine results.

	std::cout << "Please input the number of sides for your dice. (1-100)" << std::endl;
	std::cin >> numberSides;
	
	while(numberSides < 1 || numberSides > 100)	// validation loop
	{
		std::cout << "Use a valid number. (1-100)" << std::endl;
		std::cin >> numberSides;
	} 

	Dice customDice(numberSides);	// instantiate custom dice.
	LoadedDice loadedCustom(numberSides);

	std::cout << "Please input the number of test rolls for your dice. (1-100)" << std::endl;
	std::cin >> tests;
	

	while(tests < 1 || tests > 100)	// validation loop
	{
		std::cout << "Use a valid number. (1-100)" << std::endl;
		std::cin >> tests;
	} 


	myFile << "Trial Number , Dice 1, Dice 2 (" << numberSides << " sided), Standard Total, Loaded Dice 1, Loaded Dice 2 (" << numberSides << " sided), Loaded Total" << std::endl;

	for(int i=1; i<=tests; i++)
	{	// variables created to make book-keeping easier
		int dice1 = standardDie.rollDice(),
			dice2 = customDice.rollDice(),
			loadedDice1 = standardLoaded.rollDice(),
			loadedDice2 = loadedCustom.rollDice();
		
		// using doubles to avoid a floating point exception
		/* double result,
			loadedResult, 
			mean,
			loadedMean; -- this became superfluous, as I realized there may be other options when we export the files. */ 

	myFile << i << "., " << dice1 << " , " << dice2 << " , "	<< dice1 + dice2 << " , " << loadedDice1 << " , " << loadedDice2 << ", " << (loadedDice1 + loadedDice2) << std::endl;

	}
	myFile.close();
	return 0;

}