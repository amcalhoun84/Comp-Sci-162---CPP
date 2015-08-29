/*********************************************************************  
** Program Filename: video.hpp
** Author: Andrew M. Calhoun
** Date: 7/8/2015
** Description: Video Header File, informs class members or data.
				Sub-class of item class.
** Input: Book Header File.
** Outut: N/A
***********************************************************************/ 

#ifndef VIDEO_HPP
#define VIDEO_HPP

#include "item.hpp"

class Video : public Item 

{
private:
	std::string actors;
	// std::string formatVid;
	// std::string genreVideo;
	// FormatVID fmtVID;
	// GenreVID gnrVID;

public:
	Video();
	Video(std::string itID, std::string lgt, std::string title, std::string auth, std::string actors, std::string publisher, std::string lcl, bool onRev);


/*********************************************************************
** Function: std::string getActors()
** Description: Gets the actors of the video.
** Parameters: N/A
** Pre-Conditions: User or file requests actors for the item.
** Post-Conditions: Returns the actors.
*********************************************************************/ 


	std::string getActors()
	{
		return actors;
	}

/*********************************************************************
** Function: std::string getActors()
** Description: Set or update the actors of the video.
** Parameters: N/A
** Pre-Conditions: User or file requests to update actors for the item.
** Post-Conditions: Updates the actors for the video.
*********************************************************************/ 

	void setActors(std::string setActs) 
	{ 
		actors = setActs; 
	}
	
}; 

#endif