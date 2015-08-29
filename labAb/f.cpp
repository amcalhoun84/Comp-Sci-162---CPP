/*******************************************************************************
** Author: Beckett, Sam						                                       		  **
** Date: 28June15								                                              **
** Description: LabAa,                                                        **
*******************************************************************************/
#include "average.h"

/* The avg function recieves an array of doubles and its size. It iterates    **
** through the array using an accumulator to find the sum, it then returns    **
** the sum devided by the number of elemnts in the array	                    */
double avg(const double array[], int size)
{
	double total = 0.0;

	for (int i = 0; i < size; i++)
		total += array[i];

	return total/size;
}
