/*********************************************************************
** Program Filename: binarySearch.cpp
** Author: Andrew M. Calhoun
** Date: 8/6/2015
** Description: The source file for the binary search/sort functionality.
** Input: Test Files, of unsorted numbers
** Output: Console output of sorted numbers.
*********************************************************************/

#include "binarySearch.hpp"


/*  Binary Search Algorithm

Found at: https://en.wikipedia.org/wiki/Binary_search_algorithm#Algorithm

int binary_search(int A[], int key, int imin, int imax)
{
  // test if array is empty
  if (imax < imin)
    // set is empty, so return value showing not found
    return KEY_NOT_FOUND;
  else
    {
      // calculate midpoint to cut set in half
      int imid = midpoint(imin, imax);
      
      // three-way comparison
      if (A[imid] > key)
        // key is in lower subset
        return binary_search(A, key, imin, imid - 1);
      else if (A[imid] < key)
        // key is in upper subset
        return binary_search(A, key, imid + 1, imax);
      else
        // key has been found
        return imid;
    }
}

*/

/*********************************************************************
** Function: int binarySearch(ifstream& binaryIn, int search)
** Description: The binary sort algorithm
** Parameters: ifstream& binaryIn, int search
** Pre-Conditions: File name input is given.
** Post-Conditions: Console output of sorted numbers.
*********************************************************************/

void BinarySearch::binarySearch(std::ifstream& binaryIn, int search)
{

  counter = 0,
  start = 1,
  finish = 20;

  mids = (start+finish) / 2;

  while(binaryIn >> number)
  {
    numArray[counter] = number;
    counter++;
  }

  for(unsigned int i = 0; i < finish; i++)
  {
    for(unsigned int j = 0; j < finish; j++)
    {
      if(numArray[j] > numArray[j+1])
      {
          temp = numArray[j];
          numArray[j] = numArray[j+1];
          numArray[j+1] = temp;
      }
    }
  }

  while (start <= finish && numArray[mids] != search)
  {
    if(numArray[mids] < search)
    {
        start = mids + 1;
    }

    else 
    { 
          finish = mids - 1;

    }

    mids = (start + finish) / 2;
  }

  if(numArray[mids] == search)
  {
    std::cout << "Your number was found in the file: " << search << std::endl;
  }
  else
  {
    std::cout << "Your number was not found." << std::endl;
  }

return;

}