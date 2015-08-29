/*********************************************************************  
** Program Filename: item.hpp
** Author: Andrew M. Calhoun
** Date: 7/8/2015
** Description: Item Source File, informs class members or data.
				Sub-class of item class.
** Input: Book Header File.
** Outut: N/A
***********************************************************************/ 
#include "item.hpp"


// Default Constructor -- Put in headers later.
Item::Item() 
{
	this->itemID = "0"; // Null Items are designated as 0.
	this->length = 0;
	this->title = "Null Item";
	this->publisher = "Null Publisher";
	this->onReserve = false;
	this->isCheckedOut = false;
}

std::string Item::getItemID()
{
	return itemID;
}

int Item::getLength()
{
	return length;
}

int Item::getLengthHr()
{
	return lengthHr;
}
int Item::getLengthMin()
{
	return lengthMin;
}

std::string Item::getTitle()
{
	return title;
}

std::string Item::getPublisher()
{
	return publisher;
}

bool Item::getReserve()
{
	return onReserve;
}

bool Item::getUnique()
{
	return unique;
}

std::string Item::getType(ItemType iT) 	// May be deprecated
{
	if(iT == BOOK)
	{
		strItemType = "Book";
	}
	else if(iT == VIDEO)
	{
		strItemType = "Video";
	}
	else if (iT == AUDIO_BOOK)
	{
		strItemType = "Audiobook";
	}
	else
	{
		std::cout << "Invalid Item Type. Please try again." << std::endl;
		return "null";
	}

	return strItemType;
}

std::string Item::getGenre(Genre gnr)   // May need to declare this for the various subclasses.
										// May be worth doing given that Books and AudioBooks may have
										// commonality, but video doesn't.
{
	if(gnr == FICTION)
	{
		genre = "Fiction";
	}
	else if(gnr == YOUNG_ADULT)
	{
		genre = "Young Adult/Teen";
	}
	else if(gnr == NON_FICTION)
	{
		genre = "Non-Fiction";
	}
	else if(gnr == SCIFI_FANTASY)
	{
		genre = "Science Fiction & Fantasy";
	}
	else if(gnr == BIOGRAPHY)
	{
		genre = "Biography/Autobiography";
	}
	else if(gnr == MYSTERY)
	{
		genre = "Mystery";
	}
	else if(gnr == INSTRUCTIONBK)
	{
		genre = "Instructional";	
	}
	else if(gnr == HUMOR)
	{
		genre = "Humor/Funny";
	}

	else
	{
		std::cout << "Invalid genre type, please try again." << std::endl;
		genre = "null";
	}

	return genre; 
} 

std::string Item::getLocation(Location lcl)	// May be deprecated.
{
	if(lcl == 0)
	{
		locale = "On Shelf";
	}
	else if(lcl == 1)
	{
		locale = "On Reserve Shelf";
	}
	else if(lcl == 2)
	{
		locale = "On New Shelf";
	}
	else if(lcl == 3)
	{
		locale = "Checked Out";
	}
	else if(lcl == 4)
	{
		locale = "In Sorting / Returned";
	}
	else if(lcl == 5)
	{
		locale = "On Order";
	}
	else if(lcl == 6)
	{
		locale = "Order Received and In Processing";	
	}
	else if(lcl == 7)
	{
		locale = "Lost";
	}
	else if(lcl == 8)
	{
		locale = "Due For Destruction";	// For MP3/Digital Downloads Only
	}
	else if(lcl == 9)
	{
		locale = "Over Due";
	}
	else
	{
		std::cout << "Invalid location, please try again." << std::endl;
		locale = "null";
	}

	return locale;
}