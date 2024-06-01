#ifndef EXPRESSION_H
#define EXPRESSION_H

#include "IOError.h"
#include "Brackets.h"
#include "Condition.h"
#include "AddSub.h"
#include "MultDiv.h"
#include "Orders.h"
#include "Format.h"
#include "Variables.h"
#include <string>
#include <iostream>

//a class to take the expression
class Expression
{
public:
	//method combined: input, evaluate and output
	static void evaluate();

	//method to find the position of operator
	static int setAndFind(int POForigin, int actAfterFor, int forMode, int ifmode);

	//method to take in numbers & operator and return an evaluated value
	static std::string processOptr(std::string num1, std::string num2);
};

#endif