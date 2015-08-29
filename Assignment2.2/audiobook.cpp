/*********************************************************************  
** Program Filename: audiobook.cpp
** Author: Andrew M. Calhoun
** Date: 7/8/2015
** Description: Audiobook Source File, informs class members and data.
				Sub-class of item class.
** Input: Book Header File.
** Outut: N/A
***********************************************************************/ 
#include "item.hpp"
#include "audiobook.hpp"

AudioBook::AudioBook()
{
	this->itemID = "AB-0"; 
	this->lengthHr = 0;
	this->lengthMin = 0;
	this->title = "Null Book";
	this->narrator = "No Narrator";
	this->author = "John Smith";
	this->publisher = "Null Publisher";
	this->fmtAB = NO_FORMAT_AB;
	this->gnr = NOGENRE;
	this->lctn = NOLOCATION;
	this->onReserve = false;
	this->unique = false;
	this->isNew = false;
	this->isCheckedOut = false;
	this->isDigital = false;

}

AudioBook::AudioBook(std::string itID, int lgtHr, int lgtMin, std::string title, std::string auth, std::string narrat, std::string publisher, FormatAB fmtAB, Genre gnr, Location lcl, bool isNew, bool onRev, bool isOut, bool isDig)
{
	this->itemID = "AB" + itID;
	this->lengthHr = lgtHr;
	this->lengthMin = lgtMin;
	this->title = title;
	this->author = auth;
	this->publisher = publisher;
	this->narrator = narrat;
	this->gnr = gnr;
	this->lctn = lcl;
	this->onReserve = onRev;
	this->formatAB = getFormatAB(fmtAB);
	this->onReserve = onRev;
	this->isNew = isNew;
	this->isCheckedOut = isOut;
	this->isDigital = isDig;

}

std::string AudioBook::getNarrator()
{	
	return narrator;
}

std::string AudioBook::getFormatAB(FormatAB fmtAB)
{
	if(fmtAB == CASSETTE)
	{
		format = "Cassette";
	}
	else if(fmtAB == CD)
	{
		format = "CD";
	}
	else if(fmtAB == MP3)
	{
		format = "MP3";
	}
	else if(fmtAB == DIGITAL_DOWNLOAD)
	{
		format = "Digital_Download";
	}
	else 
	{
		std::cout << "Invalid Input, please try again. " << std::endl;
		return "null";
	}

	return format;
}

