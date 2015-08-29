/*********************************************************************
** Program Filename: stack.hpp
** Author: Andrew M. Calhoun
** Date: 07/21/2015
** Description: The source file for the stack portion of the lab
** Input: User puts numbers to be put on the top of the stack.
** Output: Pops the numbers out until it reaches the end of the stack.
*********************************************************************/


#include "stack.hpp"
#include "node.hpp"
#include <iostream>

/*********************************************************************
** Function: void Queue::addBack(int num)
** Description: Adds a number to the top of the stack.
** Parameters: int num
** Pre-Conditions: User inputs number and it's passed to the stack.
** Post-Conditions: That number is added to the stack.
*********************************************************************/ 

void Stack::push(int num)
{
	head = new Node(num, head);
}

int Stack::peek()
{
	if(isEmpty())
	{
		std::cout << "The stack is empty." << std::endl;
	}
	else
	{
		return head->value;	
	}
}

/*********************************************************************
** Function: void Queue::pop()
** Description: Takes a number from the top of the stack.
** Parameters: N/A
** Pre-Conditions: The stack exists.
** Post-Conditions: That number is removed from the stack and if it
** 	is empty, it notifies the user.
*********************************************************************/ 

void Stack::pop()
{
	Node* stHolder;

	if(isEmpty())
	{
		std::cout << "The stack is empty." << std::endl;
	}

	else
	{
		stHolder = head;
		head = head->next;
		delete stHolder;
	}

}


/*********************************************************************
** Function: bool Stack::isEmpty()
** Description: Checks to see if the stack is empty.
** Parameters: N/A
** Pre-Conditions: The stack is called.
** Post-Conditions: Sets the empty bool to true or false based on
**					whether the stack has anything in it.
*********************************************************************/ 

bool Stack::isEmpty()
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

