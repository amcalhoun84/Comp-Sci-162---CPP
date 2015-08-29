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

Video::Video()
{
	this->itemID = "VID-0";
	this->length = 0;
	this->title = "Null Video";
	this->actors = "No Actors";
	this->author = "John Smith";
	this->publisher = "Null Studios";


}

Video::Video(std::string itID, int lgtHr, int lgtMin, std::string title, std::string auth, std::string narrat, std::string publisher, FormatVID fmtVID, GenreVID gnr, Location lcl, bool isNew, bool onRev, bool isOut)
{
	this->itemID = "VID-" + itID;
	this->lengthHr = lgtHr;
	this->lengthMin = lgtMin;
	this->title = title;
	this->author = auth;
	this->publisher = publisher;
	this->actors = actors;
	this->gnrVID = gnr;
	this->lctn = lcl;
	this->format = getFormatVID(fmtVID);
	this->onReserve = onRev;
	this->isNew = isNew;
	this->isCheckedOut = isOut;


}

std::string Video::getActors()
{	
	return actors;
}


std::string Video::getFormatVID(FormatVID fmtVID)
{
	if(fmtVID == DVD)
	{
		format = "DVD";
	}
	else if(fmtVID == BLU_RAY)
	{
		format = "Blu-Ray Disc";
	}
	else if(fmtVID == LASERDISC)
	{
		format = "LaserDisc";
	}
	else if(fmtVID == VHS)
	{
		format = "VHS";
	}
	else if(fmtVID == BETAMAX)
	{
		format = "Beta-Max";
	}
	else
	{
		std::cout << "Invalid Input, please try again. " << std::endl;
		return "null";
	}

	return format;
}

std::string Video::getGenreVID(GenreVID gnrVID)
{
	if(gnrVID == ACTION)
	{
		genre = "Action";
	}
	else if(gnrVID == ADVENTURE)
	{
		genre = "Adventure";
	}
	else if(gnrVID == ANIMATION)
	{
		genre = "Animation";
	}

	else if(gnrVID == KIDS)
	{
		genre = "Childrens/Kids";
	}
	else if(gnrVID == COMEDY)
	{
		genre = "Comedy";
	}
	else if(gnrVID == ROMANCE)
	{
		genre = "Romance";
	}
	else if(gnrVID == DOCUMENTARY)
	{
		genre = "Documentary/Historical";
	}
	else if(gnrVID == INSTRUCTIONAL)
	{
		genre = "Instructional";	
	}

	else
	{
		std::cout << "Invalid genre type, please try again." << std::endl;
		genre = "null";
	}

	return genre; 

}