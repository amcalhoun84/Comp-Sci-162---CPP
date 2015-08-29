/*********************************************************************
** Program Filename: cipherFilter.hpp
** Author: Andrew M. Calhoun
** Date: July 14th, 2015
** Description: The header file for the cipherFilter subclass.
** Input: N/A
** Output: N/A
*********************************************************************/

#ifndef CIPHERFILTER_HPP
#define CIPHERFILTER_HPP

#include "fileFilter.hpp"

class CipherEncrypt : public FileFilter
{
private:
	
	int wordCount;
	int	lineCount;
	int cipherRotation;	
	virtual char transform(char ch);

public:

	CipherEncrypt(int cipherRotation);
	virtual void doFilter(std::ifstream &in, std::ofstream &out);
};

#endif