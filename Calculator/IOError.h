#ifndef IOERROR_H
#define IOERROR_H

#include "Variables.h"
#include <string>

//a class for taking input, output result and detecting error
class IOError
{
public:
	Variables MyVariables;

	//method to get input from user
	std::string input();

	//method to output the result
	void output();

	//method to detect error and stop execution
	void error();
};

#endif