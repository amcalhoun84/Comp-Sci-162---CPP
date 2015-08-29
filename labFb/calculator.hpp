/*********************************************************************  
** Program Filename: calculator.hpp
** Author: Andrew M. Calhoun (calhouna@onid.oregonstate.edu)
** Date: 7/31/2015
** Description: The calculator class header file for labFb.
** Input: User determined string.
** Output: Reverse Polish Notation Calculations
*********************************************************************/

#ifndef CALCULATOR_HPP
#define CALCULATOR_HPP

#include "ADT_Stack.hpp"
#include <cmath>
#include <string>
#include <iostream>
#include <cctype>

class Calculator
{

private:

	ADT_Stack stack;
	int x, y, result;
	std::string inputs;
	
public:

	Calculator();
	int operations(std::string inputs);
	void add();
	void sub();
	void mul();
	void div();
	void mod();
	void powers();
//	~Calculator();

};

#endif