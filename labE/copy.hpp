/*********************************************************************
** Program Filename: copy.hpp
** Author: Andrew M. Calhoun
** Date: July 14th, 2015
** Description: The header file for the Copy subclass.
** Input: N/A
** Output: N/A
*********************************************************************/

#ifndef COPY_HPP
#define COPY_HPP

#include "fileFilter.hpp"

class Copy : public FileFilter 
{ 

private: 
	virtual char transform(char ch);

};

#endif