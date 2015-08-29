/*********************************************************************
** Program Filename: cipherFilter.cpp
** Author: Andrew M. Calhoun
** Date: July 14th, 2015
** Description: The source file for the fileEncryption class.
** Input: N/A
** Output: N/A
*********************************************************************/


#include "fileFilter.hpp"
#include "fileEncryption.hpp"


/*********************************************************************
** Function: FileEncryption::FileEncryption
** Description: Takes the file input and shifts the letters as described by
		the cipherRotation variable,  and outputs them to file.
** Parameters: int cipherRotation
** Pre-Conditions: User defined or program defined cipherRotation.
** Post-Conditions: Populates the cipher Rotation key and encrypts on the basis of the
	key.
*********************************************************************/ 

FileEncryption::FileEncryption(int cipherRotation)
{
	this->cipherRotation = cipherRotation;	// Default Constructor for file encryption
}

/*********************************************************************
** Function: char FileFilter::transform(char ch)
** Description: Takes the file input and shifts the letters as described by
		the cipherRotation variable,  and outputs them to file.
** Parameters: char ch
** Pre-Conditions: What is passed from the doFilter function by parameter.
** Post-Conditions: Outputs each encrypted character into a specificed file.
*********************************************************************/ 

char FileEncryption::transform(char ch)
{
	if(ch >= 65 && ch <= 90)
	{
		return ((ch + this->cipherRotation ) % 26) + 65;
	}

	else if (ch >= 97 && ch <= 122)
	{
		return ((ch + this->cipherRotation) % 26) + 97;
	}

	else
	{
		return ch;
	}

}