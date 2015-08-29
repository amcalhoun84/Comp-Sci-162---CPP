/***********************
* Name: Andrew M. Calhoun (calhouna)
* Email: calhouna@onid.oregonstate.edu
* Date: 6/24/2015
* Description: Source File for the int main() function.
* 
* There are 5 test arrays, and a user generated array
* to test arrays of various sizes and look for logic errors.
*
************************/

#include "summation.h"
#include "average.h"
#include <iostream>

int main()
{
	int size; // User input variable for the size of the array.
	double arrayTest[size]; // User input array
	const int SIZE1 = 6, 
			  SIZE2 = 8, 
			  SIZE3 = 7, 
			  SIZE4 = 3,
			  SIZE5 = 3;

	double arrayTest1[SIZE1] = {1.0, 4.0, 7.05, 8.41, 4.12, 5.21};

	// Group Test 1:
	std::cout << sum(arrayTest1, SIZE1) << std::endl; // Should Come Out To 29.79
	std::cout << avg(arrayTest1, SIZE1) << std::endl; // Should Come Out To 3.72375
	
	double arrayTest2[SIZE2] = {1.0, 1.0, 2.0, 3.0, 5.0, 8.0, 13.0, 21.0}; // Fibonacci Sequence, up to the 8th iteration

	// Group Test 2:
	std::cout << sum(arrayTest2, SIZE2) << std::endl; // Should Come Out To 54.0
	std::cout << avg(arrayTest2, SIZE2) << std::endl; // Should Come Out To 6.75
	
	double arrayTest3[SIZE3] = {1.0, -1.0, 3.5, 2.1, -3.5, 1.0, 0.5};

	// Group Test 3:
	std::cout << sum(arrayTest3, SIZE3) << std::endl; // Should Come Out To 3.6
	std::cout << avg(arrayTest3, SIZE3) << std::endl; // Should Come Out To 0.514286
	
	double arrayTest4[SIZE4] = {1.0, 2.0, 3.0};
	
	// Group Test 4:
	std::cout << sum(arrayTest4, SIZE4) << std::endl; // Should Come Out To 6
	std::cout << avg(arrayTest4, SIZE4) << std::endl; // Should Come Out To 2

	double arrayTest5[SIZE5] = {'a', 1, 0.0}; // produces a "quasi-garbage" output, as the char is assigned a numerical value.
											  // I attempted to use a string, but it caused an error that won't allow the program to compile.
	// Group Test 4:
	// std::cout << sum(arrayTest5, SIZE5) << std::endl; // 0
	// std::cout << avg(arrayTest5, SIZE5) << std::endl; // 0 -- commented out as they produce garbage output in this case.

	
	std::cout << "Please tell me the number of elements in your array. (10 or fewer please)" << std::endl; // For the time being we will assume all entries are valid. 																				  					   // If we have an invalid entry, the program will just break.
	std::cin >> size;
	
	if(!(isalpha(size)))
	{
		if(size < 11 && size > 0) // limits the size of the array 
		{

		for(int z = 0; z < size; z++) // run through the size input and assigns them to the indices of the array.
		{
			std::cout << "Please input number " << z+1 << ":" << std::endl;
			std::cin >> arrayTest[z]; 

		}

		std::cout << sum(arrayTest, size) << std::endl;
		std::cout << avg(arrayTest, size) << std::endl;
	}

	else // Error catch.
		{
			std::cout << "Invalid size or input, run the program again and please create an array between 1 and 10 elements." << std::endl;
		//	return 0; -- so we don't break yet. 
		}

		
	}
}
	
