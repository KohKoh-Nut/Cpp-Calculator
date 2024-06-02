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
#include <iomanip>
#include <sstream>
#include <string>
#include <iostream>

//a class to take the expression
class Expression
{
public:
	//method combined: input, evaluate and output
	static void evaluate();

	/*	method to find the position of operator
		POForigin: what to set the posOfFor
		actAfterFor: the updation of the for loop	*/
	static int find(int POForigin, int actAfterFor, int forMode, int ifmode);

	//method to find the position of multiple operators
	static void findMultDivOrders(int ifMode);

	/*	method to take in numbers & operator and return an evaluated value
		num1: the 1st number
		num2: the 2nd number	*/
	static std::string processOptr(std::string num1, std::string num2);
};

#endif