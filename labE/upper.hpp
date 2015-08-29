/*********************************************************************
** Program Filename: upper.hpp
** Author: Andrew M. Calhoun
** Date: July 14th, 2015
** Description: The header file for the Upper subclass.
** Input: N/A
** Output: N/A
*********************************************************************/

#ifndef UPPER_HPP
#define UPPER_HPP

#include "fileFilter.hpp"

class Upper : public FileFilter {

private:

	virtual char transform(char ch);

};

#endif