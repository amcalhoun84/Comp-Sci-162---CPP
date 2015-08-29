/*********************************************************************  
** Program Filename: labD.cpp
** Author: Andrew M. Calhoun
** Date: 7/8/2015
** Description: CS162 Lab D: Merge Two Files Into One File After Sorting Them
** Input: User provides files (in theory, provided test files with Lab) and file names
** Output: All numbers from both files will be written to an outout file with numbers sorted from least to greatest.
*********************************************************************/ 

#include <iostream>
#include <cstdlib> // Necessary for exit command.
#include <string>
#include <fstream>

void fileCheck(std::string);
void fileSort(std::ifstream&, std::ifstream&, std::ofstream&);

/*********************************************************************  
** Function:  int main()
** Description: The main function of the program, asks for user inputs 
**				for file names. 
** Parameters: Start the program, input paramaters for next functions. 
** Pre-Conditions:  Start the program.
** Post-Conditions: Goes through user input and create a merged file.
*********************************************************************/

int main()
{


	std::string input;

	std::cout << "Give the name of your first file." << std::endl;
	std::cin >> input;
	std::ifstream firstFile(input.c_str());

	std::cout << "Give the name of your second file." << std::endl;
	std::cin >> input;
	std::ifstream secondFile(input.c_str());

	std::cout << "Give the name of your output file." << std::endl;
	std::cin >> input;
	std::ofstream outputFile;
	outputFile.open(input.c_str());

	fileSort(firstFile, secondFile, outputFile);

	return 0;

}


/*********************************************************************  
** Function:  void fileSort(std::ifstream& f1, std::istream& f2, std::ofstream& out)
** Description: Reads the numbers from the specified output files and
** 				sorts them, merges them, and then outputs them into a 
**				different file.
** Parameters: Reads from provided source files. 
** Pre-Conditions:  File stream from the files.
** Post-Conditions: Creates a merged file.
*********************************************************************/

void fileSort(std::ifstream& f1, std::ifstream& f2, std::ofstream& out)
{
	
	int n1, 
		n2;

	bool fileLoaded1 = true,
		 fileLoaded2 = true,
		 valueUsed1 = true,
		 valueUsed2 = true;


	if(f1 && f2 && out)
	{

		while(fileLoaded1 || fileLoaded2)
		{
			if(valueUsed1 && fileLoaded1)
			{
				if (f1 >> n1)
				{
					valueUsed1 = false;
				}
				else 
				{
					fileLoaded1 = false;
				}
			}
			
			if (valueUsed2 && fileLoaded2)
			{
				if (f2 >> n2)
				{
					valueUsed2 = false;
				}
				else
				{
					fileLoaded2 = false;
				}
			}

			if (!fileLoaded1  && fileLoaded2)
			{
				out << n2 << std::endl;
				valueUsed2 = true;
			}

			else if(fileLoaded1 && !fileLoaded2)
			{
				out << n1 << std::endl;
				valueUsed1 = true;
			}

			else if((n1 > n2) && (fileLoaded1 && fileLoaded2))
			{
				out << n2 << std::endl;
				valueUsed2 = true;
			}
			else if((n1 < n2) && (fileLoaded1 && fileLoaded2))
			{
				out << n1 << std::endl;
				valueUsed1 = true;
			}
			else if((n1 == n2) && (fileLoaded1 && fileLoaded2))
			{
				out << n1 << " " << n2 << std::endl;
				valueUsed1 = true;
 				valueUsed2 = true;

			}

		}
	}
	else
	{
		std::cout << "Bad File Name or not found!" << std::endl;
		exit(-1);
	}

	f1.close();
	f2.close();
	out.close();

	std::cout << "\nMERGE SUCCESSFUL!\n" << std::endl;

}
