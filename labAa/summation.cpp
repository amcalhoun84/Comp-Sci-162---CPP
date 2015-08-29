/***********************
* Name: Andrew M. Calhoun (calhouna)
* Email: calhouna@onid.oregonstate.edu
* Date: 6/24/2015
* Description: Source File for the avg function.
* Takes the contents of an array and adds it up
* based on input and the size of the array.
************************/

#include "summation.h"

double sum(double arrsum[], int size)
{
	double sum = 0; 

	for(int i=0; i < size; i++) 
	{
		if(isalpha(arrsum[i])) //  If array contains a character, warn the user and return 0 only!
		{
			std::cout << "Please use numbers only!" << std::endl;
			return sum;
		}
		sum += arrsum[i];	
	}

	return sum;

}