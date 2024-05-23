#include "Expression.h"
#include <string>
#include <iostream>

//the definition of the method
void Expression::getInput()
{
	std::cout << "Enter an expression: ";
	std::cin >> expression;
}