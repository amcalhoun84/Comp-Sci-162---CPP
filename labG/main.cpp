/*********************************************************************
** Program Filename: main.cpp
** Author: Andrew M. Calhoun
** Date: 8/6/2015
** Description: The main source file for LabG.
** Input: Test Files, of unsorted numbers
** Output: Console output of sorted numbers.
*********************************************************************/

#include "targetSearch.hpp"
#include "bubbleSort.hpp"
#include "binarySearch.hpp"
#include <iostream>
#include <string>

int main()
{

	int choice,
		searchInt; 

	std::ifstream ifs;

	TargetSearch targetSch;
	BubbleSort bubbaSort;
	BinarySearch binSearch;

	std::string fileIn = "";
	std::string fileOut = "";


	do
	{

	
		std::cout << "*--------------------------------------------------*\n"
				  << "Lab G Sorting and Search Algorithm Testing Suite\n"
				  << "1. Search for Target Value in File.\n"
				  << "2. Bubble Sort File.\n"
				  << "3. Do a Binary Search in File.\n"
				  << "0. Quit\n"
				  << "*--------------------------------------------------*\n\n"
				  << "Please enter choice: ";

				  std::cin >> choice;
				  std::cin.ignore(1024, '\n');
				  std::cin.clear();

		switch(choice)
		{
			case 1:
			{
				std::cout << "Please enter the file name you want to search: ";
				std::getline(std::cin, fileIn);
				std::cout << "Please enter the single digit integer you want to search for: ";
				std::cin >> searchInt;
				
				ifs.open(fileIn.c_str());
				if(ifs)
				{
					targetSch.targetSearch(ifs, searchInt);
	  			 	ifs.close();

					break;
				}
				else
				{
					std::cout << "Error: File not found." << std::endl;
					break;
				}
				
			}

		
			case 2:
			{
				std::cout << "Please enter the file name you want to sort: ";
				std::getline(std::cin, fileIn);
				std::cout << "Please enter the name of the output file: ";
				std::getline(std::cin, fileOut);
				
				ifs.open(fileIn.c_str());
				if(ifs)
				{
					std::ofstream ofs(fileOut.c_str());
					bubbaSort.bubbleSort(ifs, ofs);
				    ifs.close();
				    break;
				
				}
				else
				{
					std::cout << "Error: File not found." << std::endl;
					break;
				}
					
			}

			case 3:
			{
				std::cout << "Please enter the name of the file you want to search: ";
				std::getline(std::cin, fileIn);
				std::cout << "Please enter the single digit integer you want to search for: ";
				std::cin >> searchInt;
				ifs.open(fileIn.c_str());
				if(ifs)
				{
					binSearch.binarySearch(ifs, searchInt);
				 	ifs.close();
  				 	break;
				}
				
				else
				{
					std::cout << "Error: File not found." << std::endl;
					
				}
				break;

			}

			case 0:
			{
				std::cout << "Have a great day!" << std::endl;
				return 0;
			}

			default: 
			{
				std::cout << "Invalid option selected, please try again." << std::endl;
				break;
			}
		}

	} while(choice != 0);


}