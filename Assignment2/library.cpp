/*********************************************************************
** Program Filename: library.cpp
** Author: Andrew M. Calhoun
** Date: 07/8/2015
** Description: The primary functions for the library file.
** Input: Add Items, save requests, and printout requests, as well as delete item.
**
** Output: Will save all items in the inventory to file. Will print out
**		   what is in the inventory, remove items, etc.
*********************************************************************/

#include "item.hpp"
#include "book.hpp"
#include "video.hpp"
#include "audiobook.hpp"
#include "library.hpp"


/*********************************************************************
** Function: Library::Library()
** Description: The default constructor for the library class. 
** Parameters: N/A
** Pre-Conditions: N/A
** Post-Conditions: N/A
*********************************************************************/ 

Library::Library()
{

}

/*********************************************************************
** Function: int Library::libraryMenu()
** Description: The library menu
** Parameters: N/A
** Pre-Conditions: Start up the program.
** Post-Conditions: Will have done user input, when exited, will return
**	to the command prompt or operating system. 
*********************************************************************/ 

int Library::libraryMenu()
{
	
	std::string line;

	do
	{

		std::cout 	<< "Please select from the following options: \n\n"
			  	<< "*----------------------------------------------*\n\n"
			  	<< "A. Add Item\n"
				<< "D. Delete Item\n"
				<< "I. List Current Inventory In Memory\n"
			   	<< "S. Save Library Inventory File.\n"
 			  	<< "U. Update Item\n"
			  	<< "Q. Quit Inventory Program. \n\n"
			  	<< "*----------------------------------------------*\n";

		std::cout << "Choice >> ";
		std::cin.get(menuOption);
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    		
		switch (menuOption)
		{
			case 'A':
			case 'a':
			{
				addItem();
				break;
			}

			case 'D':
			case 'd':
			{
				
				std::cout << "Book for deletion ID >> ";
				std::getline(std::cin, fetchItemID);
				deleteItem(fetchItemID);
				break;
			}

			case 'I':
			case 'i':
			{
				readInventory();
				break;
			}

			// LEFT IN FOR DEBUGGING PURPOSES ONLY!!!!

			case 'R':
			case 'r':
			{
				readFile();
				break;
			}

			case 'S':
			case 's':
			{
				saveFile();
				break;
			}

			case 'U':
			case 'u':
			{
				std::cout << "Please input ID for item to update >> ";
				std::getline(std::cin, fetchItemID);
				updateItem(fetchItemID);
				break;
			}

			case 'Q':
			case 'q':
			{
				std::cout << "Have a nice day!\n\n";
				return 0;
			}

			default: 
			{
				std::cout << "Invalid Input" << std::endl;
				break;
			}

		}

	}

	while(menuOption != 'Q' || 'q');
}


/*********************************************************************
** Function: void Library::addItem()
** Description: This function is used to create items, and will ask for the
**	basic information and set flags and data accordingly.
** Parameters: N/A
** Pre-Conditions: Request to make an item.
** Post-Conditions: Will create an item and add it to the respective inventory
**		arrays based on user input. 
*********************************************************************/ 

void Library::addItem()
{

	do
	{
		std::cout << "What sort of item is it? (1 = Book, 2 = Video, 3 = Audio Book, 0 to Quit)" << std::endl;
		std:: cout << "Input >> ";
		std::cin >> newItemClass;
		std::cin.clear();
	
		switch (newItemClass)
		{
			case 1: 
			{
				newBook();
				break;
			}
		
			case 2:
			{
				newVideo();
				break;
			
			}

			case 3:
			{
				newAudioBook();
				break;
			}

			case 0:
			{
				return;
			}

			default: 
			{
				std::cout << "Invalid Input" << std::endl;
				break;
			}
		}
	} while(newItemClass != 0);
}

/*********************************************************************
** Function: void Library::deleteItem
** Description: Delete an item from the inventory. 
** Parameters: std::string fetchItemID 
** Pre-Conditions: User will request to delete an item based on its ID and
**	the program will search for that item in the various vectors.
** Post-Conditions: Item will be removed from its respective vector and 
	return user to main menu.
*********************************************************************/ 

void Library::deleteItem(std::string fetchItemID)
{
	for (unsigned int i = 0; i < libraryInventoryBK.size(); i++)
	
	{
		if(fetchItemID == libraryInventoryBK.at(i)->getItemID())
		{
			libraryInventoryBK.erase(libraryInventoryBK.begin()+i);
			std::cout << "Item Deleted!" << std::endl;
			return;
		}	
	}

	for (unsigned int i = 0; i < libraryInventoryVID.size(); i++)
	
	{
		if(fetchItemID == libraryInventoryVID.at(i)->getItemID())
		{
			libraryInventoryVID.erase(libraryInventoryVID.begin()+i);
			std::cout << "Item Deleted!" << std::endl;
			return;
		}	
	}

	for (unsigned int i = 0; i < libraryInventoryAB.size(); i++)
	
	{
		if(fetchItemID == libraryInventoryAB.at(i)->getItemID())
		{
			libraryInventoryAB.erase(libraryInventoryAB.begin()+i);
			std::cout << "Item Deleted!" << std::endl;
			return;
		}	
	}

	std::cout << "Item not found." << std::endl;

}

/*********************************************************************
** Function: void Library::saveFile()
** Description: Saves the current objects saved in memory to the output file.
** Parameters: N/A
** Pre-Conditions: User selects the save file option from the main menu.
** Post-Conditions: New version of the library inventory file is saved.
*********************************************************************/ 
void Library::saveFile()
{

	std::ofstream oStream;
	oStream.open("library-test.txt");

	
for (unsigned int i =0; i < libraryInventoryBK.size(); i++)
	{
		if(libraryInventoryBK.at(i)->getItemID() != "BK-0")
		{

		oStream << libraryInventoryBK.at(i)->getItemType() << std::endl
			<< libraryInventoryBK.at(i)->getItemID() << std::endl
			<< libraryInventoryBK.at(i)->getTitle() << std::endl
			<< libraryInventoryBK.at(i)->getAuthor() << std::endl
			<< libraryInventoryAB.at(i)->getPublisher() << std::endl
			<< libraryInventoryBK.at(i)->getLength() << " Pages" << std::endl
			<< libraryInventoryBK.at(i)->getLocation() << std::endl 
			<< libraryInventoryBK.at(i)->getRev() << std::endl << std::endl;
		}
	}

	for (unsigned int i =0; i < libraryInventoryVID.size(); i++)
	{
		if(libraryInventoryVID.at(i)->getItemID() != "VID-0")
		{
			oStream << libraryInventoryVID.at(i)->getItemType() << std::endl
			  << libraryInventoryVID.at(i)->getItemID() << std::endl
			  << libraryInventoryVID.at(i)->getTitle() << std::endl
			  << libraryInventoryVID.at(i)->getAuthor() << std::endl
			  << libraryInventoryVID.at(i)->getActors() << std::endl
			  << libraryInventoryVID.at(i)->getPublisher() << std::endl
			  << libraryInventoryVID.at(i)->getLength() << " minutes" << std::endl
			  << libraryInventoryVID.at(i)->getLocation() << std::endl
			  << libraryInventoryVID.at(i)->getRev() << std::endl << std::endl;
		}
	}
	
	for (unsigned int i =0; i < libraryInventoryAB.size(); i++)
	{
		if(libraryInventoryAB.at(i)->getItemID() != "AB-0")
		{
		
		oStream << libraryInventoryAB.at(i)->getItemType() << std::endl
				<< libraryInventoryAB.at(i)->getItemID() << std::endl
				<< libraryInventoryAB.at(i)->getTitle() << std::endl
				<< libraryInventoryAB.at(i)->getAuthor() << std::endl
				<< libraryInventoryAB.at(i)->getNarrator() << std::endl
				<< libraryInventoryAB.at(i)->getPublisher() << std::endl
				<< libraryInventoryAB.at(i)->getLength() << " minutes" << std::endl
				<< libraryInventoryAB.at(i)->getLocation() << std::endl 
				<< libraryInventoryAB.at(i)->getRev() << std::endl << std::endl;
			
		}
	}

	std::cout << "File Saved!" << std::endl;
}

/*********************************************************************
** Function: void Library::readInventory()
** Description: Will print out the inventory based on what is in the 
	inventory arrays.
** Parameters: N/A
** Pre-Conditions: User requests to see inventory.
** Post-Conditions: Will print out inventory to screen and return user
	to main menu.
*********************************************************************/ 

void Library::readInventory()
{
	std::cout << "Books:\n\n";

	for (unsigned int i = 0; i < libraryInventoryBK.size(); i++)
	{
		
	//	std::cout << "Item Type: " << libraryInventoryBK.at(i)->getItemType() << std::endl
			std::cout << "Item ID: " << libraryInventoryBK.at(i)->getItemID() << std::endl
			<< "Title: " << libraryInventoryBK.at(i)->getTitle() << std::endl
			<< "Author: " << libraryInventoryBK.at(i)->getAuthor() << std::endl
			<< "Publisher: " << libraryInventoryAB.at(i)->getPublisher() << std::endl
			<< "Length: " << libraryInventoryBK.at(i)->getLength() << std::endl
			<< "Location: " << libraryInventoryBK.at(i)->getLocation() << std::endl 
			<< libraryInventoryBK.at(i)->getReserve() << std::endl << std::endl;
		
	}

	for (unsigned int i = 0; i < libraryInventoryVID.size(); i++)
	{
	//		std::cout << "Item Type: " << libraryInventoryVID.at(i)->getItemType() << std::endl
			  std::cout << "Item ID: " << libraryInventoryVID.at(i)->getItemID() << std::endl
			  << "Title: " << libraryInventoryVID.at(i)->getTitle() << std::endl
			  << "Producer/Director: " << libraryInventoryVID.at(i)->getAuthor() << std::endl
			  << "Actors: "	<< libraryInventoryVID.at(i)->getActors() << std::endl
			  << "Studio: " << libraryInventoryVID.at(i)->getPublisher() << std::endl
			  << "Length: " << libraryInventoryVID.at(i)->getLength() << std::endl
			  << "Location: " << libraryInventoryVID.at(i)->getLocation() << std::endl
			  << libraryInventoryVID.at(i)->getReserve() << std::endl << std::endl;
		
	}
	
	for (unsigned int i = 0; i < libraryInventoryAB.size(); i++)
	{
		
	//	std::cout << "Item Type: " << libraryInventoryAB.at(i)->getItemType() << std::endl
		std::cout << "Item ID: " << libraryInventoryAB.at(i)->getItemID() << std::endl
				<< "Title: " << libraryInventoryAB.at(i)->getTitle() << std::endl
				<< "Author: " << libraryInventoryAB.at(i)->getAuthor() << std::endl
				<< "Narrator: " << libraryInventoryAB.at(i)->getNarrator() << std::endl
				<< "Publisher: " << libraryInventoryAB.at(i)->getPublisher() << std::endl
				<< "Length: " << libraryInventoryAB.at(i)->getLength() << std::endl
				<< "Location: " << libraryInventoryAB.at(i)->getLocation() << std::endl 
				<< libraryInventoryAB.at(i)->getReserve() << std::endl << std::endl;
			
		
	}

}

/*********************************************************************
** Function: void Library::readFile()
** Description: Will read the file specificed by the program.
** Parameters: N/A
** Pre-Conditions: Program starts.
** Post-Conditions: Reads from the Text File and saves the information inside
**					to memory, so that it becomes part of the inventory.
*********************************************************************/ 

void Library::readFile()
{

	Book* bk;
	AudioBook* ab;
	Video* vid;

	std::ifstream readLibFile;
	readLibFile.open("library-test.txt");
	
	if(readLibFile.is_open())
	{
		while(!readLibFile.eof())
		{
			std::getline(readLibFile, readString);	
			itemType = readString;
			
			if(itemType == "Book")
			{
				// Item ID: 
				std::getline(readLibFile, readString);
				newItemID = readString;
				// Title:
				std::getline(readLibFile, readString);
				newTitle = readString;
				// Author: 
				std::getline(readLibFile, readString);
				newAuthor = readString;
				// Publisher: 
				std::getline(readLibFile, readString);
				newPublisher = readString;
				// Length:
				std::getline(readLibFile, readString);
				newLength = readString;
				// Location:
				std::getline(readLibFile, readString);
				newLocale = readString;
				
			
				if(newLocale == "ON RESERVE SHELF")
				{
					isReserved = true;
				}
				else
				{
					isReserved = false;
				}
				

				bk = new Book(newItemID, newTitle, newAuthor, newPublisher, newLength, newLocale, isReserved);
				libraryInventoryBK.push_back(bk);
			}
			else if(itemType == "Video")
			{
				// Item ID: 
				std::getline(readLibFile, readString);
				newItemID = readString;
				// Title:
				std::getline(readLibFile, readString);
				newTitle = readString;
				// Author:
				std::getline(readLibFile, readString);
				newAuthor = readString;
				// Actors:
				std::getline(readLibFile, readString);
				newActors = readString;
				// Publisher: 
				std::getline(readLibFile, readString);
				newPublisher = readString;
				// Length:
				std::getline(readLibFile, readString);
				newLength = readString;
				// Location:
				std::getline(readLibFile, readString);
				newLocale = readString;
				if(newLocale == "ON RESERVE SHELF")
				{
					isReserved = true;
				}
				else
				{
					isReserved = false;
				}
				vid = new Video(newItemID, newLength, newTitle, newAuthor, newActors, newPublisher, newLocale, isReserved);
				libraryInventoryVID.push_back(vid);
				

			}
			else if(itemType == "Audiobook")
			{
							// Item ID: 
				std::getline(readLibFile, readString);
				newItemID = readString;
				// Title:
				std::getline(readLibFile, readString);
				newTitle = readString;
				// Author:
				std::getline(readLibFile, readString);
				newAuthor = readString;
				// Narrator:
				std::getline(readLibFile, readString);
				newNarrator = readString;
				// Publisher: 
				std::getline(readLibFile, readString);
				newPublisher = readString;
				// Length:
				std::getline(readLibFile, readString);
				newLength = readString;
				// Location:
				std::getline(readLibFile, readString);
				newLocale = readString;
				if(newLocale == "ON RESERVE SHELF")
				{
					isReserved = true;
				}
				else
				{
					isReserved = false;
				}

			
			ab = new AudioBook(newItemID, newLength, newTitle, newAuthor, newNarrator, newPublisher, newLocale, isReserved);
			libraryInventoryAB.push_back(ab);
			}


			else
			{
				// std::cout << "Invalid Item Type." << std::endl;
			}
		}
	}

	else
	{
		std::cout << "Bad file name or not found." << std::endl;
	}

	readLibFile.close();
	return;
}


/*********************************************************************
** Function: bool checkUnique(std::string itemID;)
** Description: Checks to see if an item has a unique ID. 
** Parameters: std::string itemID 
** Pre-Conditions: Create an item, and input the new item ID, checks to see if Unique.
** Post-Conditions: If ID is unique, allows user to continue, if not unique return
** that it is already taken.
*********************************************************************/ 

bool Library::checkUnique(std::string itemID)
{
	for(unsigned int i = 0; i < libraryInventoryBK.size(); i++)
	{
		if(libraryInventoryBK.at(i)->getItemID() == itemID)
		{
			std::cout << "ID already exists." << std::endl;
			isUnique = false;
			return false;
		}
	}

	for(unsigned int i = 0; i < libraryInventoryVID.size(); i++)
	{
		if(libraryInventoryVID.at(i)->getItemID() == itemID)
		{
			std::cout << "ID already exists." << std::endl;
			isUnique = false;
			return false;
		}
	}

	for(unsigned int i = 0; i < libraryInventoryAB.size(); i++)
	{
		if(libraryInventoryAB.at(i)->getItemID() == itemID)
		{
			std::cout << "ID already exists." << std::endl;
			isUnique = false;
			return false;
		}
	}

	return true;
}


/*********************************************************************
** Function: Library::getItem()
** Description: Will read the item specificed by the user.
** Parameters: N/A
** Pre-Conditions: User inputs an Item ID.
** Post-Conditions: Prints out the selected item when found in the
**					various arrays.
*********************************************************************/ 

void Library::getItem(std::string fetchItemID)
{
	// Books:
	for(unsigned int i = 0; i < libraryInventoryBK.size(); i++)
	{
		if(libraryInventoryBK.at(i)->getItemID() == fetchItemID)
		{
			std::cout << "Item Type: " << libraryInventoryBK.at(i)->getItemType() << std::endl
			<< "Item ID: " << libraryInventoryBK.at(i)->getItemID() << std::endl
			<< "Title: " << libraryInventoryBK.at(i)->getTitle() << std::endl
			<< "Author: " << libraryInventoryBK.at(i)->getAuthor() << std::endl
			<< "Publisher: " << libraryInventoryAB.at(i)->getPublisher() << std::endl
			<< "Length: " << libraryInventoryBK.at(i)->getLength() << std::endl
			<< "Location: " << libraryInventoryBK.at(i)->getLocation() << std::endl 
			<< libraryInventoryBK.at(i)->getReserve() << std::endl << std::endl;
		}


	}

	// Videos:
	for(unsigned int i = 0; i < libraryInventoryVID.size(); i++)
	{
		if(libraryInventoryVID.at(i)->getItemID() == fetchItemID)
		{
			std::cout << "Item Type: " << libraryInventoryVID.at(i)->getItemType() << std::endl
			  << "Item ID: " << libraryInventoryVID.at(i)->getItemID() << std::endl
			  << "Title: " << libraryInventoryVID.at(i)->getTitle() << std::endl
			  << "Producer/Director: " << libraryInventoryVID.at(i)->getAuthor() << std::endl
			  << "Actors: "	<< libraryInventoryVID.at(i)->getActors() << std::endl
			  << "Studio: " << libraryInventoryVID.at(i)->getPublisher() << std::endl
			  << "Length: " << libraryInventoryVID.at(i)->getLength() << std::endl
			  << "Location: " << libraryInventoryVID.at(i)->getLocation() << std::endl
			  << libraryInventoryVID.at(i)->getReserve() << std::endl << std::endl;


		}
	}	

	// Audiobooks:
	for(unsigned int i = 0; i < libraryInventoryAB.size(); i++)
	{
		if(libraryInventoryAB.at(i)->getItemID() == fetchItemID)
		{
			
			std::cout << "Item Type: " << libraryInventoryAB.at(i)->getItemType() << std::endl
				<< "Item ID: " << libraryInventoryAB.at(i)->getItemID() << std::endl
				<< "Title: " << libraryInventoryAB.at(i)->getTitle() << std::endl
			
				<< "Author: " << libraryInventoryAB.at(i)->getAuthor() << std::endl
				<< "Publisher: " << libraryInventoryAB.at(i)->getPublisher() << std::endl
				<< "Length: " << libraryInventoryAB.at(i)->getLength() << std::endl
				<< "Location: " << libraryInventoryAB.at(i)->getLocation() << std::endl 
				<< libraryInventoryAB.at(i)->getReserve() << std::endl << std::endl;

		}


	}

}

/*********************************************************************
** Function: void Library::newBook()
** Description: User inputs information about a new book
** Parameters: N/A
** Pre-Conditions: User navigates through the menu and selects the
**					add item and book options.
** Post-Conditions: User enters information and a new book object is
**					created or the user quits to main menu.
*********************************************************************/ 

void Library::newBook()
{
	Book* bk;

	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Flush buffer.

	std::cout << "Adding new book... enter 0 to quit at any time." << std::endl;

	
	std::cout << "Item ID #: ";
	std::getline(std::cin, newItemID);
	checkUnique(newItemID);
	/*std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');*/

	if(newItemID == "0")
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		libraryMenu();	
	}

	// Might want to check the ID before continuing -- if not unique, ask to put in a new one.
	std::cout << "Title >> ";
	std::getline(std::cin, newTitle);
	std::cout << newTitle << std::endl;
	
	if(newTitle == "0")
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	
		libraryMenu();
	}

	std::cout << "Author >> ";
	std::getline(std::cin, newAuthor);
	//std::cin.clear();
	//std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	if(newAuthor == "0")
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	
		libraryMenu();
	}
	
		
	std::cout << "Publisher >> "; 
	std::getline(std::cin, newPublisher);
	

	if(newPublisher == "0")
	{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			libraryMenu();
	}

	std::cout << "Book Length in Pages >> ";
	std::getline(std::cin, newLength);
	
	if(newLength == "0")
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		libraryMenu();
	}

	std::cout << "Location (to reserve, input ON RESERVE SHELF) >> ";
	std::getline(std::cin, newLocale);
	
	if(newLocale == "ON RESERVE SHELF")
	{
		isReserved = true;
	}

	else if(newLocale  == "0")
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		libraryMenu();
	}

	else
	{
		isReserved = false;
	}
	

	bk = new Book(newItemID, newTitle, newAuthor, newPublisher, newLength, newLocale, isReserved);
	std::cout << "Book added." << std::endl;

	std::cout << "//-------- DEBUG --------//" << std::endl
			  << "Item ID: " << bk->getItemID() << std::endl
			  << "Title: " << bk->getTitle() << std::endl
			  << "Author: " << bk->getAuthor() << std::endl
			  << "Publisher: " << bk->getPublisher() << std::endl
			  << "Length: " << bk->getLength() << " Pages" << std::endl
			  << "Location: " << bk->getLocation() << std::endl
			  << bk->getReserve() << std::endl;


	libraryInventoryBK.push_back(bk);

	libraryMenu();
	
}

/*********************************************************************
** Function: void Library::newVideo()
** Description: User inputs information about a new Video
** Parameters: N/A
** Pre-Conditions: User navigates through the menu and selects the
**					add item and video options.
** Post-Conditions: User enters information and a new video object is
**					created based on their input or the user quits to main menu.
*********************************************************************/ 
void Library::newVideo()
{
	Video* vid;

	std::cout << "Adding new video... enter 0 to quit at any time." << std::endl;

	std::cout << "Item ID # >> ";
	std::getline(std::cin, newItemID);
	if(newItemID == "0")
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		libraryMenu();
	}

	std::cout << "Title >> ";
	std::getline(std::cin, newTitle);
	if(newTitle == "0")
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		libraryMenu();
	}

	std::cout << "Director/Producer >>  ";
	std::getline(std::cin, newAuthor);
	if(newAuthor == "0")
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		libraryMenu();
	}

	std::cout << "Starring Actors >> ";
	std::getline(std::cin, newActors);
	if(newActors == "0")
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		libraryMenu();
	}
	


	std::cout << "Production Studio >> "; 
	std::getline(std::cin, newPublisher);
	if(newPublisher == "0")
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		libraryMenu();
	}
		
	std::cout << "Input length (minutes) >> ";
	std::getline(std::cin, newLength);
	if(newLength == "0")
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		libraryMenu();
	}
	
	
	std::cout << "Location (to reserve, input ON RESERVE SHELF) >> ";
	std::getline(std::cin, newLocale);
	if(newLocale == "ON RESERVE SHELF")
	{
		isReserved = true;
	}

	else if(newLocale  == "0")
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		libraryMenu();
	}

	else
	{
		isReserved = false;
	}

	vid = new Video(newItemID, newLength, newTitle, newAuthor, newActors, newPublisher, newLocale, isReserved);
	std::cout << "Video added." << std::endl;
	libraryInventoryVID.push_back(vid);

	std::cout << "//-------- DEBUG --------//"
			  << "Item ID: " << vid->getItemID() << std::endl
			  << "Title: " << vid->getTitle() << std::endl
			  << "Producer/Director: " << vid->getAuthor() << std::endl
			  << "Actors: " << vid->getActors() << std::endl
			  << "Studio: " << vid->getPublisher() << std::endl
			  << "Length (minutes):" << vid->getLength() << std::endl
			  << "Location: " << vid->getLocation() << std::endl
			  << vid->getReserve() << std::endl;




	libraryMenu();

}
/*********************************************************************
** Function: void Library::newAudioBook()
** Description: User inputs information about a new Audiobook.
** Parameters: N/A
** Pre-Conditions: User navigates through the menu and selects the
**					add item and audiobook options.
** Post-Conditions: User enters information and a new audiobook object is
**					created based on their input or the user quits to main menu.
*********************************************************************/ 
void Library::newAudioBook()
{
	AudioBook* AB;

	std::cout << "Adding new audiobook... enter 0 to quit at any time." << std::endl;
	std::cout << "Item ID #: ";
	std::getline(std::cin, newItemID);
	if(newItemID == "0")
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		libraryMenu();
	}
	

	std::cout << "Title: ";
	std::getline(std::cin, newTitle);
	if(newTitle == "0")
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		libraryMenu();
	}
	
	std::cout << "Author: ";
	std::getline(std::cin, newAuthor);
	if(newAuthor == "0")
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		libraryMenu();
	}

	std::cout << "Narrator: ";
	std::getline(std::cin, newNarrator);
	if(newNarrator == "0")
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		libraryMenu();
	}

	std::cout << "Publisher >> "; 
	std::getline(std::cin, newPublisher);
	if(newPublisher == "0")
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		libraryMenu();
	}
 

	std::cout << "Location (To reserve, enter ON RESERVE SHELF)>> ";
	std::getline(std::cin, newLocale);
	if(newLocale == "ON RESERVE SHELF")
	{
		isReserved = true;
	}

	else if(newLocale=="0")
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		libraryMenu();
	}

	else
	{
		isReserved = false;
	}
	
	AB = new AudioBook(newItemID, newLength, newTitle, newAuthor, newNarrator, newPublisher, newLocale, isReserved);

	std::cout << "//-------- DEBUG --------//"
			  << "Item ID: " << AB->getItemID() << std::endl
			  << "Title: " << AB->getTitle() << std::endl
			  << "Producer/Director: " << AB->getAuthor() << std::endl
			  << "Narrator: " << AB->getNarrator() << std::endl
			  << "Publisher: " << AB->getPublisher() << std::endl
			  << "Length (min):" << AB->getLength() << std::endl
			  << "Location: " << AB->getLocation() << std::endl;
			  


	libraryInventoryAB.push_back(AB);

	libraryMenu();

}

/*********************************************************************
** Function: Location Library:setLocale()
** Description: Sets the location of the object.
** Parameters: int newLocale
** Pre-Conditions: User is creating an object is prompted to input their item's
**				   location.
** Post-Conditions: Location is saved to variable inLocale which is saved to object.
********************************************************************* 

Location Library::setLocale(int newLocale)
{
 	   
 	   	if(newLocale == 0)
		{
			libraryMenu();
		}

		else if (newLocale == 1)
		{
			inLocale = ON_SHELF;
		}

		else if (newLocale == 2)
		{
			inLocale = ON_RESERVE;
			isReserved = true;
		}

		else if (newLocale == 3)
		{
			inLocale = ON_NEW_SHELF;
		}
		else if (newLocale == 4)
		{
			inLocale = CHECKED_OUT;
		}

		else if(newLocale == 5)
		{
			inLocale = IN_SORTING;
		}
		else if(newLocale == 6)
		{
			inLocale = ON_ORDER;
		}

		else if (newLocale == 7)
		{
			inLocale = CHECKED_OUT;
		}

		else if (newLocale == 8)
		{
			inLocale = LOST;
		}

		else if (newLocale == 9)
		{
			inLocale = DUE_FOR_DESTRUCTION;
		}

		else if (newLocale == 10)
		{
			inLocale = OVER_DUE;
		}

	return inLocale;

}

*********************************************************************
** Function: Genre Library::setGenre(int newGenre)
** Description: Sets the Genre of the object.
** Parameters: N/A
** Pre-Conditions: User is creating an object is prompted to input their item's
**				   genre.
** Post-Conditions: Genre is saved to variable inGenre which is saved to object.
********************************************************************* 
Genre Library::setGenre(int newGenre)
{
		if(newGenre == 0)
		{
			libraryMenu();
		}
		else if(newGenre == 1)
		{
			inGenre = FICTION;
		}
		else if(newGenre == 2)
		{
			inGenre = YOUNG_ADULT;
		}
		else if(newGenre == 3)
		{
			inGenre = NON_FICTION;	
		}
		else if(newGenre == 4)
		{
			inGenre = SCIFI_FANTASY;
		}
		else if(newGenre == 5)
		{
			inGenre = BIOGRAPHY;
		}
		else if(newGenre == 6)
		{
			inGenre = MYSTERY;	
		}
		else if(newGenre == 7)
		{
			inGenre = INSTRUCTIONAL;
		}
		else if(newGenre == 8)
		{
			inGenre = HUMOR;	
		}

		return inGenre;

}


*********************************************************************
** Function: void Library::updateItem(std::string fetchItemID)
** Description: Sets the Genre of the object.
** Parameters: fetchItemID - whatever the item ID is.
** Pre-Conditions: User indicates they want to update an object and change things.
** Post-Conditions: Item is updated and put back into the array.
*********************************************************************/ 

void Library::updateItem(std::string fetchItemID)
{
	// Books
	for (unsigned int i = 0; i < libraryInventoryBK.size(); i++)
	{
		if(libraryInventoryBK.at(i)->getItemID() == fetchItemID)
		{
					std::cout << "Editing Book - Enter 0 to Quit, SKIP to skip.\n";
					std::cout << "Input new title >> ";
					std::getline(std::cin, newTitle);
					
					if(newTitle == "0")
					{
						return;
					}
					else if(newTitle == "SKIP")
					{
						std::cout << "Skipping...\n";
					}
					else
					{
						libraryInventoryBK.at(i)->setTitle(newTitle);	
					}

					std::cout << "Input new author >> ";
					std::getline(std::cin, newAuthor);
					if(newAuthor == "0")
					{
						return;
					}
					else if(newAuthor == "SKIP")
					{
						std::cout << "Skipping...\n";
					}
					else
					{
						libraryInventoryBK.at(i)->setAuthor(newAuthor);	
					}
					
			
					std::cout << "\nInput new publisher >> ";
					std::getline(std::cin, newPublisher);
					if(newPublisher == "0")
					{
						return;
					}
					else if(newPublisher == "SKIP")
					{
						std::cout << "Skipping...\n";
					}
					else
					{
						libraryInventoryBK.at(i)->setPublisher(newPublisher);	
					}
				
					std::cout << "\nInput new length >> ";
					std::getline(std::cin, newLength);
					if(newLength == "0")
					{
						return;
					}
					else if(newLength == "SKIP")
					{
						std::cout << "Skipping...\n";
					}
					else
					{
						libraryInventoryBK.at(i)->setLength(newLength);	
					}
					break;

					std::cout << "\nInput new Locale >> ";
					std::getline(std::cin, newLocale);
					if(newLocale == "0")
					{
						return;
					}
					else if(newLocale == "SKIP")
					{
						std::cout << "Skipping...\n";
					}
					else if(newLocale != "ON RESERVE SHELF")
					{
						isReserved = false;

					}
					else
					{
						libraryInventoryBK.at(i)->setLocale(newLocale);
						libraryInventoryBK.at(i)->setReserve(isReserved);	
					}

						std::cout << "//-------- DEBUG --------//"
			  << "Item ID: " << libraryInventoryBK.at(i)->getItemID() << std::endl
			  << "Title: " << libraryInventoryBK.at(i)->getTitle() << std::endl
			  << "Author: " << libraryInventoryBK.at(i)->getAuthor() << std::endl
			  << "Publisher: " << libraryInventoryBK.at(i)->getPublisher() << std::endl
			  << "Length (pages):" << libraryInventoryBK.at(i)->getLength() << std::endl
			  << "Locale: " << libraryInventoryBK.at(i)->getLocation() << std::endl;
			  return;
		}
		else
		{
		std::cout << "Item not found." << std::endl;
		return;
		}

	
	}

	// Videos
	for (unsigned int i = 0; i < libraryInventoryVID.size(); i++)
	{
		if(libraryInventoryVID.at(i)->getItemID() == fetchItemID)
		{
					std::cout << "Editing Book - Enter 0 to Quit, SKIP to skip.\n";
					std::cout << "Input new title >> ";
					std::getline(std::cin, newTitle);
					
					if(newTitle == "0")
					{
						return;
					}
					else if(newTitle == "SKIP")
					{
						std::cout << "Skipping...\n";
					}
					else
					{
						libraryInventoryVID.at(i)->setTitle(newTitle);	
					}

					std::cout << "Input new author >> ";
					std::getline(std::cin, newAuthor);
					if(newAuthor == "0")
					{
						return;
					}
					else if(newAuthor == "SKIP")
					{
						std::cout << "Skipping...\n";
					}
					else
					{
						libraryInventoryVID.at(i)->setAuthor(newAuthor);	
					}
					
			
					std::cout << "\nInput new studio/distributor >> ";
					std::getline(std::cin, newPublisher);
					if(newPublisher == "0")
					{
						return;
					}
					else if(newPublisher == "SKIP")
					{
						std::cout << "Skipping...\n";
					}
					else
					{
						libraryInventoryVID.at(i)->setPublisher(newPublisher);	
					}
				
					std::cout << "\nInput new length >> ";
					std::getline(std::cin, newLength);
					if(newLength == "0")
					{
						return;
					}
					else if(newLength == "SKIP")
					{
						std::cout << "Skipping...\n";
					}
					else
					{
						libraryInventoryVID.at(i)->setLength(newLength);	
					}
					break;

								
					std::cout << "\nInput new Locale >> ";
					std::getline(std::cin, newLocale);
					if(newLocale == "0")
					{
						return;
					}
					else if(newLocale == "SKIP")
					{
						std::cout << "Skipping...\n";
					}
					else if(newLocale != "ON RESERVE SHELF")
					{
						isReserved = false;

					}
					else
					{
						libraryInventoryVID.at(i)->setLocale(newLocale);
						libraryInventoryVID.at(i)->setReserve(isReserved);	
					}

						std::cout << "//-------- DEBUG --------//"
			  << "Item ID: " << libraryInventoryVID.at(i)->getItemID() << std::endl
			  << "Title: " << libraryInventoryVID.at(i)->getTitle() << std::endl
			  << "Producer/Director: " << libraryInventoryVID.at(i)->getAuthor() << std::endl
			  << "Actors: " << libraryInventoryVID.at(i)->getActors() << std::endl
			  << "Studio: " << libraryInventoryVID.at(i)->getPublisher() << std::endl
			  << "Length (min):" << libraryInventoryVID.at(i)->getLength() << std::endl
			  << "Locale: " << libraryInventoryVID.at(i)->getLocation() << std::endl;

		}

		libraryMenu();

	}

	// Audiobooks
	for (unsigned int i = 0; i < libraryInventoryAB.size(); i++)
	{
		if(libraryInventoryAB.at(i)->getItemID() == fetchItemID)
		{
			std::cout << "Editing Book - Enter 0 to Quit, SKIP to skip.\n";
					std::cout << "Input new title >> ";
					std::getline(std::cin, newTitle);
					
					if(newTitle == "0")
					{
						return;
					}
					else if(newTitle == "SKIP")
					{
						std::cout << "Skipping...\n";
					}
					else
					{
						libraryInventoryAB.at(i)->setTitle(newTitle);	
					}

					std::cout << "Input new author >> ";
					std::getline(std::cin, newAuthor);
					if(newAuthor == "0")
					{
						return;
					}
					else if(newAuthor == "SKIP")
					{
						std::cout << "Skipping...\n";
					}
					else
					{
						libraryInventoryAB.at(i)->setAuthor(newAuthor);	
					}
					
			
					std::cout << "\nInput new publisher >> ";
					std::getline(std::cin, newPublisher);
					if(newPublisher == "0")
					{
						return;
					}
					else if(newPublisher == "SKIP")
					{
						std::cout << "Skipping...\n";
					}
					else
					{
						libraryInventoryAB.at(i)->setPublisher(newPublisher);	
					}
				
					std::cout << "\nInput new length >> ";
					std::getline(std::cin, newLength);
					if(newLength == "0")
					{
						return;
					}
					else if(newLength == "SKIP")
					{
						std::cout << "Skipping...\n";
					}
					else
					{
						libraryInventoryAB.at(i)->setLength(newLength);	
					}
					break;


					std::cout << "\nInput new Locale >> ";
					std::getline(std::cin, newLocale);
					if(newLocale == "0")
					{
						return;
					}
					else if(newLocale == "SKIP")
					{
						std::cout << "Skipping...\n";
					}
					else if(newLocale != "ON RESERVE SHELF")
					{
						isReserved = false;

					}
					else
					{
						libraryInventoryAB.at(i)->setLocale(newLocale);
						libraryInventoryAB.at(i)->setReserve(isReserved);	
					}

						std::cout << "//-------- DEBUG --------//"
			  << "Item ID: " << libraryInventoryAB.at(i)->getItemID() << std::endl
			  << "Title: " << libraryInventoryAB.at(i)->getTitle() << std::endl
			  << "Producer/Director: " << libraryInventoryAB.at(i)->getAuthor() << std::endl
			  << "Narrator: " << libraryInventoryAB.at(i)->getNarrator() << std::endl
			  << "Publisher: " << libraryInventoryAB.at(i)->getPublisher() << std::endl
			  << "Length (min):" << libraryInventoryAB.at(i)->getLength() << std::endl
			  << "Locale: " << libraryInventoryAB.at(i)->getLocation() << std::endl;
			  return;
		}
		else
		{
		std::cout << "Item not found." << std::endl;
		}	

	}
	

}


