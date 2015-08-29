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

class Item;

enum FormatAB {CASSETTE, CD, MP3, DIGITAL_DOWNLOAD, NO_FORMAT_AB};
/*enum GenreAB {FICTION, 
		YOUNG_ADULT, 
		NON_FICTION, 
		SCIFI_FANTASY,
		BIOGRAPHY,
		MYSTERY, 
		ADVENTURE, 
		COMEDY, 
		ACTION,
		INSTRUCTIONAL, 
		NOGENRE};*/

class AudioBook : public Item {

private:
	std::string narrator;
	std::string genreAB;
	FormatAB fmtAB;
	std::string formatAB;

public:
	AudioBook();
	AudioBook(std::string itID, int lgtHr, int lgtMin, std::string title, std::string auth, std::string narrat, std::string publisher, FormatAB fmtAB, Genre gnr, Location lcl, bool isNew, bool onRev, bool isOut, bool isDig);
	std::string getNarrator();
	std::string getFormatAB(FormatAB fmtAB);
//	std::string getGenreAB(GenreAB gnr);

};

#endif