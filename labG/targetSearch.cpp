/*********************************************************************
** Program Filename: targetSearch.cpp
** Author: Andrew M. Calhoun
** Date: 8/6/2015
** Description: The source file for the target search/sort functionality.
** Input: Test Files, of unsorted numbers
** Output: Console output of found numbers.
*********************************************************************/

#include "targetSearch.hpp"

// Found on: https://en.wikipedia.org/wiki/Selection_sort

/* a[0] to a[n-1] is the array to sort 
int i,j;
int iMin;

/* advance the position through the entire array */
/*   (could do j < n-1 because single element is also min element) 
for (j = 0; j < n-1; j++) {
    /* find the min element in the unsorted a[j .. n-1] 

    /* assume the min is the first element 
    iMin = j;
    /* test against elements after j to find the smallest 
    for ( i = j+1; i < n; i++) {
        /* if this element is less, then it is the new minimum *  
        if (a[i] < a[iMin]) {
            /* found new minimum; remember its index 
            iMin = i;
        }
    }
   
    if(iMin != j) {
        swap(a[j], a[iMin]);
    }
   
} */ 

    /* As we are just searching, I stripped out the sorting part of the algorithm when I
    ** wrote my code. */


/*********************************************************************
** Function: int targetSearch(std::ifstream& targetIn, int search)
** Description: The target search algorithm
** Parameters: ifstream& targetIn, int search
** Pre-Conditions: File name input is given.
** Post-Conditions: Console output of sorted numbers.
*********************************************************************/

void TargetSearch::targetSearch(std::ifstream& targetIn, int search)
{

	int counter = 0,
		numberArray[20],
		found = 0,
		number;

	while(targetIn >> number)
	{
		numberArray[counter] = number;
		counter++;
	}

	for(unsigned int i = 0; i < 20; i++)
	{
		if(numberArray[i] == search)
		{
			found++;
		}

	}

	if(found >= 1)
	{
		std::cout << "The number: " << search << " was found in the file." << std::endl;
	}
	else
	{
		std::cout << "Number was not found in the file." << std::endl;
	}

}