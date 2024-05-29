#include "Expression.h"
#include <iostream>

int main()
{
	std::cout << "This is a calculator.\n";

	//to declare an object in the class Expression
	Expression MyExpression;

	//get expression from user and output the result
	MyExpression.getInput();
	MyExpression.format();
	MyExpression.multDiv();
	MyExpression.addSub();

	std::cout << MyExpression.result;

	return 0;
}