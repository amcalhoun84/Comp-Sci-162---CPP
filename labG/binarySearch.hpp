/*********************************************************************
** Program Filename: binarySearch.hpp
** Author: Andrew M. Calhoun
** Date: 8/6/2015
** Description: The header file for the binary search functionality.
** Input: Test Files, of unsorted numbers
** Output: Console output of found numbers.
*********************************************************************/

#ifndef BINARYSEARCH_HPP
#define BINARYSEARCH_HPP

#include <iostream>
#include <fstream>

class BinarySearch
{

private:

	std::ifstream binaryIn;
	int search,
		temp,
		number,
		numArray[20],
		counter,
		start,
		mids,
		finish;

public:
	
	void binarySearch(std::ifstream& binaryIn, int search);

};

#endif

