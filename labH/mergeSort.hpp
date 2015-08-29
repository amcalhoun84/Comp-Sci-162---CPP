#ifndef MERGESORT_HPP
#define MERGESORT_HPP

#include <fstream>

class MergeSort
{
private:

	int high,
		low,
		mid,
		pivot,
		size,
		x, y;

	std::ifstream fileIn;
	std::ofstream fileOut;

public:
	int mergeIn(std::ifstream& fileIn, int low, int high, int mid);
	int	mergeOut(std::ofstream& fileOut)
	int mergeSort();
	int mergeSortRecursive();
	int max(int x, int y);


}