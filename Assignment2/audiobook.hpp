/*********************************************************************  
** Program Filename: video.hpp
** Author: Andrew M. Calhoun
** Date: 7/8/2015
** Description: Video Header File, informs class members or data.
				Sub-class of item class.
** Input: Book Header File.
** Outut: N/A
***********************************************************************/ 

#ifndef AUDIOBOOK_HPP
#define AUDIOBOOK_HPP

#include "item.hpp"

class AudioBook : public Item {

private:
	std::string narrator;
	// FormatAB fmtAB;
	// std::string formatAB;

public:
	AudioBook();
	AudioBook(std::string itID, std::string lgt, std::string title, std::string auth, std::string narrat, std::string publisher, std::string lcl, bool onRev);
	std::string getNarrator() { return narrator; }
//	std::string getFormatAB();

};

#endif