/*********************************************************************
** Program Filename: cipherFilter.cpp
** Author: Andrew M. Calhoun
** Date: July 14th, 2015
** Description: The source file for the cipherFilter class.
** Input: N/A
** Output: N/A
*********************************************************************/

#include "fileFilter.hpp"
#include "cipherFilter.hpp"

/*********************************************************************
** Function: CipherEncrypt::CipherEncrypt
** Description: Takes the file input and shifts the letters as described by
		the cipherRotation variable,  and outputs them to file.
** Parameters: int cipherRotation
** Pre-Conditions: User defined or program defined cipherRotation.
** Post-Conditions: Populates the cipher Rotation key and encrypts on the basis of the
	key.
*********************************************************************/ 

CipherEncrypt::CipherEncrypt(int cipherRotation)
{
	this->cipherRotation = cipherRotation;
}

/*********************************************************************
** Function: void CipherEncrypt::doFilter(std::ifstream &in, std::ofstream &out)
** Description: Reads through the specified files and puts them through the
	transformation process.
** Parameters: std::ifstream &in, std::ofstream &out
** Pre-Conditions: File inputs specified by user or program.
** Post-Conditions: Reads the input file and prepares it for transformation to
	be written to the output file.
*********************************************************************/ 

void CipherEncrypt::doFilter(std::ifstream &in, std::ofstream &out)
{
	char ch;
	in.get(ch);

	wordCount = 0;
	lineCount = 0;

	while(in.good())
	{
		if (ch == ' ') // ignore spaces and white space please.
			in.get(ch); 

		else
		{
			wordCount++;
			if(wordCount % 6 == 0)
			{
				out.put(' ');
			}

			else
			{
				if(ch == 10) // let's get a new line and start over.
				{
					wordCount = 0;
				}

				ch = transform(ch);
				out.put(ch);
				in.get(ch);

			}
		}
	}
}

/*********************************************************************
** Function: char FileFilter::transform(char ch)
** Description: Shifts the letters on the basis of the input key from the doFilter 
				and cipherFilter constructor
** Parameters: char ch
** Pre-Conditions: What is passed from the doFilter function by parameter.
** Post-Conditions: Outputs each character into a specificed file, ciphers them
		and makes them upper case.
*********************************************************************/ 

char CipherEncrypt::transform(char ch)
{
	ch = toupper(ch);

	if (ch >= 65 && ch <= 90) // Capitals on the ASCII table
		{
			return (ch % 26) + 65;
		}
	else if(ch >= 97 && ch <= 122) // lower case letters
	{
	
			return (ch % 26) + 97;
	}
	else if (ch == 10)
	{
		return ch;
	}
	else
		return (ch % 26);


}