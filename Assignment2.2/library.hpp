/*********************************************************************  
** Program Filename: library.hpp
** Author: Andrew M. Calhoun
** Date: 7/8/2015
** Description: Header file for the library.cpp.
				
** Input: Program primary interactive functions.
** Outut: N/A
***********************************************************************/ 

#ifndef LIBRARY_HPP
#define LIBRARY_HPP

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

#include "item.hpp"
#include "book.hpp"
#include "audiobook.hpp"
#include "video.hpp"

class Library {

private:	

	char menuOption,
		 overwriteOK,
		 quitVerification,
		 doAgain;

	std::string getItemID;

	// Items?
	
	//New Item Variables
	int newItemClass,
		newGenre,
		newFormat,
		newLocale,
		newLength, newLengthHr, newLengthMin;

	bool isDigital,
		 isReserved,
		 isNew,
		 isOut,
		 isUnique;

	char newReserve,
		 isNewYN,
		 newCheckedOut;

	FormatBK fmtBK;
	FormatAB fmtAB;
	FormatVID fmtVID;
	Genre inGenre;
	GenreVID inGenreVID;
	Location inLocale;

	std::string newItemID,
				newTitle,
				newAuthor,
				newPublisher,
				newNarrator,
				newActors;

	std::vector<Library*> libraryInventory;




public: 
	Library();
	int libraryMenu();
	void addItem();
	bool checkUnique();
	
	void deleteItem(std::string getItemID);
	void saveFile();
	void openFile();
	char quitProgram();
	void ChangeFileDestination();
	//std::string getItem(std::string itID);
	void getItem(std::string itID);
	void getReserve();

	Location setLocale(int);
	Genre setGenre(int);

// New Functions to help keep code clean and organized.

	void newBook();
	void newVideo();
	void newAudioBook();
	

};

#endif