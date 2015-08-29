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

/*********************************************************************
** Function: AudioBook::AudioBook()
** Description: Item : AudioBook Subclass Default Constructor
** Parameters: N/A
** Pre-Conditions: N/A
** Post-Conditions: N/A
*********************************************************************/ 

AudioBook::AudioBook()
{
	this->iType = "Audiobook";
	this->itemID = "AB-0"; 
	this->length = "0";
	this->title = "Null Book";
	this->narrator = "No Narrator";
	this->author = "John Smith";
	this->publisher = "Null Publisher";
	this->locale = "NOLOCATION";
	this->onReserve = false;

}

/*********************************************************************
** Function: AudioBook::AudioBook
** Description: Item : AudioBook Subclass Constructor
** Parameters: (std::string itID, int lgtHr, int lgtMin, std::string title, std::string auth, std::string narrat, 
				std::string publisher, FormatAB fmtAB, Genre gnr, 
				Location lcl, bool onRev, bool isDig)
** Pre-Conditions: User calls for a audiobook object and inputs data.
** Post-Conditions: New audiobook object is created based on parameters and saved to memory.
*********************************************************************/ 
AudioBook::AudioBook(std::string itID, std::string lgt, std::string title, std::string auth, std::string narrat, std::string publisher, std::string lcl, bool onRev)
{
	this->iType = "Audiobook";
	this->itemID = itID;
	this->length = lgt + " minutes";
	this->title = title;
	this->author = auth;
	this->publisher = publisher;
	this->narrator = narrat;
	this->locale = lcl;
	this->onReserve = onRev;

}




