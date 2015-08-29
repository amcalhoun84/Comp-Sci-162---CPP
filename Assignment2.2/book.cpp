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

Book::Book()
{
	this->itemID = "BK-0"; // Books start with prefix BK
	this->length = 0;
	this->title = "Null Book";
	this->author = "John Smith";
	this->publisher = "Null Publisher";
	this->fmtBK = NO_BK_FORMAT;
	this->gnr = NOGENRE;
	this->lctn = NOLOCATION;
	this->onReserve = false;
	this->unique = false;
	this->isNew = false;
	this->isCheckedOut = false;

}

Book::Book(std::string itID, std::string ttl, std::string auth, std::string publisher, int length, FormatBK fmtBK, Genre gnr, Location lcl, bool onRev, bool isOut)
{
	this->itemID = "BK" + itID;
	this->length = length;
	this->title = title;
	this->author = auth;
	this->publisher = publisher;
	this->genre = gnr;
	this->lctn = lcl;
	this->onReserve = onRev;
	this->format = getFormatBK(fmtBK);
	this->isCheckedOut = isOut;

}

std::string Book::getAuthor()
{
	return author;
}

std::string Book::getFormatBK(FormatBK fmtBK)
{
	if(fmtBK == 0)
	{
		format = "Hardcover";
	}
	else if(fmtBK == 1)
	{
		format = "Paperback";
	}
	else if(fmtBK == 2)
	{
		format = "Volume";
	}
	else if(fmtBK == 3)
	{
		format = "Free-Leaf/Unbound";
	}
	else 
	{
		std::cout << "Invalid Input, please try again. " << std::endl;
		return "null";
	}

	return format;
}


