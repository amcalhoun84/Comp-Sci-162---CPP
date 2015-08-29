/*********************************************************************
** Program Filename: ADT_Stack.cpp
** Author: Brett Anderson
** Date:  6/27/15
** Description: methods for the Abstract Data Type Stack Class
** Input: none.
** Output:
*********************************************************************/

#include "ADT_Stack.hpp"
#include <string>

/*********************************************************************
** Function:  constructor
** Description:  constructor
** Parameters: int
** Pre-Conditions: none
** Post-Conditions: stack is created
*********************************************************************/
ADT_Stack::ADT_Stack()
{
	this->nPtr = NULL;
}

/*********************************************************************
** Function:  constructor
** Description:  constructor
** Parameters: int
** Pre-Conditions: none
** Post-Conditions: stack is created with one element
*********************************************************************/
ADT_Stack::ADT_Stack(int num)
{
	this->nPtr = new sNode;
	this->nPtr->data = num;
	this->nPtr->nPtrNext = NULL;
}

/*********************************************************************
** Function:  push
** Description:  pushes an item into the stack
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: added element is the top of the stack, 
** other elements are pushed one deeper into the stack
*********************************************************************/
void ADT_Stack::push(int num)
{
	// create a new node
	sNode *n = new sNode;
	n->data = num;
	
	// new node now points to whatever the head pointed at
	n->nPtrNext = this->nPtr;
	// head now points to new node (top of stack)
	this->nPtr = n;
}

/*********************************************************************
** Function:  peek
** Description:  returns the value of the next element on the stack
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: data value of next element is returned
** Throws exception of type std::string if called and stack is empty
*********************************************************************/
int ADT_Stack::peek()
{
	if (this->isEmpty() == false)
		return this->nPtr->data;
	else
		throw std::string("Stack is empty");
}

/*********************************************************************
** Function:  pop
** Description:  removes the next element from the top of the stack
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: next element is removed.
** Throws exception of type std::string if called and stack is empty
*********************************************************************/
void ADT_Stack::pop()
{
	if (!this->isEmpty()) {
		sNode *p = this->nPtr;
		this->nPtr = this->nPtr->nPtrNext;
		delete p;
	}
	else
		throw std::string("Stack is empty");
}

/*********************************************************************
** Function:  isEmpty
** Description:  Checks to see if the structure is empty
** Parameters: returns bool
** Pre-Conditions: none
** Post-Conditions: returns true if empty, false if not
*********************************************************************/
bool ADT_Stack::isEmpty()
{
	if (this->nPtr != NULL)
		return false;
	else
		return true;
}


/*********************************************************************
** Function:  destructor
** Description:  destructor
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: empties the data structure if not empty
*********************************************************************/
ADT_Stack::~ADT_Stack()
{

	/*
	Cleanup
	Go through the data structure and clean up any nodes that still exist
	when we destry the stack. Prevents memory leak.
	*/
	
	while (this->isEmpty() == false) {
		this->pop();
	}

}
