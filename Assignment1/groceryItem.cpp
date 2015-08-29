/**************************
Name: Andrew M. Calhoun (calhouna)
Email: calhouna@onid.oregonstate.edu
Date: 7/3/2015
Description: Source file for the 
GroceryItem Class. 
***************************/


#include "groceryItem.hpp"

#include <iostream>
#include <vector>
#include <string>
//#include <iomanip>


// Default Constructor for Grocery Item
GroceryItem::GroceryItem()	
{
	this->pItemName = "";
	this->pItemUnit = "";
	this->pItemPrice = 0;
	this->pItemQuantity = 0;
}


/****************************************************************
 Constructor for Grocery Items, sets them on the basis of whatever 
the user input from the main menu function "Add Item" is.
*******************************************************************/

GroceryItem::GroceryItem(std::string name, std::string unit, double price, int quantity)
{
	this->pItemName = name;	// Strings can have their own setter within
	this->pItemUnit = unit;	// the file. Interesting trick!
	setItemPrice(price);
	setItemQuantity(quantity);
}

// Acccessors for the name and item unit.

std::string GroceryItem::getName()
{
	return pItemName;
}

std::string GroceryItem::getItemUnit()
{
	return pItemUnit;
}

// Set the quantity based on user input.

void GroceryItem::setItemQuantity(int quant)
{
	pItemQuantity = quant;
}

// Get quantities for our grocery list.

int GroceryItem::getItemQuantity()
{
	return pItemQuantity;
}

// Set ItemPrice, based on user input.

void GroceryItem::setItemPrice(double prc)
{
	pItemPrice = prc;
}

// Get item price.

double GroceryItem::getItemPrice()
{
	return pItemQuantity * pItemPrice; // Returns the item cost with quantity factored in.
}