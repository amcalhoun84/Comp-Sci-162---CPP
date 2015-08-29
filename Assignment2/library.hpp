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
#include <limits>

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

	std::string fetchItemID;

	//New Item Variables
	
	int newItemClass;

	bool isReserved,
		 isUnique;

	char newReserve,
		 isNewYN,
		 newCheckedOut;

//	FormatBK fmtBK;
//	FormatAB fmtAB;
//	FormatVID fmtVID;
//	Format inFmt;
//	Genre inGenre;
//	GenreVID inGenreVID;
//	Location inLocale;

/*	Location readLocale;
	Genre readGenre;
	Format readFormat;*/

	std::string itemType,
				newItemID,
				newTitle,
				newAuthor,
				newPublisher,
				newNarrator,
				newActors,
				newLength,
				newLocale,
				newReserved, 
				readString;

	std::vector<Book*> libraryInventoryBK;
	std::vector<Video*> libraryInventoryVID;
	std::vector<AudioBook*> libraryInventoryAB;


public: 
	Library();
	int libraryMenu();
	void addItem();
	bool checkUnique();
	void getItem(std::string fetchItemID);
	void readInventory();
	void readFile();	
	void deleteItem(std::string fetchItemID);
	void saveFile();
	void updateItem(std::string fetchItemID);
	char quitProgram();
	void vectorTest();

/*	Location setLocale(int);
	Genre setGenre(int);*/

// New Functions to help keep code clean and organized.

	void newBook();
	void newVideo();
	void newAudioBook();
	void editBook();
	void editVideo();
	void editAudioBook();

	bool checkUnique(std::string itemID);
	

};

#endif