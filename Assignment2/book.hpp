/*********************************************************************  
** Program Filename: book.hpp
** Author: Andrew M. Calhoun
** Date: 7/8/2015
** Description: Book Header File, informs class members or data.
				Sub-class of item class.
** Input: Book Header File.
** Outut: N/A
***********************************************************************/ 

#ifndef BOOK_HPP
#define BOOK_HPP

#include "item.hpp"

// Will be needed in all files.

class Book : public Item {

private:
	
public:
	Book();
	Book(std::string itID, std::string title, std::string auth, std::string publisher, std::string length, std::string lcl, bool onRev);
	

};

#endif