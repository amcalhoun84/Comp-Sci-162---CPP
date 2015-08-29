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
#include "characterType.hpp"
#include <iostream>

/*********************************************************************
** Function: void Stack::Push(CharacterType* character)
** Description: Adds a character to the top of the stack.
** Parameters: CharacterType* character
** Pre-Conditions: User inputs number and it's passed to the stack.
** Post-Conditions: That number is added to the stack.
*********************************************************************/ 

void Stack::push(CharacterType* character)
{
	head = new Node(character, head);
}

/*********************************************************************
** Function: void Stack::peek()
** Description: Looks at aa charaaacter at the top of the stack
** Parameters: N/A
** Pre-Conditions: The stack exists.
** Post-Conditions: That number is removed from the stack and if it
** 	is empty, it notifies the user.
*********************************************************************/ 

CharacterType* Stack::peek()
{
	if(isEmpty())
	{
		std::cout << "The stack is empty." << std::endl;
	}

	return head->character;	
	
}

/*********************************************************************
** Function: void Stack::pop()
** Description: Takes a character from the top of the stack.
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

