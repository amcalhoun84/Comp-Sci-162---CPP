/***********************
* Name: Andrew M. Calhoun (calhouna)
* Email: calhouna@onid.oregonstate.edu
* Date: 6/24/2015
* Description: Source File for the avg function.
* Takes the contents of an array and averages them out
* based on input and the size of the array.
************************/

#include "average.h"

double avg(double arravg[], int size)
{
	double avgr = 0; 

	for(int i=0; i < size; i++) // Run through the array.
	{
		if(isalpha(arravg[i])) //  If array contains a character, warn the user and return 0 only!
		{
			std::cout << "Please use numbers only!" << std::endl;
			return avgr; // will return nothing
		}
		avgr += arravg[i];	// Adds up the array elements.
	}

	avgr /= size; // Gives us the average based on the sum 
				  // and divides it by the size of the index. 

	return avgr; // Return the average to the main file.

}