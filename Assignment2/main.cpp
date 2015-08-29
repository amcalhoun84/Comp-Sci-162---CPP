/*********************************************************************  
** Program Filename: main.cpp
** Author: Andrew M. Calhoun
** Date: 7/8/2015
** Description: Main testing file for Library inventory functions.
				Takes User to libraryMenu() function.
** Input: From file or user input and potential debug mode.
** Outut: New or updated file is output when saved.
***********************************************************************/ 

#include <iostream>

#include "audiobook.hpp"
#include "item.hpp"
#include "library.hpp"
#include "video.hpp"

/*********************************************************************
** Function: int main()
** Description: Main function for libraryInventory program.
** Parameters: N/A
**
** Pre-Conditions: Calls the library menu function and starts the program.
** Post-Conditions: N/A
*********************************************************************/ 

int main()
{
	Library l;
	l.readFile(); // Reads file into memory automatically on load. 
	std::cout << "Welcome to your personal library inventory assistant.\n\n";
	l.libraryMenu();
	return 0;
}
