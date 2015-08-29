/*********************************************************************
** Program Filename: queue.cpp
** Author: Andrew M. Calhoun
** Date: 07/21/2015
** Description: The source file for the queue portion of the lab
** Input: User inputs numbers to be placed into a queue back to front.
** Output: Puts them in, and then removes them from forward to back.
*********************************************************************/

#include "queue.hpp"
#include "node.hpp"

/*********************************************************************
** Function: void Queue::addBack(int num)
** Description: Adds a number to the back of the queue to line it up.
** Parameters: int num
** Pre-Conditions: If the stack is empty, creates a new head, or adds 
**		another node, based on user input.
** Post-Conditions: That number is added to the queue.
*********************************************************************/ 

void Queue::addBack(int num)
{
	if(isEmpty())
	{
		head = new Node(num);
		tail = head;
	}
	
	else
	{
		tail->next = new Node(num);
		tail = tail->next;
	}
}

/*********************************************************************
** Function: Stack()
** Description: The default constructor for the stack
** Parameters: N/A
** Pre-Conditions: Program starts up and user runs the program in main.cpp.
** Post-Conditions: N/A
*********************************************************************/ 

int Queue::getFront()
{
	if(!head)
	{
		std::cout << "The queue is empty." << std::endl;
	}
	else
	{
		return head->value;
	}
}

/*********************************************************************
** Function: Stack()
** Description: The default constructor for the stack
** Parameters: N/A
** Pre-Conditions: Program starts up and user runs the program in main.cpp.
** Post-Conditions: N/A
*********************************************************************/ 

void Queue::removeFront()
{
	Node* qHolder;
	int num;
	if(isEmpty())
	{
		std::cout << "The queue is empty." << std::endl;
	}
	else
	{
		qHolder = head;
		head = head->next;
		delete qHolder;
	}
}

/*********************************************************************
** Function: Stack()
** Description: The default constructor for the stack
** Parameters: N/A
** Pre-Conditions: Program starts up and user runs the program in main.cpp.
** Post-Conditions: N/A
*********************************************************************/ 

bool Queue::isEmpty()
{
	if(!head)
	{
		return true;
	}
	else
	{
		return false; 
	}
}