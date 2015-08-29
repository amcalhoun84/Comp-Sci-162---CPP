/**************************
Name: Andrew M. Calhoun (calhouna)
Email: calhouna@onid.oregonstate.edu
Date: 7/3/2015
Description: Main.cpp for GroceryList
Class. 
***************************/


#include "groceryList.hpp"
#include "groceryItem.hpp"
#include <string>
#include <iostream>
#include <cctype>
#include <iomanip>


int main() {

	GroceryList l;
	GroceryItem* item = NULL;

	char input;
	const int maxchar = 1;

	/* Demonstration Items so a list instantiates every time */

	GroceryItem* item0 = new GroceryItem("Potatoes", "5 Lb. Sack", 2.50, 2);
	GroceryItem* item1 = new GroceryItem("Uncle Ben's Rice", "32 oz. Box", 2.99, 5);
 	GroceryItem* item2 = new GroceryItem("Lagunita's IPA", "6-Pack", 8.99, 2);
 	GroceryItem* item3 = new GroceryItem("Top Sirloin", "32 oz", 18.99, 1);
 	GroceryItem* item4 = new GroceryItem("Citronella Bug Spray", "12 oz. Cans", 3.99, 1);
 	
 	l.addItem(item0);
 	l.addItem(item1);
 	l.addItem(item2);
 	l.addItem(item3);
 	l.addItem(item4);
	
	do { 	// Keeps doing the menu until the User Quits.

		std::string itemName = "";
		std::string itemUnit = "";
		int itemQuant = 0;
		double itemPrice = 0;
	
		// Menu - for user input

		std::cout << "Grocery List Maker" << std::endl;
		std::cout << "1. Add Item" << std::endl;
		std::cout << "2. Remove Item" << std::endl;
		std::cout << "3. View List" << std::endl;
		std::cout << "4. Print List to File" << std::endl;
		std::cout << "0. Quit" << std::endl;

		std::cout << "Please input your choice: " << std::endl;
		
		std::cin >> input;
		
		switch (input)
		{

			case '1': 
			{
			
			while (itemName.empty())
			{
				std::cout << "Item Name: ";
				std::cin.ignore();
				std::getline(std::cin, itemName);
				if(itemName == "" || itemName == " " || itemName.empty())
				{
					std::cout << "Item must have name.\n" << std::endl;
				}

			}

			while (itemUnit.empty())
			{
				std::cout << itemName << " Packaging/Unit: " << std::flush;
				//std::cin.ignore();
				std::getline(std::cin, itemUnit);
				if (itemUnit == "" || itemUnit.empty())
				{
					std::cout << itemName << " must have packing or unit.\n" << std::endl;
				}
			}

			while(itemPrice <= 0.00)
			{
				std::cout << "Item Price: "; 
				itemPrice = l.double_input();
			}

			std::cin.ignore(100000000000, '\n'); // clearing the buffer so things don't repeat needlessly;
			while(itemQuant <= 0)
			{
				std::cout << "Number of item - please use whole integers: ";
				itemQuant = l.int_input();
			}

			item = new GroceryItem(itemName, itemUnit, itemPrice, itemQuant);

			l.addItem(item);
			std::cout << "Item Added to List!\n" << std::endl;
			std::cin.ignore(100000000000, '\n'); // clearing the buffer so things don't repeat needlessly;
			break;

			}

			case '2':
			{
				std::cout << l.removeItem(item) << std::endl;
				break;
			}

			case '3':
			{
				std::cout << "Grocery List:\n" << std::endl;
				l.showList();
				break;
			}

			case '4':
			{
				l.outputList();
				std::cout << "Grocery List Printed to File.\n" << std::endl;
				break;
			}

			case '0':
			{
				return 0;
			}

			default: 
			{	

				std::cout << "That is not a valid input." << std::endl;
				std::cin.clear();
				std::cin.ignore(100000000000, '\n'); // clearing the buffer so things don't repeat needlessly;
				break;
		
			}
			
			

		} 

	}while (input != '0');
}

