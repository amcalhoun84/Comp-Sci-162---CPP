/*********************************************************************  
** Program Filename: item.hpp
** Author: Andrew M. Calhoun
** Date: 7/8/2015
** Description: Item Header File, Superclass informs class members and data
				and subclasses.
** Input: Book Header File.
** Outut: N/A
***********************************************************************/ 

#ifndef ITEM_HPP
#define ITEM_HPP

#include <iostream>
#include <string>
#include <vector>

/*class Item;  -- Original purpose was to help reduce the chance for errors; however,
as the due date drew close, I found that there were problematic aspects to this, so
I put it in the comments to come back to it later to create something else for my portfolio at a later time. 

enum Genre {FICTION = 1, YOUNG_ADULT, NON_FICTION, SCIFI_FANTASY, BIOGRAPHY, MYSTERY, INSTRUCTIONAL, HUMOR, ACTION, ADVENTURE, ANIMATION, KIDS, ROMANCE, COMEDY, DOCUMENTARY, NOGENRE};
enum Location {ON_SHELF = 1, ON_RESERVE, ON_NEW_SHELF, CHECKED_OUT, IN_SORTING, ON_ORDER, IN_PROCESSING, LOST, DUE_FOR_DESTRUCTION, OVER_DUE, NOLOCATION};
enum Format {HARDCOVER = 1, PAPERBACK, VOLUME, FREE_LEAF, DVD, BLU_RAY, VHS, CASSETTE, CD, DIGITAL_DOWNLOAD, NO_FORMAT};*/




class Item

{
protected:

	std::string itemID, // Books start with prefix BK, Audiobooks with AB, and Video with VID
		 		title,
				author, // originally reserved for books and audiobooks, but all			items have authors.
				publisher,
				iType,
				locale,
				genre,
				length,
				format;
	
	/*Format fmt;
	Genre gnr;
	Location lctn;*/
	


	/* Deprecated as made program overly complicated for scope of assignment. 
	// int lengthHr;  // Happens in two subclasses, so promoted to superclass.
	// int lengthMin; // Happens in two subclasses, so promoted to superclass. */


	bool onReserve;	// Even if the book is checked out, you can put it on reserve.
	bool unique;	// I added this to make a functionality to check uniqueness of ID. If ID = true, good ID, if ID = false;
					// then pick another.

	// Deprecated -- Location informs whether or not it is new or checked out.
	// bool isNew;
	// bool isCheckedOut;

public:
	Item();
	// Place Holder. Item(std::string title, std:string publisher, int itID, int length, bool OnRev, bool uniq);


/*********************************************************************
** Function: std::string Item::getLocation()   
** Description: Get Location, and print it to file or screen.
** Parameters: N/A
** Pre-Conditions: Program requests data member from object.
** Post-Conditions: Returns the location if valid.
*********************************************************************/ 


	std::string getLocation() { return locale; }

/*********************************************************************
** Function: std::string Item::getReserve() 
** Description: Get Reserve, and print it to file or screen.
** Parameters: N/A
** Pre-Conditions: Program requests data member from object.
** Post-Conditions: Returns the reservation status if valid.
*********************************************************************/
	

	std::string getReserve();

/*********************************************************************
** Function: std::string Item::getLocation()   
** Description: Get itemType, and print it to file or screen.
** Parameters: N/A
** Pre-Conditions: Program requests data member from object.
** Post-Conditions: Returns the item type if valid.
*********************************************************************/ 

	std::string getItemType()
	{
		return iType;
	}

/*********************************************************************
** Function: std::string Item::getItemID()   
** Description: Get Item ID, and print it to file or screen.
** Parameters: N/A
** Pre-Conditions: Program requests data member from object.
** Post-Conditions: Returns the item ID if valid.
*********************************************************************/ 

	std::string getItemID() 
	{ 
		return itemID; 
	}
	
/*********************************************************************
** Function: void Item::getLocation(std::string setID)   
** Description: SetID and put into object, is not used, as Item IDs are unique
**	and not changed.
** Parameters: std::string setID
** Pre-Conditions: User requests to update object.
** Post-Conditions: Returns the location if valid.
*********************************************************************/ 

	void setItemID(std::string setID) 
	{ 
		itemID = setID; 
	}

/*********************************************************************
** Function: bool getRev() 
** Description: Gets the bool to see if a book or item is on review and returns it.
** Parameters: N/A
** Pre-Conditions: User or file requests boolean for reservation.
** Post-Conditions: Returns the boolean value if valid.
*********************************************************************/ 

	bool getRev()
	{
		return onReserve;
	}
	
/*********************************************************************
** Function: bool getRev() 
** Description: Get the length of the item either in pages or minutes.
** Parameters: N/A
** Pre-Conditions: User or file requests length.
** Post-Conditions: Gives the length of the item.
*********************************************************************/ 
	
	std::string getLength() 
	{
		return length; 
	}

/*********************************************************************
** Function: void setLength(std::string newLength) 
** Description: Sets or updates the length of the item either in pages or minutes.
** Parameters: N/A
** Pre-Conditions: User or file requests to update item.
** Post-Conditions: Alters the length of the object.
*********************************************************************/ 
	
	
	void setLength(std::string newLength) 
	{ 
		length = newLength; 
	}


/*********************************************************************
** Function: void setTitle(std::string newTitle)
** Description: Sets or updates the title of the item.
** Parameters: std::string newTitle
** Pre-Conditions: User or file requests update for the item.
** Post-Conditions: Changes the title of the object.
*********************************************************************/ 
	
	
	void setTitle(std::string newTitle) 
	{ 
		title = newTitle; 
	}

/*********************************************************************
** Function: std::string getTitle()
** Description: Gets the title of the item.
** Parameters: N/A
** Pre-Conditions: User or file requests title for the item.
** Post-Conditions: Returns the title.
*********************************************************************/ 

	std::string getTitle() 
	{
		return title; 
	}


/*********************************************************************
** Function: std::string getAuthor()
** Description: Gets the author of the item.
** Parameters: N/A
** Pre-Conditions: User or file requests author for the item.
** Post-Conditions: Returns the author.
*********************************************************************/ 


	std::string getAuthor() 
	{ 
		return author; 
	}

/*********************************************************************
** Function: std::string getPublisher() 
** Description: Gets the publisher of the item. Is used for the studio
				for the video objects.
** Parameters: N/A
** Pre-Conditions: User or file requests length.
** Post-Conditions: Gives the length of the item.
*********************************************************************/ 


	std::string getPublisher()	// In Video Class, use for Studio.
	{
		return publisher;
	}
	
	void setAuthor(std::string setAuth) 
	{ 
		author = setAuth; 
	}
	
/*********************************************************************
** Function: void setPublisher(std::string setPub) 
** Description: Set the publisher if the user wants to update it or creates an object.
** Parameters: std::string setPub
** Pre-Conditions: User creates item or wants to update item.
** Post-Conditions: Sets or changes the publisher of the object.
*********************************************************************/ 

	void setPublisher(std::string setPub)
	{ 
		publisher = setPub; 
	}

/*********************************************************************
** Function: void setReserve(bool setRev) 
** Description: Set or update the reserve status for an item.
** Parameters: bool setReve.
** Pre-Conditions: User wants to update the reservation status of the object.
** Post-Conditions: NA.
*********************************************************************/ 
	
	void setReserve(bool setRev) 
	{ 
		onReserve = setRev; 
	}
	
/*********************************************************************
** Function: bool getRev() 
** Description: Get the length of the item either in pages or minutes.
** Parameters: N/A
** Pre-Conditions: User or file requests length.
** Post-Conditions: Gives the length of the item.
*********************************************************************/ 
	


	void setLocale(std::string newLocale) 
	{ 
		locale = newLocale; 
	}


};

#endif