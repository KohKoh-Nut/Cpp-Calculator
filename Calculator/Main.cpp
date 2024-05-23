#include "Expression.h"
#include <iostream>

int main()
{
	std::cout << "This is a calculator.\n";

	//to declare an object in the class Expression
	Expression MyExpression;

	//run the method to get input
	MyExpression.getInput();

	std::cout << MyExpression.expression;

	return 0;
}