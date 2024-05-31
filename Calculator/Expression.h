#ifndef EXPRESSION_H
#define EXPRESSION_H

#include "Variables.h"
#include <string>

//a class to take the expression
class Expression
{
public:
	Variables MyVariables;

	//method combined: input, evaluate and output
	void evaluate();

	//method to find the position of operator
	int setAndFind(int POForigin, int actAfterFor, int forMode, int ifmode);

	//method to take in numbers & operator and return an evaluated value
	std::string processOptr(std::string num1, std::string num2);
};

#endif