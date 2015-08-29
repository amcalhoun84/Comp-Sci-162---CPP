#ifndef TARGETSEARCH_HPP
#define TARGETSEARCH_HPP

#include <iostream>
#include <fstream>

class TargetSearch
{

private:

	std::ifstream targetIn;
	int search;

public:
	
	void targetSearch(std::ifstream& binaryIn, int search);

};

#endif

