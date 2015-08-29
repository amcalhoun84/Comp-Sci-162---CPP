/*********************************************************************
** Program Filename: stack.hpp
** Author: Andrew M. Calhoun
** Date: 07/21/2015
** Description: The source file for the main function.
** Input: User inputs numbers to be put into a stack and queue.
** Output: Shows the workings of stacks and queues.
*********************************************************************/

#include "stack.hpp"
#include "queue.hpp"
#include <iostream>
#include <cstdlib> // for debugging.

/*********************************************************************
** Function: int main()
** Description: The main function for the LabFa Queue/Stack program. Has
**	a minimalist menu and user inputs. Displays the activity of the queue
**	and stack.
** Parameters: N/A
** Pre-Conditions: N/A
** Post-Conditions: N/A
*********************************************************************/ 

int main()

{
	Stack newStack;
	Queue newQueue;

//	int input[] = {1, 2, 5, 4, 3, 1, 2, 3, 4, 1}; Originally intended as a default, but
												// user input is better/more interesting.


/*	newStack.push(5);	newStack.push(1);	newStack.push(3);	newStack.push(7);	newStack.push(8);	newStack.push(9);

	newQueue.addBack(4);	newQueue.addBack(1);	newQueue.addBack(3);	newQueue.addBack(7);	newQueue.addBack(4);
*/
	int input, 
		inputNumbers,
		newNumbers;

	do
	{
		std::cout << "Stack and Queues\n"
				<< "1. Start the Program\n"
				<< "0. Quit" << std::endl;

		std::cout << "\nPlease enter choice: >> ";

		std::cin >> input;
		//std::cin.ignore(1024, '\n');
		//std::cin.clear();

		switch(input) {

				case 1:
				{

					/*Takes the user input and gives feedback. */

					std::cout << "How many integers do you want for your stack and queue?" << std::endl;
					std::cin >> inputNumbers;

					for(int i=0; i < inputNumbers; i++)
					{
						std::cout << "Number" << i+1 << " >> " << std::endl; 
						std::cin >> newNumbers;

						std::cout << "Pushing " << newNumbers << " to the top of the stack and the back of the queue." << std::endl << std::endl;
						newStack.push(newNumbers);
						newQueue.addBack(newNumbers);
					}

					std::cout << "Now, let's go through everything one by one!" << std::endl;

					while(!newStack.isEmpty())
					{
						
						std::cout << "\nPopping " << newStack.peek() << " from the top of the stack." << std::endl; 
						newStack.pop();
						
					}

					while(!newQueue.isEmpty())
					{
						std::cout << "\nGetting " << newQueue.getFront() << " from the front of the queue. " << std::endl;
						newQueue.removeFront();
					}

					break;
				}

				case 0:
				{
					return 0;
				}

				default:
				{

				std::cout << "Invalid input." << std::endl;
				}
					

			}

		}
		while (input != 0);

}
