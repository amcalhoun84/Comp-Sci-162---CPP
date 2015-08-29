/**************************
Name: Andrew M. Calhoun (calhouna)
Email: calhouna@onid.oregonstate.edu
Date: 7/3/2015
Description: Header file for the 
GroceryItem Class. 
***************************/


#ifndef GROCERYITEM_HPP
#define GROCERYITEM_HPP

#include <vector>
#include <string>


// I started with just Units, but I realized that may be confusing, so I
// split the enumerators to further expand upon what is available. 

/*enum ItemWeight {OZ, GRAMS, LBS, GALLONS, FLOZ, CUPS, QUARTS, PINTS};
enum ItemPackage {CAN, PACKAGE, JUG, BOX, BAG, SACK, BAR, PIECE, MISC}; 

When I first wrote out the program, I tried using enumerations, but I found it opened
myself up to too many bugs and potential errors, particularly if we are going to need validation
procedures, so I opted to remove them from this program for the purposes of the assignment.
*/

class GroceryItem
{
private: 
	std::string pItemName;
	std::string pItemUnit;
	double pItemPrice;
	bool valid;
	int pItemQuantity;

public:
	GroceryItem(); // Default Constructor
	GroceryItem(std::string, std::string, double, int); // Constructor
	std::string getName();
	std::string getItemUnit();
	void setItemQuantity(int);	// How many are you buying?
	int getItemQuantity();
	void setItemPrice(double);	// What is the cost of each individual item?
	double getItemPrice();

};

#endif