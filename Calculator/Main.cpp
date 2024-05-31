#include "Variables.h"
#include <iostream>

int main()
{
	std::cout << "This is a calculator.\n";

	Variables MyVariables;

	//get expression from user and output the result
	MyVariables.MyExpression.evaluate();

	return 0;
}