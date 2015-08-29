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

class Item; 

enum ItemType {BOOK = 1, 
		VIDEO,
		AUDIO_BOOK,
		NO_TYPE};
enum Genre {FICTION = 1, YOUNG_ADULT, NON_FICTION, SCIFI_FANTASY, BIOGRAPHY, MYSTERY, INSTRUCTIONBK, HUMOR, NOGENRE};
enum Location {ON_SHELF = 1, ON_RESERVE, ON_NEW_SHELF, CHECKED_OUT, IN_SORTING, ON_ORDER, IN_PROCESSING, LOST, DUE_FOR_DESTRUCTION, OVER_DUE, NOLOCATION};

class Item

{
private: 

	ItemType iType;

protected:

	std::string itemID; // Books start with prefix BK, Audiobooks with AB, and Video with VID
	std::string title;
	std::string author; // originally reserved for books and audiobooks, but all items have authors.
	std::string publisher;
	std::string itType;			// Deprecate
	std::string strItemType;	// Deprecate
	std::string locale;
	std::string genre;
	std::string format;
	
	Genre gnr;
	Location lctn;
	int itemClass;

	int length;		// Only really occurs in Books, but is general enough to be useful if program expands.
	int lengthHr;  // Happens in two subclasses, so promoted to superclass.
	int lengthMin; // Happens in two subclasses, so promoted to superclass.


	bool onReserve;	// Even if the book is checked out, you can put it on reserve.
	bool unique;	// I added this to make a functionality to check uniqueness of ID. If ID = true, good ID, if ID = false;
					// then pick another.
	bool isDigital;	// Reserved for MP3 and Digital Download Only.
	bool isNew;
	bool isCheckedOut;

public:
	Item();
	// Place Holder. Item(std::string title, std:string publisher, int itID, int length, bool OnRev, bool uniq);
	std::string getItemID();
	bool checkID();
	int getLength();
	int getLengthHr();
	int getLengthMin();
	std::string getTitle();
	std::string getPublisher();	// In Video Class, use for Studio.
	bool getReserve();
	bool getUnique();
	std::string getType(ItemType iT); // Deprecating
	std::string getGenre(Genre Gnr);
	std::string getLocation(Location lcl);
	/* Once we get basic functionality done -- we will go ahead and add editting functions if there is time. */
	

};

#endif