#ifndef EVALUATE_H
#define EVALUATE_H

#include "Log.h"
#include <stack>
#include <string>
#include <iostream>

class Evaluate
{
private:
	std::stack <int> values; //a stack to store the values
	std::stack <char> optr; //a stack to store the operators

public:
	//method to apply operator
	static int applyOptr(int a, int b, char op);

	//method to determine the precedence of the operator
	static int precedence(char op);

	//method to calculate and push
	void calPush();

public:
	//constructor that processes the expressions
	Evaluate(std::string tokens);
};

#endif