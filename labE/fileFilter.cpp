/*********************************************************************
** Program Filename: fileFilter.cpp
** Author: Andrew M. Calhoun
** Date: July 14th, 2015
** Description: The source file for the fileFilter class.
** Input: yeats.txt
** Output: yeatsCopy.txt, yeatsCopy.txt, yeatsEncrypt.txt, yeatsCihper.txt, yeatsUpper.txt
*********************************************************************/

#include "fileFilter.hpp"

/*********************************************************************
** Function: void FileFilter::doFilter(std::ifstream &in, std::ofstream &out)
** Description: Reads through the specified files and puts them through the
	transformation process.
** Parameters: std::ifstream &in, std::ofstream &out
** Pre-Conditions: File inputs specified by user or program.
** Post-Conditions: Reads the input file and prepares it for transformation to
	be written to the output file.
*********************************************************************/ 

void FileFilter::doFilter(std::ifstream &in, std::ofstream &out)
{
	while (in.peek() != EOF)
	{
		inChar;
		outChar;
		in.get(inChar);
		outChar = transform(inChar);
		out.put(outChar);
	}
}

/*********************************************************************
** Function: char FileFilter::transform(char ch)
** Description: Applies any transformations to the text as required by the file.
** Parameters: char ch
** Pre-Conditions: What is passed from the doFilter function by parameter.
** Post-Conditions: Outputs each character into a specificed file.
*********************************************************************/ 

char FileFilter::transform(char ch)
{
	return ch;
}


