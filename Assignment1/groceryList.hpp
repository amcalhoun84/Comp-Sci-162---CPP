/**************************
Name: Andrew M. Calhoun (calhouna)
Email: calhouna@onid.oregonstate.edu
Date: 7/3/2015
Description: Header file for the 
GroceryList Class. 
***************************/

#ifndef GROCERYLIST_HPP
#define GROCERYLIST_HPP

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <fstream>
#include "groceryItem.hpp"

class GroceryList
{

private:
	
	double listTotalPrice; 
	std::vector<GroceryItem*> groceryList;

public:
	GroceryList();
	void addItem(GroceryItem*);
	std::string removeItem(GroceryItem*);
	double listTotal();
	std::vector<GroceryItem*> showList();
	std::vector<GroceryItem*> outputList();
	GroceryItem* getItem(std::string);

	double double_input();
	int int_input();

};

#endif