/*********************************************************************  
** Program Filename: main.cpp
** Author: Andrew M. Calhoun (calhouna@onid.oregonstate.edu)
** Date: 7/31/2015
** Description: The main source file for labFb.
** Input: User determined string.
** Output: Reverse Polish Notation Calculations
*********************************************************************/

#include "ADT_Stack.hpp"
#include "calculator.hpp"
#include <iostream>
#include <string>

/*********************************************************************  
** Function:  int main()
** Description: the main function of labFb. Contains test cases for a 
** RPN calculator.
** Parameters:  none
** Pre-Conditions:  program start
** Post-Conditions: return 0
*********************************************************************/

int main()
{
	Calculator calc;
	std::string testing;
	int output;

	/* Static Test Cases */

	testing = "143+552+/%";	// Should be 1
	std::cout << testing << std::endl;
	std::cout << "Calculation: " << calc.operations(testing) << std::endl;

	testing = "2 5 6 + 7 - *";		// Should be 8
	std::cout << testing << std::endl;
	std::cout << "Calculation: " <<calc.operations(testing) << std::endl;

	testing	= "5742316++**++";		// Should be 92
	std::cout << testing << std::endl;
	std::cout << "Calculation: " <<calc.operations(testing) << std::endl;

	testing	= "57+42*-";		// Should be 4
	std::cout << testing << std::endl;
	std::cout << "Calculation: " <<calc.operations(testing) << std::endl;

	testing	= "574+23*1/+6-*";		// Should be 25
	std::cout << testing << std::endl;
	std::cout << "Calculation: " <<calc.operations(testing) << std::endl;

	std::cout << "Please input a custom string in polish notation." << std::endl;

	std::getline(std::cin, testing);	// Will be whatever you want. :)
	
	std::cout << "Calculation: " <<calc.operations(testing) << std::endl;

	return 0;
}