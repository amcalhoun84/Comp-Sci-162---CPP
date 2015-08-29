/*********************************************************************  
** Program Filename: main.cpp
** Author: Andrew M. Calhoun
** Date: 7/8/2015
** Description: Main testing file for Library inventory functions.
				Takes User to libraryMenu() function.
** Input: From file or user input and potential debug mode.
** Outut: New or updated file is output when saved.
***********************************************************************/ 

#include <iostream>

#include "audiobook.hpp"
#include "item.hpp"
#include "library.hpp"
#include "video.hpp"

int main()
{
	Library l;

	l.libraryMenu();
	return 0;
}
