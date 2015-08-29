/*********************************************************************
** Program Filename: bubbleSort.cpp
** Author: Andrew M. Calhoun
** Date: 8/6/2015
** Description: The source file for the bubble sort functionality.
** Input: Test Files, of unsorted numbers
** Output: File output of sorted numbers.
*********************************************************************/

#include "bubbleSort.hpp"

/*
  Found at: https://en.wikipedia.org/wiki/Bubble_sort#Pseudocode_implementation

procedure bubbleSort( A : list of sortable items )
   n = length(A)
   repeat 
     swapped = false
     for i = 1 to n-1 inclusive do
       /* if this pair is out of order 
       if A[i-1] > A[i] then
         /* swap them and remember something changed 
         swap( A[i-1], A[i] )
         swapped = true
       end if
     end for
   until not swapped
end procedure
*/

/*********************************************************************
** Function: int bubbleSearch(std::ifstream& bubbleIn, std::ofstream& bubbleOut)
** Description: The binary sort algorithm
** Parameters: ifstream& bubbleIn, ofstream& bubbleOut
** Pre-Conditions: File name input is given.
** Post-Conditions: File output of sorted numbers.
*********************************************************************/

void BubbleSort::bubbleSort(std::ifstream& bubbleIn, std::ofstream& bubbleOut)
{

  int numberArray[20],
      counter = 0,
      number,
      temp; 

      while(bubbleIn >> number)
      {
          numberArray[counter] = number;
          counter++;
      }

      for (unsigned int i = 0; i <= 19; i++)
      {

        for(unsigned int j = 0; j < 19; j++)
        {
          if(numberArray[j] > numberArray[j+1])
          {
            
            temp = numberArray[j];
            numberArray[j] = numberArray[j + 1];
            numberArray[j+1] = temp; 

          }
        }
      }

      for (unsigned int i = 0; i <= 19; i++)
      {
          bubbleOut << numberArray[i] << std::endl;
      }

}