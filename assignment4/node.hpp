/*********************************************************************
** Program Filename: node.hpp
** Author: Andrew M. Calhoun
** Date: 07/21/2015
** Description: The header and source file for the queue portion of the lab
** Input: N/A
** Output: N/A
*********************************************************************/

#ifndef NODE_HPP
#define NODE_HPP

// #define NULL 0		// Null is a 0 MACRO

#include <cctype>
#include <iostream>
#include "characterType.hpp"

struct Node 
{
	
/*********************************************************************
** Function: Node(characterType* character1, Node* next1 = NULL)
** Description: Node() constructor.
** Parameters: characterType* character1, Node* next1 = NULL
** Pre-Conditions: Creates a node to help determine the head and tail of the
		queue and stack.
** Post-Conditions: Node exists and is ready to take numbers.
*********************************************************************/ 
	

	Node(CharacterType* character1, Node* next1 = NULL)
	{
		character = character1;
		next = next1;
	}

	Node* next;
	CharacterType* character;
};

#endif