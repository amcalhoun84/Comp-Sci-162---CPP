/**************************
Name: Andrew M. Calhoun (calhouna)
Email: calhouna@onid.oregonstate.edu
Date: 7/3/2015
Description: Source file for the 
GroceryList Class. 
***************************/

#include "groceryList.hpp"

// Default Constructor
GroceryList::GroceryList()
{
	listTotalPrice = 0; // If nothing is in the grocery list, we 
						// start off with zero to prevent potential faults or other 
						// strange behaviors. 
}

// Add an item to your grocery list.

void GroceryList::addItem(GroceryItem* item)
{
	std::string productName = item->getName(); // First, we check to make sure
											   // that the item isn't on the 
											   // list alredy

	if(getItem(productName) != NULL)
	{
		std::cout << "Item already on list." << std::endl;
		return;
	}

	groceryList.push_back(item);

}

std::string GroceryList::removeItem(GroceryItem* item)
{
	if(groceryList.empty())
	{
		std::cout << "Item not found or list is empty." << std::endl;
		return "List is empty";
	}

	std::cout << "Choose an item by name to remove." << std::endl;		
	std::string itemName;
	std::cin.ignore();
	std::getline(std::cin, itemName);


	for (int i=0; i<groceryList.size(); i++)
	{
		if(groceryList.at(i)->getName() == itemName)
		{
			groceryList.erase(groceryList.begin()+i);
			// std::cout << "Item removed." << std::endl << std::endl;
			return "Item Removed.";
		}
	}

	return "Item not found.";
}

GroceryItem* GroceryList::getItem(std::string name) 
{
	GroceryItem* item;

	for (int i=0; i<groceryList.size(); i++)
	{
		if(groceryList.at(i)->getName() == name)
		{
			return groceryList.at(i);
		}

	}
}

double GroceryList::listTotal()
{
	GroceryItem* item;
	listTotalPrice = 0;

	for(int i=0; i<groceryList.size(); i++)
	{
		listTotalPrice += groceryList.at(i)->getItemPrice(); // figure out a way to keep it from adding for just the list view.
	}

	return listTotalPrice;

}

std::vector<GroceryItem*> GroceryList::showList()
{
	GroceryItem* item;
	
	for (int i=0; i<groceryList.size(); i++)
	{
		item = groceryList.at(i);
		std::cout << "Item Name: " << item->getName() << " - " << item->getItemUnit() << " - " << item->getItemQuantity() << std::endl;
		std::cout << "Item Price: $" << std::fixed << std::setprecision(2) << item->getItemPrice() << std::endl << std::endl;
	}

	std::cout << "Total: $" << listTotal() << std::endl << std::endl;
	return groceryList;
}

std::vector<GroceryItem*> GroceryList::outputList()
{
	GroceryItem* item;

	std::ofstream outlist;
	outlist.open("grocerylist.txt");
	
	outlist << "Grocery Shopping List" << std::endl << std::endl;
	
	for (int i=0; i<groceryList.size(); i++)
	{
		item = groceryList.at(i);
		outlist << i+1 << ". " << item->getName() << " - " << item->getItemUnit() << " - " << item->getItemQuantity() << std::endl;
		outlist << "Item Price: $" << std::fixed << std::setprecision(2) << item->getItemPrice() << std::endl << std::endl;
	}

	outlist << "Total: $" << listTotal() << std::endl; 
	outlist.close();
	return groceryList;
}

double GroceryList::double_input()
{

	double input = -1;
	bool valid = false;
	


	do 
	{
		std::cin >> input;

		if(std::cin.good())	// Looked up some tutorials on stack overflow, for quick validation tricks.
		{	
			if(input<=0.00)
			{
				std::cout << "Cannot be free or negative." << std::endl;
 			}
 			else
 			{
			// Things look okay!
			valid = true;
		
			}
		}
		else
		{	
			input = 0;
			// Woops! Something went wrong, so let's try something else!
			std::cin.clear();
			std::cin.ignore(1000000000, '\n');
			valid = false;
			std::cout << "Invalid input, please try again.: " << std::flush;
		}
	}
	while (valid == false);
		return (input);

}

int GroceryList::int_input()
{
	
	int input;
	bool valid = false;
	
	do 
	{
		std::cin >> input;
		if(std::cin.good())	// Looked up some tutorials on stack overflow, for quick validation tricks.
		{	
			if(input<=0)
			{
				std::cout << "Cannot be less than 1." << std::endl;
 			}
 			else
 			{
			// Things look okay!
			valid = true;

			}
		}
		else
		{	
			input = 0;
			// Woops! Something went wrong, so let's try something else!
			std::cin.clear();
			std::cin.ignore(10000000000, '\n');
			valid = false;
			std::cout << "Invalid input, please try again.: " << std::flush;
		}
	}
	while (valid == false);
	return (input);
}

