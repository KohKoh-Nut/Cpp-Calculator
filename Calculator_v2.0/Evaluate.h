#ifndef EVALUATE_H
#define EVALUATE_H

#include "Log.h"
#include "Format.h"
#include <stack>
#include <string>
#include <iostream>

class Evaluate
{
private:
	std::stack <double> values; //a stack to store the values
	std::stack <char> optr; //a stack to store the operators
	std::string tokens; //a string to store the expression

public:
	//method to apply operator
	static double applyOptr(double a, double b, char op);

	//method to determine the precedence of the operator
	static int precedence(char op);

	//method to calculate and push
	void calPush();

	//method to for taking numbers
	int digits(double& num, int& i);

public:
	//constructor that processes the expressions
	Evaluate(std::string tokens);
};

#endif