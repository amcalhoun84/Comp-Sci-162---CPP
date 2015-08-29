/*********************************************************************
** Program Filename: fileEncryption.hpp
** Author: Andrew M. Calhoun
** Date: July 14th, 2015
** Description: The fileEncryption subclass header file.
** Input: N/A
** Output: N/A
*********************************************************************/


#ifndef FILEENCRYPTION_HPP
#define FILEENCRYPTION_HPP

#include "fileFilter.hpp"

class FileEncryption : public FileFilter {

private:

	int cipherRotation;
	virtual char transform(char ch);

public:

	FileEncryption(int cipherRotation);

};

#endif