#include "fileFilter.hpp"
#include "upper.hpp"

/*********************************************************************
** Function: char Upper::transform(char ch)
** Description: Applies any transformations to the text as required by the file.
** Parameters: char ch
** Pre-Conditions: What is passed from the doFilter function by parameter.
** Post-Conditions: Transforms characters to upper case to file.
*********************************************************************/ 

char Upper::transform(char ch)
{
	ch = toupper(ch);
	return ch;
}
