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
	this->length = "0";
	this->title = "Null Item";
	this->publisher = "Null Publisher";
	this->onReserve = false;
}

std::string Item::getReserve()
{
	if(onReserve == true)
	{
		std::cout << "Item is on reserve." << std::endl;
		return "Item is on reserve";
	}
	else
	{
		std::cout << "Item is not on reserve." << std::endl;
		return "Item is not on reserve.";
	}
}

/*********************************************************************
** Function: std::string Item::getGenre()   
** Description: Get Item Genre.
** Parameters: N/A
** Pre-Conditions: User calls for a audiobook object and inputs data.
** Post-Conditions: Retrieves Genre for the User based on the gnr of the object.
*********************************************************************/ 

/*std::string Item::getGenre()   
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
	else if(gnr == INSTRUCTIONAL)
	{
		genre = "Instructional";	
	}
	else if(gnr == HUMOR)
	{
		genre = "Humor/Funny";
	}
	else if(gnr == ACTION)
	{
		genre == "Action";
	}
	else if(gnr == ADVENTURE)
	{
		genre == "Adventure";
	}
	else if(gnr == ANIMATION)
	{
		genre == "Animation";
	}
	else if(gnr == KIDS)
	{
		genre == "Kids/Family";
	}
	else if(gnr == ROMANCE)
	{
		genre == "Romance";
	}
	else if(gnr == COMEDY)
	{
		genre == "Comedy";
	}
	else if(gnr == DOCUMENTARY)
	{
		genre == "Documentary";
	}
	else
	{
		std::cout << "Invalid genre type, please try again." << std::endl;
		genre = "No Genre.";
	}

	return genre; 
} 

std::string Item::getLocation()	
{
	if(lctn == ON_SHELF)
	{
		locale = "On Shelf";
	}
	else if(lctn == ON_RESERVE)
	{
		locale = "On Reserve Shelf";
	}
	else if(lctn == ON_NEW_SHELF)
	{
		locale = "On New Shelf";
	}
	else if(lctn == CHECKED_OUT)
	{
		locale = "Checked Out";
	}
	else if(lctn == IN_SORTING)
	{
		locale = "In Sorting / Returned";
	}
	else if(lctn == ON_ORDER)
	{
		locale = "On Order";
	}
	else if(lctn == IN_PROCESSING)
	{
		locale = "Order Received and In Processing";	
	}
	else if(lctn == LOST)
	{
		locale = "Lost";
	}
	else if(lctn == DUE_FOR_DESTRUCTION)
	{
		locale = "Due For Destruction";	// For MP3/Digital Downloads Only - generally
	}
	else if(lctn == OVER_DUE)
	{
		locale = "Over Due";
	}
	else
	{
		std::cout << "Invalid location, please try again." << std::endl;
		locale = "null";
	}

	return locale;
}*/

/*********************************************************************
** Function: Item::getFormat()
** Description: Gets the format of the object.
** Parameters: N/A
** Pre-Conditions: User is looking at a selected object and has a getFormat call.
** Post-Conditions: Format returned to function call, informs user what
**					the item's format is.
******************************************************************** 

std::string Item::getFormat()
{
	// Get Book Formats

	if(fmt == HARDCOVER)
	{
		format = "Hardcover";
	}
	else if(fmt == PAPERBACK)
	{
		format = "Paperback";
	}
	else if(fmt == VOLUME)
	{
		format = "Volume";
	}
	else if(fmt == FREE_LEAF)
	{
		format = "Free-Leaf/Unbound";
	}
	
	// Get Video Formats

	else if(fmt == DVD)
	{
		format = "DVD";
	}
	else if(fmt == BLU_RAY)
	{
		format = "Blu-Ray Disc";
	}
	
	else if(fmt == VHS)
	{
		format = "VHS";
	}

	// Get Audiobook Formats

	else if(fmt == CASSETTE)
	{
		format = "Cassette";
	}
	else if(fmt == CD)
	{
		format = "CD";
	}
	else if(fmt == DIGITAL_DOWNLOAD)
	{
		format = "Digital Download";
	}
	else // If Format Fails.
	{
		std::cout << "Invalid Format. Default to No Format Given." << std::endl;
		format = "No Format Given";
	}

	return format;
}*/
