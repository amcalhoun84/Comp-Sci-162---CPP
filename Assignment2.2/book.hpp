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

class Book;

enum FormatBK{HARDCOVER, PAPERBACK, VOLUME, FREE_LEAF, NO_BK_FORMAT};

class Book : public Item {

private:
	FormatBK fmtBK;
	// std::string formatBook;

public:
	Book();
	Book(std::string itID, std::string ttl, std::string auth, std::string publisher, int length, FormatBK fmtBK, Genre gnr, Location lcl, bool onRev, bool isOut);
	std::string	getAuthor();
	std::string getFormatBK(FormatBK fmtBK);

};

#endif