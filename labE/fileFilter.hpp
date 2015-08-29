/*********************************************************************
** Program Filename: fileFilter.hpp
** Author: Andrew M. Calhoun
** Date: 7/14/2015
** Description: The parent class (FileFilter) for a text play program.
** Input: N/A
** Output: N/A
*********************************************************************/


#ifndef FILEFILTER_HPP
#define FILEFILTER_HPP

#include <iostream>
#include <string>
#include <fstream>

class FileFilter {

protected:

	char inChar,
		 outChar;
	virtual char transform(char ch);

public:

	//doFilter() {};;
	virtual void doFilter(std::ifstream &in, std::ofstream &out);
};

#endif