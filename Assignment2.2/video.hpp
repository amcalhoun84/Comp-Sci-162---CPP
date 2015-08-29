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

class Video;

enum FormatVID {DVD = 1, BLU_RAY, LASERDISC, VHS, BETAMAX, NO_VID_FORMAT};
enum GenreVID {ACTION = 1, ADVENTURE, ANIMATION, KIDS, COMEDY, ROMANCE, DOCUMENTARY, INSTRUCTIONAL, NO_VID_GENRE};


class Video : public Item 

{
private:
	std::string actors;
	//std::string formatVid;
	//std::string genreVideo;
	FormatVID fmtVID;
	GenreVID gnrVID;

public:
	Video();
	Video(std::string itID, int lgtHr, int lgtMin, std::string title, std::string auth, std::string narrat, std::string publisher, FormatVID fmtVID, GenreVID gnr, Location lcl, bool isNew, bool onRev, bool isOut);
	std::string getFormatVID(FormatVID fmtVID);
	std::string getGenreVID(GenreVID gnrVID);
	std::string getActors();
	
}; 

#endif