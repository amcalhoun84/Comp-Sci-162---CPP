/*********************************************************************
** Program Filename: ADT_Stack.hpp
** Author: Brett Anderson
** Date:  6/27/15
** Description: Header for the Abstract Data Type Stack Class
** Input: none.
** Output:
*********************************************************************/

#ifndef ADTSTACK_HPP
#define ADTSTACK_HPP


// struct for the node used in the data structure
struct sNode {
	int data;
	sNode *nPtrNext;
};

class ADT_Stack
{
private:
	sNode *nPtr;
public:
	ADT_Stack();
	ADT_Stack(int num);
	void push(int num);
	int peek();
	void pop();
	bool isEmpty();

	~ADT_Stack();
};

#endif