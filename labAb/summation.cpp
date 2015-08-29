/*******************************************************************************
** Author: Beckett, Sam						                                       		  **
** Date: 28June15								                                              **
** Description: LabAa,                                                        **
*******************************************************************************/
#include "summation.h"

/* The sum function recieves an array of doubles and its size. It iterates    **
** through the array using an accumulator to find and return the sum	        */
double sum(const double array[], int size)
{
	double total = 0.0;

	for (int i = 0; i < size; i++)
		total += array[i];

	return total;
}
