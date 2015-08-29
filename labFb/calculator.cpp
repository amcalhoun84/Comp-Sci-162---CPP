/*********************************************************************  
** Program Filename: calculator.cpp
** Author: Andrew M. Calhoun (calhouna@onid.oregonstate.edu)
** Date: 7/31/2015
** Description: The calculator class source file for labFb.
** Input: User determined string.
** Output: Reverse Polish Notation Calculations
*********************************************************************/


#include "calculator.hpp"
#include "ADT_Stack.hpp"

/*********************************************************************  
** Function: Calculator::Calculator
** Description: default constructor for RPN calculator.
** Parameters:  none
** Pre-Conditions:  N/A
** Post-Conditions: N/A
*********************************************************************/

Calculator::Calculator()
{ 
	
}

/*********************************************************************  
** Function: int Calculator::operations(std::string inputs)
** Description: Takes numbers and pushes them to the stack, if encounters
**	operator, makes a calculation based on the top two numbers in the stack.
** Parameters:  std::string inputs
** Pre-Conditions:  User or static test inputs an RPN string.
** Post-Conditions: Returns results to user. 
*********************************************************************/

int Calculator::operations(std::string inputs)
{

	int results = 0;

	for(unsigned int i = 0; i<inputs.size(); i++)
		{
			if(isdigit(inputs[i]) && inputs[i] != ' ')
			{
				// std::cout << inputs[i] << std::endl;
				x = inputs[i] - '0';
//				std::cout << x << " is being pushed to stack" << std::endl;
				stack.push(x);
			}
			
			else if(ispunct(inputs[i]) && inputs[i] != ' ')
			{
//			std::cout << "Operand: " << inputs[i] << std::endl;
				if(inputs[i] == '+')
				{
					add();		
				}
				else if(inputs[i] == '-')
				{
					sub();
				}
				else if(inputs[i] == '*' || inputs[i] == 'x')
				{
					mul();
				}
				else if(inputs[i] == '/')
				{
					div();
				}
				else if(inputs[i] == '%')
				{
					mod();
				}
				else if(inputs[i] == '^')
				{
					powers();
				}

				else
				{
					// std::cout << "Nope\n" << std::endl;
				}
			}
		}

	result = stack.peek();
	stack.pop();

	return result;
	
}


/*********************************************************************  
** Function: void Calculator::add()
** Description: the addition function of the calculator.
** Parameters:  none
** Pre-Conditions:  operations finds a '+' operator and there are two numbers in the stack.
** Post-Conditions: Returns added numbers to stack.
*********************************************************************/

void Calculator::add()
{

	x = stack.peek();
//	std::cout << x << " is being called from the stack." << std::endl;
	stack.pop();

	y = stack.peek();
//	std::cout << y << " is being called from the stack. " << std::endl;
	stack.pop();
	
	x += y;

//	std::cout << "new number is being pushed to stack: " << x << std::endl;
	stack.push(x);
		
}

/*********************************************************************  
** Function: void Calculator::sub()
** Description: the subtraction function of the calculator.
** Parameters:  none
** Pre-Conditions:  operations finds a '-' operator and there are two numbers in the stack.
** Post-Conditions: Returns subtracted numbers to stack.
*********************************************************************/

void Calculator::sub()
{
	y = stack.peek();
//	std::cout << x << " is being called from the stack." << std::endl;
	stack.pop();

	x = stack.peek();
//	std::cout << y << " is being called from the stack. " << std::endl;
	stack.pop();

	x -= y;

//	std::cout << "new number is being pushed to stack: " << x << std::endl;
	stack.push(x);
	
}

/*********************************************************************  
** Function: void Calculator::mul()
** Description: the multiplication function of the calculator.
** Parameters:  none
** Pre-Conditions:  operations finds a '*' or 'x' operator and there are two numbers in the stack.
** Post-Conditions: Returns multiplied numbers to stack.
*********************************************************************/

void Calculator::mul()
{
	x = stack.peek();
//	std::cout << x << " is being called from the stack." << std::endl;
	stack.pop();

	y = stack.peek();
//	std::cout << y << " is being called from the stack. " << std::endl;
	stack.pop();

	x *= y;

//	std::cout << "new number is being pushed to stack: " << x << std::endl;
	stack.push(x);
}


/*********************************************************************  
** Function: void Calculator::div()
** Description: the division function of the calculator.
** Parameters:  none
** Pre-Conditions:  operations finds a '/' operator and there are two numbers in the stack.
** Post-Conditions: Returns quotient to stack.
*********************************************************************/

void Calculator::div()
{
	
	y = stack.peek();
//	std::cout << x << " is being called from the stack." << std::endl;
	stack.pop();

	x = stack.peek();
//	std::cout << y << " is being called from the stack. " << std::endl;
	stack.pop();

	x /= y;

//	std::cout << "new number is being pushed to stack: " << x << std::endl;
	stack.push(x);
	
}

/*********************************************************************  
** Function: void Calculator::mod()
** Description: the modulous/remainder function of the calculator.
** Parameters:  none
** Pre-Conditions:  operations finds a '%' operator and there are two numbers in the stack.
** Post-Conditions: Returns modulus result to stack.
*********************************************************************/

void Calculator::mod()
{
	x = stack.peek();
//	std::cout << x << " is being called from the stack." << std::endl;
	stack.pop();

	y = stack.peek();
//	std::cout << y << " is being called from the stack. " << std::endl;
	stack.pop();

	x %= y;

	stack.push(x);

}

void Calculator::powers()
{
	x = stack.peek();
	stack.pop();

	y = stack.peek();
	stack.pop();

	x = pow(x, y);

	stack.push(x);

}