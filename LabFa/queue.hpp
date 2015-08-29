/*********************************************************************
** Program Filename: queue.hpp
** Author: Andrew M. Calhoun
** Date: 07/21/2015
** Description: The header file for the queue portion of the lab
** Input: N/A
** Output: N/A
*********************************************************************/

#ifndef QUEUE_HPP
#define QUEUE_HPP

#include "node.hpp"


// Queues are FIFO stacks -- first in, first out.
struct Queue {
	
	Node* head;
	Node* tail;

/*********************************************************************
** Function: Queue()
** Description: Queue() constructor.
** Parameters: N/A
** Pre-Conditions: Program is started and the queue is called upon.
** Post-Conditions: Queue exists and is ready to take numbers.
*********************************************************************/ 

	Queue() 
	{ 
	  head = NULL;
	  tail = NULL; 
	
	}
/*********************************************************************
** Function: ~Queue()
** Description: Queue() destructor.
** Parameters: N/A
** Pre-Conditions: Queue is finished.
** Post-Conditions: Queue is destroyed and freed from memory.
*********************************************************************/ 


	~Queue()
	{
		while(head != NULL)
		{	
			Node* qHolder = head;
			head = head->next;
			delete qHolder;

		}

	}

	void addBack(int num);  // adds item to the back of the stack.
	int getFront();			  // pulls out the value of the front of the structure.
	void removeFront();		// Removes the first item in the structure.
	bool isEmpty();			// confirms if it is empty or not.
	int getCount();


};

#endif