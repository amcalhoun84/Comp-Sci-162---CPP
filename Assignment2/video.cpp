/*********************************************************************  
** Program Filename: audiobook.cpp
** Author: Andrew M. Calhoun
** Date: 7/8/2015
** Description: Audiobook Source File, informs class members and data.
				Sub-class of item class.
** Input: Book Header File.
** Outut: N/A
***********************************************************************/ 
#include "video.hpp"
#include "item.hpp"

/*********************************************************************
** Function: Video::Video()
** Description: Item : Video Subclass Default Constructor
** Parameters: N/A
** Pre-Conditions: N/A
** Post-Conditions: N/A
*********************************************************************/ 

Video::Video()
{


}
/*********************************************************************
** Function: Video::Video
** Description: Item : Video Subclass Constructor
** Parameters: std::string itID, int lgtHr, int lgtMin, std::string title, std::string auth, std::string actors, std::string publisher, 
** FormatVID fmtVID, GenreVID gnr, Location lcl, bool onRev
**
** Pre-Conditions: User calls for a video object and inputs data.
** Post-Conditions: New video object is created based on parameters and saved to memory.
*********************************************************************/ 
Video::Video(std::string itID, std::string lgt, std::string title, std::string auth, std::string actors, std::string publisher, std::string lcl, bool onRev)
{
	this->iType = "Video";
	this->itemID = itID;
	this->length = lgt + " minutes";
	this->title = title;
	this->author = auth;
	this->publisher = publisher;
	this->actors = actors;
	this->locale = lcl;
	this->onReserve = onRev;
}
