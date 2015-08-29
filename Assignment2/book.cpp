/*********************************************************************  
** Program Filename: book.cpp
** Author: Andrew M. Calhoun
** Date: 7/8/2015
** Description: Item Source File, informs class members or data.
				Sub-class of item class.
** Input: Book Source File. Needed to build program.
** Outut: N/A
***********************************************************************/ 

#include <iostream>
#include "book.hpp"

/*********************************************************************
** Function: Book::Book()
** Description: Item Book Subclass Default Constructor
** Parameters: N/A
** Pre-Conditions: N/A
** Post-Conditions: N/A
*********************************************************************/ 

Book::Book()
{


}
/*********************************************************************
** Function: Book::Book
** Description: Item Book Subclass Constructor
** Parameters:(std::string itID, std::string title, std::string auth, 
**	std::string publisher, int length, FormatBK fmtBK, Genre gnr, Location lcl,
**	 bool onRev)
**
** Pre-Conditions: User creates a book object and inputs data.
** Post-Conditions: New book object is created and saved to memory.
*********************************************************************/ 
Book::Book(std::string itID, std::string title, std::string auth, std::string publisher, std::string length, std::string lcl, bool onRev)
{
	this->iType = "Book";
	this->itemID = itID;
	this->length = length + " pages";
	this->title = title;
	this->author = auth;
	this->publisher = publisher;
	this->locale = lcl;
	this->onReserve = onRev;


}

