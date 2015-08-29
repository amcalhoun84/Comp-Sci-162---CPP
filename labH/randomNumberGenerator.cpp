#include <fstream>
#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>

int main()
{

int value;

srand(time(NULL));

	std::ofstream file("randomNumbers.txt");

	for(int i = 0; i < 1000; ++i)
	{
		value = rand() % 1000;
		file << value << std::endl;
	}
	
	file.close();
	return 0;

}