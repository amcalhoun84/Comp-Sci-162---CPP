/*********************************************************************
** Program Filename: stack.hpp
** Author: Andrew M. Calhoun
** Date: 07/21/2015
** Description: The header file for the stack portion of the lab
** Input: N/A
** Output: N/A
*********************************************************************/

#ifndef STACK_HPP
#define STACK_HPP

#include "node.hpp"

// First In Last Out structure. FILO

struct Stack
{
	Node* head;

/*********************************************************************
** Function: Stack()
** Description: The default constructor for the stack
** Parameters: N/A
** Pre-Conditions: Program starts up and user runs the program in main.cpp.
** Post-Conditions: N/A
*********************************************************************/ 

	Stack() { head = NULL; }

/*********************************************************************
** Function: ~Stack()
** Description: Destructor for the Stack class object.
** Parameters: N/A
** Pre-Conditions: Stack exists and is finished with use.
** Post-Conditions: Stack is destroyed and the memory is freed.
*********************************************************************/ 

	~Stack() 
	{
		while(head != NULL)
		{
			Node* stHolder = head;
			head = head->next;
			delete stHolder;
		}

	}

	void push(CharacterType* character); // puts an item onto the structure.
	CharacterType* peek();	// returns the item to the top of the structure.
	void pop();	// removes the top item
	bool isEmpty(); // confirms if the structure is empty or not.
	int getCount();
	
};

#endif