#ifndef BUBBLESORT_HPP
#define BUBBLESORT_HPP

#include <iostream>
#include <fstream>

class BubbleSort
{

private:

	std::ifstream bubbleIn;
	std::ofstream bubbleOut;

public:
	
	void bubbleSort(std::ifstream& bubbleIn, std::ofstream& bubbleOut);

};

#endif

